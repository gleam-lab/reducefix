#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e9 + 5;
int a[N];

int find_kth_closest(int left, int right, int x, int y) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= y) return mid;
        left = mid + 1;
    }
    return left;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x + N / 2]++; // Shift by N/2 to handle negative indices
    }
    for (int i = 1; i < N; ++i) {
        a[i] += a[i - 1];
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        int left = -N / 2, right = N / 2;
        cout << abs(find_kth_closest(left, right, x, k) - x) << endl;
    }
    return 0;
}