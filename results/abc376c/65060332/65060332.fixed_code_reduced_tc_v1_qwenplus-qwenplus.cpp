#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    
    vector<ll> a(n), b(n - 1);
    
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // We need to find the minimal x such that we can assign all toys
    // Use binary search on possible x values
    
    // First, collect all candidate x values (all A_i values)
    vector<ll> candidates = a;
    candidates.push_back(0);  // For case when no extra box is needed
    sort(candidates.begin(), candidates.end());
    
    auto is_possible = [&](ll x) {
        // Try to assign toys to boxes with x being the added box size
        multiset<ll> boxes;
        for (ll val : b) boxes.insert(val);
        
        vector<ll> temp_a = a;
        temp_a.push_back(x);
        sort(temp_a.begin(), temp_a.end());
        
        // Now try greedy matching from smallest toy to largest
        // We use the smallest possible box for each toy
        int j = 0;  // pointer for boxes
        for (ll toy : temp_a) {
            if (j < b.size() && b[j] >= toy) {
                j++;
            } else {
                // Check if our purchased box can be used
                if (toy <= x) {
                    // Use the purchased box
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    };
    
    // Binary search on candidates
    ll left = 0, right = n - 1;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (is_possible(candidates[mid])) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    // Check if any value works
    if (is_possible(candidates[left])) {
        cout << candidates[left] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}