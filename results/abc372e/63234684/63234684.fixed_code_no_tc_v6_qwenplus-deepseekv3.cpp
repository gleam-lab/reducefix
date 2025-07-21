#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find{
    vector<int> par;
    vector<priority_queue<int, vector<int>, greater<int>>> top; // min-heap to keep top 10 largest

    Union_Find(int n){
        par.resize(n+1, -1); // 1-based indexing
        top.resize(n+1);
        for(int i=1; i<=n; i++){
            top[i].push(i);
        }
    }

    int root(int v){
        if(par[v] == -1) return v;
        else return par[v] = root(par[v]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    void merge(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return;
        if(top[x].size() < top[y].size()) swap(x, y);
        par[y] = x;
        while(!top[y].empty()){
            int val = top[y].top();
            top[y].pop();
            top[x].push(val);
            if(top[x].size() > 10) top[x].pop();
        }
    }

    vector<int> get_top(int v){
        v = root(v);
        vector<int> res;
        while(!top[v].empty()){
            res.push_back(top[v].top());
            top[v].pop();
        }
        reverse(res.begin(), res.end());
        for(int num : res){
            top[v].push(num);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    rep(i,q){
        int ty, a, b;
        cin >> ty >> a >> b;
        if(ty == 1){
            uf.merge(a, b);
        }
        else{
            vector<int> top = uf.get_top(a);
            if(top.size() < b){
                cout << -1 << "\n";
            }
            else{
                cout << top[b-1] << "\n";
            }
        }
    }
}