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
    char winmove = 'R'; // Initialize to first move 'R'
    char prev = 'R';    // Initialize to first move 'R'
    for (char c : S){
        if (c == 'R' || c == 'P' || c == 'S'){ // Check valid moves
            if (c == 'R'){
                winmove = 'P';
            } else if (c == 'P'){
                winmove = 'S';
            } else if (c == 'S'){
                winmove = 'R';
            }
            if (winmove != prev){ // If the move changes
                wins++; // Increment the count of transitions
                prev = winmove; // Update prev to the new move
            }
        }
    }   
    cout << wins;
}