#ifndef __LIB__GTERM_H__
#define __LIB__GTERM_H__

#include <limine_terminal/image.h>

#include <terminal/backends/framebuffer.h>
#include <terminal/term.h>

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

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

bool term_init(struct term_context *term, struct framebuffer_t frm, struct font_t font, struct style_t style, struct background_t backg);

#endif