#include"app.hpp"

App::App(int argc, char** argv) : QApplication(argc, argv), appWindow(this){

}

App::~App(){

}

GET_DEFINITION(App, AppWindow&, appWindow);
GET_DEFINITION(App, DataBaseMenager&, dbMenager);

