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
//     2. 2020.03.01, 15:00 Nuroferatu   [+] Bool/ini/float param tests
//     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial
// ---------------------------------------------------------------------------
#include <iostream>
#include "settings.h"

using namespace std;
using namespace stf;

// Sample params...
static SettingParam datastoreIPAddress( "datastore", eSettingLevel::SYS, "127.0.0.1" );
static SettingParam useCacheBuffer( "cache_buffer", eSettingLevel::SYS, eSettingType::BOOL, "TruE" );
static SettingParam workerThreadsNumber( "worker_threads", eSettingLevel::APP, eSettingType::INT, "1" );
static SettingParam timeRatio( "time ratio", eSettingLevel::APP, eSettingType::FLOAT, "1" );
static SettingParam logpath("logpath", eSettingLevel::USER, eSettingType::STRING, "/var/log/stf");

static SettingParam boolTestTrue( "bool_test_true", eSettingLevel::USER, true );
static SettingParam boolTestFalse( "bool_test_false", eSettingLevel::USER, false );
static SettingParam strTest( "str_test", eSettingLevel::USER, "some string value" );
static SettingParam floatTest( "float_test", eSettingLevel::USER, 1.234f );
static SettingParam intTest( "int_test", eSettingLevel::USER, 1234 );

Settings settings;

void onInit( ISettingsConfig& settingsCfg ) {
    settingsCfg.addParam( datastoreIPAddress );
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

    settings.loadSysConfig( "" );
}

void boolTestVal( const char* comment, const SettingParam& param ) {
    cout << "-------------------------------------------------\n";
    cout << "Test '" << comment << "'\n";
    cout << "Name: '" << param.getName() << "' default = '" << param.getDefaultVal() << "'\n";
    cout << "Val: " << std::boolalpha << param.asBool() << std::noboolalpha << endl;
}

void intTestVal( const char* comment, const SettingParam& param ) {
    cout << "-------------------------------------------------\n";
    cout << "Test '" << comment << "'\n";
    cout << "Name: '" << param.getName() << "' default = '" << param.getDefaultVal() << "'\n";
    cout << "Val: " << param.asInt() << endl;
}

void floatTestVal( const char* comment, const SettingParam& param ) {
    cout << "-------------------------------------------------\n";
    cout << "Test '" << comment << "'\n";
    cout << "Name: '" << param.getName() << "' default = '" << param.getDefaultVal() << "'\n";
    cout << "Val: " << param.asFloat() << endl;
}

void boolTestException( const char* comment, const SettingParam& param ) {
    cout << "-------------------------------------------------\n";
    cout << "Test '" << comment << "'\n";
    cout << "Name: '" << param.getName() << "' type of '" << param.getType() << "'\n";

    cout << "Get asString() = " << param.asStr() << endl;   // No exception
    cout << "Get asBool() = " << param.asBool() << endl;    // No exception

    try {
        cout << "Get asInt() = " << param.asInt() << " [TEST FAILED]" << endl;
    }
    catch (const std::exception& e) {
        cout << "* Exception: " << e.what() << " [TEST SUCCESS]" << endl;
    }

    try {
        cout << "Get asFloat() = " << param.asFloat() << " [TEST FAILED]" << endl;
    }
    catch (const std::exception& e) {
        cout << "* Exception: " << e.what() << " [TEST SUCCESS]" << endl;
    }
}

void intTestException( const char* comment, const SettingParam& param ) {
    cout << "-------------------------------------------------\n";
    cout << "Test '" << comment << "'\n";
    cout << "Name: '" << param.getName() << "' type of '" << param.getType() << "'\n";

    cout << "Get asString() = " << param.asStr() << endl;   // No exception
    cout << "Get asInt() = " << param.asInt() << endl;      // No exception

    try {
        cout << "Get asBool() = " << param.asBool() << " [TEST FAILED]" << endl;
    }
    catch (const std::exception& e) {
        cout << "* Exception: " << e.what() << " [TEST SUCCESS]" << endl;
    }

    try {
        cout << "Get asFloat() = " << param.asFloat() << " [TEST FAILED]" << endl;
    }
    catch (const std::exception& e) {
        cout << "* Exception: " << e.what() << " [TEST SUCCESS]" << endl;
    }
}

void floatTestException( const char* comment, const SettingParam& param ) {
    cout << "-------------------------------------------------\n";
    cout << "Test '" << comment << "'\n";
    cout << "Name: '" << param.getName() << "' type of '" << param.getType() << "'\n";

    cout << "Get asString() = " << param.asStr() << endl;   // No exception
    cout << "Get asFloat() = " << param.asFloat() << endl;      // No exception

    try {
        cout << "Get asBool() = " << param.asBool() << " [TEST FAILED]" << endl;
    }
    catch (const std::exception& e) {
        cout << "* Exception: " << e.what() << " [TEST SUCCESS]" << endl;
    }

    try {
        cout << "Get asInt() = " << param.asInt() << " [TEST FAILED]" << endl;
    }
    catch (const std::exception& e) {
        cout << "* Exception: " << e.what() << " [TEST SUCCESS]" << endl;
    }
}

int main(int argc, const char* argv[]) {
    try {
        onInit( settings );

        cout << settings.getParam( "datastore" ).asStr() << endl;

        boolTestVal( "Test bool true", boolTestTrue );
        boolTestVal( "Test bool false", boolTestFalse );
        boolTestVal( "useCacheBuffer", useCacheBuffer );

        intTestVal( "intTest", intTest );
        floatTestVal( "floatTest", floatTest );

        boolTestException( "Exception test asInt/asFloat must fail", boolTestTrue );
        intTestException( "Exception test asBool/asFloat must fail", intTest );
        floatTestException( "Exception test asBool/asInt must fail", floatTest );
    }
    catch (const std::exception & e) {
        cout << "Unhandled exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unhandled UNKNOWN exception" << endl;
    }
}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
