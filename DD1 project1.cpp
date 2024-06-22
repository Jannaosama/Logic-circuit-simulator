#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> read_stimuli_file(const string& filename) {
    vector<vector<string>> stimuli_data; // Vector of vector of strings to store the data in the stimuli file
    ifstream file(filename); 

    if (!file.is_open()) { // Checks if the file name is correct or not, if it isn't or it is invalid, it give the errior message
        cerr << "Error : Invalid file " << filename << endl;
        return stimuli_data; 
    }

    string line; // String to store each line of the file
    while (getline(file, line)) { // Loop through each line of the file
        vector<string> elements; // Vector to store elements of the line
        string element; // String to store each element
        size_t counter = 0; // Counter looking for the comma to seperate the elements
        while ((counter = line.find(',')) != string::npos) { // Loop until no more commas are found
            element = line.substr(0, counter); // Extract element from the beginning of the line to the comma
            elements.push_back(element); // Add element to the vector of elements
            line.erase(0, counter + 1); // Erase the element stored in the vector elements
        }
        elements.push_back(line); // Push the remaining part of the line because the counter will not identify a comma 
        stimuli_data.push_back(elements); // Add vector of elements to the vector of stimuli data
    }

    file.close();
    return stimuli_data;
}

int main() {
   
    string filename; 
    cout << "Please enter the name of your file: "; 
    cin >> filename;

    vector<vector<string>> stimuli_vectors = read_stimuli_file(filename); 


    for (const auto& line : stimuli_vectors) { // Loop through each line in the vector of vectors
        for (const auto element : line) { // Loop through each element in the line
            cout << element << " "; 
        }
        cout << endl;
    }

    return 0;
}
