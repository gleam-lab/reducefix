#include <bits/stdc++.h>
using namespace std;

int compute_max_score(const string& S, const vector<char>& hand) {
    int N = S.size();
    vector<char> next = hand;
    int total = 0;
    char last_use = '\0';

    for (int i = 0; i < N; ++i) {
        bool won = false;
        for (char c : next) {
            if ((c == 'R' && S[i] == 'S') || 
                (c == 'P' && S[i] == 'R') || 
                (c == 'S' && S[i] == 'P')) {
                total++;
                last_use = c;
                won = true;
                break;
            }
        }
        // Prepare next available moves
        vector<char> new_next;
        for (char c : hand) {
            if (c != last_use) {
                new_next.push_back(c);
            }
        }
        next = new_next;
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    
    // Case 1: Play normally from position 0
    int score1 = compute_max_score(S, hand);

    // Case 2: Skip first move and start from position 1
    string S_short = S.substr(1);
    int score2 = compute_max_score(S_short, hand);

    cout << max(score1, score2) << endl;
    return 0;
}