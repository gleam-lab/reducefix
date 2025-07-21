#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

bool canPlaceAllToys(vector<ll>& A, vector<ll>& B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (B[j] >= A[i]) {
            i++;
        } else {
            j++;
        }
    }

    // If all toys are placed, return true
    return i == n;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);

    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (ll i = 0; i < n - 1; i++) {
        cin >> B[i];
    }

    if (canPlaceAllToys(A, B)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}