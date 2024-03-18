#include "Controller/Controller.h"
#include <unistd.h>

int main() {
    Controller controller;
    controller.loop();
    sleep(5);
    return 0;
}
