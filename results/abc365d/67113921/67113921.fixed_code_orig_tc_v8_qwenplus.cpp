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
    char prev = 'a'; // no move made yet
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        if (prev != winmove) {
            wins++;
            prev = winmove;
        } else {
            // We already played the winning move, so we can keep it
            // But opponent changes, so we might need to update strategy
            // However, we don't need to change our move if it still wins
            // So we keep prev as is (winmove)
            // No increment since we're reusing the same winning move
            prev = winmove;
        }
    }   
    cout << wins;
}