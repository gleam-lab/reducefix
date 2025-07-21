#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> b(q);
    for(int i = 0; i < q; i++) {
        cin >> b[i].first >> b[i].second;
        b[i].first--;
    }

    sort(a.begin(), a.end());

    for(auto& p : b) {
        auto it = lower_bound(a.begin(), a.end(), p.first);
        int idx = it - a.begin();
        int k = p.second - 1;
        if(k == idx) cout << abs(a[idx] - p.first) << '\n';
        else if(idx == 0) cout << abs(a[idx] - p.first) << '\n';
        else if(idx == n) cout << abs(a[idx - 1] - p.first) << '\n';
        else {
            int dist1 = abs(a[idx] - p.first);
            int dist2 = abs(a[idx - 1] - p.first);
            cout << min(dist1, dist2) << '\n';
        }
    }

    return 0;
}