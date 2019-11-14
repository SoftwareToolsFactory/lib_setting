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

namespace stf {

enum eSettingLevel {
    APP,
    SYS,
    USER
};

enum eSettingType {
    BOOL,
    NUM,
    STRING
};

}; // ns:stf

#endif /* ndef __STF_SETTINGS_H__ */

// vim: ts=4:sw=4:et:nowrap
/* EOF */
