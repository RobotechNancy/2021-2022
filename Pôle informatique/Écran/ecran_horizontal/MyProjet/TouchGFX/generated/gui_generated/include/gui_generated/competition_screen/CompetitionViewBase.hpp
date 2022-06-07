/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef COMPETITIONVIEWBASE_HPP
#define COMPETITIONVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/competition_screen/CompetitionPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>

class CompetitionViewBase : public touchgfx::View<CompetitionPresenter>
{
public:
    CompetitionViewBase();
    virtual ~CompetitionViewBase() {}
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
    touchgfx::BoxWithBorder fondCategorie;
    touchgfx::TextArea texteCategorie;
    touchgfx::BoxWithBorder fondCategorie_1;
    touchgfx::TextArea texteCategorie_1;
    touchgfx::BoxWithBorder fondCategorie_2;
    touchgfx::TextArea texteCategorie_2;
    touchgfx::BoxWithBorder fondBoutonEquipe;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > > validationChoixEquipe;
    touchgfx::ToggleButton boutonChoixEquipe;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<CompetitionViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<CompetitionViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // COMPETITIONVIEWBASE_HPP
