##                                    .-""-.
##                                   / _  _ \
##                                   |(_)(_)|
## .------------------------------ooO(_ /\ _)Ooo-----------------------------.
## |                                  |====|                                 |
## |                                  '-..-'                                 |
## | Desc: SettingsLib project configuration for make                        |
## | By: Nuroferatu - https://github.com/Nuroferatu                          |
## |                                                                         |
## | Copyright (C)2019 SoftwareToolsFactory                                  |
## |                   http://softwaretoolsfactory.com                       |
## '-------------------------------------------------------------------------'
## ----= Change log =---------------------------------------------------------
##     3. 2019.11.30, 00:40 Nuroferatu   [+] SCL-36: OS_NAME used to separate build on many platforms
##     2. 2019.11.12, 22:40 Nuroferatu   [+] SCL-7: Add install dir variable
##     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial - configuration for settings library
## ---------------------------------------------------------------------------
TMP_DIR := tmp/${OS_NAME}
INC_DIR := include
SRC_DIR := src
BIN_DIR := bin/${OS_NAME}
INSTALL_DIR := /usr/local

LIB_NAME := settings
LIB_PATH := ${BIN_DIR}/lib${LIB_NAME}.a

## -Wall        - All warnings
## -Wno-comment - disable C style comments warning
## -std=c++11   - use C++ 11 standard
## -m64         - Build 64bit code
## -I           - path to look for extra non system include files
CXXFLAGS += -Wall -Wno-comment -std=c++11 -m64 -I${INC_DIR}
