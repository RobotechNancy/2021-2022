/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/maintenancecan_screen/MaintenanceCanViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


MaintenanceCanViewBase::MaintenanceCanViewBase() :
    flexButtonCallback(this, &MaintenanceCanViewBase::flexButtonCallbackHandler)
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
    texteCategorie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B0XQ));

    fondCategorie_1.setPosition(146, 8, 210, 44);
    fondCategorie_1.setColor(touchgfx::Color::getColorFromRGB(238, 90, 36));
    fondCategorie_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_1.setBorderSize(3);

    texteCategorie_1.setXY(214, 20);
    texteCategorie_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_1.setLinespacing(0);
    texteCategorie_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RLVP));

    fondCategorie_2.setPosition(361, 8, 114, 44);
    fondCategorie_2.setColor(touchgfx::Color::getColorFromRGB(255, 195, 18));
    fondCategorie_2.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fondCategorie_2.setBorderSize(3);

    texteCategorie_2.setXY(373, 20);
    texteCategorie_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    texteCategorie_2.setLinespacing(0);
    texteCategorie_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DGC0));

    scalableImage1.setBitmap(touchgfx::Bitmap(BITMAP_STM32L432_ID));
    scalableImage1.setPosition(12, 111, 100, 37);
    scalableImage1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage1_1.setBitmap(touchgfx::Bitmap(BITMAP_STM32L432_ID));
    scalableImage1_1.setPosition(190, 203, 100, 37);
    scalableImage1_1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage1_2_1.setBitmap(touchgfx::Bitmap(BITMAP_STM32L432_ID));
    scalableImage1_2_1.setPosition(372, 107, 100, 37);
    scalableImage1_2_1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage2.setBitmap(touchgfx::Bitmap(BITMAP_RASPI_ID));
    scalableImage2.setPosition(210, 63, 60, 91);
    scalableImage2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    fleche1.setPosition(186, 105, 51, 38);
    fleche1.setOrigin(0.000f, 0.000f);
    fleche1.setScale(0.400f, 0.400f);
    fleche1.setAngle(0.000f);
    fleche1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche1.setPainter(fleche1Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche1Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 60.000f, 40.000f } };
    fleche1.setShape(fleche1Points);

    ligneFleche1_1.setPosition(123, 116, 75, 16);
    ligneFleche1_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1_1.setPainter(ligneFleche1_1Painter);
    ligneFleche1_1.setStart(0, 5);
    ligneFleche1_1.setEnd(150, 5);
    ligneFleche1_1.setLineWidth(4);
    ligneFleche1_1.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    fleche2.setPosition(123, 86, 47, 42);
    fleche2.setOrigin(0.000f, 0.000f);
    fleche2.setScale(0.400f, 0.400f);
    fleche2.setAngle(0.000f);
    fleche2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche2.setPainter(fleche2Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche2Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 0.000f, 40.000f } };
    fleche2.setShape(fleche2Points);

    titreBaseRoulante_1.setXY(35, 52);
    titreBaseRoulante_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreBaseRoulante_1.setLinespacing(0);
    titreBaseRoulante_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1UZY));

    titreOdometrie.setXY(183, 241);
    titreOdometrie.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreOdometrie.setLinespacing(0);
    titreOdometrie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O7UK));

    titreAutomate.setXY(369, 77);
    titreAutomate.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreAutomate.setLinespacing(0);
    titreAutomate.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AYHZ));

    fleche1_1.setPosition(337, 87, 51, 38);
    fleche1_1.setOrigin(0.000f, 0.000f);
    fleche1_1.setScale(0.400f, 0.400f);
    fleche1_1.setAngle(0.000f);
    fleche1_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche1_1.setPainter(fleche1_1Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche1_1Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 60.000f, 40.000f } };
    fleche1_1.setShape(fleche1_1Points);

    ligneFleche1_1_1.setPosition(285, 117, 75, 16);
    ligneFleche1_1_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1_1_1.setPainter(ligneFleche1_1_1Painter);
    ligneFleche1_1_1.setStart(0, 5);
    ligneFleche1_1_1.setEnd(150, 5);
    ligneFleche1_1_1.setLineWidth(4);
    ligneFleche1_1_1.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    fleche2_1.setPosition(275, 106, 47, 42);
    fleche2_1.setOrigin(0.000f, 0.000f);
    fleche2_1.setScale(0.400f, 0.400f);
    fleche2_1.setAngle(0.000f);
    fleche2_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche2_1.setPainter(fleche2_1Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche2_1Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 0.000f, 40.000f } };
    fleche2_1.setShape(fleche2_1Points);

    ligneFleche1_1_2.setPosition(135, 96, 75, 16);
    ligneFleche1_1_2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1_1_2.setPainter(ligneFleche1_1_2Painter);
    ligneFleche1_1_2.setStart(0, 5);
    ligneFleche1_1_2.setEnd(150, 5);
    ligneFleche1_1_2.setLineWidth(4);
    ligneFleche1_1_2.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    ligneFleche1_1_1_1.setPosition(275, 98, 75, 16);
    ligneFleche1_1_1_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1_1_1_1.setPainter(ligneFleche1_1_1_1Painter);
    ligneFleche1_1_1_1.setStart(0, 5);
    ligneFleche1_1_1_1.setEnd(150, 5);
    ligneFleche1_1_1_1.setLineWidth(4);
    ligneFleche1_1_1_1.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    boxCanRaspiBase.setPosition(110, 56, 100, 30);
    boxCanRaspiBase.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCanRaspiBase.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxCanRaspiBase.setBorderSize(2);

    testCanRaspiBase.setPosition(114, 61, 92, 21);
    testCanRaspiBase.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    testCanRaspiBase.setLinespacing(0);
    Unicode::snprintf(testCanRaspiBaseBuffer, TESTCANRASPIBASE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_FBNJ).getText());
    testCanRaspiBase.setWildcard(testCanRaspiBaseBuffer);
    testCanRaspiBase.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GEIU));

    boxCanBaseRaspi.setPosition(111, 138, 100, 30);
    boxCanBaseRaspi.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCanBaseRaspi.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxCanBaseRaspi.setBorderSize(2);

    testCanBaseRaspi.setPosition(115, 142, 92, 21);
    testCanBaseRaspi.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    testCanBaseRaspi.setLinespacing(0);
    Unicode::snprintf(testCanBaseRaspiBuffer, TESTCANBASERASPI_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_HMGP).getText());
    testCanBaseRaspi.setWildcard(testCanBaseRaspiBuffer);
    testCanBaseRaspi.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ARDY));

    boxCanAutomateRaspi.setPosition(270, 138, 100, 30);
    boxCanAutomateRaspi.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCanAutomateRaspi.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxCanAutomateRaspi.setBorderSize(2);

    testCanAutomateRaspi.setPosition(276, 143, 89, 19);
    testCanAutomateRaspi.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    testCanAutomateRaspi.setLinespacing(0);
    Unicode::snprintf(testCanAutomateRaspiBuffer, TESTCANAUTOMATERASPI_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_CXQX).getText());
    testCanAutomateRaspi.setWildcard(testCanAutomateRaspiBuffer);
    testCanAutomateRaspi.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0RKS));

    boxCanRaspiAutomate.setPosition(269, 58, 100, 30);
    boxCanRaspiAutomate.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCanRaspiAutomate.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxCanRaspiAutomate.setBorderSize(2);

    testCanRaspiAutomate.setPosition(273, 63, 90, 17);
    testCanRaspiAutomate.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    testCanRaspiAutomate.setLinespacing(0);
    Unicode::snprintf(testCanRaspiAutomateBuffer, TESTCANRASPIAUTOMATE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IPGY).getText());
    testCanRaspiAutomate.setWildcard(testCanRaspiAutomateBuffer);
    testCanRaspiAutomate.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8DB6));

    boxCanOdometrieRaspi.setPosition(94, 188, 100, 30);
    boxCanOdometrieRaspi.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCanOdometrieRaspi.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxCanOdometrieRaspi.setBorderSize(2);

    testCanOdometrieRaspi.setPosition(98, 193, 92, 21);
    testCanOdometrieRaspi.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    testCanOdometrieRaspi.setLinespacing(0);
    Unicode::snprintf(testCanOdometrieRaspiBuffer, TESTCANODOMETRIERASPI_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_P6PO).getText());
    testCanOdometrieRaspi.setWildcard(testCanOdometrieRaspiBuffer);
    testCanOdometrieRaspi.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VNCE));

    boxCanRaspiOdometrie.setPosition(286, 188, 100, 30);
    boxCanRaspiOdometrie.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxCanRaspiOdometrie.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxCanRaspiOdometrie.setBorderSize(2);

    testCanRaspiOdometrie.setPosition(290, 193, 92, 21);
    testCanRaspiOdometrie.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    testCanRaspiOdometrie.setLinespacing(0);
    Unicode::snprintf(testCanRaspiOdometrieBuffer, TESTCANRASPIODOMETRIE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_RBQC).getText());
    testCanRaspiOdometrie.setWildcard(testCanRaspiOdometrieBuffer);
    testCanRaspiOdometrie.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A34J));

    ligneFleche1_1_3.setPosition(175, 130, 79, 100);
    ligneFleche1_1_3Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1_1_3.setPainter(ligneFleche1_1_3Painter);
    ligneFleche1_1_3.setStart(28, 89);
    ligneFleche1_1_3.setEnd(56, 5);
    ligneFleche1_1_3.setLineWidth(4);
    ligneFleche1_1_3.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    ligneFleche1_1_3_1.setPosition(190, 129, 100, 100);
    ligneFleche1_1_3_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ligneFleche1_1_3_1.setPainter(ligneFleche1_1_3_1Painter);
    ligneFleche1_1_3_1.setStart(87, 89);
    ligneFleche1_1_3_1.setEnd(57, 6);
    ligneFleche1_1_3_1.setLineWidth(4);
    ligneFleche1_1_3_1.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);

    fleche1_2.setPosition(262, 196, 36, 36);
    fleche1_2.setOrigin(20.000f, 0.000f);
    fleche1_2.setScale(0.400f, 0.400f);
    fleche1_2.setAngle(65.000f);
    fleche1_2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche1_2.setPainter(fleche1_2Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche1_2Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 60.000f, 40.000f } };
    fleche1_2.setShape(fleche1_2Points);

    fleche1_3.setPosition(208, 121, 41, 28);
    fleche1_3.setOrigin(1.700f, 20.100f);
    fleche1_3.setScale(0.400f, 0.400f);
    fleche1_3.setAngle(-67.400f);
    fleche1_3Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fleche1_3.setPainter(fleche1_3Painter);
    const touchgfx::AbstractShape::ShapePoint<float> fleche1_3Points[4] = { { 30.000f, 0.000f }, { 30.000f, 40.000f }, { 30.000f, 80.000f }, { 60.000f, 40.000f } };
    fleche1_3.setShape(fleche1_3Points);

    titreBaseRoulante_2.setXY(16, 81);
    titreBaseRoulante_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    titreBaseRoulante_2.setLinespacing(0);
    titreBaseRoulante_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EFD0));

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
    add(scalableImage1);
    add(scalableImage1_1);
    add(scalableImage1_2_1);
    add(scalableImage2);
    add(fleche1);
    add(ligneFleche1_1);
    add(fleche2);
    add(titreBaseRoulante_1);
    add(titreOdometrie);
    add(titreAutomate);
    add(fleche1_1);
    add(ligneFleche1_1_1);
    add(fleche2_1);
    add(ligneFleche1_1_2);
    add(ligneFleche1_1_1_1);
    add(boxCanRaspiBase);
    add(testCanRaspiBase);
    add(boxCanBaseRaspi);
    add(testCanBaseRaspi);
    add(boxCanAutomateRaspi);
    add(testCanAutomateRaspi);
    add(boxCanRaspiAutomate);
    add(testCanRaspiAutomate);
    add(boxCanOdometrieRaspi);
    add(testCanOdometrieRaspi);
    add(boxCanRaspiOdometrie);
    add(testCanRaspiOdometrie);
    add(ligneFleche1_1_3);
    add(ligneFleche1_1_3_1);
    add(fleche1_2);
    add(fleche1_3);
    add(titreBaseRoulante_2);
}

void MaintenanceCanViewBase::setupScreen()
{

}

void MaintenanceCanViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
