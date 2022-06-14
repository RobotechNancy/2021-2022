#ifndef MAINTENANCESERVOPRESENTER_HPP
#define MAINTENANCESERVOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MaintenanceServoView;

class MaintenanceServoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MaintenanceServoPresenter(MaintenanceServoView& v);

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

    virtual ~MaintenanceServoPresenter() {};

private:
    MaintenanceServoPresenter();

    MaintenanceServoView& view;
};

#endif // MAINTENANCESERVOPRESENTER_HPP
