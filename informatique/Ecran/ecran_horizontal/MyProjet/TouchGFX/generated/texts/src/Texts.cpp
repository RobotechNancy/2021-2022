/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x43, 0x68, 0x6f, 0x69, 0x78, 0x20, 0x64, 0x75, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x20, 0x64, 0x65, 0x20, 0x66, 0x6f, 0x6e, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x6e, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x0, // @0 "Choix du mode de fonctionnement"
    0x47, 0x72, 0x61, 0x6e, 0x64, 0x20, 0x72, 0x6f, 0x62, 0x6f, 0x74, 0x20, 0x3a, 0x20, 0x2, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x28, 0x73, 0x29, 0x0, // @32 "Grand robot : <> point(s)"
    0x50, 0x65, 0x74, 0x69, 0x74, 0x20, 0x72, 0x6f, 0x62, 0x6f, 0x74, 0x20, 0x3a, 0x20, 0x2, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x28, 0x73, 0x29, 0x0, // @57 "Petit robot : <> point(s)"
    0x53, 0x63, 0x6f, 0x72, 0x65, 0x20, 0x74, 0x6f, 0x74, 0x61, 0x6c, 0x20, 0x3a, 0x20, 0x2, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x28, 0x73, 0x29, 0x0, // @82 "Score total : <> point(s)"
    0x53, 0x65, 0x72, 0x76, 0x6f, 0x6d, 0x6f, 0x74, 0x65, 0x75, 0x72, 0x20, 0x62, 0x72, 0x61, 0x73, 0x20, 0x72, 0xe9, 0x73, 0x69, 0x73, 0x74, 0x61, 0x6e, 0x63, 0x65, 0x0, // @107 "Servomoteur bras r?sistance"
    0x50, 0x72, 0x6f, 0x62, 0x6c, 0xe8, 0x6d, 0x65, 0x20, 0x6c, 0x75, 0x6d, 0x69, 0xe8, 0x72, 0x65, 0x20, 0x61, 0x6d, 0x62, 0x69, 0x61, 0x6e, 0x74, 0x65, 0x0, // @135 "Probl?me lumi?re ambiante"
    0x45, 0x74, 0x61, 0x74, 0x20, 0x64, 0x65, 0x20, 0x6c, 0x27, 0x69, 0x6e, 0x69, 0x74, 0x69, 0x61, 0x6c, 0x69, 0x73, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @161 "Etat de l'initialisation"
    0x43, 0x68, 0x6f, 0x69, 0x78, 0x20, 0x73, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x20, 0xe0, 0x20, 0x74, 0x65, 0x73, 0x74, 0x65, 0x72, 0x0, // @186 "Choix service ? tester"
    0x45, 0x71, 0x75, 0x69, 0x70, 0x65, 0x20, 0x52, 0x6f, 0x62, 0x6f, 0x74, 0x65, 0x63, 0x68, 0x20, 0x4e, 0x61, 0x6e, 0x63, 0x79, 0x0, // @209 "Equipe Robotech Nancy"
    0x4f, 0x62, 0x73, 0x74, 0x61, 0x63, 0x6c, 0x65, 0x20, 0x74, 0x72, 0x6f, 0x70, 0x20, 0x70, 0x72, 0x6f, 0x63, 0x68, 0x65, 0x0, // @231 "Obstacle trop proche"
    0x50, 0x61, 0x73, 0x20, 0x64, 0x65, 0x20, 0x63, 0x6f, 0x6d, 0x6d, 0x75, 0x6e, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @252 "Pas de communication"
    0x53, 0x75, 0x63, 0x63, 0xe8, 0x73, 0x20, 0x64, 0x65, 0x20, 0x6c, 0x61, 0x20, 0x6d, 0x65, 0x73, 0x75, 0x72, 0x65, 0x0, // @273 "Succ?s de la mesure"
    0x45, 0x66, 0x66, 0x65, 0x63, 0x74, 0x75, 0x65, 0x72, 0x20, 0x75, 0x6e, 0x20, 0x63, 0x79, 0x63, 0x6c, 0x65, 0x0, // @293 "Effectuer un cycle"
    0x4f, 0x64, 0x6f, 0x6d, 0xe9, 0x74, 0x72, 0x69, 0x65, 0x20, 0x72, 0x65, 0x6c, 0x61, 0x74, 0x69, 0x76, 0x65, 0x0, // @312 "Odom?trie relative"
    0x53, 0x69, 0x67, 0x6e, 0x61, 0x6c, 0x20, 0x74, 0x72, 0x6f, 0x70, 0x20, 0x62, 0x72, 0x75, 0x69, 0x74, 0xe9, 0x0, // @331 "Signal trop bruit?"
    0x43, 0x68, 0x6f, 0x69, 0x78, 0x20, 0x64, 0x65, 0x20, 0x6c, 0x27, 0xe9, 0x71, 0x75, 0x69, 0x70, 0x65, 0x0, // @350 "Choix de l'?quipe"
    0x43, 0x6f, 0x64, 0x65, 0x73, 0x20, 0x65, 0x72, 0x72, 0x65, 0x75, 0x72, 0x73, 0x20, 0x54, 0x6f, 0x46, 0x0, // @368 "Codes erreurs ToF"
    0x43, 0x6f, 0x6d, 0x6d, 0x75, 0x6e, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x43, 0x41, 0x4e, 0x0, // @386 "Communication CAN"
    0x43, 0x6f, 0x6d, 0x6d, 0x75, 0x6e, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x48, 0x46, 0x0, // @404 "Communication HF"
    0x43, 0x6f, 0x6e, 0x66, 0x69, 0x61, 0x6e, 0x63, 0x65, 0x20, 0x66, 0x61, 0x69, 0x62, 0x6c, 0x65, 0x0, // @421 "Confiance faible"
    0x4d, 0x65, 0x73, 0x75, 0x72, 0x65, 0x20, 0x3a, 0x20, 0x2, 0x0, // @438 "Mesure : <>"
    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x20, 0x63, 0x6f, 0x6e, 0x63, 0x65, 0x72, 0x6e, 0xe9, 0x0, // @449 "Service concern?"
    0x45, 0x72, 0x72, 0x65, 0x75, 0x72, 0x20, 0x48, 0x61, 0x72, 0x64, 0x77, 0x61, 0x72, 0x65, 0x0, // @466 "Erreur Hardware"
    0x45, 0x74, 0x61, 0x74, 0x20, 0x3a, 0x20, 0x2, 0x0, // @482 "Etat : <>"
    0x49, 0x6e, 0x69, 0x74, 0x69, 0x61, 0x6c, 0x69, 0x73, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @491 "Initialisation"
    0x69, 0x6e, 0x69, 0x74, 0x20, 0x6f, 0x64, 0x6f, 0x6d, 0x65, 0x74, 0x72, 0x69, 0x65, 0x0, // @506 "init odometrie"
    0x42, 0x61, 0x73, 0x65, 0x20, 0x72, 0x6f, 0x75, 0x6c, 0x61, 0x6e, 0x74, 0x65, 0x0, // @521 "Base roulante"
    0x43, 0x27, 0x65, 0x73, 0x74, 0x20, 0x70, 0x61, 0x72, 0x74, 0x69, 0x20, 0x21, 0x0, // @535 "C'est parti !"
    0x4e, 0x6f, 0x6e, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0xe9, 0x65, 0x0, // @549 "Non connect?e"
    0x53, 0x69, 0x67, 0x6e, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @563 "Signification"
    0x43, 0x61, 0x70, 0x74, 0x65, 0x75, 0x72, 0x73, 0x20, 0x54, 0x6f, 0x46, 0x0, // @577 "Capteurs ToF"
    0x4d, 0x6f, 0x64, 0x75, 0x6c, 0x65, 0x73, 0x20, 0x58, 0x42, 0x65, 0x65, 0x0, // @590 "Modules XBee"
    0x4e, 0x6f, 0x6e, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0xe9, 0x0, // @603 "Non connect?"
    0x50, 0x6f, 0x6d, 0x70, 0x65, 0x20, 0xe0, 0x20, 0x76, 0x69, 0x64, 0x65, 0x0, // @616 "Pompe ? vide"
    0x53, 0x65, 0x72, 0x76, 0x6f, 0x6d, 0x6f, 0x74, 0x65, 0x75, 0x72, 0x73, 0x0, // @629 "Servomoteurs"
    0x43, 0x6f, 0x64, 0x65, 0x20, 0x65, 0x72, 0x72, 0x65, 0x75, 0x72, 0x0, // @642 "Code erreur"
    0x43, 0x6f, 0x6d, 0x70, 0xe9, 0x74, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @654 "Comp?tition"
    0x4d, 0x61, 0x69, 0x6e, 0x74, 0x65, 0x6e, 0x61, 0x6e, 0x63, 0x65, 0x0, // @666 "Maintenance"
    0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x31, 0x2e, 0x30, 0x0, // @678 "Version 1.0"
    0xe9, 0x63, 0x72, 0x61, 0x6e, 0x20, 0x73, 0x63, 0x6f, 0x72, 0x65, 0x0, // @690 "?cran score"
    0x47, 0x79, 0x72, 0x6f, 0x2f, 0x4f, 0x70, 0x74, 0x2e, 0x0, // @702 "Gyro/Opt."
    0x4f, 0x64, 0x6f, 0x6d, 0xe9, 0x74, 0x72, 0x69, 0x65, 0x0, // @712 "Odom?trie"
    0x41, 0x75, 0x74, 0x6f, 0x6d, 0x61, 0x74, 0x65, 0x0, // @722 "Automate"
    0x4d, 0x6f, 0x74, 0x2e, 0x20, 0x50, 0x41, 0x50, 0x0, // @731 "Mot. PAP"
    0x42, 0x75, 0x73, 0x20, 0x43, 0x41, 0x4e, 0x0, // @740 "Bus CAN"
    0x4d, 0x43, 0x55, 0x36, 0x30, 0x35, 0x30, 0x0, // @748 "MCU6050"
    0x50, 0x4d, 0x57, 0x33, 0x39, 0x30, 0x31, 0x0, // @756 "PMW3901"
    0x56, 0x61, 0x6c, 0x69, 0x64, 0x65, 0x72, 0x0, // @764 "Valider"
    0x4c, 0x69, 0x64, 0x61, 0x72, 0x0, // @772 "Lidar"
    0x50, 0x6f, 0x6d, 0x70, 0x65, 0x0, // @778 "Pompe"
    0x53, 0x65, 0x72, 0x76, 0x6f, 0x0, // @784 "Servo"
    0x42, 0x61, 0x73, 0x65, 0x0, // @790 "Base"
    0x45, 0x52, 0x52, 0x0, // @795 "ERR"
    0x32, 0x0, // @799 "2"
    0x33, 0x0, // @801 "3"
    0x34, 0x0, // @803 "4"
    0x35, 0x0 // @805 "5"
};
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}