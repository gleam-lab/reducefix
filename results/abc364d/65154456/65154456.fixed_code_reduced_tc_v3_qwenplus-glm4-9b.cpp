#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int INF = 1e9 + 7;
const int N = 200000000;

int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;  // Increment the count at the position x
    }

    for (int i = 2; i < N; i++) {
        a[i] += a[i - 1];  // Accumulate the counts to get the number of points on the left
    }

    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        // Calculate the leftmost point that can be at least k-th closest to b
        int leftmost = 0;
        // Binary search for the smallest distance that ensures we can reach b as the k-th closest
        while (leftmost < b) {
            int rightmost = b;
            while (leftmost + 1 < rightmost) {
                int mid = (leftmost + rightmost) / 2;
                if (a[mid] >= k) rightmost = mid;
                else leftmost = mid + 1;
            }
            if (a[rightmost] >= k) {
                cout << (long long)(b - rightmost) * (b - rightmost) << endl;
                break;
            } else {
                cout << -1 << endl;
                break;
            }
        }
    }

    return 0;
}