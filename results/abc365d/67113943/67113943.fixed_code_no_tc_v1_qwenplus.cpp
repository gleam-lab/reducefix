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
        
        // Determine the move that would beat the current opponent's move
        if (opponent_move == 'R') {
            my_move = 'P';
        } else if (opponent_move == 'P') {
            my_move = 'S';
        } else { // opponent_move == 'S'
            my_move = 'R';
        }
        
        // We win this round if our move is different from what we played in the previous round
        // For the first round, we can always play the winning move
        if (i == 0) {
            wins++;
        } else {
            // If we can play the winning move without repeating our previous move
            if (my_move != S[i-1]) {
                wins++;
            }
            // If we can't play the winning move (because it would repeat), 
            // we play something else but don't win
        }
    }
    
    cout << wins;
    return 0;
}