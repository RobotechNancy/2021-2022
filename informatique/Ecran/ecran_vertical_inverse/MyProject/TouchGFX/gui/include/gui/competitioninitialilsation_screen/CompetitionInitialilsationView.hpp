#ifndef COMPETITIONINITIALILSATIONVIEW_HPP
#define COMPETITIONINITIALILSATIONVIEW_HPP

#include <gui_generated/competitioninitialilsation_screen/CompetitionInitialilsationViewBase.hpp>
#include <gui/competitioninitialilsation_screen/CompetitionInitialilsationPresenter.hpp>

class CompetitionInitialilsationView : public CompetitionInitialilsationViewBase
{
public:
    CompetitionInitialilsationView();
    virtual ~CompetitionInitialilsationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void uartMsgRdy();
protected:
};

#endif // COMPETITIONINITIALILSATIONVIEW_HPP
