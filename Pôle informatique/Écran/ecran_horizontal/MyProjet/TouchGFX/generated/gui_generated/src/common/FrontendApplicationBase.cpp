/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include<platform/driver/lcd/LCD24bpp.hpp>
#include <gui/accueil_screen/AccueilView.hpp>
#include <gui/accueil_screen/AccueilPresenter.hpp>
#include <gui/competition_screen/CompetitionView.hpp>
#include <gui/competition_screen/CompetitionPresenter.hpp>
#include <gui/maintenance_screen/MaintenanceView.hpp>
#include <gui/maintenance_screen/MaintenancePresenter.hpp>
#include <gui/maintenancetof_screen/MaintenanceTofView.hpp>
#include <gui/maintenancetof_screen/MaintenanceTofPresenter.hpp>
#include <gui/informationstof_screen/InformationsTofView.hpp>
#include <gui/informationstof_screen/InformationsTofPresenter.hpp>
#include <gui/maintenancexbee_screen/MaintenanceXbeeView.hpp>
#include <gui/maintenancexbee_screen/MaintenanceXbeePresenter.hpp>
#include <gui/maintenancecan_screen/MaintenanceCanView.hpp>
#include <gui/maintenancecan_screen/MaintenanceCanPresenter.hpp>
#include <gui/maintenancegyroopt_screen/MaintenanceGyroOptView.hpp>
#include <gui/maintenancegyroopt_screen/MaintenanceGyroOptPresenter.hpp>
#include <gui/maintenancepompeavide_screen/MaintenancePompeAVideView.hpp>
#include <gui/maintenancepompeavide_screen/MaintenancePompeAVidePresenter.hpp>
#include <gui/maintenanceservo_screen/MaintenanceServoView.hpp>
#include <gui/maintenanceservo_screen/MaintenanceServoPresenter.hpp>
#include <gui/competitioninitialilsation_screen/CompetitionInitialilsationView.hpp>
#include <gui/competitioninitialilsation_screen/CompetitionInitialilsationPresenter.hpp>
#include <gui/affichagescore_screen/AffichageScoreView.hpp>
#include <gui/affichagescore_screen/AffichageScorePresenter.hpp>
#include <gui/template_screen/TemplateView.hpp>
#include <gui/template_screen/TemplatePresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD24bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
}

/*
 * Screen Transition Declarations
 */

// Accueil

void FrontendApplicationBase::gotoAccueilScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoAccueilScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoAccueilScreenNoTransitionImpl()
{
    touchgfx::makeTransition<AccueilView, AccueilPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoAccueilScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoAccueilScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoAccueilScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<AccueilView, AccueilPresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Competition

void FrontendApplicationBase::gotoCompetitionScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCompetitionScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCompetitionScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<CompetitionView, CompetitionPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoCompetitionScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCompetitionScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCompetitionScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<CompetitionView, CompetitionPresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Maintenance

void FrontendApplicationBase::gotoMaintenanceScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenanceView, MaintenancePresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoMaintenanceScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<MaintenanceView, MaintenancePresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MaintenanceTof

void FrontendApplicationBase::gotoMaintenanceTofScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceTofScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceTofScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenanceTofView, MaintenanceTofPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoMaintenanceTofScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceTofScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceTofScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<MaintenanceTofView, MaintenanceTofPresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// InformationsTof

void FrontendApplicationBase::gotoInformationsTofScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoInformationsTofScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoInformationsTofScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<InformationsTofView, InformationsTofPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MaintenanceXbee

void FrontendApplicationBase::gotoMaintenanceXbeeScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceXbeeScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceXbeeScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenanceXbeeView, MaintenanceXbeePresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MaintenanceCan

void FrontendApplicationBase::gotoMaintenanceCanScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceCanScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceCanScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenanceCanView, MaintenanceCanPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MaintenanceGyroOpt

void FrontendApplicationBase::gotoMaintenanceGyroOptScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceGyroOptScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceGyroOptScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenanceGyroOptView, MaintenanceGyroOptPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MaintenancePompeAVide

void FrontendApplicationBase::gotoMaintenancePompeAVideScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenancePompeAVideScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenancePompeAVideScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenancePompeAVideView, MaintenancePompeAVidePresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MaintenanceServo

void FrontendApplicationBase::gotoMaintenanceServoScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMaintenanceServoScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMaintenanceServoScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<MaintenanceServoView, MaintenanceServoPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// CompetitionInitialilsation

void FrontendApplicationBase::gotoCompetitionInitialilsationScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCompetitionInitialilsationScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCompetitionInitialilsationScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<CompetitionInitialilsationView, CompetitionInitialilsationPresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoCompetitionInitialilsationScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCompetitionInitialilsationScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCompetitionInitialilsationScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<CompetitionInitialilsationView, CompetitionInitialilsationPresenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// AffichageScore

void FrontendApplicationBase::gotoAffichageScoreScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoAffichageScoreScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoAffichageScoreScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<AffichageScoreView, AffichageScorePresenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
