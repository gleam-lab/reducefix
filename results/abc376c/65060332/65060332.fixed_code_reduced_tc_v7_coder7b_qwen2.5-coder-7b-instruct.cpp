#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<ll> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int idx = 0;
    bool possible = true;
    for(int i = 0; i < n-1; ++i) {
        if(idx == n || b[i] < a[idx]) {
            possible = false;
            break;
        }
        while(idx < n && b[i] >= a[idx]) {
            ++idx;
        }
    }

    if(possible) {
        cout << a[n-1] << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}