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
    char prev = 'a'; // Initialize with a value not in ['R', 'P', 'S']
    for (char c : S){
        char winmove = 'a'; // Reset winmove for each character
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else if (c == 'S'){
            winmove = 'R';
        }
        if (winmove != prev && winmove != c){ // Check if winmove is different from both previous move and current move
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }   
    cout << wins;

}