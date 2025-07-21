#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& A, vector<int>& B, long long x) {
    multiset<long long> s(B.begin(), B.end());
    for (int i = 0; i < A.size(); ++i) {
        auto it = s.upper_bound(A[i]);
        if (it == s.begin()) return false;
        --it;
        s.erase(it);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long left = 1, right = 1e9 + 10;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (check(A, B, mid)) right = mid;
        else left = mid + 1;
    }

    if (left > 1e9) cout << "-1" << endl;
    else cout << left << endl;

    return 0;
}