#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> statePopulationMap;

    // Populating the map with state names and populations
    statePopulationMap["MAHARASHTRA"] = 300000;
    statePopulationMap["GUJARAT"] = 10000;
    statePopulationMap["ASSAM"] = 20000;
    statePopulationMap["PUNJAB"] = 50000;

    string state;

    // User input
    cout << "Enter the name of the state: ";
    cin >> state;

    // Convert user input to uppercase using a simplified for loop
    for (size_t i = 0; i < state.length(); ++i) {
        state[i] = toupper(state[i]);
    }

    // Direct access using map's find() function
    auto it = statePopulationMap.find(state);
    
    if (it != statePopulationMap.end()) {
        // If state is found, display the population
        cout << it->first << " has a population of " << it->second << endl;
    } else {
        // If state is not found, display error message
        cout << "State not found!" << endl;
    }

    return 0;
}
