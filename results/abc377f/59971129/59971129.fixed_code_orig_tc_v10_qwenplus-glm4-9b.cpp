#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m, a, b;
    scanf("%lld %lld", &n, &m);
    
    set<pair<ll, ll>> row_set, col_set, diag1_set, diag2_set;
    vector<pair<ll, ll>> diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        row_set.insert({a, 1});
        col_set.insert({b, 1});
        diag1_set.insert({a + b, 1});
        diag2_set.insert({a - b, 1});
        diag1.push_back({a + b, 1});
        diag2.push_back({a - b, 1});
    }

    // Removing redundant entries from sets
    set<pair<ll, ll>> unique_row_set, unique_col_set, unique_diag1_set, unique_diag2_set;
    for (auto p : row_set) unique_row_set.insert({p.first, p.second});
    for (auto p : col_set) unique_col_set.insert({p.first, p.second});
    for (auto p : diag1_set) unique_diag1_set.insert({p.first, p.second});
    for (auto p : diag2_set) unique_diag2_set.insert({p.first, p.second});

    ll occupied = (n - unique_row_set.size()) * (n - unique_col_set.size());

    multiset<pair<ll, ll>> diag1_ms, diag2_ms;
    for (auto p : diag1) diag1_ms.insert(p);
    for (auto p : diag2) diag2_ms.insert(p);

    for (auto p : diag1_ms) {
        ll sum = get<0>(p);
        ll count = get<1>(p);
        ll row = sum - count;
        ll col = sum + count - n;
        if (row >= 1 && row <= n && col >= 1 && col <= n) {
            occupied++;
        }
    }

    for (auto p : diag2_ms) {
        ll diff = get<0>(p);
        ll count = get<1>(p);
        ll row = diff + count;
        ll col = diff - count;
        if (row >= 1 && row <= n && col >= 1 && col <= n) {
            occupied++;
        }
    }

    printf("%lld\n", n * n - occupied);
    return 0;
}