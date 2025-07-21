#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum_b = accumulate(b.begin(), b.end(), 0LL);
    long long min_x = 0;

    for(int i=0;i<n-1;i++){
        if(sum_b + a[n-1] < a[i]) {
            min_x = a[i];
            break;
        } 
        sum_b += b[i];
    }

    if(min_x == 0){
        cout << -1 << '\n';
    }else{
        cout << min_x << '\n';
    }

    return 0;
}