
# appmenu-ng-gtk-module

Nothing to see here (yet)...

This is an (incomplete) and experimental Gtk module as playground/skeleton to solve the problem of notifying a bar about appmenu dbus service and object path properties under Wayland.

https://github.com/Alexays/Waybar/issues/288#issuecomment-1817685039

## Compiling

```
meson build
ninja -C build
```

## Running

```
GTK_MODULES=$PWD/build/gtk-3.0/libappmenu-gtk-ng-module.so yourapp
```

or, together with the classic appmenu-gtk-module:

```
GTK_MODULES=appmenu-gtk-module:$PWD/build/gtk-3.0/libappmenu-gtk-ng-module.so yourapp
```

