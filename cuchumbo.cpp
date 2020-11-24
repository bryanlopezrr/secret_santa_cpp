#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main(){

    // cout << "Hello this seems to work:\n";

    vector<string> participants; 
    string name; 
    int number_participants = 0; 


    cout << "How many people will participate? \n";
    cin >> number_participants;
    cin.ignore(1000, '\n'); 

    while( number_participants ){

        cout << "Enter a participants name\n";
        getline(cin, name); 

        participants.push_back(name); 
        number_participants--; 
    }



    // for (string name : participants){

    //     cout << name << endl;
    // }



    return 0; 
}