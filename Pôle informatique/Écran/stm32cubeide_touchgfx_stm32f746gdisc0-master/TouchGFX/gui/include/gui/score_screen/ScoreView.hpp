#ifndef SCOREVIEW_HPP
#define SCOREVIEW_HPP

#include <gui_generated/score_screen/ScoreViewBase.hpp>
#include <gui/score_screen/ScorePresenter.hpp>

class ScoreView : public ScoreViewBase
{
public:
    ScoreView();
    virtual ~ScoreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void uartMsgRdy();

protected:
};

#endif // SCOREVIEW_HPP
