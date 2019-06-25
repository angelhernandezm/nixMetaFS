//
// Created by angel on 25/06/19.
//

#include "MainWindowController.h"

using namespace nixMetaFS::Core;

MainWindowController* MainWindowController::Self;
GtkApplication* MainWindowController::Application;

MainWindowController::MainWindowController() {

}

MainWindowController::~MainWindowController() {

}

void MainWindowController::Initialize() {
    // This doesn't apply for this class
}

void MainWindowController::StartUp(GtkApplication &app, gpointer user_data) {
    Application = &app;
    GError *err = nullptr;
    Self->builder = gtk_builder_new();
   // gtk_builder_add_from_file(self->builder, "./../../ui/SqlTestHarness.glade", &err);

    if (err) {
        g_error(err->message);
        g_error_free(err);
        throw std::runtime_error("Unable to load UI. Please ensure glade file exists.");
    }

  /*   self->SetUpUI();
    self->ConnectSignals();
    g_object_unref (G_OBJECT (self->builder));
    gtk_application_add_window(&app, (GtkWindow*) self->Controls.at("frmMain"));
    gtk_widget_show ((GtkWidget*) (GtkWindow*) self->Controls.at("frmMain"));

    self->Context = DataContext(app, ParentStub<Contact>([&](bool ignoreFields){self->Refresh(ignoreFields);},
                                                         [&](bool controlState) {self->EnableOrDisableFieldsBasedOnMode(controlState);},
                                                         [&](UiFieldOperation op, Contact& c){self->ReadOrWriteToFieldsOnUi(op, c);},
                                                         [&] {self->FetchDataset();}));

    self->Context.CanEdit_set(false);

    self->FetchDataset();

    g_timeout_add_seconds(1, [&](gpointer data)->gboolean {self->UpdateStatusBar(data);}, self->Controls.at("sbrMain") ); */
}