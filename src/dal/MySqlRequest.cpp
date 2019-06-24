//
// Created by angel on 21/06/19.
//

#include "MySqlRequest.h"

const sql::Driver &nixMetaFS::Dal::MySqlRequest::Driver_get()  {
    return *m_Driver;
}

const sql::Connection &nixMetaFS::Dal::MySqlRequest::Connection_get()  {
    return *m_Connection;
}

const std::string& nixMetaFS::Dal::MySqlRequest::Statement_get()  {
    return m_StatementStr;
}

const sql::ResultSet &nixMetaFS::Dal::MySqlRequest::Result_get()  {
    return *m_ResultSet;
}

const sql::SQLException& nixMetaFS::Dal::MySqlRequest::ExceptionIfAny_get()  {
    return m_ExceptionThrown;
}

void nixMetaFS::Dal::MySqlRequest::Driver_set(sql::Driver *driver) {
    if (driver != nullptr)
        m_Driver = driver;
}

void nixMetaFS::Dal::MySqlRequest::Connection_set(sql::Connection *connection) {
    if (connection != nullptr)
        m_Connection = connection;

}

void nixMetaFS::Dal::MySqlRequest::Statement_set(sql::Statement *statement) {
    if (statement != nullptr)
        m_Statement = statement;
}

void nixMetaFS::Dal::MySqlRequest::Result_set(sql::ResultSet *resultset) {
    if (resultset != nullptr)
        m_ResultSet = resultset;
}

const std::string&  nixMetaFS::Dal::MySqlRequest::ConnectionString_get() {
    return m_ConnectionString;
}

void nixMetaFS::Dal::MySqlRequest::Dispose() {

}