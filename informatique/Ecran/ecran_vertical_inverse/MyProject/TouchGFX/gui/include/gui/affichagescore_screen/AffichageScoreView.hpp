#ifndef AFFICHAGESCOREVIEW_HPP
#define AFFICHAGESCOREVIEW_HPP

#include <gui_generated/affichagescore_screen/AffichageScoreViewBase.hpp>
#include <gui/affichagescore_screen/AffichageScorePresenter.hpp>

class AffichageScoreView : public AffichageScoreViewBase
{
public:
    AffichageScoreView();
    virtual ~AffichageScoreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void uartMsgRdy();
protected:
};

#endif // AFFICHAGESCOREVIEW_HPP
