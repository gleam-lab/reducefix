#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPossible(int x, vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    multiset<int> boxes(b.begin(), b.end());
    boxes.insert(x);
    auto it = boxes.end();
    --it;
    for (int i = 0; i < n; ++i) {
        auto box_it = boxes.lower_bound(a[i]);
        if (box_it == boxes.end()) {
            return false;
        }
        boxes.erase(box_it);
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a) cin >> tt;
    for (auto &tt : b) cin >> tt;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll left = 1, right = 1e18;
    ll answer = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (isPossible(mid, a, b)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << answer << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}