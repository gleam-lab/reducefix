#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& A, vector<int>& B, long long mid) {
    multiset<long long> s(A.begin(), A.end());
    for (int b : B) {
        auto it = s.lower_bound(mid - b);
        if (it == s.end()) return false;
        s.erase(it);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];

    long long left = *max_element(A.begin(), A.end()), right = accumulate(B.begin(), B.end(), 0LL);

    while (left < right) {
        long long mid = (left + right) / 2;
        if (check(A, B, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (check(A, B, left)) cout << left << endl;
    else cout << -1 << endl;

    return 0;
}