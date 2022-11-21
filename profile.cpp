#include "profile.h"
#include <string>
// Profile constructor for a user (initializing 
// private variables username=usrn, displayname=dspn)
Profile::Profile(std::string usrn, std::string dspn){
    username = usrn;
    displayname = dspn;
}//end Profile constructor

// Default Profile constructor (username="", displayname="")
Profile::Profile(){
    username = "";
    displayname = "";
}//end default Profile constructor

// Return username
std::string Profile::getUsername(){
    return username;
}//end getUsername function

// Return name in the format: "displayname (@username)"
std::string Profile::getFullName(){
    return displayname + " " + "(@" + username + ")";
}//end getFullName function

void Profile::setDisplayName(std::string dspn){
    displayname = dspn;
}//end setDisplayName function