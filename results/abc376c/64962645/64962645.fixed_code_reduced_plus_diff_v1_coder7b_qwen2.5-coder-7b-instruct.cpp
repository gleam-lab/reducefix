#include <bits/stdc++.h>
using namespace std;

bool canPlaceToys(vector<int>& va, vector<int>& vb, long long x) {
    multiset<long long> boxes(vb.begin(), vb.end());
    for (long long toySize : va) {
        auto it = boxes.lower_bound(toySize);
        if (it == boxes.end()) {
            return false;
        }
        boxes.erase(it);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n-1; ++i) cin >> vb[i];

    sort(va.rbegin(), va.rend());

    long long low = 0, high = 1e18, ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canPlaceToys(va, vb, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}