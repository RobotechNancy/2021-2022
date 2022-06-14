#ifndef MAINTENANCEGYROOPTPRESENTER_HPP
#define MAINTENANCEGYROOPTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MaintenanceGyroOptView;

class MaintenanceGyroOptPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MaintenanceGyroOptPresenter(MaintenanceGyroOptView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MaintenanceGyroOptPresenter() {};

private:
    MaintenanceGyroOptPresenter();

    MaintenanceGyroOptView& view;
};

#endif // MAINTENANCEGYROOPTPRESENTER_HPP
