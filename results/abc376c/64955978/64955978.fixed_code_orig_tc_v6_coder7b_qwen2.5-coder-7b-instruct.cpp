#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < N-1; ++i){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll left = 0, right = *max_element(a.begin(), a.end());
    while(left < right){
        ll mid = (left + right) / 2;
        bool valid = true;
        for(int i = 0; i < N-1 && valid; ++i){
            if(b[i] >= mid || a[left] > mid){
                valid = false;
            }else{
                while(left < N && a[left] <= mid){
                    ++left;
                }
            }
        }
        if(valid){
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    if(left < a.back()){
        cout << -1 << endl;
    }else{
        cout << left << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}