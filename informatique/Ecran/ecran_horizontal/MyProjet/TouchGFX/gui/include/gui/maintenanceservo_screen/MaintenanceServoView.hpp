#ifndef MAINTENANCESERVOVIEW_HPP
#define MAINTENANCESERVOVIEW_HPP

#include <gui_generated/maintenanceservo_screen/MaintenanceServoViewBase.hpp>
#include <gui/maintenanceservo_screen/MaintenanceServoPresenter.hpp>

class MaintenanceServoView : public MaintenanceServoViewBase
{
public:
    MaintenanceServoView();
    virtual ~MaintenanceServoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCESERVOVIEW_HPP
