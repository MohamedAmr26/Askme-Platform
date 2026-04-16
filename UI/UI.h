
#ifndef UI_ABSTRACT
#define UI_ABSTRACT

#include <iostream>

using namespace std;

class UI{
    private:

    public:
        virtual UI* Clone() = 0;
        virtual int WelcomePage() = 0; // i don't know
        virtual pair<string, string> RegisterPage() = 0;
        virtual pair<string, string> LoginPage() = 0;
        virtual int InitialPage(string username, int id) = 0; // press 0 to exit
};



#endif

// try const functions