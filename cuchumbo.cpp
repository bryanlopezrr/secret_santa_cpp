#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

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

    return assignment; 

}

void welcome_message(){

    cout << endl;
    cout << endl;
    cout << "  .-\"\"-.\t\t** ** ** ** ** ** ** ** ** **\n";
    cout << " /,..___\\\t\t*        FELIZ NAVIDAD      *\n";
    cout << "() {_____}\t\t** ** ** ** ** ** ** ** ** **\n";
    cout << "  (/-@-@-\\)\n";
    cout << "  {`-=^=-'}\n";
    cout << "  {  `-'  } Empiecen poniendo cuantas personas van a partipar \n";
    cout << "   {     }  junto con sus nombres y los emails de cada persona.\n";
    cout << "    `---'   El programa luego hace la seleccion para todos.\n"; 
    cout << endl;
}



int main(int argc, char* argv[]){


    welcome_message();

    vector<string> participants, participants_names; 
    string name, email; 
    int number_participants = 0; 


    cout << "Cuantas personas van a participar? \n";
    cin >> number_participants;
    cin.ignore(1000, '\n'); 
    cout << endl;

    while( number_participants ){

        cout << "Cual es su nombre?\n";
        getline(cin, name); 
        // cin.ignore(1000, '\n');

        cout << "Cual es su correo electronico?\n";
        getline(cin, email);
        // cin.ignore(1000, '\n');

        participants_names.push_back(name);
        participants.push_back(email); 
        number_participants--; 
    }

    /*
        assign the secret santa function
    */
    map<string, string> final_assignments = secret_santa(participants); 


    //Write to text file 
    ofstream file;
    file.open("assignments.txt");
    
    cout << endl;
    for(auto final_assignment : final_assignments){
        file << final_assignment.first << "-" << final_assignment.second << endl;
        // cout << final_assignment.first << " --> " << final_assignment.second << endl;
    }

    cout << "TABLA DE REFERENCIA: \n";
    cout << "NOMBRE\t\t\tEMAIL" << endl;
    for(int i = 0; i < participants_names.size(); i++){
        cout << participants_names[i] << "\t---->\t" << participants[i] << endl;
    }
    cout << endl;

    string first_arg = argv[1];
    string second_arg = argv[2];

    string python_command = "/usr/bin/python3 santa_in_python.py " + first_arg + " " + second_arg;
    int result = system(python_command.c_str());

    if(result == 0){
        cout << endl;
        cout << "Los correos electronicos fueron enviados exitosamente!\n\n";
    }
    else{
        cout << endl;
        cout << "Hubo algun error con el servicio de correo electronico\n\n";
    }

    return 0; 
}


