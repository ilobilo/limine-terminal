# Limine Terminal
### Based on [limine bootloader](https://github.com/limine-bootloader/limine) and [limine terminal](https://github.com/limine-bootloader/terminal)

## Building
First of all, clone this repo with ``--recursive`` flag to download terminal submodule
### Meson
```
dependency('limine_terminal')
```
### Everything else
* Add directory ``src`` to your include path (optionally ``fonts``)
* Compile these files:
```
src/terminal/backends/framebuffer.c
src/terminal/term.c
src/stb_image.c
src/image.c
src/term.c
```

## Usage
```c
#include <limine_terminal/term.h>

struct image_t *image = image_open(/* Background file address */, /* Background file size */);

font_t font
{
    /* Font address */,
    /* Font width */,
    /* Font height */,
    DEFAULT_FONT_SPACING,
    DEFAULT_FONT_SCALE_X,
    DEFAULT_FONT_SCALE_Y,
};

style_t style
{
    DEFAULT_ANSI_COLOURS,
    DEFAULT_ANSI_BRIGHT_COLOURS,
    DEFAULT_BACKGROUND,
    DEFAULT_FOREGROUND_BRIGHT,
    DEFAULT_BACKGROUND_BRIGHT,
    DEFAULT_FOREGROUND_BRIGHT,
    DEFAULT_MARGIN,
    DEFAULT_MARGIN_GRADIENT
};

background_t back
{
    image, /* You can set this to NULL to disable background */
    /* IMAGE_CENTERED/STRETCHED/TILED */,
    DEFAULT_BACKDROP
};

struct term_context *term = term_init(frm, font, style, back);

term_write(term, "abcdefg", 7);
term->clear(term, true /* Move the cursor or not */);

term_write(term, "Hello, World!", 13);

size_t x, y;
term->get_cursor_pos(term, &x, &y);
/* ... */
```