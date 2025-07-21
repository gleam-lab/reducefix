#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Define possible moves
    const vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = S[i]; // Default to using the current move
        
        // Check all possible moves against the current move
        for (char n : hand) {
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        
        // Add the score to the total
        total += score;
        
        // Update the list of available moves for the next iteration
        vector<char> next(hand.begin(), hand.end());
        next.erase(remove(next.begin(), next.end(), use), next.end());
    }
    
    cout << total << endl;
    return 0;
}