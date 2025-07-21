#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxN = 200005;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        // Pair each element of A with its corresponding B element
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; i++) {
            ab[i] = {b[i], a[i]};
        }
        
        // Sort the pairs based on the first element (B values) in descending order
        sort(ab.rbegin(), ab.rend());
        
        long long sum = 0; // Initialize sum of B values for the best pair
        long long ans = LLONG_MAX; // Initialize answer with maximum possible value
        
        for (int i = 0; i < k; i++) {
            sum += ab[i].first;
            ans = min(ans, ab[i].first * sum);
        }
        
        // For the remaining pairs, choose the one that minimizes the expression
        for (int i = k; i < n; i++) {
            sum -= ab[i - k].first;
            ans = min(ans, ab[i].first * sum);
        }
        
        cout << ans << endl;
    }
    return 0;
}