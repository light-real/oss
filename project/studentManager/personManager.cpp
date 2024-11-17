#include "personManager.hpp"

personManager::personManager()
{
}
void personManager::personAdd(std::string name, std::string password, int flag)
{
    // flagΪ0 ��ѧ��
    // flagΪ1 ����ʦ
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
            std::cout << "��������������������!" << std::endl;
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
            std::cout << "��������������������!" << std::endl;
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