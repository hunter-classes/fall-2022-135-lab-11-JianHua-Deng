#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main(){
    Profile profile1("Metails", "SuperIdol's Smile");
    std::cout << profile1.getFullName() << "\n";

    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)

    Network nw2;
    // add three users
    nw2.addUser("mario", "Mario");
    nw2.addUser("luigi", "Luigi");
    nw2.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw2.follow("mario", "luigi");
    nw2.follow("mario", "yoshi");
    nw2.follow("luigi", "mario");
    nw2.follow("luigi", "yoshi");
    nw2.follow("yoshi", "mario");
    nw2.follow("yoshi", "luigi");

    nw2.printDot();

    return 0;
}