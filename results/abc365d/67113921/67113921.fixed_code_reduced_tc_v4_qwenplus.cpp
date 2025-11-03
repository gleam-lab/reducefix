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
    char prev = 'a'; // previous move played by us

    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If our winning move is different from what we played last time, we can use it
        if (winmove != prev) {
            wins++;
            prev = winmove; // we play the winning move
        } else {
            // We cannot repeat our previous move, so we must play something else
            // Play any move that is not prev and doesn't matter if it wins or loses
            // But we need to choose a valid move different from prev
            if (prev != 'R') {
                prev = 'R';
            } else if (prev != 'P') {
                prev = 'P';
            } else {
                prev = 'S';
            }
        }
    }   
    cout << wins;
}