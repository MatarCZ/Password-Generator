#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator
    string phrase;
    cout << "Enter phrase for password generation: ";
    cin >> phrase;
    return 0;
}