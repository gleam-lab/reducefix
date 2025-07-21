#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum expression value for a given subset
ll calculate_min_expression(const vector<pll>& a, const vector<ll>& b, ll k) {
    ll n = a.size();
    multiset<ll> s(b.begin() + n - k, b.end()); // Initialize multiset with the last K elements of B
    ll sum = 0;
    for (ll i = n - k; i < n; ++i) sum += a[i].se; // Sum of B elements for the first subset

    ll ans = sum * a[n - k].fi; // Calculate initial answer for the first subset

    // Iterate through the first part of the sorted sequences
    for (ll i = n - k - 1; i >= 0; --i) {
        sum -= *s.rbegin(); // Remove the smallest element from the sum
        s.erase(*s.rbegin()); // Remove the smallest element from the multiset
        s.insert(a[i].se); // Insert the next element from the second part of B
        sum += a[i].se; // Add the new element to the sum
        ans = min(ans, sum * a[i].fi); // Update the minimum answer
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<pll> a(n);
        vector<ll> b(n);
        for (ll i = 0; i < n; ++i) cin >> a[i].fi >> b[i];
        sort(a.begin(), a.end()); // Sort based on A values
        cout << calculate_min_expression(a, b, k) << endl; // Calculate and print the minimum expression value
    }
    return 0;
}