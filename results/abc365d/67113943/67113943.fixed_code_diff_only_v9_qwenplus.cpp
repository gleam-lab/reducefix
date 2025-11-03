#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char opponent_move, my_move = 'X'; // X represents no previous move
    
    for (int i = 0; i < N; i++) {
        opponent_move = S[i];
        
        // Determine the winning move against opponent's current move
        char winmove;
        if (opponent_move == 'R') {
            winmove = 'P';
        } else if (opponent_move == 'P') {
            winmove = 'S';
        } else { // opponent_move == 'S'
            winmove = 'R';
        }
        
        // If we can use the winning move (i.e., it's different from our previous move)
        if (my_move != winmove) {
            wins++;
            my_move = winmove;
        } else {
            // We have to use a different move, so we don't win this round
            // Just update to the opponent's move (or any non-winning move)
            my_move = opponent_move;
        }
    }   
    cout << wins;

    return 0;
}