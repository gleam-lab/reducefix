#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], b[N];
int sum_b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }

        sort(a + 1, a + n + 1);
        
        // Create the sorted B array matching the sorted A array
        vector<int> sorted_b(n + 1);
        for (int i = 1; i <= n; i++) {
            sorted_b[i] = b[a[i].second].first;
        }

        // Precompute prefix sums
        sum_b[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum_b[i] = sum_b[i-1] + sorted_b[i];
        }

        if (k == 1) {
            int min_val = inf;
            for (int i = 1; i <= n; i++) {
                min_val = min(min_val, a[i].first * sorted_b[i]);
            }
            cout << min_val << '\n';
            continue;
        }

        priority_queue<int> pq;
        int current_sum = 0;
        int min_result = inf;

        for (int i = 1; i <= n; i++) {
            if (pq.size() < k - 1) {
                pq.push(sorted_b[i]);
                current_sum += sorted_b[i];
            } else {
                if (k > 1) {
                    min_result = min(min_result, a[i].first * (current_sum + sorted_b[i]));
                }
                
                if (!pq.empty() && sorted_b[i] < pq.top()) {
                    current_sum -= pq.top();
                    pq.pop();
                    current_sum += sorted_b[i];
                    pq.push(sorted_b[i]);
                }
            }
        }

        cout << min_result << '\n';
    }
    return 0;
}