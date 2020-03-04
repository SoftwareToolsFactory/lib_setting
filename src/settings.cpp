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
//     4. 2020.03.04, 16:20 Nuroferatu   [+] Storing param in map with helper functions
//     3. 2020.03.01, 15:40 Nuroferatu   [+] set of update methods to sync string with coresponding ParamType value
//     2. 2020.03.01, 15:00 Nuroferatu   [+] riseInvalidTypeError - throws runtime_error with type info
//                                       [*] asXXX mothods throw when invalid type is detected (casting is not supported by design)
//     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial
// ---------------------------------------------------------------------------
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include "settings.h"

using namespace stf;

// ---------------------------------------------------------------------------
// operator <<
//
// Output eSettingLevel as string to standard output
// ---------------------------------------------------------------------------
std::ostream& stf::operator << ( std::ostream& out, eSettingLevel level ) {
    switch (level) {
        case eSettingLevel::APP: out << "APP"; break;
        case eSettingLevel::SYS: out << "SYS"; break;
        case eSettingLevel::USER: out << "USER"; break;
    }
    return out;
}

// ---------------------------------------------------------------------------
// operator <<
//
// Output eSettingType as string to standard output
// ---------------------------------------------------------------------------
std::ostream& stf::operator << ( std::ostream& out, eSettingType type ) {
    switch (type) {
        case eSettingType::BOOL: out << "BOOL"; break;
        case eSettingType::INT: out << "INT"; break;
        case eSettingType::FLOAT: out << "FLOAT"; break;
        case eSettingType::STRING: out << "STRING"; break;
    }
    return out;
}

// ---------------------------------------------------------------------------
// setVal
//
// Set _strVal and updates variable based on SettingParam type.
// ---------------------------------------------------------------------------
void SettingParam::setVal( const std::string& strVal ) {
    _strVal = strVal;
    updateVal();
}

// ---------------------------------------------------------------------------
// asBool
//
// Return stored value as bool
// Throws exception if type of param is not BOOL
// ---------------------------------------------------------------------------
bool SettingParam::asBool( void ) const {
    if (_type != eSettingType::BOOL)
        riseInvalidTypeError( "asBool", eSettingType::BOOL );

    return _val.bVal;
}

// ---------------------------------------------------------------------------
// asInt
//
// Return stored value as int
// Throws exception if type of param is not INT
// ---------------------------------------------------------------------------
int SettingParam::asInt( void ) const {
    if (_type != eSettingType::INT)
        riseInvalidTypeError( "asInt", eSettingType::INT );

    return _val.iVal;
}

// ---------------------------------------------------------------------------
// asFloat
//
// Return stored value as float
// Throws exception if type of param is not FLOAT
// ---------------------------------------------------------------------------
float SettingParam::asFloat( void ) const {
    if (_type != eSettingType::FLOAT)
        riseInvalidTypeError( "asFloat", eSettingType::FLOAT );

    return _val.fVal;
}

// ---------------------------------------------------------------------------
// asStr
//
// Return stored value as string
// ---------------------------------------------------------------------------
const std::string& SettingParam::asStr( void ) const {
    return _strVal;
}

// ---------------------------------------------------------------------------
// riseInvalidTypeError
//
// Helper to throw exception when type is different then expected
// ---------------------------------------------------------------------------
void SettingParam::riseInvalidTypeError( const std::string& method, const stf::eSettingType expectedType ) const {
    std::stringstream exceptionMsg;
    exceptionMsg << method << " failed for param: '" << _name << "' expected type '" << expectedType  << "' but param is '" << _type;
    std::string msg = exceptionMsg.str();
    std::cerr << "Error: " << msg << std::endl;
    throw std::runtime_error( msg );
}

// ---------------------------------------------------------------------------
// updateVal
//
// Update ParamType _val based on _strVal
// ---------------------------------------------------------------------------
void SettingParam::updateVal( void ) {
    switch (_type) {
        case eSettingType::BOOL: updateBoolVal( _strVal ); break;
        case eSettingType::INT: updateIntVal( _strVal ); break;
        case eSettingType::FLOAT: updateFloatVal( _strVal ); break;
        case eSettingType::STRING: break;
        default:
            throw std::runtime_error( "Unknown data type for param: '" + _name + "'" );
    }
}

// ---------------------------------------------------------------------------
// updateBoolVal
// ---------------------------------------------------------------------------
void SettingParam::updateBoolVal( std::string valAsStr ) {
    if (_type != eSettingType::BOOL) 
        riseInvalidTypeError( "updateBoolVal", eSettingType::BOOL );

    std::transform( valAsStr.begin(), valAsStr.end(), valAsStr.begin(), [](unsigned char c){ return std::tolower(c); } );
    std::istringstream is( valAsStr );
    is >> std::boolalpha >> _val.bVal;
}

// ---------------------------------------------------------------------------
// updateIntVal
// ---------------------------------------------------------------------------
void SettingParam::updateIntVal( std::string valAsStr ) {
    if (_type != eSettingType::INT)
        riseInvalidTypeError( "updateIntVal", eSettingType::INT );
    _val.iVal = std::stoi( valAsStr );
}

