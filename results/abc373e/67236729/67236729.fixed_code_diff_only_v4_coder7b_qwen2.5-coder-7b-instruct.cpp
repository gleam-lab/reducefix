#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> b(n);
    for(int i = 0; i < n; ++i) {
        b[i] = a[n - 1] - a[i];
    }

    vector<long long> c(n);
    for(int i = 0; i < n; ++i) {
        if(m - 1 <= i) {
            c[i] = 0;
        } else {
            c[i] = b[m - 1] - b[i] + 1;
        }
    }

    for(int i = 0; i < n; ++i) {
        if(k < c[i]) {
            cout << -1 << " ";
        } else {
            cout << c[i] << " ";
            k -= c[i];
        }
    }

    cout << endl;

    return 0;
}