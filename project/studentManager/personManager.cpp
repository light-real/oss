#include "personManager.hpp"

personManager::personManager()
{
}
void personManager::personAdd(std::string name, std::string password, int flag)
{
    // flag为0 加学生
    // flag为1 加老师
    if (flag)
    {
        studentMap[name] = password;
    }
    else
    {
        teacherMap[name] = password;
    }
}

bool personManager::isUser(std::string name, std::string password)
{
    if (teacherMap.find(name) == teacherMap.end() && studentMap.find(name) == studentMap.end())
    {
        return false;
    }

    if (teacherMap.find(name) != teacherMap.end())
    {
        if (teacherMap[name] == password)
        {
            return true;
        }
        else
        {
            std::cout << "你的密码错误，请重新输入!" << std::endl;
            return false;
        }
    }
    
    if (studentMap.find(name) != studentMap.end())
    {
        if (studentMap[name] == password)
        {
            return true;
        }
        else
        {
            std::cout << "你的密码错误，请重新输入!" << std::endl;
            return false;
        }
    }
}

void personManager::showAll()
{
    for (auto u : teacherMap)
    {
        std::cout << "name: " << u.first << "______password: " << u.second;
    }

    for (auto u : studentMap)
    {
        std::cout << "name: " << u.first << "______password: " << u.second;
    }
}

personManager::~personManager()
{
}