//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_CONFIG_H
#define NIXMETAFS_CONFIG_H

#include "../Common.h"
#include "../models/Command.h"
#include "../models/AppSetting.h"
#include "../models/ConnectionString.h"

namespace nixMetaFS {
    namespace Models {
        class Config {
        private:
            static Config *m_Self;
            static std::vector<Command> m_commands;
            static std::vector<AppSetting> m_appSettings;
            static std::vector<ConnectionString> m_connectionStrings;

        public:
            Config();
            ~Config();
            const static Config &Current_get();
            const std::vector<Command> &Commands_get();
            const std::vector<AppSetting> &AppSettings_get();
            const std::vector<ConnectionString> &ConnectionStrings_get();
            void Commands_set(std::vector<Command> commands);
            void AppSettings_set(std::vector<AppSetting> appSettings);
            void ConnectionStrings_set(std::vector<ConnectionString> connectionStrings);
        };
    }
}

#endif //NIXMETAFS_CONFIG_H
