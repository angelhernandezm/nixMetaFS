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
            static ConfigReader *m_Self;
            const Config &m_Config = Config::Current_get();
            bool LocateConfigFile();

            bool Initialize();


        public:
            ConfigReader(string filePath);

        };
    }
}


#endif //NIXMETAFS_CONFIGREADER_H
