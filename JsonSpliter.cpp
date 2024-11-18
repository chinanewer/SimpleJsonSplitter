#include "JsonSplitter.h"

std::vector<std::string> JsonSplitter::splitJson(const std::string &jsonStr)
{
    std::vector<std::string> jsons;
    std::string tmpJson;
    ParseStage parseStage = ParseStage::FIND_START_TAG;
    int tagNextIndex = 0;
    char lastChar = '\0';
    char stringSpliter = '\0';
    bool resetLastCheckChar = false;
    for (const char& tmpChar : jsonStr) {
        if(parseStage == ParseStage::FIND_START_TAG)
        {
            if(tmpChar == '{')
            {
                parseStage = ParseStage::PARSING_JSON;
                tmpJson += tmpChar;
                tagNextIndex = 1;
            }
        }
        else if(parseStage == ParseStage::PARSING_JSON)
        {
            tmpJson += tmpChar;
            if(tmpChar == '{')
            {
                tagNextIndex ++;
            }

            if(tmpChar == '}')
            {
                tagNextIndex --;
            }

            if(tagNextIndex == 0)
            {
                jsons.emplace_back(tmpJson);
                parseStage = ParseStage::FIND_START_TAG;
                tmpJson.clear();
            }

            if(tmpChar == '\'' || tmpChar == '"')
            {
                stringSpliter = tmpChar;
                parseStage = ParseStage::PARSING_STRING;
            }
        }
        else if(parseStage == ParseStage::PARSING_STRING)
        {
            tmpJson += tmpChar;
            if(tmpChar == '\\' && lastChar == '\\')
            {
                resetLastCheckChar = true;
            }

            if(tmpChar == stringSpliter && lastChar != '\\')
            {
                parseStage = ParseStage::PARSING_JSON;
            }
        }
        else
        {
            ; // do nothing
        }


        if(!resetLastCheckChar)
        {
            lastChar = tmpChar;
        }
        else
        {
            lastChar = '\0';
        }
    }
    return jsons;
}
