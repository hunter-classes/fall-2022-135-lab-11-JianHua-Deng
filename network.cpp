#include "network.h"

//Constructor
Network::Network(){
    numUsers = 0;
}//end Network constructor

// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false
bool Network::addUser(std::string usrn, std::string dspn){
    bool alphabetical = true;
    //Checks if usrn is alphabetical
    for(int i = 0; i < usrn.length(); i++){
        if(!isalpha(usrn[i]) && !isdigit(usrn[i])){
            alphabetical = false;
        }//end condition
    }//end for loop

    if(numUsers < MAX_USERS && alphabetical && findID(usrn) == -1){
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }//end if condition
    return false;
}//end addUser function