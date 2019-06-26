//
// Created by angel on 25/06/19.
//

#include "MainWindowController.h"

using namespace nixMetaFS::Core;

MainWindowController *MainWindowController::m_Self;
GtkApplication *MainWindowController::m_Application;

MainWindowController::MainWindowController() {
    m_Self = this;
}

MainWindowController::~MainWindowController() {

}

void MainWindowController::Initialize() {
    // This doesn't apply for this class
}

void MainWindowController::SetupUI(GtkBuilder *builder) {
    auto controlNames = {"frmMain-nixMetaFS", "txtDescription"};

    std::for_each(controlNames.begin(), controlNames.end(), [&](std::string controlName) {
        m_Controls.insert(std::pair<std::string, GtkWidget*>(controlName,
                          GTK_WIDGET (gtk_builder_get_object(builder, controlName.c_str()))));
    });
}

void MainWindowController::StartUp(GtkApplication &app, gpointer user_data) {
    m_Application = &app;

    try {
        auto builder = gtk_builder_new_from_resource(Main_Window_Resource_Name);
        m_Self->SetupUI(builder);
        g_object_unref(G_OBJECT (builder));
        auto frmMainWindow = m_Self->m_Controls.at("frmMain-nixMetaFS");
        gtk_application_add_window(&app, (GtkWindow *) frmMainWindow);
        gtk_widget_show((GtkWidget *) (GtkWindow *) frmMainWindow);
    } catch(std::exception& ex) {
        throw std::runtime_error("Unable to load UI. Please ensure resource file was linked to application.");
    }
 }