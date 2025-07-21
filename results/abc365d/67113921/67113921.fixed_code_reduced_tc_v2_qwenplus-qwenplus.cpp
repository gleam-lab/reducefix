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
    char winmove, prev = 'a'; // prev stores the previous move made by the player
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
            // We need to choose a different move that doesn't repeat
            // This can be the move that beats c but is not equal to prev
            // Only one such move exists
            if (c == 'R') {
                if (prev != 'S') winmove = 'S'; 
                else winmove = 'P';
            } else if (c == 'P') {
                if (prev != 'R') winmove = 'R';
                else winmove = 'S';
            } else { // S
                if (prev != 'P') winmove = 'P';
                else winmove = 'R';
            }
            wins++;
            prev = winmove;
        }
    }   
    cout << wins;
}