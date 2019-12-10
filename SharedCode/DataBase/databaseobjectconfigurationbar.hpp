#ifndef DATABASEOBJECTCONFIGURATIONBAR_HPP
#define DATABASEOBJECTCONFIGURATIONBAR_HPP

// _INCLUDES_ DataBaseObjectConfigurationBar.hpp -------------------------------------------------------------------------------------------------------------------------------------------
#include<QLabel>
#include<QLineEdit>
#include<QWidget>
// --------------------------------------------------------------------------------------------------------------------------------------------------------------

// _PREDEFINITIONS_ DataBaseObjectConfigurationBar.hpp --------------------------------------------------------------------------------------------------------------------------------------
class OperationPanel;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------

// _CLASSDEF_ DataBaseObjectConfigurationBar -----------------------------------------------------------------------------------------------------------------------------------------------
class DataBaseObjectConfigurationBar : public QWidget{
public:
    // _CONSTRUCTORS_ DataBaseObjectConfigurationBar.hpp
    DataBaseObjectConfigurationBar(OperationPanel*);
    // _DESTRUCTORS_ DataBaseObjectConfigurationBar.hpp
    virtual ~DataBaseObjectConfigurationBar() override;

protected:
    // _PRIVATE_MEMBERS_ DataBaseObjectConfigurationBar.hpp
    OperationPanel* parent = nullptr;
    QLineEdit titleLabel;
    QLabel configurationButton; // Preview Mode and Modification Mode Switch
public:
    // _PUBLIC_MEMBERS_ DataBaseObjectConfigurationBar.hpp

private:
    // _PRIVATE_METHODS_ DataBaseObjectConfigurationBar.hpp
    virtual void initialize();
    virtual void createObjects();   // Pointers Only
    virtual void createLayout();
    virtual void connectEvents();
    virtual void clearMemory();

public:
    // _PUBLIC_METHODS_ DataBaseObjectConfigurationBar.hpp
    void resizeEvent(QResizeEvent* ev) override;
    bool eventFilter(QObject*, QEvent*) override;
};

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // DATABASEOBJECTCONFIGURATIONBAR_HPP
