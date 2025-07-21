#include <iostream>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for (int &x : a) cin >> x;
    for (int &x : a) {
        x %= m;
        sum = (sum + x) % m;
    }

    long long res = 0;
    map<int, long long> seen;
    seen[0]++;
    for (int x : a) {
        res += seen[(x - sum + m) % m];
        seen[(x - sum + m) % m]++;
    }

    if (sum == 0) {
        cout << res - n;
    } else {
        cout << res;
    }
    cout << '\n';
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}