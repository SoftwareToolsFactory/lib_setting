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
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <regex>
#include <string>
#include <sstream>

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "settings.h"

using namespace std;
using namespace stf;

#ifdef DEBUG
#define ERROR_INFO() (cout << "ERROR: " << __FILE__ << ", " << __func__ << " : " << __LINE__ << endl)
#endif

template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val);

// This should throw if current type is not this same as used method...
//bool    asBool( void ) const;
//int     asInt( void ) const;
//float   asFloat( void ) const;
//const   std::string& asStr( void ) const;

static string ltrim(const string& s) {
	return regex_replace(s, regex("^\\s+"), string(""));
}

static string rtrim(const string& s) {
	return regex_replace(s, regex("\\s+$"), string(""));
}

static string trim(const string& s) {
	return ltrim(rtrim(s));
}

loadConfig& loadConfig::getInstance(void)
{
	static loadConfig onlyInstance;
	return onlyInstance;
}

bool loadConfig::readConfigFileContent(const char* pathWithFileName, confList* saveConfigContain)//ok
{
	bool ret = false;
	confList localList;

	ifstream file(pathWithFileName);			   //only read the file!
	if (file.is_open()) {
		confList tmpList;
		tmpList.push_back(pathWithFileName);       //add to list path with config name
        for (string line; getline(file, line); )   //add to list config lines
		{
			localList.push_back(line);
		}

        for (auto it : localList) {                //small config parser
			std::size_t foundComment = it.find('#');
			string tmpStr = it;
			if (foundComment != string::npos)
			{
                if (0 == foundComment)             //remove from list comment line - stared with '#'
				{
					continue;
				}
                else {                             //find other #comments in line and remove it with whitespaces
					tmpStr = trim(tmpStr.substr(0, foundComment - 1));
					if (!tmpStr.empty()) {
						tmpList.push_back(tmpStr);
					}
				}
			}
			else {
				tmpStr = trim(tmpStr);
				if (!tmpStr.empty()) {
                    tmpList.push_back(trim(tmpStr));//config lines without # comment
				}
			}
		}
		saveConfigContain->assign(tmpList.begin(), tmpList.end());	//copy from local list
		ret = true;
	}
	return ret;
}

bool loadConfig::getListOfConfigsInPathAndReadAll(const char* configsPath, confList* retListOfConfigFiles)
{
	bool ret = false;
	confList configsPaths, tmpConfigList;
	struct dirent* entry = nullptr;
	DIR* dp = nullptr;

	dp = opendir(configsPath);
    if (dp != nullptr) {
        while ((entry = readdir(dp)))              //find config files in path
		{
			if (strstr(entry->d_name, ".cfg"))
			{
				string filePath = configsPath;
				filePath.append(entry->d_name);
				configsPaths.push_back(filePath);
				ret = true;
			}
		}
		closedir(dp);
		//read all config files and add to one configuration list
		for (confList::iterator it = configsPaths.begin(); it != configsPaths.end(); ++it)
		{
			const char* fullPath = it->c_str();
			if (readConfigFileContent(fullPath, retListOfConfigFiles)) {
				tmpConfigList.insert(tmpConfigList.begin(), retListOfConfigFiles->begin(), retListOfConfigFiles->end());
			}
		}
		//copy from local list to main one list
		retListOfConfigFiles->assign(tmpConfigList.begin(), tmpConfigList.end());
	}
	return ret;
}

int loadConfig::readConfigFile(confList* retListOfConfigFiles)
{
	confList configurationList, tmpList;
	int pathsNumber = 0, ret = 0;
	while (configListPaths[pathsNumber] != '\0')      //how many difrent path have to be checked
	{
		pathsNumber++;
	}

	for (int ii = 0; ii < pathsNumber; ii++)
	{
		if (getListOfConfigsInPathAndReadAll(configListPaths[ii], &configurationList))
		{
			tmpList.insert(tmpList.begin(), configurationList.begin(), configurationList.end());
            ret++;                                 //return how many config files have been read
		}
		else {
			//cout << "No config files in path: " << configListPaths[ii] << endl;
		}
	}
	if (ret) {
		retListOfConfigFiles->assign(tmpList.begin(), tmpList.end());
	}
	return ret;
}

int loadConfig::getConfiguration(confList* configurationContent)
{
	int ret = 0;
	if( configFile.empty() )
	{
		ret = readConfigFile(&configFile);

        if (ret) {                                 //copy configuration list if exist
			configurationContent->assign(configFile.begin(), configFile.end());
		}
	} else {

		ret = -1;
		#ifdef DEBUG
			ERROR_INFO();
		#endif
	}
	return  ret;
}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
