project('limine-terminal', ['c', 'cpp'],
    license : 'BSD-2-Clause',
    version : 'v0.1'
)

limine_terminal_dep = declare_dependency(
    include_directories : include_directories(
        'fonts',
        'src'
    ),
    sources : files(
        'src/terminal/backends/framebuffer.c',
        'src/terminal/term.c',
        'src/stb_image.c',
        'src/image.c',
        'src/term.c'
    )
)

if meson.version().version_compare('>=0.54.0')
    meson.override_dependency('limine_terminal', limine_terminal_dep)
endif