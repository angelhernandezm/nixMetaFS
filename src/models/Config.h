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
            std::vector<Command> m_commands;
            std::vector<AppSetting> m_appSettings;
            std::vector<ConnectionString> m_connectionStrings;

        public:
            const std::vector<Command> &Commands_get();

            const std::vector<AppSetting> &AppSettings_get();

            const std::vector<ConnectionString> &ConnectionStrings_get();
        };
    }
}

#endif //NIXMETAFS_CONFIG_H
