#ifndef MAINTENANCEXBEEPRESENTER_HPP
#define MAINTENANCEXBEEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MaintenanceXbeeView;

class MaintenanceXbeePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MaintenanceXbeePresenter(MaintenanceXbeeView& v);

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

    virtual ~MaintenanceXbeePresenter() {};

private:
    MaintenanceXbeePresenter();

    MaintenanceXbeeView& view;
};

#endif // MAINTENANCEXBEEPRESENTER_HPP
