#include <iostream>
#include <string>
using namespace std;

// Function to determine the winning move against a given move
char winning_move(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case (shouldn't occur with valid input)
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Forward pass: count maximum possible wins by choosing optimal moves
    int forward_wins = 0;
    char prev_move = 'X'; // Initialize with invalid move
    
    for (int i = 0; i < n; i++) {
        char optimal_move = winning_move(s[i]);
        if (optimal_move != prev_move) {
            forward_wins++;
            prev_move = optimal_move;
        } else {
            // If we can't win this round, choose a move that doesn't lose
            // This allows us to potentially win the next round
            prev_move = s[i];
        }
    }
    
    // Backward pass: alternative approach
    int backward_wins = 0;
    prev_move = 'X'; // Reset
    
    for (int i = n-1; i >= 0; i--) {
        char optimal_move = winning_move(s[i]);
        if (optimal_move != prev_move) {
            backward_wins++;
            prev_move = optimal_move;
        } else {
            prev_move = s[i];
        }
    }
    
    // The answer is the maximum between the two approaches
    cout << max(forward_wins, backward_wins) << endl;
    
    return 0;
}