#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_played = ' '; // No move played initially
    
    for (char c : S) {
        char winning_move;
        if (c == 'R') {
            winning_move = 'P';
        } else if (c == 'P') {
            winning_move = 'S';
        } else { // c == 'S'
            winning_move = 'R';
        }
        
        // Only count a win if we play the winning move AND 
        // we didn't just play this same winning move in the previous round
        if (winning_move != last_played) {
            wins++;
            last_played = winning_move;
        } else {
            // If we can't use the winning move (due to restriction),
            // we play the losing move, which doesn't affect future moves
            // but doesn't give us a win either
            last_played = c;
        }
    }
    
    cout << wins << endl;
    return 0;
}