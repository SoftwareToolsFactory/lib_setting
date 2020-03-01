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
static SettingParam datastoreIPAddress( "datastore", eSettingLevel::SYS, "127.0.0.1" );
static SettingParam useCacheBuffer( "cache_buffer", eSettingLevel::SYS, eSettingType::BOOL, "true" );
static SettingParam workerThreadsNumber( "worker_threads", eSettingLevel::APP, eSettingType::INT, "1" );
static SettingParam timeRatio( "time ratio", eSettingLevel::APP, eSettingType::FLOAT, "1" );
static SettingParam logpath("logpath", eSettingLevel::USER, eSettingType::STRING, "/var/log/stf");

static SettingParam boolTestTrue( "bool_test_true", eSettingLevel::USER, true );
static SettingParam boolTestFalse( "bool_test_false", eSettingLevel::USER, false );
static SettingParam strTest( "str_test", eSettingLevel::USER, "some string value" );
static SettingParam floatTest( "float_test", eSettingLevel::USER, 1.234f );
static SettingParam intTest( "int_test", eSettingLevel::USER, 1234 );

void onInit( ISettingsConfig& settingsCfg ) {
    settingsCfg.addParam( datastoreIPAddress );
    settingsCfg.addParam( useCacheBuffer );
    settingsCfg.addParam( workerThreadsNumber );
    settingsCfg.addParam( timeRatio );
    settingsCfg.addParam( logpath );

    settingsCfg.addParam( boolTestTrue );
    settingsCfg.addParam( boolTestFalse );
    settingsCfg.addParam( strTest );
    settingsCfg.addParam( floatTest );
    settingsCfg.addParam( intTest );
}

Settings settings;

int main(int argc, const char* argv[]) {
    onInit( settings );
}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
