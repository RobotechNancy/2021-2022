#ifndef AFFICHAGESCOREPRESENTER_HPP
#define AFFICHAGESCOREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AffichageScoreView;

class AffichageScorePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AffichageScorePresenter(AffichageScoreView& v);

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

    virtual ~AffichageScorePresenter() {};

    virtual void uartMsgRdy();

private:
    AffichageScorePresenter();

    AffichageScoreView& view;
};

#endif // AFFICHAGESCOREPRESENTER_HPP
