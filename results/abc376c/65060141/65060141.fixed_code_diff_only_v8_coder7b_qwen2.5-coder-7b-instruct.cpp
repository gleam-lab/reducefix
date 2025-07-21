#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

bool check(ll mid, int n, vector<ll>& A, vector<ll>& B) {
    int j = 0;
    for(int i = 0; i < n - 1; ++i) {
        while(j < n && A[j] <= B[i]) ++j;
        if(j == n || A[j] > mid) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n - 1);

    int left = 0, right = 1e9, ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(check(mid, n, a, b)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}