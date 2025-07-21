#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_A = 100000000;
const intMAX_B = 200000000; // Enough to cover range of a_i and b_j

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    // Read all a_i values and increment counts at appropriate positions
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }
    
    // Sort points a to prepare for the queries
    sort(a.begin(), a.end());
    
    // Process each query
    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        
        // Calculate the position of b_j on the number line
        long long b_position = b + MAX_A;
        
        // Find the k-th closest point to b_j among a_i
        // We use upper_bound to find the first element in a that is not less than b_position
        long long pos = upper_bound(a.begin(), a.end(), b_position) - a.begin();
        
        // Calculate the k-th smallest distance
        // We use an auxiliary array to count distances
        vector<int> count(max(a.end() - a.begin(), MAX_B - a.begin()) + 1, 0);
        for (int i = 0; i < pos - 1; ++i) {
            count[a[i] - b_position + 1]++;
        }
        
        // Accumulate counts to find the position of k-th closest point
        long long acc = 0;
        for (int i = 1; i <= k && i < count.size(); ++i) {
            acc += count[i];
            if (acc >= k) {
                cout << b_position - (a[pos - i] - MAX_A) << endl;
                break;
            }
        }
    }
    
    return 0;
}