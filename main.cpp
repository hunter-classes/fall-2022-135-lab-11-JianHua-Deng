#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main(){
    Profile profile1("Metails", "SuperIdol's Smile");
    std::cout << profile1.getFullName() << "\n";

    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    for(int i = 2; i < 20; i++){
        std::cout << nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << std::endl;   // true (1)
    }
    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)

    return 0;
}