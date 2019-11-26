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
    SettingParam(string name, eSettingLevel levelValue, eSettingType typeValue, string value) {

        paramName = name;

        if (typeValue != STRING){
        
            
        }else
        {
            
        }
        
    }
    
private:
    string paramName;
    string paramValue;
    union unionType{
	    int 	iVal;
	    bool	bVal;
	    float	cVal;
    };
};

// vim: ts=4:sw=4:et:nowrap
/* EOF */
