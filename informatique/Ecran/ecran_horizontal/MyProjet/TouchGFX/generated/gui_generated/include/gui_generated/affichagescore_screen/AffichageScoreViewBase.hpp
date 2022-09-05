/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef AFFICHAGESCOREVIEWBASE_HPP
#define AFFICHAGESCOREVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/affichagescore_screen/AffichageScorePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/Gauge.hpp>

class AffichageScoreViewBase : public touchgfx::View<AffichageScorePresenter>
{
public:
    AffichageScoreViewBase();
    virtual ~AffichageScoreViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box background;
    touchgfx::TiledImage filigramme;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > > boutonAccueil;
    touchgfx::IconButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > > boutonRetour;
    touchgfx::Box fondScoreGrandRobot;
    touchgfx::Box fondScorePetitRobot;
    touchgfx::Box fondScoreTotal;
    touchgfx::TextAreaWithOneWildcard scoreTotal;
    touchgfx::TextAreaWithOneWildcard scorePetitRobot;
    touchgfx::TextAreaWithOneWildcard scoreGrandRobot;
    touchgfx::ScalableImage imageGrandRobot;
    touchgfx::ScalableImage imagePetitRobot;
    touchgfx::Gauge gaugeScore;

    /*
     * Wildcard Buffers
     */
    static const uint16_t SCORETOTAL_SIZE = 17;
    touchgfx::Unicode::UnicodeChar scoreTotalBuffer[SCORETOTAL_SIZE];
    static const uint16_t SCOREPETITROBOT_SIZE = 17;
    touchgfx::Unicode::UnicodeChar scorePetitRobotBuffer[SCOREPETITROBOT_SIZE];
    static const uint16_t SCOREGRANDROBOT_SIZE = 17;
    touchgfx::Unicode::UnicodeChar scoreGrandRobotBuffer[SCOREGRANDROBOT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<AffichageScoreViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // AFFICHAGESCOREVIEWBASE_HPP