#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = 'N';
    int ans = 0;
    for (char c : S) {
        if (past == 'N') {
            ans++;
            past = c;
        } else if (c != past) {
            if ((c == 'P' && past == 'R') || 
                (c == 'R' && past == 'S') || 
                (c == 'S' && past == 'P')) {
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