// 用于管理老师和学生的信息
#pragma once
#include "teacher.hpp"
#include <string>

class personManager
{
public:
    personManager();
    void personAdd(std::string name, std::string password, int flag);
    bool isUser(std::string name, std::string password);
    void showAll();
    ~personManager();

private:
    std::unordered_map<std::string, std::string> teacherMap; // name:password 用于存储老师的信息
    std::unordered_map<std::string, std::string> studentMap; // name:password 用于存储学生的信息
};