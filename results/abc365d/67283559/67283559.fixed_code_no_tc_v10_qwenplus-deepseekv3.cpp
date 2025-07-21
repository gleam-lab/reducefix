#include <bits/stdc++.h>
using namespace std;

int calculateMaxScore(const string& S) {
    int max_score = 0;
    const vector<char> hands = {'R', 'P', 'S'};
    
    for (char initial : hands) {
        int score = 0;
        char prev = initial;
        if (prev == 'R' && S[0] == 'S') score++;
        else if (prev == 'P' && S[0] == 'R') score++;
        else if (prev == 'S' && S[0] == 'P') score++;
        
        for (int i = 1; i < S.size(); ++i) {
            char current_hand = ' ';
            for (char hand : hands) {
                if (hand != prev) {
                    if (hand == 'R' && S[i] == 'S') {
                        current_hand = 'R';
                        break;
                    }
                    if (hand == 'P' && S[i] == 'R') {
                        current_hand = 'P';
                        break;
                    }
                    if (hand == 'S' && S[i] == 'P') {
                        current_hand = 'S';
                        break;
                    }
                }
            }
            
            if (current_hand == ' ') {
                for (char hand : hands) {
                    if (hand != prev) {
                        current_hand = hand;
                        break;
                    }
                }
            }
            
            if (current_hand == 'R' && S[i] == 'S') score++;
            else if (current_hand == 'P' && S[i] == 'R') score++;
            else if (current_hand == 'S' && S[i] == 'P') score++;
            
            prev = current_hand;
        }
        max_score = max(max_score, score);
    }
    
    return max_score;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    cout << calculateMaxScore(S) << endl;
    return 0;
}