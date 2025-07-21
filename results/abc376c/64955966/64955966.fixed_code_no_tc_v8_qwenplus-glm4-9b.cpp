#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
using namespace std;

void solve() {
    ll N;
    cin >> N;
    ll A[N], B[N-1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }

    // Sort the toy sizes and box sizes in descending order
    sort(A, A + N, greater<ll>());
    sort(B, B + N-1, greater<ll>());

    // We only need to consider the sizes B[0] to B[N-2] to cover all toys except the largest one
    ll min_x = LLONG_MAX;
    for (ll i = 0; i < N-1; ++i) {
        // We need to place A[i] into the largest box that is not full
        // B[i] is the largest box that is not full, so we need to find the smallest box size that can fit A[i]
        if (A[i] <= B[i]) {
            min_x = min(min_x, B[i]);
        } else if (A[i] <= B[i-1]) {
            // If B[i] is full, we try the next largest box
            min_x = min(min_x, B[i-1]);
        } else {
            // If all boxes B[0] to B[i-1] are full, there is no solution
            no;
            return;
        }
    }

    // After all toys are placed, we need to check if the largest toy fits into the smallest available box
    if (A[N-1] > min_x) {
        no;
    } else {
        yes;
        cout << min_x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}