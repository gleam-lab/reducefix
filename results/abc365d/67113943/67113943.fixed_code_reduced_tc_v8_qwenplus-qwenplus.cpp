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
    char winmove = 'a', prev = 'a';
    for (char c : S){
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else if (c == 'S'){
            winmove = 'R';
        }
        if (winmove != prev){
            wins++;
            prev = winmove;
        } else {
            // We need to change our move to something different than opponent's move
            // and also different from previous move we used
            // So pick the move that beats c but is not equal to prev
            if (c == 'R') {
                if (prev != 'P') {
                    winmove = 'P';
                } else {
                    winmove = 'S'; // this will lose but needed to change move
                }
            } else if (c == 'P') {
                if (prev != 'S') {
                    winmove = 'S';
                } else {
                    winmove = 'R'; // this will lose but needed to change move
                }
            } else { // c == 'S'
                if (prev != 'R') {
                    winmove = 'R';
                } else {
                    winmove = 'P'; // this will lose but needed to change move
                }
            }
            prev = winmove;
            // only increment wins if we actually won this round
            if (winmove != prev) { // sanity check, should always be true
                wins++;
            }
        }
    }   
    cout << wins;
}