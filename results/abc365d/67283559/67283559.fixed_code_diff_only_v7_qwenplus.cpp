#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> choices = {'R', 'P', 'S'};
    auto getWinner = [](char hand1, char hand2) -> int {
        if ((hand1 == 'R' && hand2 == 'S') || 
            (hand1 == 'P' && hand2 == 'R') || 
            (hand1 == 'S' && hand2 == 'P')) {
            return 1; // hand1 beats hand2
        }
        return 0;
    };
    
    int maxScore = 0;
    
    // Try all possible starting hands
    for (char firstHand : choices) {
        vector<char> available = choices;
        // Remove the first hand we're trying
        available.erase(remove(available.begin(), available.end(), firstHand), available.end());
        
        int score = 0;
        char currentHand = firstHand;
        
        for (int i = 0; i < N; i++) {
            // Check if current hand wins
            if (getWinner(currentHand, S[i])) {
                score++;
            }
            
            // Update available hands for next round (remove current hand)
            if (i < N - 1) {
                // For the next move, we can't use the current hand
                // So choose the best option from remaining two
                char nextHand = available[0];
                int nextScore = getWinner(available[0], S[i+1]);
                
                if (getWinner(available[1], S[i+1]) > nextScore) {
                    nextHand = available[1];
                }
                
                currentHand = nextHand;
                
                // Update available hands: remove the chosen next hand
                vector<char> newAvailable;
                for (char c : choices) {
                    if (c != currentHand) {
                        newAvailable.push_back(c);
                    }
                }
                available = newAvailable;
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    return 0;
}