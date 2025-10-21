// show Main Menu.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;
}
