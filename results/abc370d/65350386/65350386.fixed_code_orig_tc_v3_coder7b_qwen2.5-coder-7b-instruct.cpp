#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

struct SegmentTree{
    vector<int> tree;
    int n;
    SegmentTree(int _n):n(_n){
        tree.resize(4*n+10);
    }
    void update(int node,int start,int end,int idx,int val){
        if(start == end && start == idx){
            tree[node] = val;
            return;
        }
        int mid = (start+end)/2;
        if(idx <= mid) update(node*2,start,mid,idx,val);
        else update(node*2+1,mid+1,end,idx,val);
        tree[node] = min(tree[node*2],tree[node*2+1]);
    }
    int query(int node,int start,int end,int l,int r){
        if(l > end || r < start) return INT_MAX;
        if(l <= start && r >= end) return tree[node];
        int mid = (start+end)/2;
        return min(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> tate(w,vector<int>(h,1)),yoko(h,vector<int>(w,1));
    SegmentTree st_w(w*h),st_h(w*h);
    rep(i,h) rep(j,w) {
        st_w.update(i*w+j,0,w*h-1,i*w+j,1);
        st_h.update(i*w+j,0,w*h-1,i*w+j,1);
    }
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        int id = r*w+c;
        if (tate[c][r]) {
            tate[c][r]=0;
            yoko[r][c]=0;
            st_w.update(id,0,w*h-1,id,0);
            st_h.update(id,0,w*h-1,id,0);
        } else {
            int tmp = st_w.query(id,0,w*h-1,0,c);
            if(tmp!=0){
                int new_id = tmp-1;
                tate[new_id/w][new_id%w]=0;
                st_w.update(new_id,0,w*h-1,new_id,0);
            }
            tmp = st_w.query(id,0,w*h-1,c+1,w*h-1);
            if(tmp!=0){
                int new_id = tmp-1;
                tate[new_id/w][new_id%w]=0;
                st_w.update(new_id,0,w*h-1,new_id,0);
            }
            tmp = st_h.query(id,0,w*h-1,0,r);
            if(tmp!=0){
                int new_id = tmp-1;
                yoko[new_id/w][new_id%w]=0;
                st_h.update(new_id,0,w*h-1,new_id,0);
            }
            tmp = st_h.query(id,0,w*h-1,r+1,h*h-1);
            if(tmp!=0){
                int new_id = tmp-1;
                yoko[new_id/w][new_id%w]=0;
                st_h.update(new_id,0,w*h-1,new_id,0);
            }
        }
    }
    int ans = 0;
    rep(i,w) rep(j,h) {
        ans += tate[i][j]+yoko[j][i]-tate[i][j]*yoko[j][i];
    }
    cout << ans << "\n";
    return 0;
}