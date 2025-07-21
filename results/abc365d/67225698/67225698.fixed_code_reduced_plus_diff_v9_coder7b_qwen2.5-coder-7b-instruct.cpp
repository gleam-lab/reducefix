#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int count = 0, result = 0;
    bool isLastSegment = false;

    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] != s[i - 1]) {
            if (isLastSegment) {
                result += (count + 1) / 2;
            } else {
                result += (count + 2) / 2;
            }
            count = 0;
            isLastSegment = true;
        } else {
            ++count;
            isLastSegment = false;
        }
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}