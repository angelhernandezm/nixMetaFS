//
// Created by angel on 3/01/20.
//


#ifndef NIXMETAFS_REPOSITORY_H
#define NIXMETAFS_REPOSITORY_H

#include "../Common.h"
#include "../dal/nixDal.h"

using namespace nixMetaFS::Dal;

namespace nixMetaFS {
    namespace Core {
        class Repository {
        private:
            static std::unique_ptr<nixDal> m_dal;

        public:
            Repository();

            ~Repository();

            void
        };
    }
}


#endif //NIXMETAFS_REPOSITORY_H
