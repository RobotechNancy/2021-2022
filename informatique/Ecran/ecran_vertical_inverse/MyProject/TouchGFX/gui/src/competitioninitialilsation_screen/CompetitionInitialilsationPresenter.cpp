#include <gui/competitioninitialilsation_screen/CompetitionInitialilsationView.hpp>
#include <gui/competitioninitialilsation_screen/CompetitionInitialilsationPresenter.hpp>

CompetitionInitialilsationPresenter::CompetitionInitialilsationPresenter(CompetitionInitialilsationView& v)
    : view(v)
{

}

void CompetitionInitialilsationPresenter::activate()
{

}

void CompetitionInitialilsationPresenter::deactivate()
{

}

void CompetitionInitialilsationPresenter::uartMsgRdy(){
	view.uartMsgRdy();
}
