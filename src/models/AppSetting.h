//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_APPSETTING_H
#define NIXMETAFS_APPSETTING_H

#include "../Common.h"


namespace nixMetaFS {
    namespace Models {
        class AppSetting {
        private:
            string m_key;
            string m_value;

        public:
            AppSetting();

            AppSetting(const char *key, const char *value);

            const string &Key_get();

            const string &Value_get();
            void Key_set(string key);
            void Value_set(string value);
        };
    }
}


#endif //NIXMETAFS_APPSETTING_H
