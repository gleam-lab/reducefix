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
    char prev = 'a'; // Previous move we made
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If our winning move is different from previous move, we can use it
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // We have to use the opponent's move to break the streak
            prev = c;
        }
    }   
    cout << wins;
}