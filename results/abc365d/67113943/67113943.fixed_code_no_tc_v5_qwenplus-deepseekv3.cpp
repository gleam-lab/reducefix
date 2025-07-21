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
    for (char c : S){
        if (c == 'R'){
            wins += (c == 'R') ? 1 : 0;
        } else if (c == 'P'){
            wins += (c == 'P') ? 1 : 0;
        } else if (c == 'S'){
            wins += (c == 'S') ? 1 : 0;
        }
    }
    cout << wins;
}