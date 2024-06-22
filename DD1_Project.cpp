#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std ;


map<string, int > wires;
vector<vector<string>> read_stimuli_file(const string& filename) {

    vector<vector<string>> stimuli_data; // Vector of vector of strings to store stimuli data
    ifstream file(filename); // Open the file for reading

    if (!file.is_open()) { // Check if the file is not open
        cerr << "Error opening file: " << filename << endl; // Print error message to standard error stream
        return stimuli_data; // Return empty stimuli data
    }

    string line; // String to store each line of the file
    while (getline(file, line)) { // Loop through each line of the file
        vector<string> tokens; // Vector to store tokens of the line
        string token; // String to store each token
        size_t pos = 0; // Position variable for finding comma separator
        while ((pos = line.find(',')) != string::npos) { // Loop until no more comma found
            token = line.substr(0, pos); // Extract token from the beginning of the line to the comma
            tokens.push_back(token); // Add token to the vector of tokens
            line.erase(0, pos + 1); // Erase the token and comma from the line
        }
        tokens.push_back(line); // Push the remaining part of the line (last token)
        stimuli_data.push_back(tokens); // Add vector of tokens to the vector of stimuli data
    }

    file.close(); // Close the file
    return stimuli_data; // Return the vector of vector of strings containing stimuli data
}

vector<vector<string>> readLibFile(const string& filename) {
    vector<vector<string>> result;
    ifstream file("lib.lib");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> vec;
        string temp_string;
        while (getline(ss, temp_string, ',')) {
            vec.push_back(temp_string);

        }

        result.push_back(vec);
    }

    return result;
}
int convert_to_int (string x){
    string clean = "";
    for (auto i :x)  if ( isdigit(i))clean.push_back(i);
//    cout << "\nclean" << "" << clean << "\n";
    return stoi(clean);
}

vector<vector<string>> extractGateDefinitions(const string& filename) {
    vector<vector<string>> gateDefinitions;
    ifstream file(filename);
    string line;
    bool gates = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string token;
        if (line=="Components:") {
            gates = 1;
            continue;
        }

        if (!gates) {
            if (line !="Inputs:") wires [line] = 0;
        }
        else {
            int idx = 0;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
                if (idx>=2) wires[token] = 0;
                idx++;
            }
        }

        if (!tokens.empty())gateDefinitions.push_back(tokens);
    }

    return gateDefinitions;
}

int main() {

    vector<vector<string>> GateDef = readLibFile("lib.lib");  // reads from the library file
    auto Circut = extractGateDefinitions("circuit1.cir"); // read from the circuit file, takes the gate name, examine which gate it is ( 2d vector )
    vector <vector <string>> events = read_stimuli_file("stimuli1.stim"); // reads the events from the stimlui.stim file
    map <string, pair<int,int>> update_values; // the future value of the wire at time time
    int time=0;
    vector <string> updated_wires;
    for (auto i : wires) updated_wires.push_back(i.first); // for ( int i ; i< wires.size(); i++ ), map can not access it except this way
    while (time < 10000){
//         checking new events
//         updating values of wires
        for (auto event : events ){
           int time_stamp = convert_to_int(event[0]);    // this loop is to get the time stamp of each wire
           string wire_name = event[1];
           int wire_value = convert_to_int(event[2]);

           if (time == time_stamp){
               wires[wire_name]= wire_value; // assigns the wir
               updated_wires.push_back(wire_name);
               cout << time << "  " << wire_name << "  " << wire_value << "\n";
           }
        }
        for (auto i : update_values) {

            if (i.second.first == time) {           // second (int, int), time of updating the gate  ,first (string), type of the gate
                wires[i.first] = i.second.second;
                cout << i.second.first << "  " << i.first << "  " << i.second.second << "\n";
                updated_wires.push_back(i.first);
            }
        }

        for (int k = 0; k< Circut.size();k++){

            if (Circut[k][1]=="AND"){ // function to check the gate type
                int temp = 1;                        // to calculate the new values
                bool skip = 1;                       // to skip the evaluation of the gate when there is no new event
                for (int i=3;i<Circut[k].size();i++){               // to know the inputs
                    temp = temp & wires[Circut[k][i]];               // evalaute the gate output
                    bool search = 0;
                    for (int j = 0; j<updated_wires.size();j++) {
                        if (updated_wires[j]==Circut[k][i]) search = 1;
                    }
                    if (search) skip = 0;
                }
                // update the value of the wire after some time

                if (skip==0) update_values[Circut[k][2]] = {time + convert_to_int(GateDef[0][3]), temp};

            }
            if (Circut[k][1]== "OR"){
                bool skip = 1;
                int temp = 0;
                for (int i=3;i<Circut[k].size();i++){
                    temp = temp | wires[Circut[k][i]];
                    auto lookup = find(updated_wires.begin(), updated_wires.end(), Circut[k][i]);
                    if (lookup!=updated_wires.end()) skip = 0;
                }
                // update the value of the wire after some time
                if (skip==0) update_values[Circut[k][2]] = {time + convert_to_int(GateDef[2][3]) , temp};

            }

            if (Circut[k][1]=="NOT"){
                bool skip = 1;
                int temp = (wires[Circut[k][3]])?0:1;

                for (string wire_name : updated_wires) cout << wire_name << " " ;
                if (updated_wires[0]==Circut[k][3]) {
                    skip = 0;
                }
                if (skip==0){
                    update_values[Circut[k][2]] = {time + convert_to_int(GateDef[2][3]) , temp};
                }
            }
            updated_wires.clear();
        }
        time++;
    }

    return 0;
}