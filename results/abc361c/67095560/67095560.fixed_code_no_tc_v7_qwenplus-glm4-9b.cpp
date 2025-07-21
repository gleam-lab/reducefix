#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    
    // The goal is to maximize the difference between the max and min of the remaining elements
    // by removing `k` elements. To do this, we should aim to remove elements that are either
    // very small or very large, leaving behind a range of potential values.
    
    // If k is odd, we remove an element from the largest side to maximize the range.
    // If k is even, we remove an element from both sides to make the range symmetric around the median.
    
    if (k % 2 == 1) {
        // For odd k, remove one largest element to maximize the range
        ll max_val = a[n - 1] - a[k / 2]; // max value after removing one element from the largest side
        cout << max_val << endl;
    } else {
        // For even k, remove one element from each side to maximize the range
        ll max_val = a[n - 1 - (k / 2)] - a[k / 2 + 1]; // max value after removing one element from each side
        cout << max_val << endl;
    }
    
    return 0;
}