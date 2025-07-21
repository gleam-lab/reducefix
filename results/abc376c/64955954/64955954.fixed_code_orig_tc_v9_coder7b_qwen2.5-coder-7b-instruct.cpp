#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    for(int i=0;i<n-1;i++) sum += b[i];
    
    if(sum >= a[n-1]) cout << a[n-1] << "\n";
    else cout << "-1\n";

    return 0;
}