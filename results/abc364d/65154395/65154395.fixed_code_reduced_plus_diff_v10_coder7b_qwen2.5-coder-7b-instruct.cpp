#include <bits/stdc++.h>

using namespace std;

vector<long long> prefix_sum(vector<long long>& v) {
    vector<long long> ps(v.size() + 1);
    for (size_t i = 0; i < v.size(); ++i) {
        ps[i + 1] = ps[i] + v[i];
    }
    return ps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (long long& ai : a) {
        cin >> ai;
    }

    vector<vector<long long>> distances(q);
    for (long long i = 0; i < q; ++i) {
        long long b, k;
        cin >> b >> k;
        --k; // Convert to zero-based index
        distances[i].resize(n);
        for (long long& di : distances[i]) {
            cin >> di;
        }
        sort(distances[i].begin(), distances[i].end());
    }

    vector<long long> ps = prefix_sum(a);
    for (auto& dists : distances) {
        auto it = lower_bound(dists.begin(), dists.end(), ps.back() - ps.front() + 1);
        long long idx = it - dists.begin();
        cout << dists[idx] << '\n';
    }

    return 0;
}