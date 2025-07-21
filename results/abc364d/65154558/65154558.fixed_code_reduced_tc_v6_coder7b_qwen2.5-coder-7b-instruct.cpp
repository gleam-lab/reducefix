#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> a;

bool check(int mid, int x, int y) {
    auto it = lower_bound(a.begin(), a.end(), x - mid);
    if(it == a.end()) return false;
    return *it - (*prev(it)) >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    a.resize(2 * 1000000001);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x + 100000000]++;
    }
    for(int i = 1; i < 2 * 1000000001; i++) {
        a[i] += a[i - 1];
    }
    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int l = 0, r = 2 * 1000000000;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(mid, x, k)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}