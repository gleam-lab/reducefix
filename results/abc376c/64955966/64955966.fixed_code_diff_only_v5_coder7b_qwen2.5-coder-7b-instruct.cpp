#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = INT_MAX;
    for(int i = 0; i < n - 1; ++i){
        if(a[n - 1] <= b[i]) {
            ans = min(ans, max(a[n - 1], b[i]));
        }
    }
    if(ans == INT_MAX)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}