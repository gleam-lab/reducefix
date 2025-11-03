#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    
    long long wins = 0;
    char prev = 'X'; // Use a sentinel value to indicate no previous move
    
    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If the winning move is different from the previous move, we can win this round
        // and we choose the winning move
        if (prev != winmove) {
            wins++;
            prev = winmove;
        } else {
            // We cannot use the same move twice in a row, so we must use the opponent's move
            // This means we tie or lose, but at least we don't repeat our own move
            prev = c;
        }
    }   
    cout << wins;
}