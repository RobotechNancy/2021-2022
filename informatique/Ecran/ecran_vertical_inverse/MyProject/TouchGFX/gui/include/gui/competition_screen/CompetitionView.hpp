#ifndef COMPETITIONVIEW_HPP
#define COMPETITIONVIEW_HPP

#include <gui_generated/competition_screen/CompetitionViewBase.hpp>
#include <gui/competition_screen/CompetitionPresenter.hpp>

class CompetitionView : public CompetitionViewBase
{
public:
    CompetitionView();
    virtual ~CompetitionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // COMPETITIONVIEW_HPP
