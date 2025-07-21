#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n - 1);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (long long i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    long long new_box_size = 0;
    long long i = 0, j = 0;
    long long unplaced = 0;
    
    while (i < n && j < n - 1) {
        if (b[j] >= a[i]) {
            i++;
            j++;
        } else {
            unplaced++;
            new_box_size = max(new_box_size, a[i]);
            i++;
        }
    }
    
    while (i < n) {
        unplaced++;
        new_box_size = max(new_box_size, a[i]);
        i++;
    }
    
    if (unplaced > 1) {
        cout << -1 << endl;
    } else {
        cout << new_box_size << endl;
    }
    
    return 0;
}