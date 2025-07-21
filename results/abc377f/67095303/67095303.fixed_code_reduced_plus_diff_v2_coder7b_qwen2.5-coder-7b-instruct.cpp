#include<bits/stdc++.h>

using namespace std;

long long mod=1e9+7;

struct Point{
    long long x,y;
};

bool operator<(const Point&a,const Point&b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

bool operator==(const Point&a,const Point&b){
    return a.x==b.x&&a.y==b.y;
}

bool operator!=(const Point&a,const Point&b){
    return !(a==b);
}

vector<Point>points;
set<long long>x,y;
map<long long,long long>diag1,diag2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,m;
    cin>>n>>m;

    for(long long i=0;i<m;++i){
        long long x,y;
        cin>>x>>y;
        points.push_back({x,y});
        x.insert(x);
        y.insert(y);
        diag1[x+y]++;
        diag2[x-y]++;
    }

    sort(points.begin(),points.end());
    
    long long res=0;

    for(auto&[key,val]:diag1){
        long long temp=val*(val-1)/2;
        res=(res+temp)%mod;
    }
    
    for(auto&[key,val]:diag2){
        long long temp=val*(val-1)/2;
        res=(res+temp)%mod;
    }

    res=((n-x.size())*(n-y.size()))%mod;

    cout<<res<<'\n';

    return 0;
}