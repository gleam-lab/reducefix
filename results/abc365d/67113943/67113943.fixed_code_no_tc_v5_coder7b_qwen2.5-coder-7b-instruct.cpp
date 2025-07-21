#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    
    // Initialize variables
    int wins = 0;
    char prevMove = ' ';
    
    for (int i = 0; i < N; ++i) {
        char currentMove = S[i];
        
        // Determine Takahashi's winning move based on Aoki's move
        char takahashiMove = ' ';
        if (currentMove == 'R') takahashiMove = 'P';
        else if (currentMove == 'P') takahashiMove = 'S';
        else if (currentMove == 'S') takahashiMove = 'R';
        
        // Check if Takahashi's move is different from the previous one
        if (takahashiMove != prevMove) {
            wins++;
            prevMove = takahashiMove;
        }
    }

    cout << wins << endl;
    return 0;
}