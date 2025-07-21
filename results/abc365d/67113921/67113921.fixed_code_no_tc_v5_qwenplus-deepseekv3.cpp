#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    int wins = 0;
    char prev = '\0'; // Initialize to null character
    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // 'S'
            winmove = 'R';
        }
        if (winmove != prev){
            wins++;
            prev = winmove;
        } else {
            prev = '\0'; // Reset to allow next move to be anything
        }
    }   
    cout << wins;
    return 0;
}