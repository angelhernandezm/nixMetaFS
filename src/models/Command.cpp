//
// Created by angel on 27/06/19.
//

#include "Command.h"

using namespace nixMetaFS::Models;

const string &Command::Name_get() {
    return m_name;
}

const string &Command::Statement_get() {
    return m_statement;
}

void Command::Name_set(string name) {
    m_name = name;
}

void Command::Statement_set(string statement) {
    m_statement = statement;
}