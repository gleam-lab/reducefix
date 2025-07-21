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
    char prev_win_move = ' '; // Initialize to an invalid move
    
    for (char c : S){
        char current_win_move;
        if (c == 'R'){
            current_win_move = 'P';
        } else if (c == 'P'){
            current_win_move = 'S';
        } else if (c == 'S'){
            current_win_move = 'R';
        }
        
        if (current_win_move != prev_win_move){
            wins++;
            prev_win_move = current_win_move;
        }
    }   
    cout << wins;
    return 0;
}