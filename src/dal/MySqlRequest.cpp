//
// Created by angel on 21/06/19.
//

#include "MySqlRequest.h"

sql::Driver& nixMetaFS::Dal::MySqlRequest::Driver_get() const {
    return *m_Driver;
}

sql::Connection& nixMetaFS::Dal::MySqlRequest::Connection_get() const {
    return *m_Connection;
}

std::string nixMetaFS::Dal::MySqlRequest::Statement_get() const {
    return m_StatementStr;
}

sql::ResultSet& nixMetaFS::Dal::MySqlRequest::Result_get() const {
    return *m_Resultset;
}