#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < N - 1; ++i){
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // The minimum box size required will be the maximum of the largest toy and the second largest box
    ll min_box_size = max(a.back(), b[N - 2]);

    // Check if this box size can accommodate all toys
    bool can_store_all_toys = true;
    for(int i = 0; i < N - 1; ++i){
        if(a[i] > min_box_size || a[i + 1] > min_box_size){
            can_store_all_toys = false;
            break;
        }
    }

    if(can_store_all_toys){
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}