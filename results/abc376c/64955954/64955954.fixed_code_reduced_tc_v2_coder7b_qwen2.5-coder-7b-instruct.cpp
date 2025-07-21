#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=1; i<n; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=n-1; i>=0; --i) {
        if(a[i] <= b[i]) {
            cout << a[i] << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}