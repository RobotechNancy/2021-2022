/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/competitioninitialilsation_screen/CompetitionInitialilsationViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


CompetitionInitialilsationViewBase::CompetitionInitialilsationViewBase() :
    flexButtonCallback(this, &CompetitionInitialilsationViewBase::flexButtonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background.setPosition(0, 0, 480, 272);
    background.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));

    filigramme.setBitmap(touchgfx::Bitmap(BITMAP_LOGO_SIMPLIFIE_ROBOTECH_ID));
    filigramme.setPosition(0, 0, 480, 272);
    filigramme.setAlpha(30);
    filigramme.setOffset(0, 0);

    boutonAccueil.setBoxWithBorderPosition(0, 0, 43, 43);
    boutonAccueil.setBorderSize(5);
    boutonAccueil.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonAccueil.setIconBitmaps(Bitmap(BITMAP_HOME_ID), Bitmap(BITMAP_HOME_ID));
    boutonAccueil.setIconXY(9, 8);
    boutonAccueil.setPosition(56, 229, 43, 43);
    boutonAccueil.setAction(flexButtonCallback);

    boutonRetour.setBoxWithBorderPosition(0, 0, 43, 43);
    boutonRetour.setBorderSize(5);
    boutonRetour.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 98, 102), touchgfx::Color::getColorFromRGB(0, 98, 102), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonRetour.setIconBitmaps(Bitmap(BITMAP_LEFT_ARROW_ID), Bitmap(BITMAP_LEFT_ARROW_ID));
    boutonRetour.setIconXY(9, 9);
    boutonRetour.setPosition(0, 229, 43, 43);
    boutonRetour.setAction(flexButtonCallback);

    fondCategorie_1.setPosition(146, 8, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(238, 90, 36));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(204, 20);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZFCS));

    boutonGo.setBoxWithBorderPosition(0, 0, 124, 43);
    boutonGo.setBorderSize(5);
    boutonGo.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(232, 232, 232), touchgfx::Color::getColorFromRGB(232, 232, 232), touchgfx::Color::getColorFromRGB(255, 0, 0), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonGo.setText(TypedText(T___SINGLEUSE_NKNC));
    boutonGo.setTextPosition(0, 10, 124, 43);
    boutonGo.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    boutonGo.setPosition(356, 229, 124, 43);
    boutonGo.setAction(flexButtonCallback);

    fondCategorie.setPosition(7, 8, 132, 44);
    fondCategorie.setColor(touchgfx::Color::getColorFromRGB(255, 195, 18));
    fondCategorie.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie.setBorderSize(3);

    texteCategorie.setXY(25, 20);
    texteCategorie.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie.setLinespacing(0);
    texteCategorie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5NPH));

    fondVersion.setPosition(361, 8, 114, 44);
    fondVersion.setColor(touchgfx::Color::getColorFromRGB(18, 203, 196));
    fondVersion.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondVersion.setBorderSize(3);

    texteVersion.setXY(373, 20);
    texteVersion.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteVersion.setLinespacing(0);
    texteVersion.setTypedText(touchgfx::TypedText(T___SINGLEUSE_P1M2));

    fondTitreColonne2.setPosition(199, 61, 261, 33);
    fondTitreColonne2.setColor(touchgfx::Color::getColorFromRGB(29, 209, 161));
    fondTitreColonne2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondTitreColonne2.setBorderSize(3);

    texteColonne2.setXY(248, 67);
    texteColonne2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteColonne2.setLinespacing(0);
    texteColonne2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1L9M));

    fondTitreColonne1.setPosition(21, 61, 184, 33);
    fondTitreColonne1.setColor(touchgfx::Color::getColorFromRGB(247, 159, 31));
    fondTitreColonne1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondTitreColonne1.setBorderSize(3);

    texteColonne1.setPosition(33, 67, 161, 21);
    texteColonne1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteColonne1.setLinespacing(0);
    texteColonne1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XMM8));

    fondLigne1.setPosition(21, 89, 439, 33);
    fondLigne1.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne1.setBorderSize(3);

    fondLigne2.setPosition(21, 118, 439, 33);
    fondLigne2.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne2.setBorderSize(3);

    fondLigne3.setPosition(21, 147, 439, 33);
    fondLigne3.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne3.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne3.setBorderSize(3);

    fondLigne4.setPosition(21, 177, 439, 33);
    fondLigne4.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne4.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne4.setBorderSize(3);

    texteLigne1.setPosition(33, 95, 161, 21);
    texteLigne1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteLigne1.setLinespacing(0);
    texteLigne1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SH5Q));

    texteLigne2.setPosition(33, 124, 161, 21);
    texteLigne2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteLigne2.setLinespacing(0);
    texteLigne2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YR2N));

    texteLigne3.setPosition(33, 154, 161, 21);
    texteLigne3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteLigne3.setLinespacing(0);
    texteLigne3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UMH8));

    texteLigne4.setPosition(27, 183, 173, 21);
    texteLigne4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteLigne4.setLinespacing(0);
    texteLigne4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AEH6));

    ligneSeparationTableau.setPosition(198, 86, 100, 134);
    ligneSeparationTableauPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneSeparationTableau.setPainter(ligneSeparationTableauPainter);
    ligneSeparationTableau.setStart(5, 5);
    ligneSeparationTableau.setEnd(5, 121);
    ligneSeparationTableau.setLineWidth(3);
    ligneSeparationTableau.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    etatInit1.setPosition(221, 95, 217, 21);
    etatInit1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    etatInit1.setLinespacing(0);
    Unicode::snprintf(etatInit1Buffer, ETATINIT1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_CYA7).getText());
    etatInit1.setWildcard(etatInit1Buffer);
    etatInit1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_66HG));

    etatInit2.setPosition(221, 124, 217, 21);
    etatInit2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    etatInit2.setLinespacing(0);
    Unicode::snprintf(etatInit2Buffer, ETATINIT2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2J9N).getText());
    etatInit2.setWildcard(etatInit2Buffer);
    etatInit2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2D3A));

    etatInit3.setPosition(221, 153, 217, 21);
    etatInit3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    etatInit3.setLinespacing(0);
    Unicode::snprintf(etatInit3Buffer, ETATINIT3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_TLQ8).getText());
    etatInit3.setWildcard(etatInit3Buffer);
    etatInit3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3GYG));

    etatInit4.setPosition(221, 183, 217, 21);
    etatInit4.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    etatInit4.setLinespacing(0);
    Unicode::snprintf(etatInit4Buffer, ETATINIT4_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_8JGW).getText());
    etatInit4.setWildcard(etatInit4Buffer);
    etatInit4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_G1RP));

    add(__background);
    add(background);
    add(filigramme);
    add(boutonAccueil);
    add(boutonRetour);
    add(fondCategorie_1);
    add(texteCategorie_1);
    add(boutonGo);
    add(fondCategorie);
    add(texteCategorie);
    add(fondVersion);
    add(texteVersion);
    add(fondTitreColonne2);
    add(texteColonne2);
    add(fondTitreColonne1);
    add(texteColonne1);
    add(fondLigne1);
    add(fondLigne2);
    add(fondLigne3);
    add(fondLigne4);
    add(texteLigne1);
    add(texteLigne2);
    add(texteLigne3);
    add(texteLigne4);
    add(ligneSeparationTableau);
    add(etatInit1);
    add(etatInit2);
    add(etatInit3);
    add(etatInit4);
}

void CompetitionInitialilsationViewBase::setupScreen()
{

}

void CompetitionInitialilsationViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &boutonAccueil)
    {
        //retourAccueil
        //When boutonAccueil clicked change screen to Accueil
        //Go to Accueil with screen transition towards West
        application().gotoAccueilScreenSlideTransitionWest();
    }
    else if (&src == &boutonRetour)
    {
        //retourEcranPrecedent
        //When boutonRetour clicked change screen to Competition
        //Go to Competition with screen transition towards West
        application().gotoCompetitionScreenSlideTransitionWest();
    }
    else if (&src == &boutonGo)
    {
        //ecranScore
        //When boutonGo clicked change screen to AffichageScore
        //Go to AffichageScore with screen transition towards East
        application().gotoAffichageScoreScreenSlideTransitionEast();
    }
}
