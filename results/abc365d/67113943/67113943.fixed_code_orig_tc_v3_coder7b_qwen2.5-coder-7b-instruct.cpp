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
    char prev = 'N'; // Initialize previous move to a character not in ['R', 'P', 'S']
    for (char c : S){
        if (prev == 'N' || prev == 'R' && c == 'P' || prev == 'P' && c == 'S' || prev == 'S' && c == 'R') {
            wins++;
            prev = c;
        } else {
            prev = c;
        }
    }   
    cout << wins;

}