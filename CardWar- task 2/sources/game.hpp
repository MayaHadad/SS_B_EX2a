#pragma once

#include <iostream>
#include "player.hpp"

namespace ariel
{
    class Game{
        Player p1, p2;

        public:
        Game(Player p1, Player p2);
        ~Game();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}