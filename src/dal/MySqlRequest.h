//
// Created by angel on 21/06/19.
//

#ifndef NIXMETAFS_MYSQLREQUEST_H
#define NIXMETAFS_MYSQLREQUEST_H

#include "../Common.h"
#include "../abstractions/IDisposable.h"
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>

using namespace nixMetaFS::Abstractions;

namespace  nixMetaFS {
    namespace Dal {
        class MySqlRequest: public IDisposable {
        private:
            std::string m_ConnectionString;
            std::string m_StatementStr;
            sql::Driver *m_Driver;
            sql::Connection *m_Connection;
            sql::Statement *m_Statement;
            sql::ResultSet *m_ResultSet;
            sql::SQLException m_ExceptionThrown;
        public:
            void Dispose();
            const sql::Driver& Driver_get() ;
            const sql::Connection& Connection_get() ;
            const std::string& Statement_get();
            const sql::ResultSet& Result_get() ;
            const sql::SQLException& ExceptionIfAny_get();
            const std::string& ConnectionString_get();
            void Driver_set(sql::Driver* driver);
            void Connection_set(sql::Connection* connection);
            void Statement_set(sql::Statement* statement);
            void Result_set(sql::ResultSet* resultset);
        };
    }
 }




#endif //NIXMETAFS_MYSQLREQUEST_H
