#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        // Sort the arrays in descending order
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        // Calculate the sum of the smallest K-1 elements from A and the remaining N-K elements from B
        long long sum_a_k_minus_1 = 0;
        long long sum_b_n_minus_k = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum_a_k_minus_1 += a[i];
        }
        for (int i = k - 1; i < n; ++i) {
            sum_b_n_minus_k += b[i];
        }
        
        // Calculate the product
        long long product1 = a[k - 1] * sum_b_n_minus_k;
        long long product2 = a[0] * sum_a_k_minus_1;
        
        // Take the minimum product
        cout << min(product1, product2) << endl;
    }
    return 0;
}