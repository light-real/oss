#include "mainWindow.hpp"

mainWindow::mainWindow() : pm(new personManager())
{
}

int mainWindow::index()
{
    std::cout << "-------��ӭ����ѧ������ϵͳ---------" << std::endl;
    std::cout << "-----------1���û���¼----------" << std::endl;
    std::cout << "-----------2���û�ע��----------" << std::endl;
    std::cout << "-----------3���˳�ϵͳ----------" << std::endl;
    std::cout << "���������ѡ��:";
    int choice;
    std::cin >> choice;
    return choice;
}

void mainWindow::registerWindow()
{
    std::cout << "-------��ӭע��ѧ������ϵͳ---------" << std::endl;
    std::cout << "����������ʦ����ѧ����\n1��ѧ��\n2����ʦ\n��ѡ��";
    int choice;
    std::cin >> choice;
    std::string name;
    std::string password;
    std::cout << "���������������";
    std::cin >> name;
    std::cout << "������������룺";
    std::cin >> password;
    pm->personAdd(name, password, choice);
    // pm->showAll();
    // ע��֮����Ҫ��¼�𣿻���ֱ�����������棿----->���ǵ�¼һ��
    loginWindow();
}

void mainWindow::loginWindow()
{
    std::cout << "��ӭ��¼��" << std::endl;
    std::string name;
    std::string password;
    std::cout << "����������˻���";
    std::cin >> name;
    std::cout << "������������룺";
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