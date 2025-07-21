#include <bits/stdc++.h>

#define all(x) begin(x), end(x)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(q);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q; ++i) cin >> b[i];

    sort(all(a));

    for(int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        --k;
        auto it = lower_bound(all(a), b[i]);
        int dist = abs(b[i] - *it);
        if(it != begin(a)) dist = min(dist, abs(b[i] - *(--it)));
        if(it != prev(end(a))) dist = min(dist, abs(b[i] - *next(it)));
        cout << dist << '\n';
    }

    return 0;
}