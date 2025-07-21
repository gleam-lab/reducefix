#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    const vector<char> hand = {'R', 'P', 'S'};
    vector<int> count(3, 0); // Count of R, P, S
    
    // Count occurrences of each character in the string
    for(char c : S) {
        if(c == 'R') count[0]++;
        else if(c == 'P') count[1]++;
        else if(c == 'S') count[2]++;
    }
    
    // Determine the best move based on the counts
    char bestMove;
    int bestScore = 0;
    for(int i = 0; i < 3; ++i) {
        int score = 0;
        for(int j = 0; j < 3; ++j) {
            if((i + 1) % 3 == j) { // Winning condition
                score += count[j];
            }
        }
        if(score > bestScore) {
            bestScore = score;
            bestMove = hand[i];
        }
    }
    
    // Calculate the maximum score using the best move
    int total = 0;
    for(char c : S) {
        if(bestMove == c || (bestMove == 'R' && c == 'S') || (bestMove == 'P' && c == 'R') || (bestMove == 'S' && c == 'P')) {
            total++;
        }
    }
    
    cout << total << endl;
    return 0;
}