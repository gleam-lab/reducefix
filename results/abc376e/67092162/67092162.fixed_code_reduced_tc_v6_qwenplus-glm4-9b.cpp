#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];
pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        priority_queue< pair<int, int> > max_a;
        long long sum_a = 0, sum_b = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cin >> b[i];
            p[i] = {a[i], b[i]};
        }

        // Sort the pairs by the element in A for the top k elements
        sort(p, p + n, [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });

        // Calculate the sum of B for the top k elements
        for (int i = 0; i < k; ++i) {
            sum_b += p[i].second;
            max_a.push({p[i].first, p[i].second});
        }

        // Calculate the minimum possible value of the expression
        long long ans = sum_a * sum_b;

        // Iterate through the remaining elements
        for (int i = k; i < n; ++i) {
            sum_a += p[i].second;
            auto top_pair = max_a.top();
            max_a.pop();

            // If the new element is smaller than the current maximum in A
            if (p[i].first < top_pair.first) {
                sum_b += p[i].second - top_pair.second;
                max_a.push({p[i].first, p[i].second});
            } else {
                sum_b = sum_a; // Remove the largest in A and use sum_a for sum_b
            }

            ans = min(ans, p[i].first * sum_b);
        }

        cout << ans << '\n';
    }
    return 0;
}