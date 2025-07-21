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
    for (size_t i = 1; i < S.length(); ++i){
        if (S[i] == 'R' && S[i-1] == 'S' ||
            S[i] == 'P' && S[i-1] == 'R' ||
            S[i] == 'S' && S[i-1] == 'P') {
            wins++;
        }
        prev = S[i];
    }
    cout << wins;

    return 0;
}