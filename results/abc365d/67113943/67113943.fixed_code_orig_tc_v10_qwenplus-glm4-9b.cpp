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
        if (c == 'R' && prev == 'P' && winmove != 'R') {
            wins++;
            winmove = 'R';
        } else if (c == 'S' && prev == 'R' && winmove != 'S') {
            wins++;
            winmove = 'S';
        } else if (c == 'P' && prev == 'S' && winmove != 'P') {
            wins++;
            winmove = 'P';
        }
        prev = c;
    }   
    cout << wins;
}