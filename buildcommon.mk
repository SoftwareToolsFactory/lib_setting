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
##     3. 2019.11.30, 01:15 Nuroferatu   [+] [SCL-29] Multiplatform build
##     2. 2019.11.30, 00:40 Nuroferatu   [+] [SCL-36] OS_NAME variable, that stores system name
##     1. 2019.11.11, 13:16 Nuroferatu   [+] Initial
##                                           * Definitions of vpath based of prjcfg VARIABLES
##                                           * Terminal colors for echo and echo as ${LOG}
## ---------------------------------------------------------------------------
## TODO: This should go to some global path, and be used as part of buld chain of STF applications

OS_NAME := $(shell uname -s | tr A-Z a-z)
## On FreeBSD Unix we need to rename OS_NAME
ifeq (${OS_NAME},freebsd)
  OS_NAME=unix
endif

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

vpath %.cpp ${SRC_DIR} ${SRC_DIR}/${OS_NAME}
vpath %.h   ${INC_DIR}
vpath %.d   ${TMP_DIR}
vpath %.o   ${TMP_DIR}
