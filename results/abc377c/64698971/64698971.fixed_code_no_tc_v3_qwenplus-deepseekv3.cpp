#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
#define IF_T if(Is_test)

#define ll long long
using namespace std;

int N,M; 
set<pair<int,int>> st;
set<pair<int,int>> existing;

void set_insert(int a,int b){
    if(1<=a && a<=N && 1<=b && b<=N) st.insert({a,b});
}

int main() {
    cin>>N>>M;

    vector<pair<int,int>> vc={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    rep(i,M){
        int a,b; cin>>a>>b;
        existing.insert({a,b});
        for(auto x:vc) set_insert(a+x.first,b+x.second);
    }

    ll total_squares = (ll)N * N;
    ll under_attack_or_occupied = st.size() + existing.size();
    
    // Calculate the number of squares that are both under attack and occupied
    set<pair<int,int>> intersection;
    set_intersection(st.begin(), st.end(), existing.begin(), existing.end(), inserter(intersection, intersection.begin()));
    ll safe_squares = total_squares - under_attack_or_occupied + intersection.size();
    
    cout << safe_squares << endl;
    return 0;
}