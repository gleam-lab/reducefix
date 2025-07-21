#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int best_diff = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        best_diff = min(best_diff, v[n-k+i-1] - v[i]);
    }
    
    cout << best_diff << endl;
    
    return 0;
}