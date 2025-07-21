#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a[n - 1] > b[n - 2]){
        cout << -1 << endl;
        return;
    }

    for(int i = 0; i < n - 1; i++){
        if(a[i] <= b[0])
            continue;
        else if(i == n - 2 && a[i] > b[n - 2]){
            cout << -1 << endl;
            return;
        }else{
            cout << a[i] << endl;
            return;
        }
    }
    cout << a[n - 1] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}