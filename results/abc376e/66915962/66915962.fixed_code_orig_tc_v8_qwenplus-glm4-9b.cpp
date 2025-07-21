#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        // Sort in descending order
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        long long min_value = LLONG_MAX;
        
        // Try every possible subset of size k
        for (int i = 0; i <= n - k; i++) {
            long long sum_b = 0;
            for (int j = i; j < i + k; j++) {
                sum_b += b[j];
            }
            long long current_value = a[i] * sum_b;
            min_value = min(min_value, current_value);
        }
        
        cout << min_value << '\n';
    }
    return 0;
}