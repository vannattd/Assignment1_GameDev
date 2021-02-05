#include "Game.hpp"

//Constructor
Game::Game(){
        std::string name = "";
        std::string console = "";
        
}

//Setters
void Game::setName(std::string name){
    this->name = name;
}
void Game::setOnline(bool online){
    this->online = online;
}
void Game::setSales(double sales){
    this->sales = sales;
}
void Game::setConsole(std::string console){
    this->console = console;
}
void Game::setRating(char rating){
    this->rating = rating;
}
void Game::setReleaseYear(int releaseYear){
    this->releaseYear = releaseYear;
}

//Getters
std::string Game::getName(){
    return name;
}
bool Game::getOnline(){
    return online;
}
double Game::getSales(){
    return sales;
}
std::string Game::getConsole(){
    return console;
}
char Game::getRating(){
    return rating;
}
int Game::getReleaseYear(){
    return releaseYear;
}