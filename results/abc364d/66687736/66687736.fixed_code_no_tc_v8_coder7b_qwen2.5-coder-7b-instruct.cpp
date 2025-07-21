#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e9 + 7;
const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n), distances(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < q; ++i) {
        long long b, k;
        cin >> b >> k;

        for(int j = 0; j < n; ++j)
            distances[j] = abs(a[j] - b);

        sort(distances.begin(), distances.end());

        cout << distances[k - 1] << '\n';
    }

    return 0;
}