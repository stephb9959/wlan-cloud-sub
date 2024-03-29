//
//	License type: BSD 3-Clause License
//	License copy: https://github.com/Telecominfraproject/wlan-cloud-ucentralgw/blob/master/LICENSE
//
//	Created by Stephane Bourque on 2021-03-04.
//	Arilia Wireless Inc.
//

#include "framework/MicroService.h"

#include "Daemon.h"
#include "StorageService.h"
#include "SubscriberCache.h"

namespace OpenWifi {
	class Daemon *Daemon::instance_ = nullptr;

	class Daemon *Daemon::instance() {
		if (instance_ == nullptr) {
			instance_ = new Daemon(vDAEMON_PROPERTIES_FILENAME,
								   vDAEMON_ROOT_ENV_VAR,
								   vDAEMON_CONFIG_ENV_VAR,
								   vDAEMON_APP_NAME,
								   vDAEMON_BUS_TIMER,
								   SubSystemVec{
									   StorageService(),
									   SubscriberCache()
								   });
		}
		return instance_;
	}

	void Daemon::initialize(Poco::Util::Application &self) {
		MicroService::initialize(*this);
    }

    void MicroServicePostInitialization() {
	}
}

int main(int argc, char **argv) {
	try {
		auto App = OpenWifi::Daemon::instance();
		auto ExitCode =  App->run(argc, argv);
		delete App;

		return ExitCode;

	} catch (Poco::Exception &exc) {
		std::cerr << exc.displayText() << std::endl;
		return Poco::Util::Application::EXIT_SOFTWARE;
	}
}

// end of namespace