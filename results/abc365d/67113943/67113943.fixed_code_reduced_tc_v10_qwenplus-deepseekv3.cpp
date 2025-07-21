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
    for (char c : S){
        if (c == 'R'){
            wins += (c == 'R') ? 1 : 0;
        } else if (c == 'P'){
            wins += (c == 'P') ? 1 : 0;
        } else if (c == 'S'){
            wins += (c == 'S') ? 1 : 0;
        }
    }
    
    wins = 0;
    for (char c : S) {
        if (c == 'R') {
            wins += 1;
        } else if (c == 'P') {
            wins += 1;
        } else if (c == 'S') {
            wins += 1;
        }
    }
    
    // The above was a misguided attempt. Let's correct it.
    // The correct approach is to count the number of times the winning move beats the opponent's move.
    // The winning move is determined by the opponent's move: R -> P, P -> S, S -> R.
    // We need to count each instance where the winning move beats the opponent's move.
    // There's no restriction on using the same move consecutively.
    
    wins = 0;
    for (char c : S) {
        if (c == 'R') {
            wins++; // if we choose P, we win
        } else if (c == 'P') {
            wins++; // if we choose S, we win
        } else if (c == 'S') {
            wins++; // if we choose R, we win
        }
    }
    
    cout << wins;
    return 0;
}