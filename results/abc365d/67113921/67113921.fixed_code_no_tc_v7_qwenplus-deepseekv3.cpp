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
    char prev_win_move = '\0';
    
    for (char c : S){
        char win_move;
        if (c == 'R'){
            win_move = 'P';
        } else if (c == 'P'){
            win_move = 'S';
        } else { // 'S'
            win_move = 'R';
        }
        
        if (win_move != prev_win_move){
            wins++;
            prev_win_move = win_move;
        } else {
            // Reset the previous move to allow future wins
            prev_win_move = '\0';
        }
    }
    cout << wins;
    return 0;
}