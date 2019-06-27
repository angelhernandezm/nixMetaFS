//
// Created by angel on 24/06/19.
//

#ifndef NIXMETAFS_IDISPOSABLE_H
#define NIXMETAFS_IDISPOSABLE_H


namespace  nixMetaFS {
    namespace Abstractions {
        class IDisposable {
        public:
            IDisposable() {};
            virtual ~IDisposable() {};
            virtual void Dispose() = 0;
        };
    }
}

#endif //NIXMETAFS_IDISPOSABLE_H