// ---------------------------------------------------------------------------
// updateFloatVal
// ---------------------------------------------------------------------------
void SettingParam::updateFloatVal( std::string valAsStr ) {
    if (_type != eSettingType::FLOAT)
        riseInvalidTypeError( "updateFloatVal", eSettingType::FLOAT );
    _val.fVal = std::stof( valAsStr );
}

// ---------------------------------------------------------------------------
// paramExist
//
// Return true if param is registeted in map
// ---------------------------------------------------------------------------
bool Settings::paramExist( const std::string& paramName ) {
    auto item = _paramMap.find( paramName );
    return item != _paramMap.end();
}

// ---------------------------------------------------------------------------
// getParam
//
// Return reference to SettingParam
// Trows runtime error if param is not registered
// ---------------------------------------------------------------------------
SettingParam& Settings::getParam( const std::string& paramName ) {
    auto item = _paramMap.find( paramName );
    if (item != _paramMap.end())
        return *item->second;

    throw std::runtime_error( "Settings::getParam - param '" + paramName + "' does not exist" );
}

// ---------------------------------------------------------------------------
// addParam
//
// Adds SettingParam to map, if param is already in map, it will be ignored.
// ---------------------------------------------------------------------------
void Settings::addParam( SettingParam& param ) {
    if (paramExist( param.getName() )) {
        std::cout << "Param '" << param.getName() << "' already registered" << std::endl;
        return;
    }
    _paramMap.insert( std::make_pair(param.getName(), &param) );

    std::cout << "Settings::addparam '" << param.getName() << "' of type '" << param.getType() << "' and level '" << param.getLevel() << "' with default value of '" << param.getDefaultVal() << "'\n";
}

// ---------------------------------------------------------------------------
// loadSysConfig
//
// Reads System level configuration from system directory
// ---------------------------------------------------------------------------
void Settings::loadSysConfig( const std::string& appName ) {
    const std::string   SYS_FILE = "..\\sample_sys_config.cfg";
    loadConfig( SYS_FILE, eSettingLevel::SYS );
}

// ---------------------------------------------------------------------------
// loadUsrConfig
//
// Reads User level configuration from user home directory
// ---------------------------------------------------------------------------
void Settings::loadUsrConfig( const std::string& appName ) {
    const std::string   USER_FILE = "..\\sample_user_config.cfg";
    loadConfig( USER_FILE, eSettingLevel::USER );
}

// ---------------------------------------------------------------------------
// findComment
//
// Returns position of comment character in configuration line.
// If there is no comment std::string::npos is returned
// ---------------------------------------------------------------------------
std::size_t Settings::findComment( const std::string& configLine ) {
    constexpr char COMMENT_CHAR = '#';
    return configLine.find( COMMENT_CHAR, 0 );
}

// ---------------------------------------------------------------------------
// extractParamName
//
// Read param name from config line ( part on left of = )
// ---------------------------------------------------------------------------
std::string Settings::extractParamName( const std::string& configLine ) {
    std::string     retStr;
    if (!configLine.empty()) {
        std::size_t pos = configLine.find( '=' );
        if (pos != std::string::npos) {
            retStr = configLine.substr( 0, pos );
            trimStr( retStr );
        }
    }
    return retStr;
}

// ---------------------------------------------------------------------------
// extractParamValue
//
// Read param value from config line ( part on right of = )
// ---------------------------------------------------------------------------
std::string Settings::extractParamValue( const std::string& configLine ) {
    std::string     retStr;
    if (!configLine.empty()) {
        std::size_t pos = configLine.find( '=' );
        if (pos != std::string::npos) {
            retStr = configLine.substr( pos+1 );
            trimStr( retStr );
        }
    }
    return retStr;
}

// ---------------------------------------------------------------------------
// trimStr
//
// Trims white space from left and right of string
// ---------------------------------------------------------------------------
void Settings::trimStr( std::string& str ) {
    str.erase( str.begin(), std::find_if( str.begin(), str.end(), [](int ch) { return !std::isspace(ch); } ) );
    str.erase( std::find_if( str.rbegin(), str.rend(), [](int ch) { return !std::isspace(ch); } ).base(), str.end() );
}

// ---------------------------------------------------------------------------
// loadConfig
// ---------------------------------------------------------------------------
void Settings::loadConfig( const std::string& path, stf::eSettingLevel level ) {

    std::ifstream inputFile( path );
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open: '" << path << "'\n";
        return;
    }

    std::string line;
    int linePos = 1;

    while (std::getline( inputFile, line )) {
        std::cout << line << std::endl;
        std::size_t commentPos = findComment( line );
        if (commentPos != std::string::npos)
            line = line.substr( 0, commentPos );

        if (!line.empty()) {
            std::string     paramName = extractParamName( line );
            std::string     paramVal = extractParamValue( line );

            if (paramExist( paramName )) {
                std::cout << "[DBG] Param: '" << paramName << "' Exits - new val to set = '" << paramVal << "' current val = '" << getParam( paramName ).asStr() << "'\n";
                getParam( paramName ).setVal( paramVal );
            }
            else
                std::cout << "Param '" << paramName << "' does not exist - '" << path << "' at line " << linePos << std::endl;
        }
        linePos++;
    }
    inputFile.close();
}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
