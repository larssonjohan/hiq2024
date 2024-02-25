#include "hiq/game/CarGame.h"

#include <iostream>

int main()
{
    hiq::game::CarGame carGame;
    try 
    {
        carGame.run();
    }
    catch(std::runtime_error& e)
    {
        std::cout << "Error occured: " << e.what() << ".\n";

        return 1;
    }

    return 0;
}
