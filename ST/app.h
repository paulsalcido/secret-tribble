#ifndef __ST_APP__
#define __ST_APP__

namespace st {
    enum st_app_type {
        SDL
    };

    class app {
        public:
            app();
            ~app();

            static st::app* build_app( st_app_type app_type = SDL );
    };
}

#endif
