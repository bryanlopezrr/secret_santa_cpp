#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std; 


map<string, string> secret_santa(vector<string> participants_p){
    map<string, string> assignment; 

    vector<string> givees = participants_p;

    int max = participants_p.size();
    srand(time(0)); 

    int i = 0; 

    while(i < max){
        
        int random_num = rand()%max;    

        if(random_num == i){
            continue;
        }

        if(givees[random_num] == "X"){
            continue;
        }
        
        assignment.insert(pair<string, string>(participants_p[i], givees[random_num]));    
        givees[random_num] = "X";        

        i++;
    }

    // cout << "ASSIGNEMNETS\n";
    // for(auto map_assignment : assignment){
    //     cout << map_assignment.first << " --> " << map_assignment.second << endl;
    // }


    return assignment; 

}

void welcome_message(){

    cout << endl;
    cout << endl;
    cout << "  .-\"\"-.\t\t** ** ** ** ** ** ** ** ** **\n";
    cout << " /,..___\\\t\t*       MERRY CHRISTMAS     *\n";
    cout << "() {_____}\t\t** ** ** ** ** ** ** ** ** **\n";
    cout << "  (/-@-@-\\)\n";
    cout << "  {`-=^=-'}\n";
    cout << "  {  `-'  } Enter the amount of participants and their names \n";
    cout << "   {     }  into the program for it to randomize the exchange\n";
    cout << "    `---'\n"; 
    cout << endl;
}



int main(){


    welcome_message();

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

    /*
        assign the secret santa function
    */

   map<string, string> final_assignments = secret_santa(participants); 

    // for(auto final_assignment : final_assignments){
    //     cout << final_assignment.first << " --> " << final_assignment.second << endl;
    // }


    return 0; 
}