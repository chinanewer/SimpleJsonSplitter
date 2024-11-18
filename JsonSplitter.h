#pragma once

#include <vector>
#include <string>

class JsonSplitter
{
public:
    JsonSplitter() = delete;
    ~JsonSplitter() = delete;

    static std::vector<std::string> splitJson(const std::string& jsonStr);

private:
    enum class ParseStage
    {
        FIND_START_TAG,
        PARSING_JSON,
        PARSING_STRING
    };
};
