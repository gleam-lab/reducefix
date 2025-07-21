#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>& A, vector<ll>& B, ll x) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int j = 0;
    for(int i = 0; i < A.size(); i++) {
        while(j < B.size() && B[j] < A[i]) j++;
        if(j == B.size()) return false;
        j++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<ll> A(n), B(n-1);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n-1; i++) cin >> B[i];

    ll lo = *max_element(A.begin(), A.end()), hi = *max_element(B.begin(), B.end());
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(A, B, mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << lo << endl;
    return 0;
}