/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINTENANCECANVIEWBASE_HPP
#define MAINTENANCECANVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/maintenancecan_screen/MaintenanceCanPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/canvas/Shape.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class MaintenanceCanViewBase : public touchgfx::View<MaintenanceCanPresenter>
{
public:
    MaintenanceCanViewBase();
    virtual ~MaintenanceCanViewBase() {}
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
    touchgfx::ScalableImage scalableImage1;
    touchgfx::ScalableImage scalableImage1_1;
    touchgfx::ScalableImage scalableImage1_2_1;
    touchgfx::ScalableImage scalableImage2;
    touchgfx::Shape<4> fleche1;
    touchgfx::PainterRGB888 fleche1Painter;
    touchgfx::Line ligneFleche1_1;
    touchgfx::PainterRGB888 ligneFleche1_1Painter;
    touchgfx::Shape<4> fleche2;
    touchgfx::PainterRGB888 fleche2Painter;
    touchgfx::TextArea titreBaseRoulante_1;
    touchgfx::TextArea titreOdometrie;
    touchgfx::TextArea titreAutomate;
    touchgfx::Shape<4> fleche1_1;
    touchgfx::PainterRGB888 fleche1_1Painter;
    touchgfx::Line ligneFleche1_1_1;
    touchgfx::PainterRGB888 ligneFleche1_1_1Painter;
    touchgfx::Shape<4> fleche2_1;
    touchgfx::PainterRGB888 fleche2_1Painter;
    touchgfx::Line ligneFleche1_1_2;
    touchgfx::PainterRGB888 ligneFleche1_1_2Painter;
    touchgfx::Line ligneFleche1_1_1_1;
    touchgfx::PainterRGB888 ligneFleche1_1_1_1Painter;
    touchgfx::BoxWithBorder boxCanRaspiBase;
    touchgfx::TextAreaWithOneWildcard testCanRaspiBase;
    touchgfx::BoxWithBorder boxCanBaseRaspi;
    touchgfx::TextAreaWithOneWildcard testCanBaseRaspi;
    touchgfx::BoxWithBorder boxCanAutomateRaspi;
    touchgfx::TextAreaWithOneWildcard testCanAutomateRaspi;
    touchgfx::BoxWithBorder boxCanRaspiAutomate;
    touchgfx::TextAreaWithOneWildcard testCanRaspiAutomate;
    touchgfx::BoxWithBorder boxCanOdometrieRaspi;
    touchgfx::TextAreaWithOneWildcard testCanOdometrieRaspi;
    touchgfx::BoxWithBorder boxCanRaspiOdometrie;
    touchgfx::TextAreaWithOneWildcard testCanRaspiOdometrie;
    touchgfx::Line ligneFleche1_1_3;
    touchgfx::PainterRGB888 ligneFleche1_1_3Painter;
    touchgfx::Line ligneFleche1_1_3_1;
    touchgfx::PainterRGB888 ligneFleche1_1_3_1Painter;
    touchgfx::Shape<4> fleche1_2;
    touchgfx::PainterRGB888 fleche1_2Painter;
    touchgfx::Shape<4> fleche1_3;
    touchgfx::PainterRGB888 fleche1_3Painter;
    touchgfx::TextArea titreBaseRoulante_2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TESTCANRASPIBASE_SIZE = 17;
    touchgfx::Unicode::UnicodeChar testCanRaspiBaseBuffer[TESTCANRASPIBASE_SIZE];
    static const uint16_t TESTCANBASERASPI_SIZE = 17;
    touchgfx::Unicode::UnicodeChar testCanBaseRaspiBuffer[TESTCANBASERASPI_SIZE];
    static const uint16_t TESTCANAUTOMATERASPI_SIZE = 17;
    touchgfx::Unicode::UnicodeChar testCanAutomateRaspiBuffer[TESTCANAUTOMATERASPI_SIZE];
    static const uint16_t TESTCANRASPIAUTOMATE_SIZE = 17;
    touchgfx::Unicode::UnicodeChar testCanRaspiAutomateBuffer[TESTCANRASPIAUTOMATE_SIZE];
    static const uint16_t TESTCANODOMETRIERASPI_SIZE = 17;
    touchgfx::Unicode::UnicodeChar testCanOdometrieRaspiBuffer[TESTCANODOMETRIERASPI_SIZE];
    static const uint16_t TESTCANRASPIODOMETRIE_SIZE = 17;
    touchgfx::Unicode::UnicodeChar testCanRaspiOdometrieBuffer[TESTCANRASPIODOMETRIE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MaintenanceCanViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // MAINTENANCECANVIEWBASE_HPP
