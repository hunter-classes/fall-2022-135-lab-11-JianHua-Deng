#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
//#include "funcs.h"

TEST_CASE("Profile class"){
    Profile p1("marco", "Marco");  
    Profile p2("tarma1", "Tarma Roving");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
    p1.setDisplayName("Marco Rossi"); 
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

}

TEST_CASE("Network class"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == true);    // true (1)
    CHECK(nw.addUser("luigi", "Luigi") == true);     // true (1)

    CHECK(nw.addUser("mario", "Mario2") == false);    // false (0)
    CHECK(nw.addUser("mario 2", "Mario2") == false);  // false (0)
    CHECK(nw.addUser("mario-2", "Mario2") == false);  // false (0)

    for(int i = 2; i < 20; i++){
        CHECK(nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) == true);   // true (1)
    }//end for loop
    CHECK(nw.addUser("yoshi", "Yoshi") == false);     // false (0)
}