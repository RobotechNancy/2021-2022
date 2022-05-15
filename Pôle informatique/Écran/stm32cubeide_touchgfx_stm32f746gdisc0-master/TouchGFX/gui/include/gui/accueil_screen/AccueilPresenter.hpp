#ifndef ACCUEILPRESENTER_HPP
#define ACCUEILPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AccueilView;

class AccueilPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AccueilPresenter(AccueilView& v);

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

    virtual ~AccueilPresenter() {};

private:
    AccueilPresenter();

    AccueilView& view;
};

#endif // ACCUEILPRESENTER_HPP
