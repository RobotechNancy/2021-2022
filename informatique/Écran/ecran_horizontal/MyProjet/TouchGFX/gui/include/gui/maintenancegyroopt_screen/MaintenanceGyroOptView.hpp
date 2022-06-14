#ifndef MAINTENANCEGYROOPTVIEW_HPP
#define MAINTENANCEGYROOPTVIEW_HPP

#include <gui_generated/maintenancegyroopt_screen/MaintenanceGyroOptViewBase.hpp>
#include <gui/maintenancegyroopt_screen/MaintenanceGyroOptPresenter.hpp>

class MaintenanceGyroOptView : public MaintenanceGyroOptViewBase
{
public:
    MaintenanceGyroOptView();
    virtual ~MaintenanceGyroOptView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCEGYROOPTVIEW_HPP
