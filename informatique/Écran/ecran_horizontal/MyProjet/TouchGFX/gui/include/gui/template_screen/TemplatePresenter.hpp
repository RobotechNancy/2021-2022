#ifndef TEMPLATEPRESENTER_HPP
#define TEMPLATEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TemplateView;

class TemplatePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TemplatePresenter(TemplateView& v);

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

    virtual ~TemplatePresenter() {};

private:
    TemplatePresenter();

    TemplateView& view;
};

#endif // TEMPLATEPRESENTER_HPP
