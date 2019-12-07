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

void Settings::addParam( SettingParam& param ) {
    //Code here 
}

void Settings::loadSysConfig( const std::string& appName ){
    //Code here
}

void Settings::loadUsrConfig( const std::string& appName ){
    //Code here
}

// This should throw if current type is not this same as used method...
bool    asBool( void ) const;
int     asInt( void ) const;
float   asFloat( void ) const;
const   std::string& asStr( void ) const;

// vim: ts=4:sw=4:et:nowrap
/* EOF */
