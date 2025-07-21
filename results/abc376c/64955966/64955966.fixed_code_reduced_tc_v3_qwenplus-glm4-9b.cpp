#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
using namespace std;

ll binary_search(vector<ll>& A, ll target) {
    int left = 0, right = A.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (ll i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    ll smallest_x = LLONG_MAX;
    bool possible = true;
    
    for (ll i = 0; i < N; ++i) {
        ll idx = binary_search(B, A[i]);
        if (idx == -1 || B[idx] < A[i]) {
            if (A[i] > smallest_x) {
                smallest_x = A[i];
            } else {
                possible = false;
                break;
            }
        }
    }
    
    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << smallest_x << endl;
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}