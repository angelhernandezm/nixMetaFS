//
// Created by angel on 25/06/19.
//

#ifndef NIXMETAFS_MAINWINDOWCONTROLLER_H
#define NIXMETAFS_MAINWINDOWCONTROLLER_H

#include "../Common.h"
#include "../core/BaseController.h"

namespace  nixMetaFS {
    namespace Core {
        class MainWindowController: BaseController {
        private:
            static MainWindowController *Self;
            static GtkApplication *Application;
            GtkBuilder *builder;

        public:
            MainWindowController();
            ~MainWindowController();
            static void StartUp(GtkApplication &app, gpointer user_data);

        protected:
            void Initialize() override;

        };
    }
}


#endif //NIXMETAFS_MAINWINDOWCONTROLLER_H
