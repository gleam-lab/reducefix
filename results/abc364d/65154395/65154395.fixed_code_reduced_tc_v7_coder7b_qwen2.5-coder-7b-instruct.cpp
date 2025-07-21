#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int MAXN = 100005;

vector<ll> a(MAXN);

bool check(ll mid, int x, int k) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (abs(a[i] - x) <= mid) {
            cnt++;
            if (cnt >= k) return true;
        }
    }
    return false;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        ll l = 0, r = 1e8 + 10;
        while (r > l) {
            ll mid = l + (r - l) / 2;
            if (check(mid, x, k)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    while (t--) solve();
    
    return 0;
}