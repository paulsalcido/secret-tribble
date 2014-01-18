#include <iostream>
#include "ST/app.h"

int main(int argc, char *argv[]) {
    st::app *main_app = st::app::build_app();
    delete main_app;
    return 0;
}
