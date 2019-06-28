//
// Created by angel on 27/06/19.
//

#include "ConnectionString.h"

using namespace nixMetaFS::Models;

const string &ConnectionString::Server_get() {
    return m_server;
}

const string &ConnectionString::Username_get() {
    return m_username;
}

const string &ConnectionString::Password_get() {
    return m_password;
}

const bool &ConnectionString::IsEnabled_get() {
    return m_isenabled;
}

void ConnectionString::Server_set(string server) {
    m_server = server;
}

void ConnectionString::Username_set(string username) {
    m_username = username;
}

void ConnectionString::Password_set(string password) {
    m_password = password;
}

void ConnectionString::IsEnabled_set(bool isenabled) {
    m_isenabled = isenabled;
}

ConnectionString::ConnectionString() {

}

ConnectionString::ConnectionString(const char *server, const char *username, const char *password, bool isenabled)
        : ConnectionString() {
    m_isenabled = isenabled;
    m_server.append(server);
    m_username.append(username);
    m_password.append(password);
}