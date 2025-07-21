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
        if (prev == ' ' || c != prev){
            wins++;
            prev = c;
        }
    }   
    cout << wins;

}