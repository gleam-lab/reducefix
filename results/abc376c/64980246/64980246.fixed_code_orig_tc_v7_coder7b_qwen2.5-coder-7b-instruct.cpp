#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int x = -1;
    for (int i = 0, j = 0; i < n && j < n - 1; ++i) {
        if (a[i] <= b[j]) {
            if (x == -1)
                x = a[i];
            else
                break;
        } else {
            ++j;
        }
    }
    
    if (x != -1)
        cout << x << endl;
    else
        cout << "1" << endl; // If no suitable box found, buy the smallest box available which is 1
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