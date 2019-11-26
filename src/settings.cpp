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

using namespace std;
using namespace stf;

class SettingParam{
public:    
    SettingParam(string paramValue, eSettingLevel levelValue, eSettingType typeValue, bool boolValue) : \
    paramName(paramValue), level(levelValue), type(typeValue), boolParam(boolValue) {}
    
private:
    string paramName;
    eSettingLevel level;
    eSettingType type;
    bool boolParam;
};

// vim: ts=4:sw=4:et:nowrap
/* EOF */
