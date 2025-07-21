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
    char prev = 'N'; // Initialize prev to a character that is not R, P, or S
    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else if (c == 'S'){
            winmove = 'R';
        }
        if (prev != 'N' && winmove != prev){ // Check if it's not the first move and the move changes
            wins++;
        }
        prev = winmove; // Update previous move to current winning move
    }   
    cout << wins;

}