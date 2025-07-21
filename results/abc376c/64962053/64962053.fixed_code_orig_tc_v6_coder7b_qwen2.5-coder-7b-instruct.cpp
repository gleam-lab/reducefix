#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n-1);

    for(int i=0;i<n;i++) 
        cin >> a[i];

    for(int i=0;i<n-1;i++) 
        cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long min_box_size = *max_element(b.begin(), b.end());

    for(int i=n-1; i>=0; i--) {
        if(min_box_size >= a[i]) {
            cout << min_box_size << '\n';
            return 0;
        } else {
            min_box_size += a[i];
        }
    }

    cout << -1 << '\n';

    return 0;
}