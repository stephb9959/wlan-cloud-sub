//
// Created by stephane bourque on 2021-10-23.
//

#include "framework/MicroService.h"

namespace OpenWifi {

    Poco::Net::HTTPRequestHandler * RESTAPI_external_server(const char *Path, RESTAPIHandler::BindingMap &Bindings,
                                                            Poco::Logger & L, RESTAPI_GenericServer & S) {
//      return  RESTAPI_Router<>(Path, Bindings, L, S);
        return nullptr;
    }

    Poco::Net::HTTPRequestHandler * RESTAPI_internal_server(const char *Path, RESTAPIHandler::BindingMap &Bindings,
                                                            Poco::Logger & L, RESTAPI_GenericServer & S) {
//      return RESTAPI_Router_I<>(Path, Bindings, L, S);
        return nullptr;
    }
}