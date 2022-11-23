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

        // add a user who does not follow others
    nw2.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        nw2.addUser(usrn, dspn);
        nw2.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw2.follow("mario2", "luigi");

    nw2.printDot();

    return 0;
}