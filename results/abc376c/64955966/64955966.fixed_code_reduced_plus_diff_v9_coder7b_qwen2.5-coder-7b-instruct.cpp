#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

bool canPlace(ll mid, vector<ll> &a, vector<ll> &b){
    int n = a.size();
    vector<bool> used(n-1, false);
    for(int i = 0; i < n; i++){
        bool placed = false;
        for(int j = 0; j < n-1; j++){
            if(!used[j] && b[j] >= a[i]){
                used[j] = true;
                placed = true;
                break;
            }
        }
        if(!placed){
            return false;
        }
    }
    return true;
}

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a[0] > b.back()){
        cout << -1 << endl;
        return;
    }

    ll low = 0, high = 1e9 + 7, ans = -1;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(canPlace(mid, a, b)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}