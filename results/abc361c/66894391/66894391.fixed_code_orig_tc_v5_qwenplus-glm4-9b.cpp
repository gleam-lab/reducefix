#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int max_val = A[n - k - i]; // Elements to remove from the end
        int min_val = A[i];         // Elements to remove from the start
        ans = min(ans, max_val - min_val);
    }
    
    cout << ans << endl;
    return 0;
}