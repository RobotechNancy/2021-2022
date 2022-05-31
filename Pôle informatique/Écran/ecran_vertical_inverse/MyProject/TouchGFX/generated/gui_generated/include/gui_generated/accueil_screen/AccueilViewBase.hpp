/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ACCUEILVIEWBASE_HPP
#define ACCUEILVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/accueil_screen/AccueilPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>

class AccueilViewBase : public touchgfx::View<AccueilPresenter>
{
public:
    AccueilViewBase();
    virtual ~AccueilViewBase() {}
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
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > boutonCompetition;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > boutonMaintenance;
    touchgfx::Box fondTitreSecondaire;
    touchgfx::TextArea titreSecondaire;
    touchgfx::TextArea titrePrincipal;
    touchgfx::TextArea titrePrincipal_1;
    touchgfx::TextArea titreSecondaire_1;
    touchgfx::TextArea titreSecondaire_1_1;
    touchgfx::ScalableImage scalableImage1;
    touchgfx::ScalableImage scalableImage2;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<AccueilViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // ACCUEILVIEWBASE_HPP
