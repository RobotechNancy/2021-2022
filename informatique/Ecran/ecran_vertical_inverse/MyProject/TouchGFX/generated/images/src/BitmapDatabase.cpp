// 4.19.1 0x0925da6e
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_bouton_jaune[]; // BITMAP_BOUTON_JAUNE_ID = 0, Size: 176x76 pixels
extern const unsigned char image_bouton_violet[]; // BITMAP_BOUTON_VIOLET_ID = 1, Size: 176x76 pixels
extern const unsigned char image_grand_robot[]; // BITMAP_GRAND_ROBOT_ID = 2, Size: 439x585 pixels
extern const unsigned char image_home[]; // BITMAP_HOME_ID = 3, Size: 24x24 pixels
extern const unsigned char image_information[]; // BITMAP_INFORMATION_ID = 4, Size: 6x22 pixels
extern const unsigned char image_left_arrow[]; // BITMAP_LEFT_ARROW_ID = 5, Size: 24x24 pixels
extern const unsigned char image_logo_3d_advance[]; // BITMAP_LOGO_3D_ADVANCE_ID = 6, Size: 200x195 pixels
extern const unsigned char image_logo_rs[]; // BITMAP_LOGO_RS_ID = 7, Size: 200x168 pixels
extern const unsigned char image_logo_simplifie_robotech[]; // BITMAP_LOGO_SIMPLIFIE_ROBOTECH_ID = 8, Size: 125x116 pixels
extern const unsigned char image_logos_equipe_robotech[]; // BITMAP_LOGOS_EQUIPE_ROBOTECH_ID = 9, Size: 181x277 pixels
extern const unsigned char image_petit_robot[]; // BITMAP_PETIT_ROBOT_ID = 10, Size: 502x759 pixels
extern const unsigned char image_right_arrow[]; // BITMAP_RIGHT_ARROW_ID = 11, Size: 24x24 pixels
extern const unsigned char image_signature_robotech_competition[]; // BITMAP_SIGNATURE_ROBOTECH_COMPETITION_ID = 12, Size: 400x137 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_bouton_jaune, 0, 176, 76, 0, 0, 176, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 76, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_bouton_violet, 0, 176, 76, 0, 0, 176, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 76, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_grand_robot, 0, 439, 585, 54, 130, 212, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 168, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_home, 0, 24, 24, 3, 8, 16, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 10, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_information, 0, 6, 22, 0, 6, 6, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 16, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_left_arrow, 0, 24, 24, 7, 8, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 8, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_logo_3d_advance, 0, 200, 195, 85, 83, 27, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 21, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_logo_rs, 0, 200, 168, 9, 7, 183, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 154, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_logo_simplifie_robotech, 0, 125, 116, 46, 108, 33, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 5, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_logos_equipe_robotech, 0, 181, 277, 14, 190, 162, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 76, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_petit_robot, 0, 502, 759, 115, 129, 250, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 399, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_right_arrow, 0, 24, 24, 13, 8, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 8, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_signature_robotech_competition, 0, 400, 137, 285, 16, 106, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 104, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase