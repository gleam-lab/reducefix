#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N];

bool canPlace(ll x, vector<ll>& A, vector<ll>& B) {
    int j = 0;
    for(int i = 0; i < A.size(); ++i) {
        while(j < B.size() && B[j] < A[i]) {
            ++j;
        }
        if(j == B.size()) return false;
        ++j;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll low = 0, high = *max_element(A.begin(), A.end()), mid, ans = -1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(canPlace(mid, A, B)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}