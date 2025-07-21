#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    vector<bool> used(N-1, false);
    int a_ptr = 0, b_ptr = 0;
    int new_box_toys = 0;
    ll x = 0;

    while (a_ptr < N && b_ptr < N-1) {
        if (A[a_ptr] <= B[b_ptr]) {
            used[b_ptr] = true;
            a_ptr++;
            b_ptr++;
        } else {
            if (x == 0) {
                x = A[a_ptr];
                new_box_toys++;
                a_ptr++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    while (a_ptr < N) {
        if (x == 0) {
            x = A[a_ptr];
            new_box_toys++;
            a_ptr++;
        } else if (A[a_ptr] <= x) {
            new_box_toys++;
            a_ptr++;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    if (new_box_toys > 1) {
        cout << -1 << endl;
        return;
    }

    if (x == 0) {
        x = 1; // minimum possible x if all toys fit into existing boxes
    }

    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}