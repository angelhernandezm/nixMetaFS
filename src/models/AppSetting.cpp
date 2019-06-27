//
// Created by angel on 27/06/19.
//

#include "AppSetting.h"

using namespace nixMetaFS::Models;

const string &AppSetting::Key_get() {
    return m_key;
}

const string &AppSetting::Value_get() {
    return m_value;
}

void AppSetting::Key_set(string key) {
    m_key = key;
}

void AppSetting::Value_set(string value) {
    m_value = value;
}
