#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
//#include "funcs.h"

TEST_CASE("Profile class"){
    Profile p1("marco", "Marco");  
    Profile p2("tarma1", "Tarma Roving");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
    p1.setDisplayName("Marco Rossi"); 
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

}