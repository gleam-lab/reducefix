#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Initialize variables
    int count = 0;
    char previous = 'X'; // Initialize with 'X' to handle the first character comparison correctly
    
    // Iterate through the string
    for (char current : s) {
        // If the current character is a losing character ('R' against 'S', 'S' against 'P', 'P' against 'R')
        // and it's different from the previous character, it's a valid move
        if ((previous == 'R' && current == 'S') ||
            (previous == 'S' && current == 'P') ||
            (previous == 'P' && current == 'R')) {
            count++;
        }
        previous = current; // Update previous character
    }
    
    // Output the count of valid moves
    cout << count << endl;
    
    return 0;
}