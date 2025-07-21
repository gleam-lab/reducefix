#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        
        // Find the k-th closest point to b
        int idx = a[distance(a.begin(), lower_bound(a.begin(), a.end(), b)) + k - 1];

        // Calculate and print the distance
        cout << abs(idx - b) << "\n";
    }

    return 0;
}