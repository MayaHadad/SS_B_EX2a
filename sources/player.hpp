#pragma once

#include <iostream>

namespace ariel
{
    class Player{
        std:: string name;

        public:
            Player();
            Player(std:: string name);
            ~Player();
            int stacksize();
            int cardesTaken();
    };
}
 