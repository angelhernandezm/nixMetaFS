//
// Created by angel on 21/06/19.
//

#ifndef NIXMETAFS_IMODEL_H
#define NIXMETAFS_IMODEL_H

#endif //NIXMETAFS_IMODEL_H

#include "../Common.h"

namespace  nixMetaFS {
    namespace Abstractions {
        template<typename T>
        class IModel {
        protected:
            T m_data;

        public:
            IModel() {};
            virtual ~IModel() {};
            virtual string ToString() = 0;
        };
    }
}
