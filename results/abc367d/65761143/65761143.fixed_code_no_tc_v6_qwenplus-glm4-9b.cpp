#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    long long res = 0;
    if (sum == 0) res++;
    map<int, int> map[2];
    map[0][0] = 1;
    int pre = 0;
    for (int x : a) {
        pre = (pre + x) % m;
        res += map[0].count(pre);
        map[0][pre]++;
    }
    for (int x : a) {
        pre = (pre - x + m) % m;
        res += map[0].count(pre);
        map[0][pre]++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}