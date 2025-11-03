#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char opponent_move, my_last_move = 'X'; // Use 'X' as initial placeholder (no previous move)
    
    for (int i = 0; i < N; i++) {
        opponent_move = S[i];
        char best_response;
        
        // Determine the move that beats the opponent's move
        if (opponent_move == 'R') {
            best_response = 'P';
        } else if (opponent_move == 'P') {
            best_response = 'S';
        } else { // opponent_move == 'S'
            best_response = 'R';
        }
        
        // If our best response is different from our last move, we can use it and win
        if (best_response != my_last_move) {
            wins++;
            my_last_move = best_response;
        } 
        // Otherwise, we are forced to repeat our last move (or choose something that doesn't win)
        // In this case, we don't win and may need to update our last move to the opponent's move
        // or keep our last move. Actually, we can choose any move, but to maximize future wins,
        // we should set our last move to something strategic.
        else {
            // We cannot use best_response because it's same as last move
            // So we must choose a different move (either tie or lose)
            // To prepare for future rounds, we should set our last move to the opponent's current move
            // This gives better chances for next round
            my_last_move = opponent_move;
        }
    }   
    cout << wins;
    return 0;
}