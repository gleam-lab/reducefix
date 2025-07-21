#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

bool check(vector<ll>& a, vector<ll>& b, ll x) {
    int cnt = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    
    // Add all toys into the priority queue
    for(int i = 0; i < a.size(); ++i) {
        pq.push({a[i], i});
    }
    
    // Try to place toys into boxes
    while(!pq.empty()) {
        auto [size, idx] = pq.top();
        pq.pop();
        
        // Find a box with sufficient size
        int j = upper_bound(begin(b), end(b), size) - begin(b);
        if(j >= x) return false;
        
        // If we have already used this box, try the next available box
        if((j & 1) == (cnt & 1)) ++j;
        
        // Check if we have enough boxes left
        if(j >= x) return false;
        
        // Assign the toy to the box
        b[j] = max(b[j], size);
        ++cnt;
    }
    
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];
    
    sort(begin(b), end(b));
    reverse(begin(b), end(b));
    
    ll low = 1, high = 2e9, ans = -1;
    
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(check(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}