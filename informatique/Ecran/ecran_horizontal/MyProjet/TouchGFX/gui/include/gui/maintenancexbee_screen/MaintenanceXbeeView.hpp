#ifndef MAINTENANCEXBEEVIEW_HPP
#define MAINTENANCEXBEEVIEW_HPP

#include <gui_generated/maintenancexbee_screen/MaintenanceXbeeViewBase.hpp>
#include <gui/maintenancexbee_screen/MaintenanceXbeePresenter.hpp>

class MaintenanceXbeeView : public MaintenanceXbeeViewBase
{
public:
    MaintenanceXbeeView();
    virtual ~MaintenanceXbeeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCEXBEEVIEW_HPP
