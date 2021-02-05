#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

//Gets the games from video_games.csv and stores them as Game objects in a vector
// @return The vector full of passed in games.
std::vector<Game*>* getGames(){
    std::vector<Game*> *games = new std::vector<Game*>;
    std::ifstream input("./data/video_games.csv");
    if(!input.is_open()){
        throw std::runtime_error("File not opened");
    }
    std::string line;
    std::string part;
    if(input.good()){
        std::getline(input, line);
        //Taking in data and only grabbing what we need.
        while(std::getline(input, line)){
            std::stringstream ss(line);
            Game* temp = new Game();
            getline(ss, part, ',');
            temp->setName(part);
            getline(ss, part, ',');
            getline(ss, part, ',');
            getline(ss, part, ',');
            getline(ss, part, ',');
            if(part.find("True")){
                temp->setOnline(true);
            }
            else{
                temp->setOnline(false); 
            }
            getline(ss, part, ',');
            getline(ss, part, ',');
            getline(ss, part, ',');
            getline(ss, part, ',');
            getline(ss, part, ',');
            getline(ss, part, ',');
            temp->setSales(std::stod(part));
            getline(ss, part, ',');
            getline(ss, part, ',');
            temp->setConsole(part);
            getline(ss, part, ',');
            temp->setRating(part[0]);
            getline(ss, part, ',');
            getline(ss, part, ',');
            temp->setReleaseYear(std::stoi(part));
            games->push_back(temp);
        }
    }
    return games;
}

TEST_CASE( "Testing...", "[all]" ) {
    std::vector<Game*> *games = getGames();
    REQUIRE( games->size() == 1114);
    Game* g = games->at(222);
    REQUIRE( g->getName() == "WWE SmackDown vs. Raw 2007" );
    g = games->at(235);
    REQUIRE( g->getName() == "Rockstar Games presents Table Tennis");
    REQUIRE( !g->getOnline());
    g = games->at(254);
    REQUIRE( g->getSales() == 0.23 );
    g = games->at(541);
    REQUIRE( g->getConsole() == "PlayStation 3");
    g = games->at(978);
    REQUIRE( g->getRating() == 'M');
    g = games->at(1113);
    REQUIRE( g->getName() == "Chicken Hunter");
    REQUIRE( g->getReleaseYear() == 2008);
    double value = 0;
    for(auto it=games->begin(); it!=games->end(); ++it){
        value += (*it)->getSales();
    }
    REQUIRE( value > 574.3);
    REQUIRE( value < 574.4);
}
