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
    char prev = 'a'; // Initialize previous move with a non-rock-paper-scissors character
    for (int i = 0; i < N; ++i){
        char c = S[i];
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else if (c == 'S'){
            winmove = 'R';
        }
        if (winmove != prev && winmove != c){ // Check if the move is different from the previous one and not equal to current move
            wins++;
            prev = winmove;
        } else{
            prev = c;
        }
    }   
    cout << wins;

}