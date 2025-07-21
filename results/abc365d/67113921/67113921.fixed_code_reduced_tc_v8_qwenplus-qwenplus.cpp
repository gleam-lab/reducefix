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
    char winmove, prev = 'a'; // 'a' is used as an initial placeholder
    
    for (char c : S){
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // S
            winmove = 'R';
        }
        
        if (winmove != prev){
            wins++;
            prev = winmove;
        } else {
            // We tied, so we set prev to current move to prepare for next round
            prev = c;
        }
    }   
    cout << wins << endl;
}