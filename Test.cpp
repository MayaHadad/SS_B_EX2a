#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <stdexcept>

using namespace ariel;

TEST_CASE("before starting the game"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2);
    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLog());
    game.playTurn();
    CHECK(p1.stacksize()<26);
    CHECK(p2.stacksize()<26);
}

TEST_CASE("should fail because a player can play in one game only"){
    Player p1("bob");
    Player p2("alice");
    Player p3("tom");
    Game game1(p1,p2);
    Game game2(p2, p3);
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());
    CHECK_THROWS(game2.printLastTurn());
    CHECK_THROWS(game2.printWiner());
    CHECK_THROWS(game2.printLog());
    CHECK_THROWS(game2.printStats());
    
}

TEST_CASE("end of game"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
    //game ends in tie
    if (p1.cardesTaken()==p2.cardesTaken())
    {
        CHECK_THROWS(game.printWiner());
    }
}
