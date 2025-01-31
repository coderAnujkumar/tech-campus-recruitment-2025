#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

void extractLogsByDate(const string& filename, const string& date) {
    ifstream logFile(filename, ios::in);
    
    if (!logFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string logDatePrefix = date;

    string outputFileName = "../output/output_" + date + ".txt"; 
    ofstream outputFile(outputFileName, ios::out);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not create output file " << outputFileName << endl;
        return;
    }

    string line;

    while (getline(logFile, line)) {
        if (line.compare(0, logDatePrefix.size(), logDatePrefix) == 0) {
            outputFile << line << endl;
        }
    }

    logFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <YYYY-MM-DD>" << endl;
        return 1;
    }

    string date = argv[1];

    string logFile = "logs_2024.log";

    extractLogsByDate(logFile, date);

    return 0;
}
