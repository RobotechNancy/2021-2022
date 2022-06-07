/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/maintenancegyroopt_screen/MaintenanceGyroOptViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MaintenanceGyroOptViewBase::MaintenanceGyroOptViewBase() :
    flexButtonCallback(this, &MaintenanceGyroOptViewBase::flexButtonCallbackHandler)
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
    texteCategorie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7FSH));

    fondCategorie_1.setPosition(146, 8, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(238, 90, 36));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(178, 20);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IY1Q));

    fondCategorie_2.setPosition(361, 8, 114, 44);
    fondCategorie_2.setColor(touchgfx::Color::getColorFromRGB(255, 195, 18));
    fondCategorie_2.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_2.setBorderSize(3);

    texteCategorie_2.setXY(373, 20);
    texteCategorie_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_2.setLinespacing(0);
    texteCategorie_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_42ZG));

    gyroscopeAccelerometre.setBitmap(touchgfx::Bitmap(BITMAP_MPU6050_ID));
    gyroscopeAccelerometre.setPosition(79, 84, 81, 63);
    gyroscopeAccelerometre.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    capteurOptique.setBitmap(touchgfx::Bitmap(BITMAP_PMW3901_ID));
    capteurOptique.setPosition(318, 84, 73, 63);
    capteurOptique.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    titreGyro.setXY(79, 63);
    titreGyro.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreGyro.setLinespacing(0);
    titreGyro.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0EUS));

    titreOptique.setXY(312, 63);
    titreOptique.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreOptique.setLinespacing(0);
    titreOptique.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NZXT));

    boxEtatGyro.setPosition(31, 149, 177, 36);
    boxEtatGyro.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxEtatGyro.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxEtatGyro.setBorderSize(2);

    etatGyro.setPosition(37, 156, 165, 20);
    etatGyro.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    etatGyro.setLinespacing(0);
    Unicode::snprintf(etatGyroBuffer, ETATGYRO_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_9QBV).getText());
    etatGyro.setWildcard(etatGyroBuffer);
    etatGyro.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YUVB));

    boxMesureGyro.setPosition(15, 189, 208, 36);
    boxMesureGyro.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxMesureGyro.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxMesureGyro.setBorderSize(2);

    mesureGyro.setPosition(23, 198, 193, 19);
    mesureGyro.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    mesureGyro.setLinespacing(0);
    Unicode::snprintf(mesureGyroBuffer, MESUREGYRO_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_KC94).getText());
    mesureGyro.setWildcard(mesureGyroBuffer);
    mesureGyro.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LPC4));

    boxEtatOptique.setPosition(266, 149, 177, 36);
    boxEtatOptique.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxEtatOptique.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxEtatOptique.setBorderSize(2);

    etatOptique.setPosition(272, 156, 165, 20);
    etatOptique.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    etatOptique.setLinespacing(0);
    Unicode::snprintf(etatOptiqueBuffer, ETATOPTIQUE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_3GG6).getText());
    etatOptique.setWildcard(etatOptiqueBuffer);
    etatOptique.setTypedText(touchgfx::TypedText(T___SINGLEUSE_C5RJ));

    boxMesureOptique.setPosition(252, 189, 208, 36);
    boxMesureOptique.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxMesureOptique.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxMesureOptique.setBorderSize(2);

    mesureOptiques.setPosition(258, 198, 193, 19);
    mesureOptiques.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    mesureOptiques.setLinespacing(0);
    Unicode::snprintf(mesureOptiquesBuffer, MESUREOPTIQUES_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_4XK6).getText());
    mesureOptiques.setWildcard(mesureOptiquesBuffer);
    mesureOptiques.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W9GD));

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
    add(gyroscopeAccelerometre);
    add(capteurOptique);
    add(titreGyro);
    add(titreOptique);
    add(boxEtatGyro);
    add(etatGyro);
    add(boxMesureGyro);
    add(mesureGyro);
    add(boxEtatOptique);
    add(etatOptique);
    add(boxMesureOptique);
    add(mesureOptiques);
}

void MaintenanceGyroOptViewBase::setupScreen()
{

}

void MaintenanceGyroOptViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
