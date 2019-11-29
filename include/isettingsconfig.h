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
//     1. 2019.11.29, 20:00 Vasile   [+] Initial
// ---------------------------------------------------------------------------
#pragma once
#ifndef __STF_SETTINGS_CONFIG_H__

namespace stf {

class ISettingsConfig{

public:
    virtual ~ISettingsConfig() = default;

private:
    virtual void addParam(string strValue) = 0;
};

}; // ns:stf

#endif /* ndef __STF_SETTINGS_CONFIG_H__ */

// vim: ts=4:sw=4:et:nowrap
/* EOF */
