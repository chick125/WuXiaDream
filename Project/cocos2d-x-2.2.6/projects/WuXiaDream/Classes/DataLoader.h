//
//  DataLoader.h
//  WuXiaDream
//
//  Created by 何金 北京 on 15/3/26.
//
//

#ifndef __WuXiaDream__DataLoader__
#define __WuXiaDream__DataLoader__
#include "Common.h"
#include <stdio.h>
class DataLoader : public CCObject
{
public:
    static DataLoader* getLoader();
    void init();
    CCDictionary *getConfig(std::string configName);
    int parseInt(std::string configName,std::string key);
    CCString* parseString(std::string configName,std::string key);
    CCArray* parseStringArray(std::string configName,std::string key);// return CCString array
    CCString* getLocalString(const char* contentKey, ...);
private:
    CCDictionary* m_pLangDic;
    CCDictionary* m_pCacheDic;
    
};
#define LOCAL_TEXT(__KEY__, __VALUES__...)DataLoader::getLoader()->getLocalString((__KEY__), ##__VALUES__)

#endif /* defined(__WuXiaDream__DataLoader__) */
