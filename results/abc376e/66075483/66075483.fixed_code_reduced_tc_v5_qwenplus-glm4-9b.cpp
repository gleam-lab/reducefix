#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9;

int n, k, t;
vector<pair<int, int>> a(N), b(N); // a is for max values, b is for sum values

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.assign(n, {0, 0});
        b.assign(n, {0, 0});
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort by A[i].first descending
        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });

        // Sort by B[i].first descending
        sort(b.begin(), b.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });
        
        long long sum_k_elements = 0;
        
        // Calculate initial sum of the largest k-1 elements from B
        for (int i = 0; i < k - 1; ++i) {
            sum_k_elements += b[i].first;
        }
        
        long long min_value = (a[k-1].first * sum_k_elements);
        
        // Iterate through the remaining elements of A and calculate the minimum value
        for (int i = k; i < n; ++i) {
            sum_k_elements += b[i].first - b[i - k].first;
            min_value = min(min_value, a[i].first * sum_k_elements);
        }
        
        cout << min_value << endl;
    }
    
    return 0;
}