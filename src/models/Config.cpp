//
// Created by angel on 27/06/19.
//

#include "Config.h"

using namespace nixMetaFS::Models;

Config *Config::m_Self;

const Config &Config::Current_get() {
    return *m_Self;
}

const std::vector<Command> &Config::Commands_get() {
    return m_commands;
}

const std::vector<AppSetting> &Config::AppSettings_get() {
    return m_appSettings;
}

const std::vector<ConnectionString> &Config::ConnectionStrings_get() {
    return m_connectionStrings;
}

Config::Config() {
    std::lock_guard<std::mutex> guard(g_Config_mutex);
    if (m_Self == nullptr)
        m_Self = this;
}

Config::~Config() {

}