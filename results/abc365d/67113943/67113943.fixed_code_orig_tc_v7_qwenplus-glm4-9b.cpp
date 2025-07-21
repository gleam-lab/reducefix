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
    
    for (int i = 0; i < N; i++){
        winmove = 'R';  // Default winmove
        if (S[i] == 'R') winmove = 'P';
        else if (S[i] == 'P') winmove = 'S';
        else if (S[i] == 'S') winmove = 'R';

        // Increment wins if the current move wins over the previous move
        if (winmove != prev) wins++;
        prev = winmove;
    }   
    cout << wins;
}