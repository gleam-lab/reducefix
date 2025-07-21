#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(a[i] - b);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}