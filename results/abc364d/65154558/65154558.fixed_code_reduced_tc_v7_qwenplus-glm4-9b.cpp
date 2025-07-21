#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n), b(q), k(q);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    // Sort the points A and keep the original indices
    vector<pair<long long, int>> indexed_a(n);
    for (int i = 0; i < n; ++i) {
        indexed_a[i] = {a[i], i};
    }
    sort(indexed_a.begin(), indexed_a.end());
    
    // Prepare the lower and upper bounds for binary search
    vector<long long> lower(n);
    vector<long long> upper(n);
    for (int i = 0; i < n; ++i) {
        lower[i] = indexed_a[i].first - b[k[i]];
        upper[i] = indexed_a[i].first + b[k[i]];
    }
    
    // Sort the queries by distance b[k[i]] to handle the closest point correctly
    vector<pair<long long, int>> indexed_k(q);
    for (int i = 0; i < q; ++i) {
        indexed_k[i] = {b[i], i};
    }
    sort(indexed_k.begin(), indexed_k.end());
    
    // Answer each query with binary search over the possible indices in A
    for (int i = 0; i < q; ++i) {
        long long distance = indexed_k[i].first;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (lower[mid] <= distance && distance <= upper[mid]) {
                cout << indexed_a[mid].first + b[indexed_k[i].second] << endl;
                break;
            } else if (lower[mid] > distance) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    
    return 0;
}