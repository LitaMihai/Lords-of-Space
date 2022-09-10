#include "Game.h"
#include <time.h>

int WinMain()
{
    srand(static_cast<unsigned>(time(0)));
    Game game;

    game.run();

    //End of application
    return 0;
}