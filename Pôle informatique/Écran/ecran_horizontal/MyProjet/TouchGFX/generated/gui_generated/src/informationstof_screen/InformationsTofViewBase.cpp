/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/informationstof_screen/InformationsTofViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


InformationsTofViewBase::InformationsTofViewBase() :
    flexButtonCallback(this, &InformationsTofViewBase::flexButtonCallbackHandler)
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
    boutonAccueil.setPosition(437, 229, 43, 43);
    boutonAccueil.setAction(flexButtonCallback);

    boutonRetour.setBoxWithBorderPosition(0, 0, 43, 43);
    boutonRetour.setBorderSize(5);
    boutonRetour.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 98, 102), touchgfx::Color::getColorFromRGB(0, 98, 102), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonRetour.setIconBitmaps(Bitmap(BITMAP_LEFT_ARROW_ID), Bitmap(BITMAP_LEFT_ARROW_ID));
    boutonRetour.setIconXY(9, 9);
    boutonRetour.setPosition(0, 229, 43, 43);
    boutonRetour.setAction(flexButtonCallback);

    fondCategorie.setPosition(7, 8, 132, 44);
    fondCategorie.setColor(touchgfx::Color::getColorFromRGB(18, 203, 196));
    fondCategorie.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie.setBorderSize(3);

    texteCategorie.setXY(22, 20);
    texteCategorie.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie.setLinespacing(0);
    texteCategorie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CVMR));

    fondCategorie_1.setPosition(146, 8, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(238, 90, 36));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(177, 20);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LE85));

    fondCategorie_2.setPosition(361, 8, 114, 44);
    fondCategorie_2.setColor(touchgfx::Color::getColorFromRGB(255, 195, 18));
    fondCategorie_2.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_2.setBorderSize(3);

    texteCategorie_2.setXY(373, 20);
    texteCategorie_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_2.setLinespacing(0);
    texteCategorie_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TH69));

    fondTitreColonne2.setPosition(163, 58, 261, 33);
    fondTitreColonne2.setColor(touchgfx::Color::getColorFromRGB(29, 209, 161));
    fondTitreColonne2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondTitreColonne2.setBorderSize(3);

    texteColonne2.setXY(245, 63);
    texteColonne2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteColonne2.setLinespacing(0);
    texteColonne2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2NI5));

    fondTitreColonne1.setPosition(55, 58, 114, 33);
    fondTitreColonne1.setColor(touchgfx::Color::getColorFromRGB(247, 159, 31));
    fondTitreColonne1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondTitreColonne1.setBorderSize(3);

    texteColonne1.setXY(64, 63);
    texteColonne1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteColonne1.setLinespacing(0);
    texteColonne1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TSXI));

    fondLigne1.setPosition(55, 85, 369, 33);
    fondLigne1.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne1.setBorderSize(3);

    fondLigne6.setPosition(55, 233, 369, 33);
    fondLigne6.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne6.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne6.setBorderSize(3);

    fondLigne5.setPosition(55, 203, 369, 33);
    fondLigne5.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne5.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne5.setBorderSize(3);

    fondLigne4.setPosition(55, 173, 369, 33);
    fondLigne4.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne4.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne4.setBorderSize(3);

    fondLigne3.setPosition(55, 143, 369, 33);
    fondLigne3.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne3.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne3.setBorderSize(3);

    fondLigne2.setPosition(55, 114, 369, 33);
    fondLigne2.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));
    fondLigne2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fondLigne2.setBorderSize(3);

    codeErreur0.setPosition(75, 91, 74, 21);
    codeErreur0.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    codeErreur0.setLinespacing(0);
    codeErreur0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RYWI));

    codeErreur1.setPosition(75, 120, 74, 21);
    codeErreur1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    codeErreur1.setLinespacing(0);
    codeErreur1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9VI5));

    codeErreur2.setPosition(75, 149, 74, 21);
    codeErreur2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    codeErreur2.setLinespacing(0);
    codeErreur2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JPZH));

    codeErreur3.setPosition(75, 179, 74, 21);
    codeErreur3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    codeErreur3.setLinespacing(0);
    codeErreur3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_42SB));

    codeErreur4.setPosition(75, 209, 74, 21);
    codeErreur4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    codeErreur4.setLinespacing(0);
    codeErreur4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WZ42));

    codeErreur5.setPosition(75, 239, 74, 21);
    codeErreur5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    codeErreur5.setLinespacing(0);
    codeErreur5.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Z9O5));

    descriptionErreur0.setPosition(176, 90, 235, 22);
    descriptionErreur0.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    descriptionErreur0.setLinespacing(0);
    descriptionErreur0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0AMK));

    descriptionErreur1.setPosition(176, 119, 235, 22);
    descriptionErreur1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    descriptionErreur1.setLinespacing(0);
    descriptionErreur1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PYVA));

    descriptionErreur2.setPosition(176, 148, 235, 22);
    descriptionErreur2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    descriptionErreur2.setLinespacing(0);
    descriptionErreur2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YXCN));

    descriptionErreur3.setPosition(176, 179, 235, 22);
    descriptionErreur3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    descriptionErreur3.setLinespacing(0);
    descriptionErreur3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8DSZ));

    descriptionErreur4.setPosition(176, 208, 235, 22);
    descriptionErreur4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    descriptionErreur4.setLinespacing(0);
    descriptionErreur4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6CVD));

    descriptionErreur5.setPosition(176, 238, 235, 22);
    descriptionErreur5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    descriptionErreur5.setLinespacing(0);
    descriptionErreur5.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SYE9));

    ligneSeparationTableau.setPosition(163, 84, 100, 182);
    ligneSeparationTableauPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneSeparationTableau.setPainter(ligneSeparationTableauPainter);
    ligneSeparationTableau.setStart(4, 5);
    ligneSeparationTableau.setEnd(4, 178);
    ligneSeparationTableau.setLineWidth(3);
    ligneSeparationTableau.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    add(__background);
    add(background);
    add(filigramme);
    add(boutonAccueil);
    add(boutonRetour);
    add(fondCategorie);
    add(texteCategorie);
    add(fondCategorie_1);
    add(texteCategorie_1);
    add(fondCategorie_2);
    add(texteCategorie_2);
    add(fondTitreColonne2);
    add(texteColonne2);
    add(fondTitreColonne1);
    add(texteColonne1);
    add(fondLigne1);
    add(fondLigne6);
    add(fondLigne5);
    add(fondLigne4);
    add(fondLigne3);
    add(fondLigne2);
    add(codeErreur0);
    add(codeErreur1);
    add(codeErreur2);
    add(codeErreur3);
    add(codeErreur4);
    add(codeErreur5);
    add(descriptionErreur0);
    add(descriptionErreur1);
    add(descriptionErreur2);
    add(descriptionErreur3);
    add(descriptionErreur4);
    add(descriptionErreur5);
    add(ligneSeparationTableau);
}

void InformationsTofViewBase::setupScreen()
{

}

void InformationsTofViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
        //When boutonRetour clicked change screen to MaintenanceTof
        //Go to MaintenanceTof with screen transition towards West
        application().gotoMaintenanceTofScreenSlideTransitionWest();
    }
}
