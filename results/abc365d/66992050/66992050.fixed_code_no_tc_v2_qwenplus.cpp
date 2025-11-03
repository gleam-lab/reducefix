#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char last = 'N'; // Last gesture shown by the player
    int ans = 0;
    
    for (char c : S) {
        if (c == 'P') {
            if (last != 'S') {
                ans++;
            }
            last = 'P';
        } else if (c == 'R') {
            if (last != 'P') {
                ans++;
            }
            last = 'R';
        } else if (c == 'S') {
            if (last != 'R') {
                ans++;
            }
            last = 'S';
        }
    }
    
    cout << ans;
    return 0;
}