#include <iostream>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    
    int wins = 0;
    char winmove = 'R'; // The winning move for rock, paper, scissors is rock, paper, scissors respectively
    char prev = 'R';   // The previous character in the string S
    
    for (char c : S) {
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        
        // Increment wins if the current winning move is different from the previous move
        if (winmove != prev) {
            wins++;
            prev = winmove; // Update the previous move to the current winning move
        } else {
            prev = c; // If the character and the winning move are the same, update prev to the character
        }
    }
    
    cout << wins;
    return 0;
}