#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

bool cmp(pl a, pl b) {
    return a.first > b.first;
}

vector<ll> get_min_values(vector<pl>& pairs, int k) {
    int n = pairs.size();
    vector<ll> res(k, 0);
    sort(pairs.begin(), pairs.end(), cmp);
    multiset<ll> sums;
    for (int i = 0; i < k; ++i) {
        sums.insert(pairs[i].second);
        res[i] = pairs[i].first * accumulate(sums.begin(), sums.end(), 0LL);
    }
    for (int i = k; i < n; ++i) {
        auto it = sums.end(); --it;
        if (*it > pairs[i].second) {
            sums.erase(it);
            sums.insert(pairs[i].second);
            res[k - 1] += pairs[i].second;
        } else {
            break;
        }
    }
    for (int i = k - 2; i >= 0; --i) {
        res[i] = res[i + 1];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pl> pairs(n);
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].first >> pairs[i].second;
        }

        vector<ll> results = get_min_values(pairs, k);
        for (int i = 0; i < k; ++i) {
            cout << results[i] << "\n";
        }
    }

    return 0;
}