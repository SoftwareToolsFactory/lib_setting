//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: Settings library test app                                         |
// | By: Nuroferatu - https://github.com/Nuroferatu                          |
// |                                                                         |
// | Copyright (C)2019 SoftwareToolsFactory                                  |
// |                   http://softwaretoolsfactory.com                       |
// '-------------------------------------------------------------------------'
// ----= Change log =---------------------------------------------------------
//     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial
// ---------------------------------------------------------------------------
#include <iostream>
#include "settings.h"

using namespace std;
using namespace stf;

// Sample params...
static SettingParam datastoreIPAddress( "datastore", eSettingLevel::SYS, eSettingType::STRING, "127.0.0.1" );
static SettingParam useCacheBuffer( "cache buffer", eSettingLevel::SYS, eSettingType::BOOL, "true" );
static SettingParam workerThreadsNumber( "worker threads", eSettingLevel::APP, eSettingType::NUM_INT, "1" );
static SettingParam logpath("logpath", eSettingLevel::USER, eSettingType::STRING, "/var/log/stf");

void onInit( ISettingsConfig& settingsCfg ) {
    settingsCfg.addParam( datastoreIPAddress );
    settingsCfg.addParam( useCacheBuffer );
    settingsCfg.addParam( workerThreadsNumber );
    settingsCfg.addParam( logpath );
}

int main(int argc, const char* argv[]) {
    cout << Settings::get( "datastore" ).asStr() << endl;
    cout << std::boolalpha << Settings::get( "cache buffer" ).asBool() << std::noboolalpha << endl;
    cout << Settings::get( "worker threads" ).asInt() << endl;
    cout << Settings::get( "logpath" ).asStr() << endl;



}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
