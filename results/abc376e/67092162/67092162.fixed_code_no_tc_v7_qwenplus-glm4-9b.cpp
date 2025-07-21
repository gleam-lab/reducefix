#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];
long long sumB[maxN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;
        long long minSum = LLONG_MAX;
        long long currentSum = 0;
        long long maxA = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cin >> b[i];
            sumB[i] = b[i];
            q.push({a[i], b[i]});
            currentSum += b[i];
            if (i >= k) {
                currentSum -= q.top().second;
                q.pop();
            }
            if (i >= k - 1) {
                minSum = min(minSum, currentSum);
            }
        }
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (minSum == sumB[i]) {
                result = max(result, (long long)a[i] * minSum);
            }
        }
        cout << result << "\n";
    }
    return 0;
}