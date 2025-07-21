#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canFit(vector<ll>& sizes, ll mid, int n) {
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        if(sizes[i] <= mid) cnt[sizes[i]]++;
        else return false;
    }
    for(int i = 1; i <= n; ++i) {
        if(i == 1) {
            if(cnt[i] > 1) return false;
        } else {
            if(cnt[i] != cnt[i - 1] + 1) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll low = 0, high = 1e9, ans = -1;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(canFit(a, mid, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}