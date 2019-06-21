//
// Created by angel on 21/06/19.
//

#include "../abstractions/IModel.h"

using namespace nixMetaFS::Abstractions;

namespace  nixMetaFS {
    namespace Core {
        template<class T>
        class BaseModel : public IModel<T> {
        public:
            std::string ToString() {
                //TODO: Serialize object as string here

                return "";
            }
        };
    }
}