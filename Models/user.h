#include <iostream>

using namespace std;

#ifndef USER
#define USER

class User{
    private:
        string name;
        int id;
        static int count;
    public:
        User(string name) : name(name){
            id = count++;
        }
        const User& get_user_from_id();
        string get_name() const { return name; }
        int get_id() const { return id; }
};
int User::count = 0;

#endif

// try const functions