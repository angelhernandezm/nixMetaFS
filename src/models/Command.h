//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_COMMAND_H
#define NIXMETAFS_COMMAND_H

#include "../Common.h"

namespace nixMetaFS {
    namespace Models {
        class Command {
        private:
            string m_name;
            string m_statement;
        public:
            Command();

            Command(const char *name, const char *statement);
            const string &Name_get();
            const string &Statement_get();
            void Name_set(string name);
            void Statement_set(string statement);
        };
    }
}


#endif //NIXMETAFS_COMMAND_H
