#include <iostream>
#include <map>

#include "Services/Authentication.h"
#include "UI/UI.h"

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

    public:

    application(UI* My_UI) 
    { 
        App_UI = My_UI->Clone();
        auth = AuthenticationService(accounts);
    }

    void Run(){
        int option = App_UI->WelcomePage();

        switch (option){
            case 1:
                process_login();
                break;
            case 2:
            {
                bool res = process_register();

                if (res)
                    process_login();
                else
                    Run();
                break;
            }
            default:
                return;
        }
    }

    void process_login();
    bool process_register();
};

void application::process_login(){
    pair<string, string> credentials = App_UI->LoginPage();
    int user_id = auth.login(credentials.first, credentials.second);

    if (user_id != -1)
        App_UI->InitialPage("example username" , user_id);
}

bool application::process_register(){
    pair<string, string> credentials = App_UI->RegisterPage();
    bool result = auth.Register_user(credentials.first, credentials.second);

    return result;
}
