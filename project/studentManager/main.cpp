#include <iostream>
#include "mainWindow.cpp"
#include "personManager.cpp"
int main()
{
    mainWindow *mw = new mainWindow();
    int choice = mw->index();
    if(choice == 2)
    {
        mw->registerWindow();
    }
    
    return 0;
}