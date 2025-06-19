#include "pass.h"

using namespace std;

string userInput();

int main() {

    string phrase = userInput(); // Get user input for the password generation

    char map[7][3] = {
        {'q', 'a', 'z'},
        {'w', 's', 'x'},
        {'e', 'd', 'c'},
        {'r', 'f', 'v'},
        {'t', 'g', 'b'},
        {'y', 'h', 'n'},
        {'u', 'j', 'm'},
    };

    size_t phraseSize = phrase.size(); // Get the size of the input phrase
    int mapIndex = 0; // Initialize the map index

    for (size_t i = 0; i < phraseSize; i++) {
        phrase.insert(i + mapIndex + 1, string(map[mapIndex / 3 % 7], 3)); // Insert characters from the map into the phrase
        mapIndex += 3;
    }
    
    string indexingMap[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"}; // Define the indexing map for character positions

    for (size_t i = 0; i < phrase.size(); i += 4) {
        for (size_t j = 0; j < 3; j++) {
            for (char character : indexingMap[j]) {
                if (phrase[i] == toupper(character)) { // Check if the character matches any in the indexing map
                    phrase += to_string(j + 1); // Append the index of the character to the phrase
                    break; // Exit the loop once a match is found
                }
            }
        }
    }

    std::string downloads = get_downloads_path();
    if (downloads.empty()) {
        std::cerr << "Could not determine the Downloads folder path!" << std::endl;
        return 1;
    }
#ifdef _WIN32
    std::string path = downloads + "\\password.txt"; // Use backslashes for Windows paths
#else
    std::string path = downloads + "/password.txt"; // Use forward slashes for Linux paths
#endif
    std::ofstream file(path);
    if (file.is_open()) {
        file << phrase; // Write the generated password to the file
        file.close();
        std::cout << "Your password has been saved to: " << path << std::endl;
    } else {
        std::cerr << "Error: Could not write to file." << std::endl;
        return 1;
    }

    cout << "For safety purposes, we recommend renaming the .txt file or copying the password to a safe location." << endl;

    return 0; // End of the program
}

string userInput() {
    string phrase;
    cout << "Enter phrase for password generation (letters only, no spaces, no diacritis): ";
    cin >> phrase;

    // Validate input and convert to uppercase
    for (size_t i = 0; i < phrase.size(); ++i) {
        if (!isalpha(phrase[i])) {
            cout << "Invalid input. Please enter letters only." << endl;
            return userInput(); // Recursively ask for valid input
        }
        phrase[i] = toupper(phrase[i]); // Convert to uppercase
    }
    return phrase; // Return the validated and converted input
}