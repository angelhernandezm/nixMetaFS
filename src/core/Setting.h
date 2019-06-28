//
// Created by angel on 28/06/19.
//

#ifndef NIXMETAFS_SETTING_H
#define NIXMETAFS_SETTING_H

#include "../Common.h"
#include "../models/AppSetting.h"
#include "../models/Command.h"
#include "../models/ConnectionString.h"
#include "tinyxml.h"

using namespace nixMetaFS::Models;

namespace nixMetaFS {
    namespace Core {
        template<class T>
        class Setting {
        public:
            vector<T> RehydrateFromXml(TiXmlHandle &hRoot, string elementName) {
                throw "Not implemented function";
            }
        };

        template<>
        class Setting<AppSetting> {
        public:
            vector<AppSetting> RehydrateFromXml(TiXmlHandle &hRoot, string elementName) {
                vector<AppSetting> retval;

                auto pElem = hRoot.FirstChild(elementName).FirstChild().Element();

                if (pElem) {
                    for (pElem; pElem; pElem = pElem->NextSiblingElement()) {
                        AppSetting appSetting(pElem->Attribute("key"), pElem->Attribute("value"));
                        retval.push_back(appSetting);
                    }
                }
                return retval;
            }
        };

        template<>
        class Setting<ConnectionString> {
        public:
            vector<ConnectionString> RehydrateFromXml(TiXmlHandle &hRoot, string elementName) {
                vector<ConnectionString> retval;

                auto pElem = hRoot.FirstChild(elementName).FirstChild().Element();

                if (pElem) {
                    for (pElem; pElem; pElem = pElem->NextSiblingElement()) {
                        string disableStr(pElem->Attribute("isEnabled"));
                        std::transform(disableStr.begin(), disableStr.end(), disableStr.begin(), ::tolower);
                        auto isDisabled = disableStr.compare("true") == 0;
                        ConnectionString connStr(pElem->Attribute("server"), pElem->Attribute("userName"),
                                                 pElem->Attribute("password"), isDisabled);
                        retval.push_back(connStr);
                    }
                }
                return retval;
            }
        };

        template<>
        class Setting<Command> {
        public:
            vector<Command> RehydrateFromXml(TiXmlHandle &hRoot, string elementName) {
                vector<Command> retval;

                auto pElem = hRoot.FirstChild(elementName).FirstChild().Element();

                if (pElem) {
                    for (pElem; pElem; pElem = pElem->NextSiblingElement()) {
                        Command cmd(pElem->Attribute("name"), pElem->Attribute("statement"));
                        retval.push_back(cmd);
                    }
                }
                return retval;
            }
        };
    }
}

#endif //NIXMETAFS_SETTING_H
