#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    char last = ' ';
    int ans = 0;
    
    for (char c : S) {
        if (c == 'R') {
            if (last != 'P') {
                ans++;
                last = 'P';
            }
        } else if (c == 'P') {
            if (last != 'S') {
                ans++;
                last = 'S';
            }
        } else if (c == 'S') {
            if (last != 'R') {
                ans++;
                last = 'R';
            }
        }
    }
    
    cout << ans;
    return 0;
}