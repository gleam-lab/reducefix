#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    
    // Analysis of moves for the first player
    for (int i = 0; i < N; i++) {
        int score = 0;
        char bestMove = 0; // Initialize to zero to represent no move found yet
        for (char c : hand) {
            if ((c == 'R' && S[i] == 'S') || (c == 'P' && S[i] == 'R') || (c == 'S' && S[i] == 'P')) {
                score++;
                bestMove = c;
                break; // Best move found, break out of the loop
            }
        }
        total += score; // Add the score to the total
        
        // Remove the best move from the available moves for the next round
        hand.erase(remove(hand.begin(), hand.end(), bestMove), hand.end());
    }
    
    // Reset the hand for the second player and analysis of moves
    hand = {'R', 'P', 'S'};
    int total2 = 0;
    for (int i = 0; i < N; i++) {
        int score = 0;
        char bestMove = 0; // Initialize to zero to represent no move found yet
        for (char c : hand) {
            if ((c == 'R' && S[i] == 'S') || (c == 'P' && S[i] == 'R') || (c == 'S' && S[i] == 'P')) {
                score++;
                bestMove = c;
                break; // Best move found, break out of the loop
            }
        }
        total2 += score; // Add the score to the total
        
        // Remove the best move from the available moves for the next round
        hand.erase(remove(hand.begin(), hand.end(), bestMove), hand.end());
    }
    
    // Output the maximum score between the two players
    cout << max(total, total2);
    
    return 0;
}