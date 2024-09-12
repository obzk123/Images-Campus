#include "Game.h"

int main()
{
    Game* game = new Game(10);
    game->play();
    delete game;
    
    return 0;
}