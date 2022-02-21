//
// Created by stephane bourque on 2022-02-20.
//

#include "RESTAPI_signup_handler.h"
#include "StorageService.h"
#include "RESTObjects/RESTAPI_SecurityObjects.h"

namespace OpenWifi {

    void RESTAPI_signup_handler::DoPost() {

        auto UserName = GetParameter("email","");
        auto SerialNumber = GetParameter("serialNumber","");

        if(UserName.empty() || SerialNumber.empty()) {
            return BadRequest(RESTAPI::Errors::MissingOrInvalidParameters);
        }

        if(!Utils::ValidEMailAddress(UserName)) {
            return BadRequest(RESTAPI::Errors::InvalidEmailAddress);
        }

        if(!Utils::ValidSerialNumber(SerialNumber)) {
            return BadRequest(RESTAPI::Errors::InvalidSerialNumber);
        }

        return OK();
    }

    void RESTAPI_signup_handler::DoPut() {
        // TODO
    }

}