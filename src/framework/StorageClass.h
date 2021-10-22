//
// Created by stephane bourque on 2021-10-06.
//

#ifndef OPENWIFI_STORAGE_H
#define OPENWIFI_STORAGE_H

#include "framework/MicroService.h"

namespace OpenWifi {
    enum DBType {
        sqlite,
        pgsql,
        mysql
    };

    class StorageClass : public SubSystemServer {
    public:
        static StorageClass *instance() {
            if (instance_ == nullptr) {
                instance_ = new StorageClass;
            }
            return instance_;
        }

        StorageClass() noexcept:
            SubSystemServer("StorageClass", "STORAGE-SVR", "storage")
        {
        }

        int Start() override {
            std::lock_guard		Guard(Mutex_);

            Logger_.setLevel(Poco::Message::PRIO_NOTICE);
            Logger_.notice("Starting.");
            std::string DBType = MicroService::instance().ConfigGetString("storage.type");

            if (DBType == "sqlite") {
                Setup_SQLite();
            } else if (DBType == "postgresql") {
                Setup_PostgreSQL();
            } else if (DBType == "mysql") {
                Setup_MySQL();
            }
            return 0;
        }

        void Stop() override {

        }

    private:
        static StorageClass      							*instance_;
        std::unique_ptr<Poco::Data::SessionPool>        	Pool_;
        std::unique_ptr<Poco::Data::SQLite::Connector>  	SQLiteConn_;
        std::unique_ptr<Poco::Data::PostgreSQL::Connector>  PostgresConn_;
        std::unique_ptr<Poco::Data::MySQL::Connector>       MySQLConn_;
        DBType                                              dbType_ = sqlite;

        typedef std::function<bool(const char *FieldName, std::string &Value)>   exist_func;
        typedef std::function<bool(const char *FieldName, std::string &Value, std::string &Name, std::string &Description)>   expand_func;
        std::map<std::string, exist_func>                   ExistFunc_;
        std::map<std::string, expand_func>                  ExpandFunc_;

        Poco::Thread                                        Updater_;
        std::set<std::string>                               DeviceTypes_;
        std::atomic_bool                                    Running_=false;

        inline int Setup_SQLite();
        inline int Setup_MySQL();
        inline int Setup_PostgreSQL();
    };

    inline StorageClass * Storage() { return StorageClass::instance(); }

#ifdef	SMALL_BUILD
    int Service::Setup_MySQL() { Daemon()->exit(Poco::Util::Application::EXIT_CONFIG); return 0; }
    int Service::Setup_PostgreSQL() { Daemon()->exit(Poco::Util::Application::EXIT_CONFIG); return 0; }
#else

    inline int StorageClass::Setup_SQLite() {
        Logger_.notice("SQLite StorageClass enabled.");
        dbType_ = sqlite;
        auto DBName = MicroService::instance().DataDir() + "/" + MicroService::instance().ConfigGetString("storage.type.sqlite.db");
        auto NumSessions = MicroService::instance().ConfigGetInt("storage.type.sqlite.maxsessions", 64);
        auto IdleTime = MicroService::instance().ConfigGetInt("storage.type.sqlite.idletime", 60);
        SQLiteConn_ = std::make_unique<Poco::Data::SQLite::Connector>();
        SQLiteConn_->registerConnector();
        Pool_ = std::make_unique<Poco::Data::SessionPool>(SQLiteConn_->name(), DBName, 4, NumSessions, IdleTime);
        return 0;
    }

    inline int StorageClass::Setup_MySQL() {
        Logger_.notice("MySQL StorageClass enabled.");
        dbType_ = mysql;
        auto NumSessions = MicroService::instance().ConfigGetInt("storage.type.mysql.maxsessions", 64);
        auto IdleTime = MicroService::instance().ConfigGetInt("storage.type.mysql.idletime", 60);
        auto Host = MicroService::instance().ConfigGetString("storage.type.mysql.host");
        auto Username = MicroService::instance().ConfigGetString("storage.type.mysql.username");
        auto Password = MicroService::instance().ConfigGetString("storage.type.mysql.password");
        auto Database = MicroService::instance().ConfigGetString("storage.type.mysql.database");
        auto Port = MicroService::instance().ConfigGetString("storage.type.mysql.port");

        std::string ConnectionStr =
                "host=" + Host +
                ";user=" + Username +
                ";password=" + Password +
                ";db=" + Database +
                ";port=" + Port +
                ";compress=true;auto-reconnect=true";

        MySQLConn_ = std::make_unique<Poco::Data::MySQL::Connector>();
        MySQLConn_->registerConnector();
        Pool_ = std::make_unique<Poco::Data::SessionPool>(MySQLConn_->name(), ConnectionStr, 4, NumSessions, IdleTime);

        return 0;
    }

    inline int StorageClass::Setup_PostgreSQL() {
        Logger_.notice("PostgreSQL StorageClass enabled.");
        dbType_ = pgsql;
        auto NumSessions = MicroService::instance().ConfigGetInt("storage.type.postgresql.maxsessions", 64);
        auto IdleTime = MicroService::instance().ConfigGetInt("storage.type.postgresql.idletime", 60);
        auto Host = MicroService::instance().ConfigGetString("storage.type.postgresql.host");
        auto Username = MicroService::instance().ConfigGetString("storage.type.postgresql.username");
        auto Password = MicroService::instance().ConfigGetString("storage.type.postgresql.password");
        auto Database = MicroService::instance().ConfigGetString("storage.type.postgresql.database");
        auto Port = MicroService::instance().ConfigGetString("storage.type.postgresql.port");
        auto ConnectionTimeout = MicroService::instance().ConfigGetString("storage.type.postgresql.connectiontimeout");

        std::string ConnectionStr =
                "host=" + Host +
                " user=" + Username +
                " password=" + Password +
                " dbname=" + Database +
                " port=" + Port +
                " connect_timeout=" + ConnectionTimeout;

        PostgresConn_ = std::make_unique<Poco::Data::PostgreSQL::Connector>();
        PostgresConn_->registerConnector();
        Pool_ = std::make_unique<Poco::Data::SessionPool>(PostgresConn_->name(), ConnectionStr, 4, NumSessions, IdleTime);

        return 0;
    }
#endif

}

#endif //OPENWIFI_STORAGE_H