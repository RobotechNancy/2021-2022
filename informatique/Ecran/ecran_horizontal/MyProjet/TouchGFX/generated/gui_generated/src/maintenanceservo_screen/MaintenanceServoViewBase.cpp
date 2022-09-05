/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/maintenanceservo_screen/MaintenanceServoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MaintenanceServoViewBase::MaintenanceServoViewBase() :
    flexButtonCallback(this, &MaintenanceServoViewBase::flexButtonCallbackHandler)
{

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
    texteCategorie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WETY));

    fondCategorie_1.setPosition(146, 8, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(238, 90, 36));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(195, 20);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_R7RU));

    fondCategorie_2.setPosition(361, 8, 114, 44);
    fondCategorie_2.setColor(touchgfx::Color::getColorFromRGB(255, 195, 18));
    fondCategorie_2.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_2.setBorderSize(3);

    texteCategorie_2.setXY(373, 20);
    texteCategorie_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_2.setLinespacing(0);
    texteCategorie_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IF7A));

    servomoteur1.setBitmap(touchgfx::Bitmap(BITMAP_SERVO_ID));
    servomoteur1.setPosition(58, 123, 88, 93);
    servomoteur1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    titreSevoResistance.setXY(81, 67);
    titreSevoResistance.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreSevoResistance.setLinespacing(0);
    titreSevoResistance.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GS8F));

    boxEtatServoResistance.setPosition(162, 117, 296, 45);
    boxEtatServoResistance.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxEtatServoResistance.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxEtatServoResistance.setBorderSize(3);

    etatServoResistance.setPosition(173, 131, 271, 19);
    etatServoResistance.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    etatServoResistance.setLinespacing(0);
    Unicode::snprintf(etatServoResistanceBuffer, ETATSERVORESISTANCE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_8OJ4).getText());
    etatServoResistance.setWildcard(etatServoResistanceBuffer);
    etatServoResistance.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H3YM));

    boutonCycleServoResistance.setBoxWithBorderPosition(0, 0, 169, 37);
    boutonCycleServoResistance.setBorderSize(5);
    boutonCycleServoResistance.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(77, 195, 255), touchgfx::Color::getColorFromRGB(77, 195, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonCycleServoResistance.setText(TypedText(T___SINGLEUSE_SK73));
    boutonCycleServoResistance.setTextPosition(0, 8, 169, 37);
    boutonCycleServoResistance.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    boutonCycleServoResistance.setPosition(224, 186, 169, 37);

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
    add(servomoteur1);
    add(titreSevoResistance);
    add(boxEtatServoResistance);
    add(etatServoResistance);
    add(boutonCycleServoResistance);
}

void MaintenanceServoViewBase::setupScreen()
{

}

void MaintenanceServoViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
        //retourEcranPredecent
        //When boutonRetour clicked change screen to Maintenance
        //Go to Maintenance with screen transition towards West
        application().gotoMaintenanceScreenSlideTransitionWest();
    }
}