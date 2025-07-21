#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canStore(vector<ll>& a, vector<ll>& b, ll x) {
    int n = a.size();
    multiset<ll> boxes;
    for(int i = 0; i < n - 1; ++i) {
        boxes.insert(b[i]);
    }
    
    for(int i = 0; i < n; ++i) {
        auto it = boxes.lower_bound(a[i]);
        if(it == end(boxes)) return false;
        boxes.erase(it);
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    ll low = 0, high = *max_element(begin(a), end(a)), ans = -1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(canStore(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}