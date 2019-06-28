//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_CONFIGREADER_H
#define NIXMETAFS_CONFIGREADER_H

#include "../Common.h"
#include "../models/Config.h"
#include "tinyxml.h"

using namespace nixMetaFS::Models;

namespace nixMetaFS {
    namespace Core {
        class ConfigReader {
        private:
            string m_filePath;

            bool Initialize();
            static ConfigReader *m_Self;
            const Config &m_Config = Config::Current_get();

            template<typename T>
            vector<T> RehydrateFromXml(TiXmlHandle &hRoot, TiXmlElement *pElem, string elementName);

        public:
            ConfigReader(string filePath);

        };
    }
}


#endif //NIXMETAFS_CONFIGREADER_H
