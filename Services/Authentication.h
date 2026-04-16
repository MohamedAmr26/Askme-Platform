#ifndef AUTHENTICATION_SERVICE
#define AUTHENTICATION_SERVICE

#include <iostream>
#include <map>
#include "../Models/user.h"

using namespace std;

#define ds map<string, string>
#define acc pair<string, string>

class AuthenticationService{
    private:
        map<string, string> accounts;

        string Get_password(string username);
        bool Create_account(string username, string password);
    public:
        AuthenticationService();
        AuthenticationService(ds accounts);
        bool Check_account(string username);
        int login(string username, string password);
        bool Register_user(string username, string password);
};


#endif

// try const functions