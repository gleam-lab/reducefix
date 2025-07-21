#include<bits/stdc++.h>
using namespace std;

vector<int> a;

bool check(int mid, int x, int y) {
    auto it = lower_bound(a.begin(), a.end(), x - mid);
    int idx = it - a.begin();
    int left_count = idx;
    int right_count = a.size() - idx;
    return left_count + right_count >= y && (idx == 0 || a[idx - 1] < x - mid) && (idx == a.size() || a[idx] >= x + mid);
}

void solve(void) {
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        int l = 0, r = 2 * 1e8;
        while(r > l) {
            int mid = l + r >> 1;
            if(check(mid, x, y)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}