#ifndef MAINTENANCECANVIEW_HPP
#define MAINTENANCECANVIEW_HPP

#include <gui_generated/maintenancecan_screen/MaintenanceCanViewBase.hpp>
#include <gui/maintenancecan_screen/MaintenanceCanPresenter.hpp>

class MaintenanceCanView : public MaintenanceCanViewBase
{
public:
    MaintenanceCanView();
    virtual ~MaintenanceCanView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCECANVIEW_HPP
