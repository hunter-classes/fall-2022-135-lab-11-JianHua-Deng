#include <iostream>
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

 void Network::printDot(){
    std::string connectionString;
    std::string usrnstring;
    bool firstTrue = true;//This is to get the username every first time follow[row] is true is recognized
    for(int row = 0; row < MAX_USERS; row++){
        for(int col = 0; col < MAX_USERS; col++){
            if(following[row][col] == true){
                connectionString += "\t\"@" + profiles[row].getUsername() + "\" -> \"@" + profiles[col].getUsername() + "\"\n";
                if(firstTrue){
                    usrnstring += "\t\"@" + profiles[row].getUsername() + "\"\n";
                    firstTrue = false;
                }//end inner if condition
            }//end if condition
        }//end inner for loop
        firstTrue = true;
    }//end for loop
    std::string finalString = "digraph {\n" + usrnstring + "\n" + connectionString + "}\n";
    std::cout << finalString;
 }//end printDot function

 bool Network::getFollowing(int row, int col) const{
    return following[row][col];
 }//end getFollowing funcs