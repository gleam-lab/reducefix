#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<ll> b_set;
    for (ll x : B) b_set.insert(x);

    int j = 0;
    for (int i = 0; i < N; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it != b_set.end()) {
            b_set.erase(it);
        } else if (i < N - 1) {
            // We can place this toy in the additional box
            continue;
        } else {
            // Last toy must fit in some box, and all boxes are used
            cout << -1 << endl;
            return;
        }
    }

    // The minimum size of the additional box needed is the maximum unmatched toy
    // Since we greedily matched smaller toys to boxes, the largest unmatched toy is the last one that couldn't be matched
    // But since we sorted both arrays, the largest toy that couldn't find a box is A[N-1] (if any)
    // However, there might still be a box left from B that can accommodate it
    // So we check if any box remains after matching
    if (!b_set.empty()) {
        cout << *b_set.rbegin() << endl;
    } else {
        cout << A[N-1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}