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
    
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    for(int i = 0; i < n - 1; i++) {
        if(a[i] <= b[i]) {
            cout << a[i] << endl;
            return;
        }
    }

    cout << "-1" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}