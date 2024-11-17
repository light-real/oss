// ���ڹ�����ʦ��ѧ������Ϣ
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
    std::unordered_map<std::string, std::string> teacherMap; // name:password ���ڴ洢��ʦ����Ϣ
    std::unordered_map<std::string, std::string> studentMap; // name:password ���ڴ洢ѧ������Ϣ
};