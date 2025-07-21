#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<pair<long long, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        long long b;
        int k;
        cin >> b >> k;
        queries[i] = {abs(a[k - 1] - b), k};
    }

    // Sort queries by distance to B_j, then by k_j descending
    sort(queries.begin(), queries.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    // Create a map to track used indices
    map<int, int> used;
    for (int i = 0; i < q; ++i) {
        int k = queries[i].second;
        while (used.count(k)) {
            k++;
        }
        used[k] = 1; // Mark this index as used
        cout << queries[i].first << endl;
    }

    return 0;
}