#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Initialize variables
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = S[i];
        
        // Check all possible moves against the current character
        for (char n : hand) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        
        // Update total score and remaining options
        total += score;
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());
    }
    
    cout << total << endl;
    return 0;
}