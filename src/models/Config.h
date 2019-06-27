//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_CONFIG_H
#define NIXMETAFS_CONFIG_H

#include "../Common.h"
#include "../models/Command.h"
#include "../models/AppSetting.h"
#include "../models/ConnectionString.h"

std::mutex g_Config_mutex;

namespace nixMetaFS {
    namespace Models {
        class Config {
        private:
            static Config *m_Self;
            std::vector<Command> m_commands;
            std::vector<AppSetting> m_appSettings;
            std::vector<ConnectionString> m_connectionStrings;

        public:
            Config();

            ~Config();

            const static Config &Current_get();
            const std::vector<Command> &Commands_get();
            const std::vector<AppSetting> &AppSettings_get();
            const std::vector<ConnectionString> &ConnectionStrings_get();
        };
    }
}

#endif //NIXMETAFS_CONFIG_H
