//
// Created by angel on 27/06/19.
//

#include "../core/Setting.h"
#include "ConfigReader.h"

using namespace nixMetaFS::Core;
namespace fs = std::experimental::filesystem;

ConfigReader *ConfigReader::m_Self;

ConfigReader::ConfigReader(string filePath) {
    if (m_Self == nullptr) {
        m_filePath = filePath;
        m_Self = this;
        auto result = std::async(std::launch::async, &ConfigReader::Initialize, this);

        if (!result.get())
            throw "Unable to load and parse config file.";
    }
}


bool ConfigReader::Initialize() {
    auto retval = false;
    auto configFile = m_filePath.substr(0, m_filePath.find_last_of("\\/") + 1);
    configFile = configFile.append(ConfigFile);

    if (fs::exists(fs::path(configFile))) {
        try {
            TiXmlDocument config(configFile);
            if (config.LoadFile()) {
                TiXmlElement *pElem;
                Setting<Command> cmd;
                TiXmlHandle hDoc(&config);
                Setting<AppSetting> appSettings;
                Setting<ConnectionString> connectionStrings;
                pElem = hDoc.FirstChildElement().Element();

                if (pElem) {
                    auto hRoot = TiXmlHandle(pElem);
                    std::async(std::launch::async,
                               [&] { m_Config.Commands_set(cmd.RehydrateFromXml(hRoot, "commands")); });
                    std::async(std::launch::async,
                               [&] { m_Config.AppSettings_set(appSettings.RehydrateFromXml(hRoot, "appSettings")); });
                    std::async(std::launch::async, [&] {
                        m_Config.ConnectionStrings_set(connectionStrings.RehydrateFromXml(hRoot, "connectionStrings"));
                    });
                    retval = true;
                }
            }
        } catch (std::exception &e) {

        }
    }

    return retval;
}
