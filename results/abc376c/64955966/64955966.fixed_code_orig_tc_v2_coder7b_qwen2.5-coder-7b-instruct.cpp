#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<long long> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    long long mx_b = *max_element(b.begin(), b.end());
    
    bool found = false;
    for(int i = 0; i < n && !found; ++i) {
        if(a[i] <= mx_b) {
            cout << a[i] << '\n';
            found = true;
        } else {
            for(int j = i+1; j < n && !found; ++j) {
                if(a[j] > mx_b) continue;
                if(a[j] >= a[i]) {
                    cout << a[j] << '\n';
                    found = true;
                }
            }
        }
    }
    
    if(!found) cout << "-1\n";
    
    return 0;
}