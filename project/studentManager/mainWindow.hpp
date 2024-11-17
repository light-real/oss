#pragma once
#include <iostream>
#include <string>
#include "personManager.hpp"

class mainWindow
{
public:
    mainWindow();
    ~mainWindow();
    int index();
    void registerWindow();
    void loginWindow();
    void functionWindow();
private:
    personManager* pm;
};