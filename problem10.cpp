#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>   //rand() function   srand() function
#include <ctime>
using namespace std;
map<string, vector<string>> lookupTable;   //we will store the lookup file into a map

void LoadLookupTable(string& lookupFile) {
    ifstream file(lookupFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            int delimiterPos = line.find(',');
            if (delimiterPos != string::npos) {   //this mean find function return a value
                string censoredWord = line.substr(0, delimiterPos);
                string alternatives = line.substr(delimiterPos + 1);
                int subDelimiterPos = 0;
                vector<string> alternativeWords;  //vector contains alternatives of word
                while ((subDelimiterPos = alternatives.find(',')) != string::npos) {
                    string alternative = alternatives.substr(0, subDelimiterPos);
                    alternativeWords.push_back(alternative);
                    alternatives.erase(0, subDelimiterPos + 1);
                }
                alternativeWords.push_back(alternatives);
                lookupTable[censoredWord] = alternativeWords;
            }
        }
        file.close();
    } else {
        cout << "Error opening the lookup file." << endl;
        exit(1);
    }
}

string GetRandomAlternative(vector<string>& alternativeWords) {
    int randomIndex = rand() % alternativeWords.size();  //indexs will be from 0 to size-1
    return alternativeWords[randomIndex];
}

void AlterMessage( string& inputFile, string& outputFile) {
    ifstream input(inputFile);
    if (input.is_open()) {
        ofstream output(outputFile);
        if (output.is_open()) {
            string word;
            while (input >> word) {
                if (lookupTable.count(word) > 0) {
                     vector<string>&alternativeWords = lookupTable[word];
                    string alternative = GetRandomAlternative(alternativeWords);
                    output << alternative << " ";
                } else {
                    output << word << " ";
                }
            }
        } else {
            cout << "Error opening the output file." << endl;
            exit(1);
        }
        input.close();
        output.close();
    } else {
        cout << "Error opening the input file." << endl;
        exit(1);
    }
}

int main() {
    srand((time(0)));  // Initialize the random seed (the point at which rand()will generate a random indexes)

    string lookupFile = "lookupTable.txt";  // Replace with your lookup table file name
    LoadLookupTable(lookupFile);

    string inputFile = "input.txt";  // Replace with your input file name
    string outputFile = "output.txt";  // Replace with your output file name
    AlterMessage(inputFile, outputFile);

    cout << "Message altered successfully." << endl;

    return 0;
}