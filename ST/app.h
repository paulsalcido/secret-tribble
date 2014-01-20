#ifndef __ST_APP__
#define __ST_APP__

#include "media.h"
#include <string>

namespace st {
    class app {
        public:
            app();
            ~app();

            static st::app* build_app( std::string name = "sdl" );
            st::media* media();

            virtual void run() = 0;
        protected:
            st::media* m_st_media;
    };
}

#endif
