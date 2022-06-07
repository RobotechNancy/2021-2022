#include <gui/affichagescore_screen/AffichageScoreView.hpp>
#include <gui/affichagescore_screen/AffichageScorePresenter.hpp>

AffichageScorePresenter::AffichageScorePresenter(AffichageScoreView& v)
    : view(v)
{

}

void AffichageScorePresenter::activate()
{

}

void AffichageScorePresenter::deactivate()
{

}

void AffichageScorePresenter::uartMsgRdy(){
	view.uartMsgRdy();
}

