#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<long long> a(n), b(n-1);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    while(i < n && j < n-1) {
        if(a[i] <= b[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    if(i == n) cout << "1";
    else cout << "-1";
    
    return 0;
}