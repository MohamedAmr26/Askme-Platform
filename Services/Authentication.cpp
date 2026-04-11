#include <iostream>
#include <map>

#include "Models/user.h"

#define ds map<string, string>
#define acc pair<string, string>


using namespace std;

class AuthenticationService{
    private:
        map<string, string> accounts;

        string Get_password(string username){
            return accounts.count(username)? accounts[username] : "";
        }
        bool Create_account(string username, string password){
            if (Check_account(username)) return false;

            accounts[username] = password;
            return true;
        }

    public:
        AuthenticationService(){}
        AuthenticationService(ds accounts) : accounts(accounts){

        }
        bool Check_account(string username){
            return accounts.count(username);
        }
        string login(string username, string password){
            if (Check_account(username) && Get_password(username) == password){
                return username;
            }
            return "";
        }
        bool Register_user(string username, string password){
            if (Check_account(username)) return false;
            // in future add validation service to username and password

            bool res = Create_account(username, password);

            return res;
        }
};

/*
optional in c++:

auto result = login("alice", "1234");

// Method 1: check then unwrap
if (result.has_value()) {
    result->doSomething();   // access like a pointer
    result.value().doSomething();  // or explicitly
}

// Method 2: shorthand (most common)
if (result) {
    result->doSomething();
}

// Method 3: default fallback
User u = result.value_or(User("guest"));

*/