#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int min_size = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            min_size = max(min_size, a[i]);
        } else if (a[i] < b[i-1]) {
            min_size = max(min_size, b[i-1] + 1);
        } else {
            min_size = max(min_size, a[i]);
        }
    }
    
    cout << (min_size > 0 ? min_size : -1) << endl;
    return 0;
}