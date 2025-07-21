#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = 'N'; // 'N' represents no previous move
    int ans = 0;
    for (char c : S) {
        if (past == 'N') {
            ans++;
            past = c;
        } else {
            if ((past == 'R' && c == 'P') || 
                (past == 'P' && c == 'S') || 
                (past == 'S' && c == 'R')) {
                ans++;
                past = c;
            } else {
                past = c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}