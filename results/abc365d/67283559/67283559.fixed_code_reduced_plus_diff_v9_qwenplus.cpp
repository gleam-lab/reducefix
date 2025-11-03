#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Define the winning moves
    auto wins = [](char a, char b) -> bool {
        return (a == 'R' && b == 'S') || 
               (a == 'P' && b == 'R') || 
               (a == 'S' && b == 'P');
    };
    
    // Try both possible starting strategies: use the same hand as opponent or choose optimally
    vector<char> choices = {'R', 'P', 'S'};
    int max_score = 0;
    
    for (char first : choices) {
        int score = 0;
        char current = first;
        
        for (int i = 0; i < N; i++) {
            if (wins(current, S[i])) {
                score++;
            }
            
            // Update strategy: choose the move that would beat the opponent's next move
            // but avoid using the current move (since we can't repeat)
            if (i + 1 < N) {
                vector<char> available;
                for (char c : choices) {
                    if (c != current) {
                        available.push_back(c);
                    }
                }
                
                // If only one choice left, take it
                if (available.size() == 1) {
                    current = available[0];
                } else {
                    // Choose the best option that beats the next opponent move if possible
                    char best = available[0];
                    bool found_win = false;
                    
                    for (char c : available) {
                        if (wins(c, S[i+1])) {
                            best = c;
                            found_win = true;
                            break;
                        }
                    }
                    
                    if (!found_win) {
                        // If none wins, pick any (preferably the one that doesn't lose)
                        for (char c : available) {
                            if (c != S[i+1]) { // doesn't lose
                                best = c;
                                break;
                            }
                        }
                    }
                    
                    current = best;
                }
            }
        }
        
        max_score = max(max_score, score);
    }
    
    cout << max_score << endl;
    return 0;
}