/*
 * Copyright (C) 2023 Duncan Mac-Vicar P.
 *
 * based on libcanberra:
 * Copyright (C) 2008 Lennart Poettering
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <gtk/gtk.h>

static guint signal_id_widget_window_state_event;

static gboolean
emission_hook_cb (GSignalInvocationHint *hint, guint n_param_values, const GValue *param_values, gpointer data)
{
  GObject *object;
  object = g_value_get_object (&param_values[0]);

  if (!GTK_IS_WINDOW (object))
    {
      return TRUE;
    }

  if (hint->signal_id == signal_id_widget_window_state_event)
    {
      GdkEventWindowState *e = (GdkEventWindowState *) gdk_event_copy (g_value_peek_pointer (&param_values[1]));
      if (e->new_window_state & GDK_WINDOW_STATE_FOCUSED)
        {
          g_message ("window '%s' is now focused", gtk_window_get_title (GTK_WINDOW (object)));
        }
      else
        {
          g_message ("window '%s' is not focused", gtk_window_get_title (GTK_WINDOW (object)));
        }
    }
  return TRUE;
}

static void
install_hook (GType type, const char *sig, guint *sn)
{
  GTypeClass *type_class;

  type_class = g_type_class_ref (type);

  *sn = g_signal_lookup (sig, type);
  g_signal_add_emission_hook (*sn, 0, emission_hook_cb, NULL, NULL);

  g_type_class_unref (type_class);
}

G_MODULE_EXPORT void
gtk_module_init (gint *argc, gchar ***argv[])
{
  install_hook (GTK_TYPE_WIDGET, "window-state-event", &signal_id_widget_window_state_event);
}
