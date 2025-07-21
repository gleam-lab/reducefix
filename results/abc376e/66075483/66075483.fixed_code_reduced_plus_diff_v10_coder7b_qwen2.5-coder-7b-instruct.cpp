#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-(a[0].first * b[0].first), {a[0].second, b[0].second}});
        vector<bool> used(n, false);
        used[a[0].second] = true;
        used[b[0].second] = true;
        int totalSum = b[0].first;
        
        for (int i = 1; i < n; ++i) {
            if (!used[a[i].second]) {
                auto [negMax, indices] = pq.top();
                int oldMax = -negMax / totalSum;
                pq.pop();

                int newTotalSum = totalSum + b[i].first;
                int newNegMax = -(oldMax * newTotalSum + b[i].first);
                
                pq.push({newNegMax, {indices.first, b[i].second}});
                used[a[i].second] = true;
                totalSum = newTotalSum;
            }
        }
        
        cout << -pq.top().first << '\n';
    }

    return 0;
}