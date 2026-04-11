#include <iostream>
#include <map>
#include "Services\Authentication.cpp"
#include "Services\UI.h"


#define ds map<string, string>
#define acc pair<string, string>


using namespace std;

ds accounts = {
    {"zoz", "pass1"},
    {"hamada", "pass2"},
    {"ayman", "pass3"}
};

class application {

    private:

    UI* App_UI;
    AuthenticationService auth;

    void login(){
        
        string username = auth.login(App_UI->LoginPage());
        App_UI->InitialPage(username , 0);

    }

    public:
    
    application(UI* My_UI) 
    { 
        App_UI = new UI(*MY_UI);
        auth = AuthenticationService(accounts);
    }
    
    
    

    void Run(){
        
        int option = App_UI->WelcomePage();

        switch (option)
        {
        case 1:
            {
                login();
                break;
            }

        case 2:
            {
                bool result = auth.Register_user(App_UI->RegisterPage());
                if (result){    
                    login();
                } else { 
                    Run(); //recursion is bad , will be removed later 
                }
                break;
            }

        default:

            return;
        }
        
    }



};

