#ifndef COMPETITIONPRESENTER_HPP
#define COMPETITIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CompetitionView;

class CompetitionPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CompetitionPresenter(CompetitionView& v);

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

    virtual ~CompetitionPresenter() {};

private:
    CompetitionPresenter();

    CompetitionView& view;
};

#endif // COMPETITIONPRESENTER_HPP
