#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        vector<pair<ll, ll>> AB(N);

        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second;
        }

        // Sort by A value
        sort(AB.begin(), AB.end());

        ll sumB = 0;
        multiset<ll> selectedB;

        // Initialize the first K B values
        for (int i = 0; i < K; ++i) {
            selectedB.insert(AB[i].second);
            sumB += AB[i].second;
        }

        ll res = AB[K - 1].first * sumB;

        // Try replacing one element at a time
        for (int i = K; i < N; ++i) {
            // If current B is better than worst in selectedB
            if (AB[i].second < *selectedB.rbegin()) {
                sumB -= *selectedB.rbegin();
                selectedB.erase(prev(selectedB.end()));
                selectedB.insert(AB[i].second);
                sumB += AB[i].second;
            }
            res = min(res, AB[i].first * sumB);
        }

        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}