#include<bits/stdc++.h>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef map<ll,ll> mp;

struct segtree {
    vl t,neg;
    int size;
    segtree(int n){
        size=1;
        while(size<n)size*=2;
        t.assign(2*size,0);
        neg.assign(2*size,0);
    }
    void push(int v,int tl,int tr){
        if(neg[v]){
            t[v]*=(tr-tl+1);
            if(tl<tr){
                neg[2*v]*=neg[v];
                neg[2*v+1]*=neg[v];
            }
            neg[v]=0;
        }
    }
    void update(int v,int tl,int tr,int l,int r){
        push(v,tl,tr);
        if(l>r)return;
        if(l==tl&&r==tr){
            neg[v]^=1;
            push(v,tl,tr);
            return;
        }
        int tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm));
        update(2*v+1,tm+1,tr,max(l,tm+1),r);
        t[v]=t[2*v]+t[2*v+1];
    }
    ll sum(int v,int tl,int tr,int l,int r){
        push(v,tl,tr);
        if(l>r)return 0;
        if(l==tl&&r==tr)return t[v];
        int tm=(tl+tr)/2;
        return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,q;
    cin>>h>>w>>q;
    segtree hor(h);
    segtree ver(w);
    forn(i,1,h+1)hor.update(1,1,h,i,i);
    forn(i,1,w+1)ver.update(1,1,w,i,i);
    forn(i,1,q+1){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(hor.sum(1,1,h,x,x)){
            hor.update(1,1,h,x,x);
            ver.update(1,1,w,y,y);
        }else{
            int lx=0,rx=h+1,ly=0,ry=w+1;
            while(rx-lx>1){
                int mid=(lx+rx)/2;
                if(hor.sum(1,1,h,mid,mid))
                    rx=mid;
                else lx=mid;
            }
            hor.update(1,1,h,lx,lx);
            ver.update(1,1,w,ly,ly);
        }
    }
    cout<<hor.sum(1,1,h,1,h)*ver.sum(1,1,w,1,w)<<endl;
    return 0;
}