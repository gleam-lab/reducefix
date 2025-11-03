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
    char prev = 'a'; // no move played yet

    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // We can choose the winning move unless we used it in the previous round
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // If our winning move was just used, we cannot use it again due to the constraint
            // So we must pick a non-winning move (which results in loss or tie), and update prev to that move
            // But we don't win this round, so just set prev to something other than winmove
            // Note: We are free to choose any move except the one used last time.
            // Since we can't use winmove (because prev == winmove), we must use a losing/tie move.
            // The two options: winmove (can't use), and two others. One of them beats c? No: only winmove beats c.
            // So both alternatives either lose or tie.
            // We just need to pick one that isn't winmove.
            if (c == 'R') {
                // winmove is 'P', so we can choose 'R' or 'S'. Choose one that's not 'P'
                // doesn't matter which, but let's pick 'R' arbitrarily
                prev = 'R';
            } else if (c == 'P') {
                prev = 'P';
            } else {
                prev = 'S';
            }
        }
    }   
    cout << wins;
}