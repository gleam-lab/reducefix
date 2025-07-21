#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int idx;
};

bool cmp(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<Point>> distances(q);
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        distances[i].push_back({x, i});
    }

    sort(a.begin(), a.end());

    vector<int> ans(q, 0);
    for(auto& dists : distances) {
        sort(dists.begin(), dists.end(), cmp);
        for(auto& p : dists) {
            int index = upper_bound(a.begin(), a.end(), p.x) - a.begin();
            ans[p.idx] = abs(a[index - 1] - p.x);
        }
    }

    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}