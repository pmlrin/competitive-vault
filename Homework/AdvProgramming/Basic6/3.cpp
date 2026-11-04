#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string filename = "test.txt";

    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return 1;
    }

    outFile << "test file input." << endl;
    outFile << "5116888!" << endl;
    outFile.close();

    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}
