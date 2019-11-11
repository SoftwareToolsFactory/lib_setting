##                                    .-""-.
##                                   / _  _ \
##                                   |(_)(_)|
## .------------------------------ooO(_ /\ _)Ooo-----------------------------.
## |                                  |====|                                 |
## |                                  '-..-'                                 |
## | Desc: Common definitions for build process                              |
## | By: Nuroferatu - https://github.com/Nuroferatu                          |
## |                                                                         |
## | Copyright (C)2019 SoftwareToolsFactory                                  |
## |                   http://softwaretoolsfactory.com                       |
## '-------------------------------------------------------------------------'
## ----= Change log =---------------------------------------------------------
##     1. 2019.11.11, 13:16 Nuroferatu   [+] Initial
##                                           * Definitions of vpath based of prjcfg VARIABLES
##                                           * Terminal colors for echo and echo as ${LOG}
## ---------------------------------------------------------------------------
## TODO: This should go to some global path, and be used as part of buld chain of STF applications
include prjcfg.mk

## Sample usage:
## ${LOG} ${YELLOW}Warrnig${CRESET} 
LOG := @echo -e

## Predefined colors that can be used with ${LOG}
CRESET := "\e[0m"
CDEFAULT := "\e[39m"
CRED := "\e[31m"
CGREEN := "\e[32m"
CYELLOW := "\e[33m"
CBLUE := "\e[34m"
CMAGNETA := "\e[35m"
CCYAN := "\e[36m"
CWHITE := "\e[37m"

vpath %.cpp ${SRC_DIR}
vpath %.h   ${INC_DIR}
vpath %.d   ${TMP_DIR}
vpath %.o   ${TMP_DIR}
