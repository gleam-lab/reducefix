#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    // Sort the toy sizes in ascending order.
    sort(A.begin(), A.end());

    // Find the size of the largest toy.
    ll maxToySize = A[N-1];

    // Sort the box sizes in ascending order.
    sort(B.begin(), B.end());

    // Use binary search to find the smallest box size that is larger than maxToySize.
    auto it = lower_bound(B.begin(), B.end(), maxToySize);

    // If such a box exists, print its size.
    if (it != B.end()) {
        cout << *it << endl;
    } else {
        cout << maxToySize << endl;
    }

    return 0;
}