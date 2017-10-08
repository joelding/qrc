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

## What is GLib
* Written in C 
* Cross-platform
* License: GNU LGPL
* Able to run independently
* Terms: glib, libc, uclibc, glibc, newlib

## Version Information
* https://developer.gnome.org/glib/stable/glib-Version-Information.html
* GLIB\_MAJOR/MINOR?MICRO\_VERSION
* glib_check_version()

## Basic Types
* https://developer.gnome.org/glib/stable/glib-Basic-Types.html
* glib.h
* gboolean, TRUE, FALSE
* gchar, guchar
* gshort, gushort, gint, guint, glong, gulong
* gint8, guint8, gint16, guint16, gint32, guint32, gint64, guint64
* gfloat, gdouble
* gponter, gconstpointer
* gsize, gssize 
* G\_HAVE\_GINT64, gint64, guint64

## Standard Macros
* https://developer.gnome.org/glib/stable/glib-Standard-Macros.html
* TRUE, FALSE
* ABS(), MIN(), MAX(), CLAMP()
* G\_DIR\_SEPARATOR

## Numerical Definitions
* https://developer.gnome.org/glib/stable/glib-Numerical-Definitions.html
* G\_E, G\_N2/10, G\_PI/PI\_2/PI\_4, G\_SQRT2, G\_LOG_2\_BASE\_10

## Message Output and Debugging Functions
* g\_log(), G\_LOG\_DOMAIN
* G\_LOG\_FLAG\_RECURSION/FATAL/ERROR/CRITICAL/WARNING/MESSAGE/INFO/DEBUG
* \_FATAL/ERROR can lead to quit the app and dump the core
* convenient functions: g\_message/warning/critical/error/debug
