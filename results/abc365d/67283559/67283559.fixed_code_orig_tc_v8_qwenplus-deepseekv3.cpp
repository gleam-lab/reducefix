#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int total = 0;
    vector<char> available = {'R', 'P', 'S'};
    vector<char> next;
    
    for (int i = 0; i < N; ++i) {
        char opponent = S[i];
        char best_move = opponent;
        int max_score = 0;
        
        for (char move : available) {
            int score = 0;
            if (move == 'R' && opponent == 'S') score = 1;
            else if (move == 'P' && opponent == 'R') score = 1;
            else if (move == 'S' && opponent == 'P') score = 1;
            
            if (score > max_score) {
                max_score = score;
                best_move = move;
            }
        }
        
        total += max_score;
        next.clear();
        for (char move : {'R', 'P', 'S'}) {
            if (move != best_move) next.push_back(move);
        }
        available = next;
    }
    
    cout << total << endl;
    return 0;
}