#ifndef __ST_MEDIA_H__
#define __ST_MEDIA_H__

#include <string>

namespace st {
    class media {
        public:
            media(std::string base_media_path);
            media();
            ~media();

            std::string get_media_path(std::string name);
            std::string get_image_media_path(std::string name);
            std::string get_typeface_media_path(std::string name);
            static std::string default_media_path();
        private:
            std::string m_base_media_path;
    };
}

#endif
