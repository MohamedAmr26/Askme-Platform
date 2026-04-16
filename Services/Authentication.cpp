#include "Authentication.h"

string AuthenticationService::Get_password(string username){
    return accounts.count(username)? accounts[username] : "";
}

bool AuthenticationService::Create_account(string username, string password){
    if (Check_account(username)) return false;

    accounts[username] = password;
    return true;
}

AuthenticationService::AuthenticationService(){}

AuthenticationService::AuthenticationService(ds accounts) : accounts(accounts){}

bool AuthenticationService::Check_account(string username){
    return accounts.count(username);
}

int AuthenticationService::login(string username, string password){
    if (Check_account(username) && Get_password(username) == password){
        return 1234;
    }
    return -1;
}

bool AuthenticationService::Register_user(string username, string password){
    if (Check_account(username)) return false;
    // in future add validation service to username and password

    bool res = Create_account(username, password);

    return res;
}