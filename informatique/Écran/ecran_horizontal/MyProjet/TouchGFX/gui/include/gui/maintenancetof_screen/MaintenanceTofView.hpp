#ifndef MAINTENANCETOFVIEW_HPP
#define MAINTENANCETOFVIEW_HPP

#include <gui_generated/maintenancetof_screen/MaintenanceTofViewBase.hpp>
#include <gui/maintenancetof_screen/MaintenanceTofPresenter.hpp>

class MaintenanceTofView : public MaintenanceTofViewBase
{
public:
    MaintenanceTofView();
    virtual ~MaintenanceTofView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void uartMsgRdy();
protected:
};

#endif // MAINTENANCETOFVIEW_HPP
