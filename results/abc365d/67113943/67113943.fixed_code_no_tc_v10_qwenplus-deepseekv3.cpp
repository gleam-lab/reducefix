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
            wins += 'P' > 'R'; // P beats R
        } else if (c == 'P'){
            wins += 'S' > 'P'; // S beats P
        } else if (c == 'S'){
            wins += 'R' > 'S'; // R beats S
        }
    }   
    cout << wins;
}