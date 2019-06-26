#include <iostream>
#include <gtk/gtk.h>
#include "app/MainWindowController.h"

using namespace std;
using namespace nixMetaFS::Core;

GtkApplication *app;
MainWindowController mainWindow;

int main(int argc, char **argv) {
   // cout << "Hello, World!" << endl;

    app = gtk_application_new("Gtk.nixMetafs.Demo", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (&MainWindowController::StartUp), NULL);
    g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return 0;
}