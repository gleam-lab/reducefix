#include <bits/stdc++.h>
using namespace std;

set<int> s;

void solve(int n) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            s.insert(x);
        } else if (t == 2) {
            s.erase(s.find(x));
        } else {
            cout << s.size() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve(T);
    }
    return 0;
}