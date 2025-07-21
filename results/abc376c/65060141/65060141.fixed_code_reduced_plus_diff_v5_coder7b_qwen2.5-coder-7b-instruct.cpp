#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

bool canStoreAll(vector<ll>& A, vector<ll>& B, ll x) {
    int n = A.size();
    vector<ll> prefixSum(n + 1, 0);
    
    // Calculate prefix sums of toy sizes
    for(int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + A[i - 1];
    }
    
    // Check if we can store all toys with the given box size
    for(int i = 0; i < n - 1; ++i) {
        if(prefixSum[n] - prefixSum[i] > x * (n - 1 - i)) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    
    for(ll i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for(ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    ll l = A.back(); // Minimum box size needed is the size of the largest toy
    ll r = accumulate(A.begin(), A.end(), 0LL); // Maximum possible box size
    
    while(l < r) {
        ll m = (l + r) / 2;
        
        if(canStoreAll(A, B, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    cout << (canStoreAll(A, B, l) ? l : -1) << endl;
    return 0;
}