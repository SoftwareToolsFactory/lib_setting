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
//     7. 2020.03.04, 16:20 Nuroferatu   [+] Storing param in map with helper functions
//     6. 2020.03.01, 15:40 Nuroferatu   [+] set of update methods to sync string with coresponding ParamType value
//     5. 2020.03.01, 15:00 Nuroferatu   [+] riseInvalidTypeError - throws runtime_error with type info
//     4. 2020.03.01, 13:45 Nuroferatu   [*] eSettingLevel & eSettingType are scoped
//     3. 2020.03.01, 13:20 Nuroferatu   [+] Extra SettingParam ctors to make usage simpler
//     2. 2019.11.14, 21:10 Vasile       [+] Added eSettingLevel & eSettingType
//     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial
// ---------------------------------------------------------------------------
#pragma once
#ifndef __STF_SETTINGS_H__

#include <map>
#include <string>

namespace stf {

enum class eSettingLevel {
    APP,        // Application level setting is defined in application and can not be modified by config file
    SYS,        // System level can be modyfied only by config file that cames from system directory
    USER        // User level can be modified by user and system configuration files
};


enum class eSettingType {
    BOOL,
    INT,
    FLOAT,
    STRING
};

std::ostream& operator << ( std::ostream& out, stf::eSettingLevel level );
std::ostream& operator << ( std::ostream& out, stf::eSettingType type );

class SettingParam {
public:
    // TODO: This ctor should be hiden, to prevent some wild usage of it :)
    SettingParam( std::string name, eSettingLevel level, eSettingType type, std::string defaultVal ) : _name( name ), _level( level ), _type( type ), _defaultVal( defaultVal ), _strVal( defaultVal ) { updateVal(); }

    SettingParam( std::string name, eSettingLevel level, const char* defaultVal ) : SettingParam( name, level, eSettingType::STRING, std::string( defaultVal ) ) {}
    SettingParam( std::string name, eSettingLevel level, bool defaultVal ) : SettingParam( name, level, eSettingType::BOOL, std::string( (defaultVal ? "true" : "false") ) ) {}
    SettingParam( std::string name, eSettingLevel level, int defaultVal ) : SettingParam( name, level, eSettingType::INT, std::to_string(defaultVal) ) {}
    SettingParam( std::string name, eSettingLevel level, float defaultVal )  : SettingParam( name, level, eSettingType::FLOAT, std::to_string(defaultVal) ) {}

    const std::string&  getName( void ) const { return _name; }
    eSettingLevel       getLevel( void ) const { return _level; }
    eSettingType        getType( void ) const { return _type; }
    const std::string&  getDefaultVal( void ) const { return _defaultVal; }

    void setVal( const std::string& strVal ) { /* Not implemented */ }
    void resetToDefault( void ) { setVal( _defaultVal ); }

    bool    asBool( void ) const;
    int     asInt( void ) const;
    float   asFloat( void ) const;
    const std::string& asStr( void ) const;

private:
    void riseInvalidTypeError( const std::string& method, const stf::eSettingType expectedType ) const;
    void updateVal( void );
    void updateBoolVal( std::string valAsStr );
    void updateIntVal( std::string valAsStr );
    void updateFloatVal( std::string valAsStr );

    union ParamType {
        ParamType() : iVal( 0 ) {}
        int     iVal;
        bool    bVal;
        float   fVal;
        char    cVal;
    };

    eSettingLevel   _level;
    eSettingType    _type;
    ParamType       _val;

    std::string     _name;
    std::string     _strVal;
    std::string     _defaultVal;
};

class ISettingsConfig {
public:
    virtual ~ISettingsConfig() = default;
    virtual bool paramExist( const std::string& paramName ) = 0;
    virtual SettingParam& getParam( const std::string& paramName ) = 0;
    virtual void addParam( SettingParam& param ) = 0;
};

class Settings : public ISettingsConfig {
    std::map<std::string, stf::SettingParam*>   _paramMap;

public:
    bool paramExist( const std::string& paramName ) override;
    SettingParam& getParam( const std::string& paramName ) override;
    void addParam( SettingParam& param ) override;

    void loadSysConfig( const std::string& appName );
    void loadUsrConfig( const std::string& appName );
};

}; // ns:stf

#endif /* ndef __STF_SETTINGS_H__ */

// vim: ts=4:sw=4:et:nowrap
/* EOF */
