//
// Created by angel on 3/01/20.
//

#include "Repository.h"

using namespace nixMetaFS::Core;

std::unique_ptr<nixDal> Repository::m_dal;

Repository::Repository() {
    if (m_dal == nullptr)
        m_dal = std::unique_ptr<nixDal>(new nixDal);
}

Repository::~Repository() {

}