#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long max_b = *max_element(b.begin(), b.end());
    bool found = false;

    for(long long x = max_b + 1; !found && x <= a.back(); ++x) {
        int j = 0;
        for(int i = 0; i < n; ++i) {
            while(j < n - 1 && b[j] < a[i]) ++j;
            if(j >= n - 1 || b[j] < a[i]) break;
            ++j;
        }
        if(i == n) {
            cout << x << '\n';
            found = true;
        }
    }

    if(!found) cout << -1 << '\n';

    return 0;
}