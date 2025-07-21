#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>& a, vector<ll>& b, int x) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
        while(j < b.size() && b[j] < a[i]) j++;
        if(j == b.size()) return false;
        j++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) cin >> b[i];
    
    sort(b.begin(), b.end(), greater<int>());
    int low = 1, high = 1e9, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
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