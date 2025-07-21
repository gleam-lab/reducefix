#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    vector<pair<long long, int>> queries(q);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].second; // Adjusting index to zero-based
    }
    
    sort(a.begin(), a.end());
    
    vector<long long> prefix_sums(n + 1);
    for(int i = 0; i < n; ++i) {
        prefix_sums[i + 1] = prefix_sums[i] + a[i];
    }
    
    auto find_kth_closest = [&](long long target, int k) {
        int left = 0, right = n;
        while(left < right) {
            int mid = (left + right) / 2;
            if(prefix_sums[mid + 1] - prefix_sums[upper_bound(a.begin(), a.end(), target - a[mid]) - a.begin()] >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return a[left] - target;
    };
    
    for(const auto& query : queries) {
        cout << find_kth_closest(query.first, query.second + 1) << '\n';
    }
    
    return 0;
}