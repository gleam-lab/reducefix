#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; ++i)

vector<ll> pointsA;
vector<pair<ll, int>> queries;

void preprocess() {
    sort(pointsA.begin(), pointsA.end());
}

ll findKthClosest(int b, int k) {
    auto it = lower_bound(pointsA.begin(), pointsA.end(), b);
    int pos = it - pointsA.begin();
    
    if (pos >= k && pos + k <= pointsA.size()) {
        return abs(pointsA[pos + k - 1] - b);
    } else if (pos < k) {
        return abs(pointsA[k - 1] - b);
    } else {
        return abs(pointsA[pointsA.size() - k] - b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    pointsA.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pointsA[i];
    }

    preprocess();

    for (int i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        queries.emplace_back(b, k - 1); // Adjusting k to zero-based index
    }

    sort(queries.begin(), queries.end());

    int lastPos = 0;
    for (auto &[b, k] : queries) {
        while (lastPos < n && pointsA[lastPos] < b) {
            ++lastPos;
        }
        
        if (lastPos == n) break;
        
        ll dist = findKthClosest(b, k);
        cout << dist << '\n';
    }

    return 0;
}