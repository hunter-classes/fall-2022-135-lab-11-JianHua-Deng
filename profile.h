
class Profile {
private:
    std::string username;
    std::string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(std::string usrn, std::string dspn){
      username = usrn;
      displayname = dspn;
    }//end Profile constructor

    // Default Profile constructor (username="", displayname="")
    Profile(){
      username = "";
      displayname = "";
    }//end default Profile constructor

    // Return username
    std::string getUsername(){
      return username;
    }//end getUsername function

    // Return name in the format: "displayname (@username)"
    std::string getFullName(){
      return displayname + " " + "(@" + username + ")";
    }//end getFullName function
    // Change display name

    void setDisplayName(std::string dspn){
      displayname = dspn;
    }//end setDisplayName function
};