#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;

    // Initialize the past state to something that doesn't interfere with the first move
    char past = 'N';  // 'N' for "None" or "No previous move"
    int ans = 0;

    for (char c : S) {
        if (c == 'P') {
            if (past != 'S') {
                ans++;
                past = 'S';
            } else {
                past = 'P';
            }
        } else if (c == 'R') {
            if (past != 'P') {
                ans++;
                past = 'P';
            } else {
                past = 'R';
            }
        } else if (c == 'S') {
            if (past != 'R') {
                ans++;
                past = 'R';
            } else {
                past = 'S';
            }
        }
    }

    cout << ans << endl;
    return 0;
}