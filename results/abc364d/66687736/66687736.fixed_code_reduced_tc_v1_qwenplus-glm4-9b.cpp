#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--; // decrement k_j to be zero-indexed
    }
    
    sort(queries.begin(), queries.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });
    
    map<int, int> indexMap;
    int currentCount = 0;
    for (int i = 0; i < n; ++i) {
        indexMap[a[i]] = currentCount++;
    }
    
    int j = 0; // index for queries
    map<int, int> indexIndex; // maps index to the index of the point in a
    for (auto &idx : indexMap) {
        indexIndex[idx.second] = idx.first;
    }
    
    for (int i = 0; i < q; ++i) {
        int b = queries[i].first;
        int k = queries[i].second;
        
        while (j < q && queries[j].first == b) {
            k = min(k, queries[j].second);
            j++;
        }
        
        int l = upper_bound(a.begin(), a.end(), b - k) - a.begin() - 1;
        int r = lower_bound(a.begin(), a.end(), b - k) - a.begin();
        
        while (l >= 0 && k > 0) {
            l--;
            k--;
        }
        
        if (r < n && (l < 0 || k <= indexMap[a[r]] - indexMap[a[l]])) {
            cout << (long long)a[r] - b << endl;
        } else if (l >= 0) {
            cout << (long long)a[l] - b << endl;
        }
    }
    
    return 0;
}