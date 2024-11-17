#include "mainWindow.hpp"

mainWindow::mainWindow() : pm(new personManager())
{
}

int mainWindow::index()
{
    std::cout << "-------欢迎来到学生管理系统---------" << std::endl;
    std::cout << "-----------1、用户登录----------" << std::endl;
    std::cout << "-----------2、用户注册----------" << std::endl;
    std::cout << "-----------3、退出系统----------" << std::endl;
    std::cout << "请输入你的选择:";
    int choice;
    std::cin >> choice;
    return choice;
}

void mainWindow::registerWindow()
{
    std::cout << "-------欢迎注册学生管理系统---------" << std::endl;
    std::cout << "请问您是老师还是学生？\n1、学生\n2、老师\n请选择：";
    int choice;
    std::cin >> choice;
    std::string name;
    std::string password;
    std::cout << "请输入你的姓名：";
    std::cin >> name;
    std::cout << "请输入你的密码：";
    std::cin >> password;
    pm->personAdd(name, password, choice);
    // pm->showAll();
    // 注册之后需要登录吗？还是直接跳到主界面？----->还是登录一下
    loginWindow();
}

void mainWindow::loginWindow()
{
    std::cout << "欢迎登录！" << std::endl;
    std::string name;
    std::string password;
    std::cout << "请输入你的账户：";
    std::cin >> name;
    std::cout << "请输入你的密码：";
    std::cin >> password;
    if (pm->isUser(name, password))
    {
        functionWindow();
    }
    else
    {
        loginWindow();
    }
}

void mainWindow::functionWindow()
{
    std::cout << "this is functionWindow!" << std::endl;
}

mainWindow::~mainWindow()
{
}