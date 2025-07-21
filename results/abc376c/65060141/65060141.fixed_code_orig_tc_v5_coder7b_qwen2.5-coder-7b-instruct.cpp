#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
ll a[MAXN], b[MAXN];

bool check(ll x, vector<ll>& boxes) {
    sort(boxes.begin(), boxes.end());
    for(int i = 0; i < boxes.size(); ++i) {
        if(x < a[i]) return false;
        x -= a[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i) cin >> b[i];

    vector<ll> boxes(b, b + n - 1);
    sort(boxes.begin(), boxes.end());

    ll left = 1, right = 1e9, mid, ans = -1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(check(mid, boxes)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}