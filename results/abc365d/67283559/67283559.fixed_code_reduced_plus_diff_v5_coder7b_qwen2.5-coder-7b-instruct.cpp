#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Initialize scores and hands
    vector<int> scores(3, 0); // R, P, S
    vector<char> hands = {'R', 'P', 'S'};
    vector<char> nextHands = {'R', 'P', 'S'};
    
    // Calculate initial scores and update nextHands
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((hands[j] == 'R' && S[i] == 'S') ||
                (hands[j] == 'P' && S[i] == 'R') ||
                (hands[j] == 'S' && S[i] == 'P')) {
                scores[j]++;
                break;
            }
        }
    }
    
    // Find the best choice for the first move
    int bestIndex = max_element(scores.begin(), scores.end()) - scores.begin();
    char bestChoice = hands[bestIndex];
    
    // Remove the best choice from hands
    nextHands.erase(remove(nextHands.begin(), nextHands.end(), bestChoice), nextHands.end());
    
    // Calculate the maximum score with the best choice
    int maxScore = *max_element(scores.begin(), scores.end());
    
    // Try all other choices as the second move
    for (char choice : nextHands) {
        scores[choice == 'R'] = 0;
        scores[choice == 'P'] = 0;
        scores[choice == 'S'] = 0;
        
        for (int i = 0; i < N; ++i) {
            if ((choice == 'R' && S[i] == 'S') ||
                (choice == 'P' && S[i] == 'R') ||
                (choice == 'S' && S[i] == 'P')) {
                scores[choice == 'R']++;
            } else if (choice == S[i]) {
                scores[choice == 'R']++;
            }
        }
        
        maxScore = max(maxScore, *max_element(scores.begin(), scores.end()));
    }
    
    cout << maxScore << endl;
    return 0;
}