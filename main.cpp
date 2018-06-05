#include <iostream>
#include "allClasses.h"

int main() {
    Zoo z1( "Zoological Center Tel Aviv Ramat Gan Safari Israel", "1 Hatzvi Ave, Ramat Gan", 90, "8:00", "20:00" );

    z1.AddAnimal( new Horse( "GRAY", 2, 20, 11, 3, "Selle Francais" ) );
    z1.AddAnimal( new Mermaid( "BROWN", 3, 65.5, 9, 2, 2, 4, "Ariel", "Princess" ) );

    cout << "here" << endl;
}