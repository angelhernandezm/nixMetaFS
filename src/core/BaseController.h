//
// Created by angel on 25/06/19.
//

#ifndef NIXMETAFS_BASECONTROLLER_H
#define NIXMETAFS_BASECONTROLLER_H

namespace  nixMetaFS {
    namespace Core {
        class BaseController {
        public:
            virtual ~BaseController() = 0;

        protected:
            virtual void Initialize() = 0;
        };
    }
}



#endif //NIXMETAFS_BASECONTROLLER_H
