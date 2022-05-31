#ifndef MAINTENANCEPOMPEAVIDEVIEW_HPP
#define MAINTENANCEPOMPEAVIDEVIEW_HPP

#include <gui_generated/maintenancepompeavide_screen/MaintenancePompeAVideViewBase.hpp>
#include <gui/maintenancepompeavide_screen/MaintenancePompeAVidePresenter.hpp>

class MaintenancePompeAVideView : public MaintenancePompeAVideViewBase
{
public:
    MaintenancePompeAVideView();
    virtual ~MaintenancePompeAVideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCEPOMPEAVIDEVIEW_HPP
