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
    char prev = 'a'; // previous move we made

    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If our winning move is different from the previous move we played, we can use it and win
        if (winmove != prev){
            wins++;
            prev = winmove;
        } else {
            // We cannot repeat moves, so we must play something else (non-winning or losing)
            // So we don't win this round, and we update our move to opponent's move (or any non-repeating)
            prev = c; // using opponent's move as our next move avoids repetition and is safe
        }
    }   
    cout << wins;

    return 0;
}