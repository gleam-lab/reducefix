#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int possible = -1;
    // Check if we can place all but the largest toy in the existing boxes
    bool ok = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        possible = a.back();
    } else {
        // Try placing the largest toy in one of the existing boxes and see if the rest can fit
        // Specifically, place the largest toy in the largest existing box
        if (n >= 2 && a[n - 1] <= b[n - 2]) {
            bool other_ok = true;
            for (int i = 0; i < n - 2; ++i) {
                if (a[i] > b[i]) {
                    other_ok = false;
                    break;
                }
            }
            if (other_ok && a[n - 2] <= b[n - 2]) {
                possible = max(1, a[n - 2]);
            }
        }
    }
    
    // Another case: maybe the largest toy is in the new box, and the second largest is in the largest box
    if (possible == -1) {
        bool other_case_ok = true;
        for (int i = 0; i < n - 2; ++i) {
            if (a[i] > b[i]) {
                other_case_ok = false;
                break;
            }
        }
        if (other_case_ok && a[n - 2] <= b[n - 2]) {
            possible = a.back();
        }
    }
    
    if (possible != -1) {
        // We need to ensure that the possible x is at least the largest toy not placed in existing boxes
        bool final_check = true;
        int x = possible;
        // The largest toy is placed in the new box (x >= a[?])
        // The other N-1 toys must be placed in the existing boxes
        vector<int> new_b = b;
        new_b.push_back(x);
        sort(new_b.begin(), new_b.end());
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            if (a[i] > new_b[i]) {
                final_check = false;
                break;
            }
        }
        if (final_check) {
            cout << possible << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}