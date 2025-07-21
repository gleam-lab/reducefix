#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

struct Node {
    int sum, idx;
    bool operator<(const Node &other) const {
        return sum > other.sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n);
        vector<pair<int, int>> b(n);
        
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
        
        priority_queue<Node> pq;
        int total_sum = 0;
        for (int i = 0; i < k; ++i) {
            total_sum += b[i].first;
            pq.push({total_sum, b[i].second});
        }
        
        int result = LLONG_MAX;
        for (int i = 0; i < n - k + 1; ++i) {
            int max_a = a[i].first;
            int sum_b = pq.top().sum;
            result = min(result, max_a * sum_b);
            pq.pop();
            if (i + k < n) {
                total_sum -= pq.top().sum;
                total_sum += b[i + k].first;
                pq.push({total_sum, b[i + k].second});
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}