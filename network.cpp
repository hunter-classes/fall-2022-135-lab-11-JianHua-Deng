#include "network.h"

//Constructor
Network::Network(){
    //Task B
    numUsers = 0;
    //Task C making following 2d array to be false
    for(int i = 0; i < MAX_USERS; i++){
        for(int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }//end inner for loop
    }//end for loop
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

 // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool Network::follow(std::string usrn1, std::string usrn2){
    //if both username exists in the network
    if(findID(usrn1) != -1 && findID(usrn2) != -1){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }else{
        return false;
    }//end else codnition
 }//end follow function