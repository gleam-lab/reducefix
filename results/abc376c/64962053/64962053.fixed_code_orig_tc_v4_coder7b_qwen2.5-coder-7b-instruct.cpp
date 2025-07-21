#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) cin >> b[i];

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Check if we can place each toy in a box
    for(int i = 0; i < n; i++) {
        if(i == 0 && a[i] > b[i]) {
            cout << -1 << "\n";
            return 0;
        } 
        else if(i != 0 && a[i] > b[i - 1]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // The smallest box needed will be the maximum toy size
    cout << *max_element(a.begin(), a.end()) << "\n";

    return 0;
}