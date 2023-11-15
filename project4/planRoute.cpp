// <Your Name> 
// <Partner uniqname (or "none")> 
// <Lab Section Number(s)> 
// <Date Submitted>

//------------------------------------------------------
// AUTOGRADER INFO -- IGNORE BUT DO NOT REMOVE 
// test_cases: true
// feedback('all')
// 35b24e49-2842-4603-8ba7-0f656200c2d1
//------------------------------------------------------

// g++ -std=c++11 -Wall -pedantic planRoute.cpp -o planRoute

/* 
Get the filenames for each file from the user
Open the files (gracefully exit the program if either/both of the files cannot be opened)
Read in the information in the locations file
If a planet is outside the driver’s range (the “grid”), print a message to the user and do not include that planet in your route planning
Read in the information in the names file
Correct any data corruption in the planet names
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Planet() {
    vector<int> driverInfo;
    int planetRow;
    int planetCol;
    char planetSymbol;
    int planetID;
};

struct Names() {
    int nameId;
    string nameLoc;
};

void loadNames(vector<Names> &name, ifstream &input2) {
    Names nameVec;
    while(input2 >> nameVec.nameId >> nameVec.nameLoc){
        name.push_back(nameVec);
    }

}

void fixCorruption(vector<Names> &name) {
    for(size_t i = 0; i < name.size(); ++i){
        for(int j = 0; j < name.nameLoc[i].length(); ++j){
            if(name.nameLoc[i][j] == "X"){
                name.nameLoc[i][j] == ' ';
            }
            if(name.nameLoc[i][j] == "_"){
                name.nameLoc[i][j] == " ";
            }
        }
    }

}

void parseFile(istream &input; vector<Planet> &planets) {
    // put everything from the file into a vector of strings to be parsed through
    string temp;
    vector<string> tempVec;
    while(input >> temp) {
        tempVec.push_back(temp);
    }
    
    // push the first six strings->ints into the pplanet struct
    vector<int> driver;
    for(int i = 0; i < 6; ++i) {
        driver.push_back(int(tempVec.at(i)));
    } 
    tempVec.erase(tempVec.begin(), tempVec.begin() + 6);
    
    // push everything into the vector of structs
    for(int i = 0; i < int(temp.size())/4; ++i) {
        Planet temp;
        temp.planetRow = int(temp.at(i));
        temp.planetCol = int(temp.at(i+1));
        temp.planetSymbol = char(temp.at(i+2));
        temp.planetID = int(temp.at(i+3));
        planets.push_back(temp);
    }
}




int main() {
    // prompt user for files to be opened
    string locationsFilename;
    string namesFilename;
    cout << "Enter Locations Filename:"
    cin >> locationsFilename;
    cout << "Enter Names Filename:"
    cin >> namesFilename;

    // open files and exit if it doesn't work
    ifstream input1(locationsFilename);
    ifstream input2(namesFilename);
    if(!input1.is_open() || !input2.is_open()) {
        cout << "Input file could not be opened" << endl;
        return 1;
    }

    int arr[]
}

//read in the files given (all locations, planets with id numbers)
//create a vector of vectors (struct) for the map
//place correct planet symbol at the specific location of that planet on the map
//get rid of _ and X where they appear and replace with spaces
//nearest neighbor algorithm
//write to a journey.txt file for final
//only do work with planets that are in range of the driver
//ignore planets that are out of range, print them to terminal with the id number
