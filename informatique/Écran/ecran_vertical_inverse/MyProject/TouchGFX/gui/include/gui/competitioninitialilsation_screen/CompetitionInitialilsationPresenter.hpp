#ifndef COMPETITIONINITIALILSATIONPRESENTER_HPP
#define COMPETITIONINITIALILSATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CompetitionInitialilsationView;

class CompetitionInitialilsationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CompetitionInitialilsationPresenter(CompetitionInitialilsationView& v);

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

    virtual ~CompetitionInitialilsationPresenter() {};

    virtual void uartMsgRdy();

private:
    CompetitionInitialilsationPresenter();

    CompetitionInitialilsationView& view;
};

#endif // COMPETITIONINITIALILSATIONPRESENTER_HPP
