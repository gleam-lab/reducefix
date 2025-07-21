#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>& a, vector<ll>& b, ll mid){
    int n = a.size();
    multiset<ll> s;
    for(int i=0;i<b.size();i++){
        s.insert(b[i]);
    }
    for(int i=0;i<n;i++){
        auto it = s.lower_bound(a[i]);
        if(it == s.end()){
            return false;
        }
        s.erase(it);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n-1;i++)cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll low = 0, high = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end()), ans = -1;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(check(a, b, mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}