#include <iostream>
#include <map>

#include "models/user.h"

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
            if (Get_password(username)) return false;

            accounts[username] = password;
            cout << accounts[username]
            return true;
        }

    public:
        AuthenticationService(ds accounts) : accounts(accounts){

        }
        bool Check_account(string username){
            return accounts.count(username);
        }
        pair<bool, User&> login(string username, string password){
            User my_user = new User(username);
            if (Check_account(username) && Get_password(username) == password){
                return true;
            }
            
            return {true, my_user};
        }
        bool Register_user(string username, string password){
            if (Check_account(username)) return false;
            // in future add validation service to username and password

            bool res = Create_account(username, password);

            return res;
        }
};


int main(){

}