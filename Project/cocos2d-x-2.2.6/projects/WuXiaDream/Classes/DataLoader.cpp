//
//  DataLoader.cpp
//  WuXiaDream
//
//  Created by 何金 北京 on 15/3/26.
//
//

#include "DataLoader.h"
static DataLoader* _DataLoader=NULL;
DataLoader* DataLoader::getLoader()
{
    if (!_DataLoader) {
        _DataLoader=new DataLoader();
        _DataLoader->init();
    }
    return _DataLoader;
}
void DataLoader::init()
{
    m_pLangDic=CCDictionary::createWithContentsOfFile("zh_cn.plist");
    m_pLangDic->retain();
    m_pCacheDic=CCDictionary::create();
    m_pCacheDic->retain();
}
CCString*  DataLoader::getLocalString(const char* contentKey, ...)
{
    char szBuf[kMaxLogLen];
    const char *pszFormat=((CCString *)m_pLangDic->objectForKey(contentKey))->getCString();
    if (pszFormat) {
        va_list ap;
        va_start(ap, contentKey);
        vsnprintf(szBuf, kMaxLogLen, pszFormat, ap);
        va_end(ap);
        
        CCString *pStr = CCString::create(szBuf);
        return pStr;
    }
    else
    {
        return CCString::createWithFormat("error lang not found");
    }
}
CCDictionary* DataLoader::getConfig(std::string configName)
{
    CCDictionary *config=(CCDictionary *)m_pCacheDic->objectForKey(configName);
    if (!config) {
        config=CCDictionary::createWithContentsOfFile(configName.c_str());
        m_pCacheDic->setObject(config, configName);
    }
    return config;
}
int DataLoader::parseInt(std::string configName, std::string key)
{
    CCDictionary *config=getConfig(configName);
    if (!config) {
        return 0;
    }
    else
    {
        CCString* number=(CCString *)config->objectForKey(key);
        return number->intValue();
    }
}
CCString* DataLoader::parseString(std::string configName, std::string key)
{
    CCDictionary *config=getConfig(configName);
    if (!config) {
        return CCString::create("error string");
    }
    else
    {
        CCString* loadString=(CCString *)config->objectForKey(key);
        return loadString;
    }
}
CCArray* DataLoader::parseStringArray(std::string configName, std::string key)
{
    CCArray *stringArray=CCArray::create();
    CCString *orginString=parseString(configName, key);
    std:: string splitString=orginString->getCString();
    std::string::size_type i = 0;
    std::string::size_type j = splitString.find(',');
    while(j != std::string::npos)//没到字符串结束
    {
        CCString* childString=CCString::create(splitString.substr(i,j - i).c_str());
        stringArray->addObject(childString);
        i = ++j;
        j = splitString.find(',', j);
        if(j == std::string::npos)
        {
            CCString* childStringLast=CCString::create(splitString.substr(i, splitString.length()));
            stringArray->addObject(childStringLast);
        }
    }
    return stringArray;
    
}