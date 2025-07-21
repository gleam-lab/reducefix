#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int unmatched = -1;
    int i = 0, j = 0;
    
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            ++i;
            ++j;
        } else {
            if (unmatched == -1) {
                unmatched = a[i];
                ++i;
            } else {
                // More than one toy cannot be matched, impossible
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    if (unmatched == -1) {
        if (i < n) {
            // All boxes are used, the new box must fit the remaining toy(s)
            if (i == n - 1) {
                cout << a[i] << endl;
            } else {
                // More than one toy left, impossible
                cout << -1 << endl;
            }
        } else {
            // All toys matched, but we have an extra box; x can be any value, but the problem expects smallest, which is not possible as per problem statement
            cout << 1 << endl;
        }
    } else {
        if (i < n) {
            // More than one toy cannot be matched
            cout << -1 << endl;
        } else {
            cout << unmatched << endl;
        }
    }
    
    return 0;
}