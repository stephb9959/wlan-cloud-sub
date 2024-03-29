//
// Created by stephane bourque on 2021-12-07.
//

#pragma once

#include <string>
#include "framework/MicroService.h"
#include "framework/OpenWifiTypes.h"
#include "RESTObjects/RESTAPI_SecurityObjects.h"

namespace OpenWifi {

    namespace CertObjects {

        struct CertificateEntry {
            OpenWifi::Types::UUID_t         id;
            OpenWifi::Types::UUID_t         entity;
            OpenWifi::Types::UUID_t         creator;
            std::string                     type;
            std::string                     status;
            std::string                     certificate;
            std::string                     key;
            std::string                     devid;
            std::string                     cas;
            std::string                     manufacturer;
            std::string                     model;
            std::string                     redirector;
            std::string                     commonName;
            std::string                     certificateId;
            OpenWifi::Types::UUID_t         batch;
            uint64_t                        created = 0;
            uint64_t                        modified = 0;
            uint64_t                        revoked = 0;
            uint64_t                        revokeCount = 0;

            void to_json(Poco::JSON::Object &Obj) const;
            bool from_json(const Poco::JSON::Object::Ptr &Obj);
        };

        struct EntityEntry {
            OpenWifi::Types::UUID_t         id;
            OpenWifi::Types::UUID_t         creator;
            std::string                     name;
            std::string                     description;
            std::string                     defaultRedirector;
            std::string                     apiKey;
            std::string                     serverEnrollmentProfile;
            std::string                     clientEnrollmentProfile;
            std::string                     organization;
            SecurityObjects::NoteInfoVec    notes;
            bool                            suspended=false;
            bool                            deleted=false;
            uint64_t                        created = 0 ;
            uint64_t                        modified = 0 ;

            void to_json(Poco::JSON::Object &Obj) const;
            bool from_json(const Poco::JSON::Object::Ptr &Obj);
        };

        struct BatchEntry {
            OpenWifi::Types::UUID_t         id;
            OpenWifi::Types::UUID_t         entity;
            OpenWifi::Types::UUID_t         creator;
            std::string                     name;
            std::string                     description;
            std::string                     manufacturer;
            std::string                     model;
            std::string                     redirector;
            std::vector<std::string>        commonNames;
            std::vector<std::string>        jobHistory;
            SecurityObjects::NoteInfoVec    notes;
            uint64_t                        submitted = 0 ;
            uint64_t                        started = 0 ;
            uint64_t                        completed = 0 ;
            uint64_t                        modified = 0 ;

            void to_json(Poco::JSON::Object &Obj) const;
            bool from_json(const Poco::JSON::Object::Ptr &Obj);
        };

        struct JobEntry {
            OpenWifi::Types::UUID_t         id;
            OpenWifi::Types::UUID_t         entity;
            OpenWifi::Types::UUID_t         creator;
            OpenWifi::Types::UUID_t         batch;
            std::string                     command;
            OpenWifi::Types::StringVec      commonNames;
            OpenWifi::Types::StringVec      completedNames;
            OpenWifi::Types::StringVec      errorNames;
            Types::StringPairVec            parameters;
            std::string                     status;
            uint64_t                        submitted=0;
            uint64_t                        started=0;
            uint64_t                        completed=0;

            void to_json(Poco::JSON::Object &Obj) const;
            bool from_json(const Poco::JSON::Object::Ptr &Obj);
        };
    }
}