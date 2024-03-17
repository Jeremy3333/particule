//
// Created by tally on 16/03/24.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/Model.h"
#include "../Vue/Vue.h"


class Controller {
public:
    // update the vue using the model
    void draw() const;
private:
    Model model_;
    Vue vue_;
};



#endif //CONTROLLER_H
