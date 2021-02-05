#ifndef             __HPP__GAME__
#define             __HPP__GAME__

#include <string>

class Game {

    public:
        Game();

        //Getters
        std::string getName();
        bool getOnline();
        double getSales();
        std::string getConsole();
        char getRating();
        int getReleaseYear();

        //Setters
        void setName(std::string name);
        void setOnline(bool online);
        void setSales(double sales);
        void setConsole(std::string console);
        void setRating(char rating);
        void setReleaseYear(int releaseYear);
       

    private:
        std::string name;
        bool online;
        double sales;
        std::string console;
        char rating;
        int releaseYear;
      

};

#endif