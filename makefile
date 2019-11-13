##                                    .-""-.
##                                   / _  _ \
##                                   |(_)(_)|
## .------------------------------ooO(_ /\ _)Ooo-----------------------------.
## |                                  |====|                                 |
## |                                  '-..-'                                 |
## | Desc: SettingsLib make file                                             |
## | By: Nuroferatu - https://github.com/Nuroferatu                          |
## |                                                                         |
## | Copyright (C)2019 SoftwareToolsFactory                                  |
## |                   http://softwaretoolsfactory.com                       |
## '-------------------------------------------------------------------------'
## ----= Change log =---------------------------------------------------------
##     2. 2019.11.13, 20:50 Nuroferatu   [*] Fix: Incorrect depenency file
##                                       [+] fix: Missing bin and tmp directories makes make fail on build, added prepare target to solve this problem
##     1. 2019.11.11, 13:16 Nuroferatu   [+] Initial - builds library and testing application that uses it
## ---------------------------------------------------------------------------
include buildcommon.mk

build: prepare ${LIB_PATH} ${BIN_DIR}/testapp
	@echo "Build done"

prepare:
	@mkdir -p ./${BIN_DIR}
	@mkdir -p ./${TMP_DIR}
clean:
	${RM} ./${BIN_DIR}/*
	${RM} ./${TMP_DIR}/*.o
	${RM} ./${TMP_DIR}/*.d

rebuild: clean build

install:

${LIB_PATH}: ${TMP_DIR}/settings.o
	${RM} ${LIB_PATH}
	${AR} rcs $@ $^

# Test app wil llink with build library. It's expected that library gets build into bin as lib[name].a file
${BIN_DIR}/testapp: ${TMP_DIR}/main.o
	${CXX} ${CXXFLAGS} -o $@ $^ -L${BIN_DIR} -l${LIB_NAME}

# Build object file and dependency file for future updates
${TMP_DIR}/%.o: %.cpp
	${CXX} -MT '$@' -E -MM ${CXXFLAGS} $< -o $(@D)/$(*F).d
	${CXX} ${CXXFLAGS} -c $< -o $@

## Dependency
-include ${TMP_DIR}/main.d
-include ${TMP_DIR}/settings.d

.PHONY: build clean rebuild install
