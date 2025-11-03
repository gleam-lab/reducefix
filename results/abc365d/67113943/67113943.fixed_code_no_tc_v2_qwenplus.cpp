#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char opponent_move, my_move;
    
    for (int i = 0; i < N; i++) {
        opponent_move = S[i];
        
        // Determine the winning move against opponent's move
        if (opponent_move == 'R') {
            my_move = 'P';
        } else if (opponent_move == 'P') {
            my_move = 'S';
        } else { // opponent_move == 'S'
            my_move = 'R';
        }
        
        // We win this round if we play the winning move
        // We can choose to play optimally, so we always play the winning move
        wins++;
    }
    
    cout << wins;
    return 0;
}