#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

typedef long long ll;

vector<int> a, b;

bool check(ll mid, int k) {
    int count = 0;
    for (int ai : a) {
        if (abs(ai - b.back()) <= mid) count++;
        if (count >= k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q; cin >> n >> q;
    a.resize(n); b.resize(q);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i] >> a[i + n]; // Combine a and b into one array

    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        int k = a[n + i] - b[i];
        if (k < 0) k = 0; // Ensure no negative distances

        int l = 0, r = 2e8;
        while (r > l) {
            int mid = (l + r) / 2;
            if (check(mid, k)) r = mid;
            else l = mid + 1;
        }

        cout << r << endl;
    }

    return 0;
}