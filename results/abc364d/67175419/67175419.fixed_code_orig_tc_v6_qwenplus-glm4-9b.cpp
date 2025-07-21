#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, q;
int a[N], b[N];

// Function to calculate the number of points that are closer or exactly at distance 'dist' from point B_j
int calculate(int B_j, int dist) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int distance = abs(a[i] - B_j);
        if (distance == dist) {
            count++;
        } else if (distance < dist) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> b[i] >> b[i + q];
        int low = -100000000, high = 100000000;
        while (low < high) {
            int mid = (low + high) / 2;
            if (calculate(b[i], mid) >= b[i + q]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << '\n';
    }
    return 0;
}