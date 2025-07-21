#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        vector<ll> distances(N);
        rep(i, N) distances[i] = abs(a[i] - b);
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}