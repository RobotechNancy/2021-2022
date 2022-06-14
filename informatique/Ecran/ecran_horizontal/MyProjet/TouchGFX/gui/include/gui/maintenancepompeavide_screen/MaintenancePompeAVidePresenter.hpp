#ifndef MAINTENANCEPOMPEAVIDEPRESENTER_HPP
#define MAINTENANCEPOMPEAVIDEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MaintenancePompeAVideView;

class MaintenancePompeAVidePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MaintenancePompeAVidePresenter(MaintenancePompeAVideView& v);

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

    virtual ~MaintenancePompeAVidePresenter() {};

private:
    MaintenancePompeAVidePresenter();

    MaintenancePompeAVideView& view;
};

#endif // MAINTENANCEPOMPEAVIDEPRESENTER_HPP
