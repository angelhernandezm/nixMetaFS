//
// Created by angel on 27/06/19.
//

#include "Config.h"

using namespace nixMetaFS::Models;

const std::vector<Command> &Config::Commands_get() {
    return m_commands;
}

const std::vector<AppSetting> &Config::AppSettings_get() {
    return m_appSettings;
}

const std::vector<ConnectionString> &Config::ConnectionStrings_get() {
    return m_connectionStrings;
}