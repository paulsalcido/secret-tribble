#ifndef __ST_APP__
#define __ST_APP__

#include "media.h"

namespace st {
    enum st_app_type {
        SDL
    };

    class app {
        public:
            app();
            ~app();

            static st::app* build_app( st_app_type app_type = SDL );
            st::media* media();

            virtual void run() = 0;

        protected:
            st::media* m_st_media;
    };
}

#endif
