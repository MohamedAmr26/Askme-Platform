#include <iostream>
#include "Services\UI.h"

using namespace std;

class terminalUI : public UI
{
    // add verfecation class later
    public:
        int WelcomePage()                                       
        {                                       
            cout << " || Welcome to AskMe platform ||" << endl;                                     
            cout << "_________________________" << endl;                                        
            cout << "1.Login \n 2.Register \n 0.Exit" << endl;                                      
            int option;                                     
            cin >> option;                                    
            return option;                                      
        }

        pair<string, string> RegisterPage(){
            string U_name;
            cout << "Enter your username: " << endl;
            cin >> U_name;

            cout << "Enter your password: " << endl;
            string U_password;
            cin >> U_password;

            cout << "Confirm your password: " << endl;
            string U_confirm;
            cin >> U_confirm;

            while (U_password != U_confirm){
                cin >> U_confirm;
                if (U_password != U_confirm){
                    cout << "Password does not match, please retry\n";
                }
            }
            pair<string,string> User_account;
            User_account = make_pair(U_name, U_password);
            return User_account;

        }

        pair<string, string> LoginPage(){
            cout << "|| Ask me platform ||" << endl;
            string U_name ;
            string U_password ;
            cout << "Your User name: " << endl;
            cin >> U_name ;
            cout << "Password: " << endl;
            return U_account = make_pair(U_name, U_password) 
        }

        int InitialPage(string username, int id){

            cout << " || Main Page || " << endl; // adjustments later , press 0 to exit

            return 1;
        }

        void Error_massage(){
            cout << "--There is an Error with your login/register please try again--"
            return;
        }
};