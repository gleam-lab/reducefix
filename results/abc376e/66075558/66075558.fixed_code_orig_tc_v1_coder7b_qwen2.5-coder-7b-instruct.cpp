#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
ll INF = LLONG_MAX / 2;

struct Element{
    ll first, second;
};

bool compare(Element &a, Element &b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

vector<ll> getPrefixSums(vector<ll>& nums){
    vector<ll> prefix(nums.size());
    prefix[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        prefix[i] = prefix[i-1] + nums[i];
    }
    return prefix;
}

void solve(){
    ll n, k; cin>>n>>k;
    vector<Element> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    for(int i=0;i<n;i++){
        cin>>b[i].first;
    }
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end());

    vector<ll> pref = getPrefixSums(b);
    
    ll ans = INF;
    for(int i=k-1;i<n;i++){
        ans = min(ans, ((pref[i] - (i-k>=0?pref[i-k]:0)) * a[i].first));
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}