#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    int ans = 0;
    char prev = ' ';
    
    for (char c : S) {
        if (prev == ' ') {
            prev = c;
            ans++;
            continue;
        }
        
        if (c == 'P' && prev == 'R') {
            ans++;
            prev = 'P';
        } 
        else if (c == 'R' && prev == 'S') {
            ans++;
            prev = 'R';
        } 
        else if (c == 'S' && prev == 'P') {
            ans++;
            prev = 'S';
        }
        else {
            prev = c;
        }
    }
    
    cout << ans << endl;
    return 0;
}