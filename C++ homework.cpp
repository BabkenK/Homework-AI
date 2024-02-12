#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

const int MAX_NAMES = 100;

void processText(std::ifstream &inputFile, std::string nameDatabase[], int &nameCount) {
    std::string line, word;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

            bool found = false;
            for (int i = 0; i < nameCount; ++i) {
                if (word == nameDatabase[i]) {
                    std::cout << "X ";
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << word << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ifstream databaseFile("database.txt"), inputFile("input.txt");
    std::string nameDatabase[MAX_NAMES];
    int nameCount = 0;

    while (std::getline(databaseFile, nameDatabase[nameCount++], ','));

    processText(inputFile, nameDatabase, nameCount);

    std::cout << "\nName Counts:\n";
    for (int i = 0; i < nameCount; ++i) {
        std::cout << nameDatabase[i] << ": " << "\n";
    }

    databaseFile.close();
    inputFile.close();

    return 0;
}