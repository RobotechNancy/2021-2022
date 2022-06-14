#ifndef INFORMATIONSTOFPRESENTER_HPP
#define INFORMATIONSTOFPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class InformationsTofView;

class InformationsTofPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    InformationsTofPresenter(InformationsTofView& v);

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

    virtual ~InformationsTofPresenter() {};

private:
    InformationsTofPresenter();

    InformationsTofView& view;
};

#endif // INFORMATIONSTOFPRESENTER_HPP
