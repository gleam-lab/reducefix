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
            // We need to change our move to something different from opponent and previous move
            // Choose a move that beats c but is not equal to prev
            char new_move = 'R';
            if (c == 'R') new_move = 'P'; // P beats R, check if not equal to prev
            else if (c == 'P') new_move = 'S'; // S beats P
            else if (c == 'S') new_move = 'R'; // R beats S

            // If new_move equals prev, pick another valid option
            if (new_move == prev) {
                if (c == 'R') new_move = 'S'; // R beats S, so we choose S
                else if (c == 'P') new_move = 'R';
                else if (c == 'S') new_move = 'P';
            }

            prev = new_move;
            wins++;
        }
    }   
    cout << wins;
}