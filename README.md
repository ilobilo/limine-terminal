# Limine Terminal
### Based on [limine bootloader](https://github.com/limine-bootloader/limine) and [flanterm](https://github.com/mintsuki/flanterm)

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
src/flanterm/backends/fb.c
src/flanterm/flanterm.c
src/stb_image.c
src/image.c
src/term.c
```

## Usage
```c
#include <limine_terminal/term.h>

void *term_alloc(size_t size) { /* allocate memory */ }
void *term_realloc(void *oldptr, size_t size) { /* reallocate memory */ }

// size is the same value that was passed to term_alloc()
void term_free(void *ptr, size_t size) { /* free memory with size */ }
void term_freensz(void *ptr) { /* free memory */ }

void *term_memcpy(void *dest, const void *src, size_t size) { /* memcpy */ }
void *term_memset(void *dest, int val, size_t count) { /* memset */ }

struct image_t *image = image_open(/* Background file address (BMP, PNG, or JPEG) */, /* Background file size */);

struct font_t font =
{
    /* Font address */,
    /* Font width */,
    /* Font height */,
    DEFAULT_FONT_SPACING,
    DEFAULT_FONT_SCALE_X,
    DEFAULT_FONT_SCALE_Y,
};

struct style_t style =
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

struct background_t back =
{
    image, /* You can set this to NULL to disable background */
    /* IMAGE_CENTERED/STRETCHED/TILED */,
    DEFAULT_BACKDROP
};

term_t *term = term_init(frm, font, style, back);

term_write(term, "abcdefg", 7);
term->clear(term, true /* Move the cursor or not */);

term_write(term, "Hello, World!", 13);

size_t x, y;
term->get_cursor_pos(term, &x, &y);
/* ... */
```
