//
// Created by angel on 27/06/19.
//

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
    vector<type_index> types{typeid(ConnectionString), typeid(Command), typeid(AppSetting)};

    if (fs::exists(fs::path(configFile))) {
        try {
            TiXmlDocument config(configFile);
            config.LoadFile();

            for_each(types.begin(), types.end(), [&](std::type_index &t) {

            });

            retval = true;
        } catch (std::exception &e) {

        }
    }

    return retval;
}

template<typename T>
vector<T> ConfigReader::RehydrateFromXml(TiXmlHandle &hRoot, TiXmlElement *pElem, string elementName) {
    vector<T> retval;


    return retval;
}
