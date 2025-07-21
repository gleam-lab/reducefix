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
    char prev = 'a';
    for (int i = 0; i < N; ++i){
        char c = S[i];
        if (c == 'R'){
            if (prev == 'S') {
                wins++;
            }
        } else if (c == 'P'){
            if (prev == 'R') {
                wins++;
            }
        } else if (c == 'S'){
            if (prev == 'P') {
                wins++;
            }
        }
        prev = c;
    }   
    cout << wins;

}