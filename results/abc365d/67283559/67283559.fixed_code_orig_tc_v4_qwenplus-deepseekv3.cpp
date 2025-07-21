#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int total = 0;
    set<char> available = {'R', 'P', 'S'};
    char last_move = '\0';
    
    for (int i = 0; i < N; ++i) {
        char current = S[i];
        char best_move = '\0';
        int max_score = -1;
        
        for (char move : available) {
            int score = 0;
            if (move == 'R' && current == 'S') score = 1;
            else if (move == 'P' && current == 'R') score = 1;
            else if (move == 'S' && current == 'P') score = 1;
            
            if (score > max_score) {
                max_score = score;
                best_move = move;
            } else if (score == max_score && move == current) {
                best_move = move;  // prefer same move when tie
            }
        }
        
        if (max_score == 0) {
            best_move = current;  // can't win, choose same to not lose
        }
        
        total += max_score;
        last_move = best_move;
        available = {'R', 'P', 'S'};
        available.erase(last_move);
    }
    
    cout << total << endl;
    return 0;
}