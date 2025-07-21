#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    
    unordered_map<int, int> t;
    long long an = 0;
    int sum = 0;
    
    for (int i = 0; i < 2 * n; ++i) {
        sum = (sum + a[i]) % m;
        if (i >= n) {
            an += t[sum];
        }
        t[sum]++;
    }
    
    cout << an << endl;
    return 0;
}