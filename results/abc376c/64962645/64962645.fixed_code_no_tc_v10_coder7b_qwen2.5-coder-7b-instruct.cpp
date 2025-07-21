#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n - 1; ++i)
        cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    long long mx = 0;
    for(int i = 0; i < n - 1; ++i) {
        if(a[i] <= b[i]) {
            mx = max(mx, 1LL * a[i]);
        }
    }

    if(mx == 0)
        cout << "-1\n";
    else
        cout << mx << "\n";

    return 0;
}