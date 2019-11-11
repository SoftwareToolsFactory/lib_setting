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
##     1. 2019.11.11, 13:16 Nuroferatu   [+] Initial - builds library and testing application that uses it
## ---------------------------------------------------------------------------
include buildcommon.mk

build: ${LIB_PATH} ${BIN_DIR}/testapp
	@echo "Build done"

clean:
	${RM} -f ${TMP_DIR}/*.o
	${RM} -f ${TMP_DIR}/*.d

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
-include ${TMP_DIR}/servicebase.d

.PHONY: build clean rebuild install
