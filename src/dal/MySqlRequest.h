//
// Created by angel on 21/06/19.
//

#ifndef NIXMETAFS_MYSQLREQUEST_H
#define NIXMETAFS_MYSQLREQUEST_H

#include "../Common.h"
#include "mysql_connection.h"

namespace  nixMetaFS {
    namespace Dal {
        class MySqlRequest {
        private:
            std::string m_StatementStr;
            sql::Driver *m_Driver;
            sql::Connection *m_Connection;
            sql::Statement *m_Statement;
            sql::ResultSet *m_Resultset;
        public:
            sql::Driver& Driver_get() const;
            sql::Connection& Connection_get() const;
            std::string Statement_get() const;
            sql::ResultSet& Result_get() const;
        };
    }
 }




#endif //NIXMETAFS_MYSQLREQUEST_H
