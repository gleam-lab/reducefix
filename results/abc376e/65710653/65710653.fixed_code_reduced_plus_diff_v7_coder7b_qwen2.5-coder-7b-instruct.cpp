#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;

struct Data {
    ll maxVal;
    ll sum;
};

bool compare(Data &a, Data &b) {
    if (a.maxVal != b.maxVal) return a.maxVal > b.maxVal;
    else return a.sum < b.sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

        sort(a.begin(), a.end());

        priority_queue<Data, vector<Data>, decltype(&compare)> pq(compare);
        for (int i = n - 1; i >= n - k; --i) {
            pq.push({a[i].first, a[i].second});
        }

        Data res = pq.top();
        pq.pop();

        for (int i = n - k - 1; i >= 0; --i) {
            Data curr = pq.top(); pq.pop();
            res.sum -= curr.sum;
            res.sum += curr.second;
            res.maxVal = max(res.maxVal, a[i].first);
            pq.push(curr);
        }

        cout << res.maxVal * res.sum << "\n";
    }

    return 0;
}