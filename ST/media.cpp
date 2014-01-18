#include "media.h"
#include <string>
#include <unistd.h>
#include <iostream>

st::media::media(std::string base_media_path) {
    m_base_media_path = base_media_path;
}

st::media::media() {
    m_base_media_path = default_media_path();
}

st::media::~media() {
}

std::string st::media::default_media_path() {
    // TODO: Lazy, lazy! I just don't know any better.
    char tmp_default_media_path[10000];
    readlink("/proc/self/exe",tmp_default_media_path,sizeof(tmp_default_media_path));
    std::string default_media_path = tmp_default_media_path;
    return default_media_path.substr(0,
            default_media_path.find_last_of("/")+1);
}

std::string st::media::get_media_path(std::string name) {
    return "";
}
