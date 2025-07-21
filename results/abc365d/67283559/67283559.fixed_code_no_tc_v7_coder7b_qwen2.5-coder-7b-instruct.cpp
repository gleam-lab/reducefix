#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Define the possible moves
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use;
        
        // Check all possible moves to see which one beats the current move
        for (char n : hand) {
            if ((n == 'R' && S[i] == 'S') ||
                (n == 'P' && S[i] == 'R') ||
                (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        
        // If no move beats the current move, use the current move itself
        if (score == 0) use = S[i];
        
        // Calculate the total score
        total += score;
        
        // Update the list of possible moves
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());
    }
    
    cout << total << endl;
    return 0;
}