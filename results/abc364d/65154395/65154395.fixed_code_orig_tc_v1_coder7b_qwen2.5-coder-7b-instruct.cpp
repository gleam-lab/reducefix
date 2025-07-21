#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a, b;

bool check(int mid, int x, int y) {
    vector<int> dists;
    for (int ai : a) {
        dists.push_back(abs(ai - x));
    }
    sort(dists.begin(), dists.end());
    return dists[k - 1] <= mid;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    a.resize(n); b.resize(q);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k;
    }

    for (int i = 0; i < q; ++i) {
        int l = 0, r = 2 * 1e8; // Adjust range based on problem constraints
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid, b[i], k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }

    return 0;
}