/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/maintenancexbee_screen/MaintenanceXbeeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


MaintenanceXbeeViewBase::MaintenanceXbeeViewBase() :
    flexButtonCallback(this, &MaintenanceXbeeViewBase::flexButtonCallbackHandler)
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
    texteCategorie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J188));

    fondCategorie_1.setPosition(146, 8, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(238, 90, 36));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(193, 20);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8VEY));

    fondCategorie_2.setPosition(361, 8, 114, 44);
    fondCategorie_2.setColor(touchgfx::Color::getColorFromRGB(255, 195, 18));
    fondCategorie_2.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_2.setBorderSize(3);

    texteCategorie_2.setXY(373, 20);
    texteCategorie_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_2.setLinespacing(0);
    texteCategorie_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S8WE));

    grandRobot.setBitmap(touchgfx::Bitmap(BITMAP_GRAND_ROBOT_ID));
    grandRobot.setPosition(3, 84, 103, 139);
    grandRobot.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    petitRobot.setBitmap(touchgfx::Bitmap(BITMAP_PETIT_ROBOT_ID));
    petitRobot.setPosition(383, 88, 97, 130);
    petitRobot.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    moduleXbeeGrand.setBitmap(touchgfx::Bitmap(BITMAP_XBEE_ID));
    moduleXbeeGrand.setPosition(112, 128, 45, 50);
    moduleXbeeGrand.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    moduleXbeePetit.setBitmap(touchgfx::Bitmap(BITMAP_XBEE_ID));
    moduleXbeePetit.setPosition(343, 128, 45, 50);
    moduleXbeePetit.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    ligneFleche1.setPosition(173, 136, 156, 15);
    ligneFleche1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1.setPainter(ligneFleche1Painter);
    ligneFleche1.setStart(0, 5);
    ligneFleche1.setEnd(150, 5);
    ligneFleche1.setLineWidth(4);
    ligneFleche1.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    ligneFleche2.setPosition(173, 163, 156, 15);
    ligneFleche2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche2.setPainter(ligneFleche2Painter);
    ligneFleche2.setStart(0, 5);
    ligneFleche2.setEnd(150, 5);
    ligneFleche2.setLineWidth(4);
    ligneFleche2.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    fleche1.setPosition(303, 126, 47, 42);
    fleche1.setOrigin(0.000f, 0.000f);
    fleche1.setScale(0.400f, 0.400f);
    fleche1.setAngle(0.000f);
    fleche1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche1.setPainter(fleche1Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche1Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 60.000f, 40.000f } };
    fleche1.setShape(fleche1Points);

    fleche2.setPosition(170, 153, 47, 42);
    fleche2.setOrigin(0.000f, 0.000f);
    fleche2.setScale(0.400f, 0.400f);
    fleche2.setAngle(0.000f);
    fleche2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche2.setPainter(fleche2Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche2Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 0.000f, 40.000f } };
    fleche2.setShape(fleche2Points);

    boxXbeePetitGrand.setPosition(167, 184, 153, 34);
    boxXbeePetitGrand.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxXbeePetitGrand.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxXbeePetitGrand.setBorderSize(2);

    texteXbeePetitGrand.setPosition(173, 191, 141, 20);
    texteXbeePetitGrand.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteXbeePetitGrand.setLinespacing(0);
    Unicode::snprintf(texteXbeePetitGrandBuffer, TEXTEXBEEPETITGRAND_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_RCPF).getText());
    texteXbeePetitGrand.setWildcard(texteXbeePetitGrandBuffer);
    texteXbeePetitGrand.setTypedText(touchgfx::TypedText(T___SINGLEUSE_99NX));

    boxXbeeGrandPetit.setPosition(167, 92, 153, 34);
    boxXbeeGrandPetit.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxXbeeGrandPetit.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxXbeeGrandPetit.setBorderSize(2);

    texteXbeeGrandPetit.setPosition(173, 99, 141, 21);
    texteXbeeGrandPetit.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteXbeeGrandPetit.setLinespacing(0);
    Unicode::snprintf(texteXbeeGrandPetitBuffer, TEXTEXBEEGRANDPETIT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_I7SI).getText());
    texteXbeeGrandPetit.setWildcard(texteXbeeGrandPetitBuffer);
    texteXbeeGrandPetit.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5ZMQ));

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
    add(grandRobot);
    add(petitRobot);
    add(moduleXbeeGrand);
    add(moduleXbeePetit);
    add(ligneFleche1);
    add(ligneFleche2);
    add(fleche1);
    add(fleche2);
    add(boxXbeePetitGrand);
    add(texteXbeePetitGrand);
    add(boxXbeeGrandPetit);
    add(texteXbeeGrandPetit);
}

void MaintenanceXbeeViewBase::setupScreen()
{

}

void MaintenanceXbeeViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
        //When boutonRetour clicked change screen to Maintenance
        //Go to Maintenance with screen transition towards West
        application().gotoMaintenanceScreenSlideTransitionWest();
    }
}