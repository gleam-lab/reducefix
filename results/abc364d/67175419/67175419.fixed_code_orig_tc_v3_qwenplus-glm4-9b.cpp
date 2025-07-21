#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    while (q--) {
        int b, k;
        cin >> b >> k;
        int min_distance = INT_MAX;
        // Binary search for the k-th closest point
        for (int i = 0; i < n; ++i) {
            // Calculate the distance from the point in a to the query point b
            int distance = abs(a[i] - b);
            // If the current distance is within the top k, update the minimum distance
            if (distance < min_distance) {
                min_distance = distance;
            }
            // If the current distance is greater than the k-th closest distance found so far,
            // then we can stop searching further since all subsequent points will be further away
            if (abs(a[i] - b) > min_distance) {
                break;
            }
        }
        cout << min_distance << "\n";
    }
    return 0;
}