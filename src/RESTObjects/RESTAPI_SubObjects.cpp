//
// Created by stephane bourque on 2021-10-27.
//

#include "RESTAPI_SubObjects.h"
#include "framework/MicroService.h"

using OpenWifi::RESTAPI_utils::field_to_json;
using OpenWifi::RESTAPI_utils::field_from_json;


namespace OpenWifi::SubObjects {

    void HomeDeviceMode::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "enableLEDS", enableLEDS);
        field_to_json(Obj, "type", type);
        field_to_json(Obj, "subnet", subnet);
        field_to_json(Obj, "subnetMask", subnetMask);
        field_to_json(Obj, "startIP", startIP);
        field_to_json(Obj, "endIP", endIP);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool HomeDeviceMode::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "enableLEDS", enableLEDS);
            field_from_json(Obj, "type", type);
            field_from_json(Obj, "subnet", subnet);
            field_from_json(Obj, "subnetMask", subnetMask);
            field_from_json(Obj, "startIP", startIP);
            field_from_json(Obj, "endIP", endIP);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void IPReservation::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "nickname", nickname);
        field_to_json(Obj, "ipAddress", ipAddress);
        field_to_json(Obj, "macAddress", macAddress);
    }

    bool IPReservation::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "nickname", nickname);
            field_from_json(Obj, "ipAddress", ipAddress);
            field_from_json(Obj, "macAddress", macAddress);
            return true;
        } catch (...) {
        }
        return false;
    }

    void IPReservationList::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "id", id);
        field_to_json(Obj, "reservations", reservations);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool IPReservationList::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "id", id);
            field_from_json(Obj, "reservations", reservations);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void DnsConfiguration::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "ISP", ISP);
        field_to_json(Obj, "custom", custom);
        field_to_json(Obj, "primary", primary);
        field_to_json(Obj, "secondary", secondary);
    }

    bool DnsConfiguration::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "ISP", ISP);
            field_from_json(Obj, "custom", custom);
            field_from_json(Obj, "primary", primary);
            field_from_json(Obj, "secondary", secondary);
            return true;
        } catch (...) {
        }
        return false;
    }

    void InternetConnection::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "type", type);
        field_to_json(Obj, "username", username);
        field_to_json(Obj, "password", password);
        field_to_json(Obj, "ipAddress", ipAddress);
        field_to_json(Obj, "subNetMask", subNetMask);
        field_to_json(Obj, "defaultGateway", defaultGateway);
        field_to_json(Obj, "primaryDns", primaryDns);
        field_to_json(Obj, "secondaryDns", secondaryDns);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool InternetConnection::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "type", type);
            field_from_json(Obj, "username", username);
            field_from_json(Obj, "password", password);
            field_from_json(Obj, "ipAddress", ipAddress);
            field_from_json(Obj, "subNetMask", subNetMask);
            field_from_json(Obj, "defaultGateway", defaultGateway);
            field_from_json(Obj, "primaryDns", primaryDns);
            field_from_json(Obj, "secondaryDns", secondaryDns);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void WifiNetwork::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "type", type);
        field_to_json(Obj, "name", name);
        field_to_json(Obj, "password", password);
        field_to_json(Obj, "encryption", encryption);
        field_to_json(Obj, "bands", bands);
    }

    bool WifiNetwork::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "type", type);
            field_from_json(Obj, "name", name);
            field_from_json(Obj, "password", password);
            field_from_json(Obj, "encryption", encryption);
            field_from_json(Obj, "bands", bands);
            return true;
        } catch (...) {
        }
        return false;
    }

    void WifiNetworkList::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "wifiNetworks", wifiNetworks);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool WifiNetworkList::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "wifiNetworks", wifiNetworks);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void AccessTime::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "day", day);
        field_to_json(Obj, "rangeList", rangeList);
    }

    bool AccessTime::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "day", day);
            field_from_json(Obj, "rangeList", rangeList);
            return true;
        } catch (...) {
        }
        return false;
    }

    void AccessTimes::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "schedule", schedule);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool AccessTimes::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "schedule", schedule);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void SubscriberDevice::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "name", name);
        field_to_json(Obj, "description", description);
        field_to_json(Obj, "macAddress", macAddress);
        field_to_json(Obj, "manufacturer", manufacturer);
        field_to_json(Obj, "firstContact", firstContact);
        field_to_json(Obj, "lastContact", lastContact);
        field_to_json(Obj, "group", group);
        field_to_json(Obj, "icon", icon);
        field_to_json(Obj, "suspended", suspended);
        field_to_json(Obj, "ip", ip);
        field_to_json(Obj, "schedule", schedule);
    }

    bool SubscriberDevice::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "name", name);
            field_from_json(Obj, "description", description);
            field_from_json(Obj, "macAddress", macAddress);
            field_from_json(Obj, "manufacturer", manufacturer);
            field_from_json(Obj, "firstContact", firstContact);
            field_from_json(Obj, "lastContact", lastContact);
            field_from_json(Obj, "group", group);
            field_from_json(Obj, "icon", icon);
            field_from_json(Obj, "suspended", suspended);
            field_from_json(Obj, "ip", ip);
            field_from_json(Obj, "schedule", schedule);
            return true;
        } catch (...) {
        }
        return false;
    }

    void SubscriberDeviceList::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "devices", devices);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool SubscriberDeviceList::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "devices", devices);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void Association::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "name", name);
        field_to_json(Obj, "macAddress", macAddress);
        field_to_json(Obj, "rssi", rssi);
        field_to_json(Obj, "power", power);
        field_to_json(Obj, "ipv4", ipv4);
        field_to_json(Obj, "ipv6", ipv6);
        field_to_json(Obj, "tx", tx);
        field_to_json(Obj, "rx", rx);
    }

    bool Association::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "name", name);
            field_from_json(Obj, "macAddress", macAddress);
            field_from_json(Obj, "rssi", rssi);
            field_from_json(Obj, "power", power);
            field_from_json(Obj, "ipv4", ipv4);
            field_from_json(Obj, "ipv6", ipv6);
            field_from_json(Obj, "tx", tx);
            field_from_json(Obj, "rx", rx);
            return true;
        } catch (...) {
        }
        return false;
    }

    void AssociationList::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "associations", associations);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool AssociationList::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "associations", associations);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void Client::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "macAddress", macAddress);
        field_to_json(Obj, "speed", speed);
        field_to_json(Obj, "mode", mode);
        field_to_json(Obj, "ipv4", ipv4);
        field_to_json(Obj, "ipv6", ipv6);
        field_to_json(Obj, "tx", tx);
        field_to_json(Obj, "rx", rx);
    }

    bool Client::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "macAddress", macAddress);
            field_from_json(Obj, "speed", speed);
            field_from_json(Obj, "mode", mode);
            field_from_json(Obj, "ipv4", ipv4);
            field_from_json(Obj, "ipv6", ipv6);
            field_from_json(Obj, "tx", tx);
            field_from_json(Obj, "rx", rx);
            return true;
        } catch (...) {
        }
        return false;
    }

    void ClientList::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "clients", clients);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool ClientList::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "clients", clients);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }

    void Location::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "buildingName", buildingName);
        field_to_json(Obj, "addressLines", addressLines);
        field_to_json(Obj, "city", city);
        field_to_json(Obj, "state", state);
        field_to_json(Obj, "postal", postal);
        field_to_json(Obj, "country", country);
        field_to_json(Obj, "phones", phones);
        field_to_json(Obj, "mobiles", mobiles);
    }

    bool Location::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "buildingName", buildingName);
            field_from_json(Obj, "addressLines", addressLines);
            field_from_json(Obj, "city", city);
            field_from_json(Obj, "state", state);
            field_from_json(Obj, "postal", postal);
            field_from_json(Obj, "country", country);
            field_from_json(Obj, "phones", phones);
            field_from_json(Obj, "mobiles", mobiles);
            return true;
        } catch (...) {
        }
        return false;

    }

    void AccessPoint::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "macAddress", macAddress);
        field_to_json(Obj, "name", name);
        field_to_json(Obj, "id", id);
        field_to_json(Obj, "location", location);
    }

    bool AccessPoint::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "macAddress", macAddress);
            field_from_json(Obj, "name", name);
            field_from_json(Obj, "id", id);
            field_from_json(Obj, "location", location);
            return true;
        } catch (...) {
        }
        return false;
    }

    void AccessPointList::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "list", list);
    }

    bool AccessPointList::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "list", list);
            return true;
        } catch (...) {
        }
        return false;
    }

    void SubscriberInfo::to_json(Poco::JSON::Object &Obj) const {
        field_to_json(Obj, "id", id);
        field_to_json(Obj, "userId", userId);
        field_to_json(Obj, "firstName", firstName);
        field_to_json(Obj, "initials", initials);
        field_to_json(Obj, "lastName", lastName);
        field_to_json(Obj, "phoneNumber", phoneNumber);
        field_to_json(Obj, "secondaryEmail", secondaryEmail);
        field_to_json(Obj, "accessPoints", accessPoints);
        field_to_json(Obj, "serviceAddress", serviceAddress);
        field_to_json(Obj, "billingAddress", billingAddress);
        field_to_json(Obj, "created", created);
        field_to_json(Obj, "modified", modified);
    }

    bool SubscriberInfo::from_json(const Poco::JSON::Object::Ptr &Obj) {
        try {
            field_from_json(Obj, "id", id);
            field_from_json(Obj, "userId", userId);
            field_from_json(Obj, "firstName", firstName);
            field_from_json(Obj, "initials", initials);
            field_from_json(Obj, "lastName", lastName);
            field_from_json(Obj, "phoneNumber", phoneNumber);
            field_from_json(Obj, "secondaryEmail", secondaryEmail);
            field_from_json(Obj, "accessPoints", accessPoints);
            field_from_json(Obj, "serviceAddress", serviceAddress);
            field_from_json(Obj, "billingAddress", billingAddress);
            field_from_json(Obj, "created", created);
            field_from_json(Obj, "modified", modified);
            return true;
        } catch (...) {
        }
        return false;
    }
}