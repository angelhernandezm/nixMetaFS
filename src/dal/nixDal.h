//
// Created by angel on 21/06/19.
//

#ifndef NIXMETAFS_NIXDAL_H
#define NIXMETAFS_NIXDAL_H

#include "../Common.h"
#include "MySqlRequest.h"
#include "mysql_connection.h"

// https://stackoverflow.com/questions/16424828/how-to-connect-mysql-database-using-c

namespace  nixMetaFS {
    namespace Dal {
        class nixDal {
        private:


        protected:
           template <class Func>
            void Using(Func&& dataAccessCode, MySqlRequest& request) {
               GetConnection(request);
               dataAccessCode(request);
               ReleaseConnectionResources(request);
            }

            void GetConnection(MySqlRequest& request);

            void ReleaseConnectionResources(MySqlRequest& request);

        public:


        };
    }
}


#endif //NIXMETAFS_NIXDAL_H
