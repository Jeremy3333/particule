#include "Controller/Controller.h"
#include <unistd.h>

int main() {
    const Controller controller;
    controller.draw();
    sleep(5);
    return 0;
}
