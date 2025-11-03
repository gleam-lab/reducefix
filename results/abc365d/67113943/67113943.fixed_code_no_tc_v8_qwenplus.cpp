#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char opponent_move, my_last_move = 'X'; // X indicates no previous move
    
    for (int i = 0; i < N; i++) {
        opponent_move = S[i];
        char winning_move;
        
        // Determine the move that beats the opponent's move
        if (opponent_move == 'R') {
            winning_move = 'P';
        } else if (opponent_move == 'P') {
            winning_move = 'S';
        } else { // opponent_move == 'S'
            winning_move = 'R';
        }
        
        // If we can make a different move than last time, we win
        if (my_last_move != winning_move) {
            wins++;
            my_last_move = winning_move;
        } else {
            // We have to play the same winning move as last time
            // This means we either repeat our move or lose
            // In this case, we don't increment wins and update to opponent's move
            // to allow different move next time
            my_last_move = opponent_move;
        }
    }   
    cout << wins;
    return 0;
}