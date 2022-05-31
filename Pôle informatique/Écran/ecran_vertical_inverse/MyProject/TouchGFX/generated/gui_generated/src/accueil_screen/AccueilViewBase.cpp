/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/accueil_screen/AccueilViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

AccueilViewBase::AccueilViewBase() :
    flexButtonCallback(this, &AccueilViewBase::flexButtonCallbackHandler)
{

    __background.setPosition(0, 0, 272, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background.setPosition(0, 0, 272, 480);
    background.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));

    filigramme.setBitmap(touchgfx::Bitmap(BITMAP_LOGO_SIMPLIFIE_ROBOTECH_ID));
    filigramme.setPosition(0, 0, 272, 480);
    filigramme.setAlpha(30);
    filigramme.setOffset(0, 0);

    boutonCompetition.setBoxWithBorderPosition(0, 0, 169, 50);
    boutonCompetition.setBorderSize(5);
    boutonCompetition.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(247, 159, 31), touchgfx::Color::getColorFromRGB(247, 159, 31), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonCompetition.setPosition(52, 231, 169, 50);
    boutonCompetition.setAction(flexButtonCallback);

    boutonMaintenance.setBoxWithBorderPosition(0, 0, 169, 50);
    boutonMaintenance.setBorderSize(5);
    boutonMaintenance.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(18, 203, 196), touchgfx::Color::getColorFromRGB(18, 203, 196), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonMaintenance.setPosition(52, 159, 169, 50);
    boutonMaintenance.setAction(flexButtonCallback);

    fondTitreSecondaire.setPosition(31, 330, 216, 35);
    fondTitreSecondaire.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    titreSecondaire.setXY(40, 337);
    titreSecondaire.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreSecondaire.setLinespacing(0);
    titreSecondaire.setRotation(touchgfx::TEXT_ROTATE_180);
    titreSecondaire.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PVC0));

    titrePrincipal.setXY(52, 412);
    titrePrincipal.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titrePrincipal.setLinespacing(0);
    titrePrincipal.setRotation(touchgfx::TEXT_ROTATE_180);
    titrePrincipal.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9MUY));

    titrePrincipal_1.setXY(102, 440);
    titrePrincipal_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titrePrincipal_1.setLinespacing(0);
    titrePrincipal_1.setRotation(touchgfx::TEXT_ROTATE_180);
    titrePrincipal_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NWJN));

    titreSecondaire_1.setXY(88, 246);
    titreSecondaire_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreSecondaire_1.setLinespacing(0);
    titreSecondaire_1.setRotation(touchgfx::TEXT_ROTATE_180);
    titreSecondaire_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VVYF));

    titreSecondaire_1_1.setXY(85, 174);
    titreSecondaire_1_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreSecondaire_1_1.setLinespacing(0);
    titreSecondaire_1_1.setRotation(touchgfx::TEXT_ROTATE_180);
    titreSecondaire_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TLB2));

    scalableImage1.setBitmap(touchgfx::Bitmap(BITMAP_SIGNATURE_ROBOTECH_COMPETITION_ID));
    scalableImage1.setPosition(0, 0, 272, 97);
    scalableImage1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage2.setBitmap(touchgfx::Bitmap(BITMAP_LOGOS_EQUIPE_ROBOTECH_ID));
    scalableImage2.setPosition(5, 410, 42, 66);
    scalableImage2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    add(__background);
    add(background);
    add(filigramme);
    add(boutonCompetition);
    add(boutonMaintenance);
    add(fondTitreSecondaire);
    add(titreSecondaire);
    add(titrePrincipal);
    add(titrePrincipal_1);
    add(titreSecondaire_1);
    add(titreSecondaire_1_1);
    add(scalableImage1);
    add(scalableImage2);
}

void AccueilViewBase::setupScreen()
{

}

void AccueilViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &boutonCompetition)
    {
        //affichageEcranCompetition
        //When boutonCompetition clicked change screen to Competition
        //Go to Competition with screen transition towards East
        application().gotoCompetitionScreenSlideTransitionEast();
    }
    else if (&src == &boutonMaintenance)
    {
        //affichageEcranMaintenance
        //When boutonMaintenance clicked change screen to Accueil
        //Go to Accueil with screen transition towards East
        application().gotoAccueilScreenSlideTransitionEast();
    }
}
