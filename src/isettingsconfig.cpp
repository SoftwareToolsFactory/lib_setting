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
//     1. 2019.11.29, 20:00 Vasile   [+] Initial
// ---------------------------------------------------------------------------
#include <iostream>
#include "settings.h"

using namespace std;

class ISettingsConfig{

public:
    virtual ~ISettingsConfig() = 0;

private:
    virtual void addParam(string strValue) = 0;
};
