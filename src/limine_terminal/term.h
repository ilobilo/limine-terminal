#ifndef __LIB__GTERM_H__
#define __LIB__GTERM_H__

#include <limine_terminal/image.h>

#include <terminal/backends/framebuffer.h>
#include <terminal/term.h>

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define DEFAULT_FONT_SPACING 1
#define DEFAULT_FONT_SCALE_X 1
#define DEFAULT_FONT_SCALE_Y 1

#define DEFAULT_ANSI_COLOURS { 0x00000000, 0x00AA0000, 0x0000AA00, 0x00AA5500, 0x000000AA, 0x00AA00AA, 0x0000AAAA, 0x00AAAAAA }
#define DEFAULT_ANSI_BRIGHT_COLOURS { 0x00555555, 0x00FF5555, 0x0055FF55, 0x00FFFF55, 0x005555FF, 0x00FF55FF, 0x0055FFFF, 0x00FFFFFF }

#define DEFAULT_BACKGROUND 0xA0000000
#define DEFAULT_FOREGROUND 0x00AAAAAA

#define DEFAULT_BACKGROUND_BRIGHT 0xA0555555
#define DEFAULT_FOREGROUND_BRIGHT 0x00FFFFFF

#define DEFAULT_MARGIN 64
#define DEFAULT_MARGIN_GRADIENT 4

#define DEFAULT_BACKDROP 0x00000000

struct framebuffer_t
{
    uintptr_t address;
    uint64_t width;
    uint64_t height;
    uint64_t pitch;
};

struct font_t
{
    uintptr_t address;
    uint8_t width;
    uint8_t height;
    uint8_t spacing;
    uint8_t scale_x;
    uint8_t scale_y;
};

struct style_t
{
    uint32_t ansi_colours[8];
    uint32_t ansi_bright_colours[8];
    uint32_t background;
    uint32_t foreground;
    uint32_t background_bright;
    uint32_t foreground_bright;
    uint16_t margin;
    uint16_t margin_gradient;
};

struct background_t
{
    struct image_t *background;
    enum image_style style;
    uint32_t backdrop;
};


#ifdef __cplusplus
extern "C" {
#endif

struct term_context *term_init(struct framebuffer_t frm, struct font_t font, struct style_t style, struct background_t backg);

#ifdef __cplusplus
}
#endif

#endif