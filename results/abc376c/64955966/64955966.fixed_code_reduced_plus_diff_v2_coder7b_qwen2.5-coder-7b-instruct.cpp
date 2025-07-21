#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> a(N), b(N - 1);
    
    // Read toy sizes
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Read box sizes
    for (int i = 0; i < N - 1; ++i) {
        cin >> b[i];
    }
    
    // Sort toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Try to place each toy in the smallest possible box
    int j = 0; // Index for the box array
    bool canPlaceAll = true;
    
    for (int i = 0; i < N && canPlaceAll; ++i) {
        while (j < N - 1 && b[j] < a[i]) {
            ++j;
        }
        
        if (j == N - 1 && b[j] < a[i]) {
            canPlaceAll = false;
        } else {
            ++j;
        }
    }
    
    if (canPlaceAll) {
        cout << a.back() << endl; // Output the size of the last toy which is the maximum
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}