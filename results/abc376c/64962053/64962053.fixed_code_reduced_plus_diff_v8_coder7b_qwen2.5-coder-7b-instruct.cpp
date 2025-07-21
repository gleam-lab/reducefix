#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)cin>>b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i=0;i<n-1;i++){
        if(b[i]<a[i+1]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<max(a[n-1], b[n-2])<<endl;
    return 0;
}