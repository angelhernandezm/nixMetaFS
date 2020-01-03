//
// Created by angel on 21/06/19.
//

#include "nixDal.h"

extern "C" {
  sql::Driver* get_driver_instance();
}

void nixMetaFS::Dal::nixDal::GetConnection(MySqlRequest& request) {
    try {
        request.Driver_set(get_driver_instance());

    } catch(sql::SQLException &e) {

    }
}

void nixMetaFS::Dal::nixDal::ReleaseConnectionResources(MySqlRequest& request) {

}