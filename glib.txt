# GLIB

## History
* 2017/10/11 KM, also prepare to write gstreamer elements.

## Reference
* GLib Reference manual - GNOME Developer Center https://developer.gnome.org/glib/

## Why is GLib important
* GStreamer adheres to the GObject, GLib Object System, programming model
* GLib provides many utilities.
  * Already there. version 2.50.3
  * No rewriting of codes
  * Unlikely to write better 

## How to Compile with GLib
```
#include <glib.h>
CFLAGS = `pkg-config --cflags glib-2.0`
LDFLAGS = `pkg-config --libs glib-2.0`
```

## What is GLib
* Written in C 
* Cross-platform
* License: GNU LGPL
* Able to run independently
* Terms: glib, libc, uclibc, glibc, newlib

## Version Information
* https://developer.gnome.org/glib/stable/glib-Version-Information.html
* GLIB\_MAJOR/MINOR/MICRO\_VERSION
* glib\_check\_version()

## Basic Types
* https://developer.gnome.org/glib/stable/glib-Basic-Types.html
* gboolean, TRUE, FALSE
* gchar, guchar
* gshort, gushort, gint, guint, glong, gulong
* gint8, guint8, gint16, guint16, gint32, guint32, gint64, guint64
* gfloat, gdouble
* gponter (void \*), gconstpointer (const void \*)
* gsize, gssize 
* G\_HAVE\_GINT64, gint64, guint64

## Standard Macros
* https://developer.gnome.org/glib/stable/glib-Standard-Macros.html
* TRUE, FALSE
* ABS(), MIN(), MAX(), CLAMP()
* G\_DIR\_SEPARATOR

## Type Conversion Macros
* GINT\_TO\_POINTER, GPOINTER\_TO\_INT
* GUINT\_TO\_POINTER, GPOINTER\_TO\_UINT
* GSIZE\_TO\_POINTER, GPOINTER\_TO\_SIZE

## Numerical Definitions
* https://developer.gnome.org/glib/stable/glib-Numerical-Definitions.html
* G\_E, G\_N2/10, G\_PI/PI\_2/PI\_4, G\_SQRT2, G\_LOG_2\_BASE\_10

## Message Output and Debugging Functions
* g\_log(), G\_LOG\_DOMAIN
* G\_LOG\_FLAG\_RECURSION/FATAL/ERROR/CRITICAL/WARNING/MESSAGE/INFO/DEBUG
* \_FATAL/ERROR can lead to quit the app and dump the core
* convenient functions: g\_message/warning/critical/error/debug

## The Main Event Loop
* https://developer.gnome.org/glib/stable/glib-The-Main-Event-Loop.html
* purpose: to sleep until some event occurs.
* Able to manage all the available sources of events
  * file descriptors (plain files, pipes, sockets)
  * timeouts
* GMainLoop: representing one instance of the main loop

## Threads
* https://developer.gnome.org/glib/stable/glib-Threads.html
* GThread, g\_thread\_new/try\_new/join/unref

## Time Zone

## Memory Allocation
* g\_new/new0, g\_try\_new/new0
* g\_malloc/malloc0/try\_malloc/try\_malloc0
* g\_free
