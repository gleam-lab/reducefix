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
    char winmove, prev = 'a'; // 'a' is just an initial value that won't match any move
    for (char c : S){
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        if (winmove != prev){
            wins++;
            prev = winmove;
        } else {
            // We need to change our previous move to current move
            // So that next round can be evaluated properly
            prev = c;
        }
    }   
    cout << wins << endl;
}