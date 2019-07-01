//
// Created by angel on 27/06/19.
//

#include "Config.h"

using namespace nixMetaFS::Models;

Config *Config::m_Self;
std::mutex g_Config_mutex;
std::vector<Command> Config::m_commands;
std::vector<AppSetting> Config::m_appSettings;
std::vector<ConnectionString> Config::m_connectionStrings;

const Config &Config::Current_get() {
    Config newConfig; // If singleton hasn't been created, we'll create one
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

void Config::Commands_set(std::vector<Command> commands) {
    Config::m_commands.assign(commands.begin(), commands.end());
}

void Config::AppSettings_set(std::vector<AppSetting> appSettings) {
    Config::m_appSettings.assign(appSettings.begin(), appSettings.end());

}

void Config::ConnectionStrings_set(std::vector<ConnectionString> connectionStrings) {
    Config::m_connectionStrings.assign(connectionStrings.begin(), connectionStrings.end());
}


Config::Config() {
    std::lock_guard<std::mutex> guard(g_Config_mutex);
    if (m_Self == nullptr)
        m_Self = this;
}

Config::~Config() {

}