#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int total = 0;
    char prev = ' ';
    
    for (int i = 0; i < N; i++) {
        char current = S[i];
        char best_move;
        
        if (current == 'R') best_move = 'P';
        else if (current == 'P') best_move = 'S';
        else best_move = 'R';
        
        if (best_move != prev) {
            total++;
            prev = best_move;
        } else {
            prev = ' ';
        }
    }
    
    cout << total << endl;
    return 0;
}