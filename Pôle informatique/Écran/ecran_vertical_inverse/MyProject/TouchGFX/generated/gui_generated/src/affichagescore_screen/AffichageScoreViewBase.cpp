/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/affichagescore_screen/AffichageScoreViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

AffichageScoreViewBase::AffichageScoreViewBase() :
    flexButtonCallback(this, &AffichageScoreViewBase::flexButtonCallbackHandler)
{

    __background.setPosition(0, 0, 272, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background.setPosition(0, 0, 272, 480);
    background.setColor(touchgfx::Color::getColorFromRGB(232, 232, 232));

    filigramme.setBitmap(touchgfx::Bitmap(BITMAP_LOGO_SIMPLIFIE_ROBOTECH_ID));
    filigramme.setPosition(0, 0, 272, 480);
    filigramme.setAlpha(30);
    filigramme.setOffset(0, 0);

    boutonAccueil.setBoxWithBorderPosition(0, 0, 43, 43);
    boutonAccueil.setBorderSize(5);
    boutonAccueil.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonAccueil.setIconBitmaps(Bitmap(BITMAP_HOME_ID), Bitmap(BITMAP_HOME_ID));
    boutonAccueil.setIconXY(9, 8);
    boutonAccueil.setPosition(229, 0, 43, 43);
    boutonAccueil.setAction(flexButtonCallback);

    boutonRetour.setBoxWithBorderPosition(0, 0, 43, 43);
    boutonRetour.setBorderSize(5);
    boutonRetour.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 98, 102), touchgfx::Color::getColorFromRGB(0, 98, 102), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(119, 140, 163));
    boutonRetour.setIconBitmaps(Bitmap(BITMAP_RIGHT_ARROW_ID), Bitmap(BITMAP_RIGHT_ARROW_ID));
    boutonRetour.setIconXY(9, 9);
    boutonRetour.setPosition(0, 0, 43, 43);
    boutonRetour.setAction(flexButtonCallback);

    boxWithBorder1.setPosition(27, 88, 219, 94);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 238, 84));
    boxWithBorder1.setBorderSize(5);

    fondScoreGrandRobot.setPosition(99, 222, 160, 37);
    fondScoreGrandRobot.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondScoreGrandRobot.setAlpha(0);

    fondScorePetitRobot_1_1.setPosition(99, 183, 160, 39);
    fondScorePetitRobot_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondScorePetitRobot_1_1.setAlpha(0);

    fondScorePetitRobot.setPosition(99, 337, 160, 39);
    fondScorePetitRobot.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondScorePetitRobot.setAlpha(0);

    scoreTotal.setPosition(36, 104, 201, 27);
    scoreTotal.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    scoreTotal.setLinespacing(0);
    scoreTotal.setRotation(touchgfx::TEXT_ROTATE_180);
    Unicode::snprintf(scoreTotalBuffer, SCORETOTAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_H5F1).getText());
    scoreTotal.setWildcard(scoreTotalBuffer);
    scoreTotal.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KN2V));

    scoreGrandRobot.setPosition(107, 191, 145, 22);
    scoreGrandRobot.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    scoreGrandRobot.setLinespacing(0);
    scoreGrandRobot.setRotation(touchgfx::TEXT_ROTATE_180);
    scoreGrandRobot.setAlpha(0);
    Unicode::snprintf(scoreGrandRobotBuffer, SCOREGRANDROBOT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5492).getText());
    scoreGrandRobot.setWildcard(scoreGrandRobotBuffer);
    scoreGrandRobot.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5ICM));

    imageGrandRobot.setBitmap(touchgfx::Bitmap(BITMAP_GRAND_ROBOT_ID));
    imageGrandRobot.setPosition(15, 183, 73, 93);
    imageGrandRobot.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    imageGrandRobot.setAlpha(0);

    imagePetitRobot.setBitmap(touchgfx::Bitmap(BITMAP_PETIT_ROBOT_ID));
    imagePetitRobot.setPosition(71, 205, 131, 171);
    imagePetitRobot.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scoreTotal_1.setPosition(36, 137, 201, 27);
    scoreTotal_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    scoreTotal_1.setLinespacing(0);
    scoreTotal_1.setRotation(touchgfx::TEXT_ROTATE_180);
    scoreTotal_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XYBT));

    fondScorePetitRobot_1.setPosition(99, 298, 160, 39);
    fondScorePetitRobot_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondScorePetitRobot_1.setAlpha(0);

    scorePetitRobot_1.setPosition(107, 345, 144, 22);
    scorePetitRobot_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    scorePetitRobot_1.setLinespacing(0);
    scorePetitRobot_1.setRotation(touchgfx::TEXT_ROTATE_180);
    scorePetitRobot_1.setAlpha(0);
    scorePetitRobot_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FXX9));

    scorePetitRobot_1_1.setPosition(107, 229, 144, 22);
    scorePetitRobot_1_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    scorePetitRobot_1_1.setLinespacing(0);
    scorePetitRobot_1_1.setRotation(touchgfx::TEXT_ROTATE_180);
    scorePetitRobot_1_1.setAlpha(0);
    scorePetitRobot_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_85XP));

    fondCategorie_1.setPosition(31, 420, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 138, 150));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(62, 432);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setRotation(touchgfx::TEXT_ROTATE_180);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FM8E));

    scorePetitRobot.setPosition(107, 306, 144, 22);
    scorePetitRobot.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    scorePetitRobot.setLinespacing(0);
    scorePetitRobot.setRotation(touchgfx::TEXT_ROTATE_180);
    scorePetitRobot.setAlpha(0);
    Unicode::snprintf(scorePetitRobotBuffer, SCOREPETITROBOT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_N2V1).getText());
    scorePetitRobot.setWildcard(scorePetitRobotBuffer);
    scorePetitRobot.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U9JP));

    add(__background);
    add(background);
    add(filigramme);
    add(boutonAccueil);
    add(boutonRetour);
    add(boxWithBorder1);
    add(fondScoreGrandRobot);
    add(fondScorePetitRobot_1_1);
    add(fondScorePetitRobot);
    add(scoreTotal);
    add(scoreGrandRobot);
    add(imageGrandRobot);
    add(imagePetitRobot);
    add(scoreTotal_1);
    add(fondScorePetitRobot_1);
    add(scorePetitRobot_1);
    add(scorePetitRobot_1_1);
    add(fondCategorie_1);
    add(texteCategorie_1);
    add(scorePetitRobot);
}

void AffichageScoreViewBase::setupScreen()
{

}

void AffichageScoreViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
}
