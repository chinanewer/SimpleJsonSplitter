# 简单的Json分割器
# A simple JSON splitter


当多个Json字符串黏在一起的时候，可以使用它将其分割成多个json字符串。  
When multiple JSON strings are glued together, it can be used to split them into multiple JSON strings.  

**前提条件**：需要每个堆叠在一起的json字符串格式是正确的。  
**Prerequisite**: Each stacked JSON string must have the correct format.

示例代码：  
sample code:  
```cpp
#include "JsonSplitter.h"

void test00()
{
    std::string jsonStr = "{}";
    std::vector<std::string> jsons = JsonSplitter::splitJson(jsonStr);
    for (const auto& json : jsons) {
        std::cout << "Json : " << json << std::endl;
    }
}

void test01()
{
    std::string jsonStr = "{}{}";
    std::vector<std::string> jsons = JsonSplitter::splitJson(jsonStr);
    for (const auto& json : jsons) {
        std::cout << "Json : " << json << std::endl;
    }
}

void test02()
{
    std::string jsonStr = "{\"xxxx{\":\"\\\".}\"}{}";
    std::vector<std::string> jsons = JsonSplitter::splitJson(jsonStr);
    for (const auto& json : jsons) {
        std::cout << "Json : " << json << std::endl;
    }
}

int main()
{
    std::cout << "------------test 00--------------" << std::endl;
    test00();
    std::cout << "------------test 01--------------" << std::endl;
    test01();
    std::cout << "------------test 02--------------" << std::endl;
    test02();
    return 0;
}

```