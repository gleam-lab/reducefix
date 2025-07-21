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
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N - 1; i++){
        cin >> b[i];
    }
    
    // Sort sizes in ascending order for easy comparison
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // The largest toy must fit into the largest available box
    if(a.back() > b.back()){
        cout << -1 << endl;
        return;
    }
    
    // Check if we can fit all toys into the existing boxes
    bool all_fit = true;
    for(int i = 0; i < N - 1; i++){
        if(a[i] > b[i]){
            all_fit = false;
            break;
        }
    }
    
    if(all_fit){
        cout << "1" << endl; // Only need the smallest box which is size 1
        return;
    }
    
    // Find the smallest box that can accommodate the largest toy
    ll min_box_size = a.back();
    for(int i = 0; i < N - 1; i++){
        if(b[i] >= min_box_size){
            cout << min_box_size << endl;
            return;
        }
    }
    
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}