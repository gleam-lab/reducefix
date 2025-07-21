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
    char prev = S[0];
    for (size_t i = 1; i < S.length(); ++i){
        if (S[i] != prev){
            wins++;
            prev = S[i];
        }
    }   
    cout << wins + 1;

}