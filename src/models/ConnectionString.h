//
// Created by angel on 27/06/19.
//

#ifndef NIXMETAFS_CONNECTIONSTRING_H
#define NIXMETAFS_CONNECTIONSTRING_H

#include "../Common.h"

namespace nixMetaFS {
    namespace Models {
        class ConnectionString {
        private:
            string m_server;
            string m_username;
            string m_password;
            bool m_isenabled;

        public:
            ConnectionString();
            const string &Server_get();
            const string &Username_get();
            const string &Password_get();
            const bool &IsEnabled_get();
            void Server_set(string server);
            void Username_set(string username);
            void Password_set(string password);
            void IsEnabled_set(bool isenabled);

            ConnectionString(const char *server, const char *username, const char *password, bool isenabled);
        };
    }
}


#endif //NIXMETAFS_CONNECTIONSTRING_H
