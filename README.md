Rodayna El Khouly 900221860
 Janna Osama 900225228
 Ahmed Bamadhaf 900205060
 
 Report Project (1) DDI- Logic Circuits Simulator
 
 Purpose:
 The given code simulates the behavior of digital circuits using stimuli and gate definitions from
 external files. It includes functions for reading stimulus data, gate definitions, and circuit
 designs, as well as simulating the evolution of wire values over time.
 
 Used data structures:
 Vectors:
 ● vector<vector<string>>: Used to represent a variety of data structures, such as stimulus
 data, gate specifications, and gate configurations. Inner vectors include tokens (separated
 by commas) from lines in files.
 ● vector<string>: Files are used to store tokens extracted from lines.
 
 Maps:
 ● map<string, int>: This map data structure is used to store information about wires. The
 key represents the name of the wire (string), and the value represents its associated
 stimuli value (integer). Stores the name of wires and their corresponding stimuli values.
 
 Used Algorithms:
 1- File Input/Output (I/O):
 ● Thecodeutilizes file input/output operations to read data from external files
 2- String Tokenization:
 ● Thecodetokenizes strings using the stringstream and getline() functions. It splits
 lines read from files into tokens based on the comma separator (,) and stores them
 in vectors.
3- Searching and Updating:
 ● Various algorithms are used for searching and updating wire values and gate
 outputs:
 ● Thefind() algorithm from the <algorithm> library is used to search for
 updated wire names in the updated_wires vector.
 ● Bitwise operations (&, |) are used to calculate gate outputs (e.g., for AND
 and OR gates).
 ● Conditional statements are used to determine gate types and perform
 corresponding operations.
 ● Theclear() function is used to clear the updated_wires vector at the end of
 each iteration.
 4- Conversion: ‘ convert_to_int()’
 ● Thefunction extracts integers from a string and returns them as integer values. In
 our code, this method is mostly used to extract integers from strings expressing
 numerical values, like the timestamps and wire the values in file-read events.
 
 Usage:
 ● isused to extract integers from strings representing timestamps and wire values in
 file-read events. These integers are then utilized to perform comparisons,
 calculations, and updates during digital circuit simulation.
 Functions and Their Purposes:
 read_stimuli_file(const string& filename):
 ● Readsstimuli data from a file.
 readLibFile(const string& filename):
 ● Readsgate definitions from a library file.
 extractGateDefinitions(const string& filename):
 ● Readscircuit configurations from a circuit file, distinguishing between wire declarations
 and gate definitions.
 Testing
Creating 5 test circuits, testing them manually using truth tables.
 Then we created the waveform manually to check the delay, we simulated the delay.
Followed by this we tested the circuits to make sure our truth tables were correct and that the
 circuits work.
After testing these circuits we implemented the files and started our code.
 The code starts with increasing the time stamp and reads every gate
 
 Unit Testing:
 ● Wethoroughly check each function, like reading stimuli files or gate definitions,
 individually. For example, we make sure that functions like read_stimuli_file(),
 readLibFile(), and extractGateDefinitions() work correctly on their own.
 
 Integration Testing:
 ● Wealsotest how these functions work together. We ensure that they interact
 smoothly with each other and with the data structures they rely on.
 
 Debugging:
 ● Weusedebuggingtools to find and fix any mistakes or inconsistencies in our
 simulation results. This allows us to identify problems quickly and make our code
 more reliable.
 
Challenges:
 ● Reading and parsing data from external files (such as stimuli files and gate library files)
 can be error-prone, especially with varying file formats and data structures.
 ● Ourlibrary file was not being read but we managed to fix it.
 ● Wearereceiving an output of
 1099 w2 0
 1999 w2 1
 While 99 is not even a timestamp in our files.
 ● Wearefacing an issue with the time stamp; the output isn’t correct.
 ● NORgateisnot as efficient.
 ● Wearefacing a problem with the access of gate 2 and 3. They are not being read.
 ● DuetoRamadan, we faced problems meeting as each of us had time management issues.
 
 The contributions of each member
 Please note: we worked on this project as a group. We met and worked on it together.
 First meeting:
 ● Rodayna, Janna and Ahmed composed the 5 circuits.
 ● Rodayna drew the circuits manually.
 ● Janna and Rodayna did the truth tables.
 ● Ahmedworkedonthe waveforms.
 Second meeting:
 ● Thethree of us worked on the logic.
 ● Rodayna and Janna worked on the functions of each gate.
 ● AhmedandJanna Worked on the Main function.
 Third meeting:
 ● Weaddressed the comments that were written in github by the Dr.
● Wehavefixed some of the bugs that occurred in the first code ( reading the rest of the
 gates )
 Forth meeting:
 ● Wefixedthe bugs, and completed the rest of the code.
 Side Notes
 Weused chat gpt to help us with creating the logic of the code.
 Wealso used it for debugging our errors and functions.
 Weused Replit to share the codes and work together in the same environment and then we push
 on github.
