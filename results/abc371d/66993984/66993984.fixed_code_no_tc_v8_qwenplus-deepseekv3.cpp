#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    vector<pair<int, int>> data(n); // to store x[i] and p[i] pairs
    
    for (int i = 0; i < n; i++) {
        cin >> data[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> data[i].second;
    }
    
    // Sort the data based on x values
    sort(data.begin(), data.end());
    
    // Prepare prefix sum array
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + data[i].second;
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the first x >= L
        auto it1 = lower_bound(data.begin(), data.end(), make_pair(L, 0));
        int start = it1 - data.begin();
        
        // Find the first x > R
        auto it2 = upper_bound(data.begin(), data.end(), make_pair(R, INT_MAX));
        int end = it2 - data.begin();
        
        cout << prefix[end] - prefix[start] << endl;
    }
    
    return 0;
}