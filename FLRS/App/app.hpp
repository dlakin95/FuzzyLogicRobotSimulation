#ifndef APP_HPP
#define APP_HPP

#include<QApplication>
#include"GeneralPurposeMacros/standardclassdefinitions.hpp"
#include"AppWindow/appwindow.hpp"
#include"DataBaseMenager/databasemenager.hpp"

class App : public QApplication{
public:
    App(int argc, char** argv);
    ~App();

private:
    AppWindow appWindow;
    DataBaseMenager dbMenager;

public:
    GET_DECLARATION(AppWindow&, appWindow);
    GET_DECLARATION(DataBaseMenager&, dbMenager);
};

#endif // APP_HPP
