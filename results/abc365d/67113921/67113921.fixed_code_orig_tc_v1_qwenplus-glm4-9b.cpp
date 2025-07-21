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
    char winmove, prev = 'a';
    for (char c : S){
        if (c == 'R' && prev != 'S') winmove = 'S'; // Rock beats Scissors
        else if (c == 'P' && prev != 'R') winmove = 'R'; // Paper beats Rock
        else if (c == 'S' && prev != 'P') winmove = 'P'; // Scissors beats Paper
        else winmove = 'a'; // No win move if it's the same as the previous

        if (winmove != 'a' && winmove != prev){ // Non-consecutive win
            wins++;
            prev = winmove;
        } else{
            prev = c;
        }
    }   
    cout << wins;
}