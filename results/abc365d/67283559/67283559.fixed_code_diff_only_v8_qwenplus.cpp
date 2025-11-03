#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> choices = {'R', 'P', 'S'};
    auto getWinner = [](char a, char b) {
        if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P')) {
            return 1; // a wins
        } else if (a == b) {
            return 0; // tie
        } else {
            return -1; // b wins
        }
    };
    
    int maxScore = 0;
    
    // Try all possible starting hands
    for (char firstHand : choices) {
        vector<char> available = choices;
        // Remove the hand we're starting with
        available.erase(remove(available.begin(), available.end(), firstHand), available.end());
        
        int score = 0;
        char currentHand = firstHand;
        
        for (int i = 0; i < N; i++) {
            // Check if current hand wins
            if (getWinner(currentHand, S[i]) == 1) {
                score++;
            }
            
            // Update available hands for next round (remove the one we just used)
            if (i < N - 1) {
                // For the next move, we can't use the current hand
                // So choose the best option from remaining two
                char bestNext = available[0];
                int bestResult = getWinner(available[0], S[i+1]);
                
                if (getWinner(available[1], S[i+1]) > bestResult) {
                    bestNext = available[1];
                }
                
                currentHand = bestNext;
                // Update available to exclude the new currentHand
                available = choices;
                available.erase(remove(available.begin(), available.end(), currentHand), available.end());
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    
    return 0;
}