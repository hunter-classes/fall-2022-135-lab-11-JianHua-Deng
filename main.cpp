#include <iostream>
#include "profile.h"

int main(){
    Profile profile1("Metails", "SuperIdol's Smile");
    std::cout << profile1.getFullName() << "\n";

    return 0;
}