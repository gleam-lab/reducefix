#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<pair<int, ll>> sorted_pairs;
    for (int i = 0; i < n; i++) {
        sorted_pairs.emplace_back(x[i], p[i]);
    }
    sort(sorted_pairs.begin(), sorted_pairs.end());
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        auto it_lower = lower_bound(sorted_pairs.begin(), sorted_pairs.end(), make_pair(l, 0LL));
        auto it_upper = upper_bound(sorted_pairs.begin(), sorted_pairs.end(), make_pair(r, LLONG_MAX));
        
        ll sum = 0;
        for (auto it = it_lower; it != it_upper; ++it) {
            sum += it->second;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}