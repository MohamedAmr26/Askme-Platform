#include <iostream>

using namespace std;

class User{
    private:
        string name;
        User
    public:
        User(){

        }

        // parameterized constructor
        User(string name) : name(name){

        }

        string get_name(){
            return name;
        }

        void set_name(string new_name){
            if (new_name == "fucketol"){
                return;
            }

            name = new_name;
        }
};

class Post{
    private:
        string content;
    public:

};

int main(){
    User user1("Hamada");

    if (user1.get_name() == "Hamada"){
        user1.set_name("ZOZ");
    }

    cout << user1.get_name() << endl;
}