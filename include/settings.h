//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: Settings library main include file                                |
// | By: Nuroferatu - https://github.com/Nuroferatu                          |
// |     Vasile     - https://github.com/Vasile0091                          |
// |                                                                         |
// | Copyright (C)2019 SoftwareToolsFactory                                  |
// |                   http://softwaretoolsfactory.com                       |
// '-------------------------------------------------------------------------'
// ----= Change log =---------------------------------------------------------
//     2  2019.11.14, 21:10 Vasile       [+] Added eSettingLevel & eSettingType
//     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial
// ---------------------------------------------------------------------------
#pragma once
#ifndef __STF_SETTINGS_H__

#include "isettingsconfig.h"
#include <string>

namespace stf {

enum eSettingLevel {
    APP,        // Application level setting is defined in application and can not be modified by config file
    SYS,        // System level can be modyfied only by config file that cames from system directory
    USER        // User level can be modified by user and system configuration files
};

enum eSettingType {
    BOOL,
    NUM_INT,
    NUM_FLOAT,
    STRING
};

class SettingParam {
public:
    SettingParam( std::string name, eSettingLevel level, eSettingType type, std::string defaultVal ) \
                :_name( name ), _level( level ), _type( type ), _defaultVal( defaultVal ), _strVal(defaultVal) {}

    eSettingLevel   getLevel( void ) const { return _level; }
    eSettingType    getType( void ) const { return _type; }

    bool    asBool( void ) const;
    int     asInt( void ) const;
    float   asFloat( void ) const;
    const   std::string& asStr( void ) const;

private:
    union ParamType {
        ParamType() : iVal( 0 ) {}
        int 	iVal;
        bool	bVal;
        float	cVal;
    };

    eSettingLevel   _level;
    eSettingType    _type;

    std::string     _name;
    std::string     _strVal;
    std::string     _defaultVal;
    ParamType       _val;
};

class Settings : public ISettingsConfig {
public:
    static const SettingParam& get( const std::string& paramName );
    void addParam( SettingParam& param );
    void loadSysConfig( const std::string& appName );
    void loadUsrConfig( const std::string& appName );
};

}; // ns:stf

#endif /* ndef __STF_SETTINGS_H__ */

// vim: ts=4:sw=4:et:nowrap
/* EOF */
