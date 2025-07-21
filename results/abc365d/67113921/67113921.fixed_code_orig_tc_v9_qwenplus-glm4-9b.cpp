#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;  // Read the number of moves
    cin >> S;  // Read the sequence of moves
    int wins = 0;
    char winmove, prev = 'a';
    for (char c : S){
        if (c == 'R') {  // If the current move is R
            winmove = 'P';  // The winning move against R is P
        } else if (c == 'P') {  // If the current move is P
            winmove = 'S';  // The winning move against P is S
        } else if (c == 'S') {  // If the current move is S
            winmove = 'R';  // The winning move against S is R
        }
        
        if (winmove != prev) {  // If the winning move is different from the previous move
            wins++;  // Increment the count of wins
            prev = winmove;  // Updateprev to the current winning move
        } else {
            prev = c;  // If it's the same move, update prev to the current move
        }
    }   
    cout << wins << endl;  // Output the total number of wins
}