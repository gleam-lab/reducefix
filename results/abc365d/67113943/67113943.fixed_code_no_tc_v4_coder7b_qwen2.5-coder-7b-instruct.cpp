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
    char prev = ' ';
    for (char c : S){
        if (c == 'R' && prev != 'P'){
            wins++;
            prev = 'P';
        } else if (c == 'P' && prev != 'S'){
            wins++;
            prev = 'S';
        } else if (c == 'S' && prev != 'R'){
            wins++;
            prev = 'R';
        } else {
            prev = c;
        }
    }   
    cout << wins;

}