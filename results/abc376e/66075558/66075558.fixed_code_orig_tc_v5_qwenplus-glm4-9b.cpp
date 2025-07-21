#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, k, t;
vector<int> a, b;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n), b.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long sum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            sum += b[i];
            if (i >= k) sum -= b[i - k];
            
            if (i >= k - 1) {
                pq.push({sum, a[i - k + 1]});
            }
            
            if (i >= k - 1) {
                ans = min(ans, (long long)pq.top().first * (long long)a[i]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}