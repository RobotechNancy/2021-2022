/**
******************************************************************************
* File Name : TouchGFXConfiguration.cpp
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under Ultimate Liberty license
* SLA0044, the "License"; You may not use this file except in compliance with
* the License. You may obtain a copy of the License at:
* www.st.com/SLA0044
*
******************************************************************************
*/
#include <texts/TypedTextDatabase.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <BitmapDatabase.hpp>
#include <platform/driver/lcd/LCD24bpp.hpp>
#include "STM32DMA.hpp"
#include "../TouchGFXHAL.hpp"
#include "../STM32TouchController.hpp"
#include <stm32f7xx_hal.h>

extern "C" void touchgfx_init();
extern "C" void touchgfx_taskEntry();

static STM32TouchController tc;
static STM32F7DMA dma;
static LCD24bpp display;
static ApplicationFontProvider fontProvider;
static Texts texts;
static TouchGFXHAL hal(dma, display, tc, 480, 272);

void touchgfx_init()
{
  Bitmap::registerBitmapDatabase(BitmapDatabase::getInstance(), BitmapDatabase::getInstanceSize());
  TypedText::registerTexts(&texts);
  Texts::setLanguage(0);

  FontManager::setFontProvider(&fontProvider);

  FrontendHeap& heap = FrontendHeap::getInstance();
  (void)heap; // we need to obtain the reference above to initialize the frontend heap.

  hal.initialize();
}

void touchgfx_taskEntry()
{
 /*
  * Main event loop. Will wait for VSYNC signal, and then process next frame. Call
  * this function from your GUI task.
  *
  * Note This function never returns
  */
  hal.taskEntry();
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
