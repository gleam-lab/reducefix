#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200000 + 1;
const int INF = 2e8;

int a[N];

int check(int mid, int x, int y) {
    int left = x - mid, right = x + mid;
    left = max(1, left);
    right = min(N - 1, right);
    return (long long)(a[right] - a[left - 1]) >= y;
}

void preprocess(vector<int>& A) {
    int shift = (N - 5) / 2;
    for (int x : A) {
        a[shift + x] += 1;
    }
    for (int i = shift; i < N; ++i) {
        a[i] += a[i - 1];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    preprocess(A);
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = 1, r = INF;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, x, y)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r - 1 << endl;
    }
    return 0;
}