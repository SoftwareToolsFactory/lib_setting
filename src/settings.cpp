//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: Settings library                                                  |
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

using namespace stf;

std::ostream& stf::operator << ( std::ostream& out, stf::eSettingLevel level ) {
    switch (level) {
        case eSettingLevel::APP: out << "APP"; break;
        case eSettingLevel::SYS: out << "SYS"; break;
        case eSettingLevel::USER: out << "USER"; break;
    }
    return out;
}

std::ostream& stf::operator << ( std::ostream& out, stf::eSettingType type ) {
    switch (type) {
        case eSettingType::BOOL: out << "BOOL"; break;
        case eSettingType::INT: out << "INT"; break;
        case eSettingType::FLOAT: out << "FLOAT"; break;
        case eSettingType::STRING: out << "STRING"; break;
    }
    return out;
}

bool SettingParam::asBool( void ) const {
    // Throw if type is not BOOL
    return _val.bVal;
}

int SettingParam::asInt( void ) const {
    // Throw if type is not INT
    return _val.iVal;
}

float SettingParam::asFloat( void ) const {
    // Throw if type is not FLOAT
    return _val.fVal;
}

const std::string& SettingParam::asStr( void ) const {
    return _strVal;
}

void Settings::addParam( SettingParam& param ) {
    std::cout << "Settings::addparam '" << param.getName() << "' of type '" << param.getType() << "' and level '" << param.getLevel() << "' with default value of '" << param.getDefaultVal() << "'\n";
}

void Settings::loadSysConfig( const std::string& appName ) {
}

void Settings::loadUsrConfig( const std::string& appName ) {
}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
