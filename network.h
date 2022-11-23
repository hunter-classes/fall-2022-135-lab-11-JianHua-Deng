#pragma once
#include "profile.h"
#include <string>

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
  // following[id1][id2] == true when id1 is following id2
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (std::string usrn){
    for(int i = 0; i < MAX_USERS; i++){
        if(profiles[i].getUsername() == usrn){
            return i;
        }//end condition
    }//end for loop
    return -1;
  }//end findID function
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(std::string usrn, std::string dspn);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  bool getFollowing(int row, int col) const;
};