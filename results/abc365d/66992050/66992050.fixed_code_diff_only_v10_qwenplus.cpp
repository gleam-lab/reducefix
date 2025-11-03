#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char past = 'N'; // No previous move
    int ans = 0;
    
    for (char c : S) {
        if (c == 'P') {
            if (past != 'S') {
                ans++;
            }
            past = 'P';
        } else if (c == 'R') {
            if (past != 'P') {
                ans++;
            }
            past = 'R';
        } else if (c == 'S') {
            if (past != 'R') {
                ans++;
            }
            past = 'S';
        }
    }
    
    cout << ans;
    return 0;
}