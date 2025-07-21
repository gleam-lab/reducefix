#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = n-2; i >= 0; --i) b[i] += b[i+1]; // Accumulate sizes of boxes

    int res = -1;
    for(int i = 0; i < n-1; ++i) { // Check if we can fit toy i into any box
        if(a[i] <= b[i]) {
            res = a[i];
            break;
        }
    }

    cout << res << '\n';
    return 0;
}