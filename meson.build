project(
  'appmenu-ng-gtk-module',
  'c',
  version : '0.0.1',
  meson_version : '>=0.51.0',
  license : 'LGPL-3.0-or-later',
  default_options : ['c_std=gnu11', 'buildtype=debugoptimized', 'warning_level=1']
)

am_cflags = [
    '-fstack-protector',
    '-DGETTEXT_PACKAGE="@0@"'.format(meson.project_name()),
]
add_project_arguments(am_cflags, language: 'c')

module_sources = files(
    'src/appmenu-ng-gtk-module.c',
)

gtk3 = dependency('gtk+-3.0', version: '>=3.22.0', required: true)
  
module_subdirs = ['gtk-3.0']

if gtk3.found()
    subdir('gtk-3.0')
endif
