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
            Config &m_Config = const_cast<Config &>(Config::Current_get());

        public:
            ConfigReader(string filePath);

        };
    }
}


#endif //NIXMETAFS_CONFIGREADER_H
