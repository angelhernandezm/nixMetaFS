//
// Created by angel on 21/06/19.
//

#ifndef NIXMETAFS_METADATA_H
#define NIXMETAFS_METADATA_H

#include "../Common.h"

namespace  nixMetaFS {
    namespace Models {
        class Metadata {
        private:
            int m_Pk;
            int m_fileId;
            string m_fileName;
            string m_filePath;
            string m_Description;
            string m_AdditionalComments;
        public:

        };
    }
}

#endif //NIXMETAFS_METADATA_H