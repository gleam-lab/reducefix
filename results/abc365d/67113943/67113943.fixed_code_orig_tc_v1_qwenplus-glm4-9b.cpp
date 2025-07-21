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
    char winmove = S[0]; // Initialize with the first character of S
    for (int i = 1; i < S.length(); ++i){
        if (S[i] == 'R' && winmove == 'S') {
            winmove = 'S'; // Rock beats Scissors, next winning move is Scissors
        } else if (S[i] == 'S' && winmove == 'R') {
            winmove = 'R'; // Scissors beat Rock, next winning move is Rock
        } else if (S[i] == 'P' && winmove == 'S') {
            winmove = 'R'; // Paper beats Scissors, next winning move is Rock
        } else if (S[i] == 'S' && winmove == 'P') {
            winmove = 'P'; // Scissors beats Paper, next winning move is Paper
        } else if (S[i] == 'P' && winmove == 'R') {
            winmove = 'S'; // Paper beats Rock, next winning move is Scissors
        } else if (S[i] == 'R' && winmove == 'P') {
            winmove = 'P'; // Rock beats Paper, next winning move is Paper
        }
        if (winmove != S[i]) {
            wins++;
        }
    }   
    cout << wins;
}