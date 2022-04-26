#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <fstream>

using namespace std;

int main() {

    ifstream inFile("state_flowers.txt");
    string line, temp, state;
    map<string, string> state_flowers;

    while(!inFile.eof()) { //Get states and flowers
        getline(inFile, line);
        temp = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);

        state_flowers.insert(pair<string, string>(temp, line));
    }

    inFile.close();

    do {
        cout << "Enter State name (press <enter> to quit): ";
        getline(cin, state);

        if(state == "") continue; //go to the end of the loop, causing it to end

        if(state_flowers.find(state) != state_flowers.end()) { //Make sure it is a valid state
            cout << state_flowers[state] << " is the state flower for " << state << endl << endl;
        }
        else {
            cout << "State " << state << " not found! Please try again." << endl << endl;
        }
    } while(state != "");

    return 0;
}