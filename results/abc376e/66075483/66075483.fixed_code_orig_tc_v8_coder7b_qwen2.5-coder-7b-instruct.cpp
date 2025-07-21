#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define int long long
#define lowbit(x) x & (-x)

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
int s, q;
pair<int, int> a[N], b[N];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort A and B based on their indices
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        vector<pair<int, int>> pq;
        int current_sum = 0;
        for (int i = 1; i <= k; i++) {
            pq.emplace_back(b[i].first, b[i].second);
            current_sum += b[i].first;
        }

        // Initialize the answer with the initial product
        ans = current_sum * a[k].first;

        for (int i = k + 1; i <= n; i++) {
            int max_a = a[i].first;
            int new_min_b = pq.front().first;

            // Calculate the new product
            int new_product = (current_sum - new_min_b + b[i].first) * max_a;

            // Update the answer if the new product is smaller
            ans = min(ans, new_product);

            // Remove the smallest element from the heap
            current_sum -= new_min_b;
            pq.erase(pq.begin());

            // Insert the next smallest element from B into the heap
            pq.emplace_back(b[i].first, b[i].second);
            current_sum += b[i].first;
        }

        cout << ans << endl;
    }
    return 0;
}