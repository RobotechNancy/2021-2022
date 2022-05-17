#include <gui/score_screen/ScoreView.hpp>
#include <gui/score_screen/ScorePresenter.hpp>

ScorePresenter::ScorePresenter(ScoreView& v)
    : view(v)
{

}

void ScorePresenter::activate()
{

}

void ScorePresenter::deactivate()
{

}

void ScorePresenter::uartMsgRdy(){
	view.uartMsgRdy();
}
