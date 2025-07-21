#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, q;
vector<int> a(N+1), b(N+1), k(N+1);
int distances[N+1];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> b[i] >> k[i];
    }

    for (int j = 1; j <= q; j++) {
        for (int i = 1; i <= n; i++) {
            distances[i] = abs(a[i] - b[j]); // Calculate the distance between points A_i and B_j
        }
        sort(distances + 1, distances + n + 1); // Sort distances in ascending order
        cout << distances[k[j]] << '\n'; // Output the k-j-th closest distance
    }

    return 0;
}