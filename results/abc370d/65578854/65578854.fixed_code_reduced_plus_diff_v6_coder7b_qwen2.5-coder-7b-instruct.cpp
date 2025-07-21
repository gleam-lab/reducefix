#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next[4];
    Node(int v):val(v){next[0] = next[1] = next[2] = next[3] = nullptr;}
};

class Solution {
public:
    int n,m,q;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<Node*> rows;
    vector<Node*> cols;
    vector<vector<bool>> visited;

    void insert(int x,int y){
        Node* curRow = rows[x];
        Node* curCol = cols[y];

        while(curRow->next[0]!=nullptr && curRow->next[0]->val<y){
            curRow = curRow->next[0];
        }
        Node* newNode = new Node(y);
        newNode->next[0] = curRow->next[0];
        curRow->next[0] = newNode;

        while(curCol->next[2]!=nullptr && curCol->next[2]->val<x){
            curCol = curCol->next[2];
        }
        newNode = new Node(x);
        newNode->next[2] = curCol->next[2];
        curCol->next[2] = newNode;
    }

    void remove(int x,int y){
        Node* curRow = rows[x];
        while(curRow->next[0]->val!=y){
            curRow = curRow->next[0];
        }
        Node* delNode = curRow->next[0];
        curRow->next[0] = delNode->next[0];
        delete delNode;

        Node* curCol = cols[y];
        while(curCol->next[2]->val!=x){
            curCol = curCol->next[2];
        }
        delNode = curCol->next[2];
        curCol->next[2] = delNode->next[2];
        delete delNode;
    }

    bool check(int x,int y){
        for(int i=0;i<4;++i){
            int nx = x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]){
                if(rows[nx]->next[0]->val==ny){
                    visited[nx][ny]=true;
                    return true;
                }
                if(cols[ny]->next[2]->val==nx){
                    visited[nx][ny]=true;
                    return true;
                }
            }
        }
        return false;
    }

    int solve(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

        cin>>n>>m>>q;
        rows.resize(n,nullptr);
        cols.resize(m,nullptr);
        visited.resize(n,vector<bool>(m,false));

        for(int i=0;i<n;++i){
            rows[i] = new Node(-1);
            rows[i]->next[0] = new Node(n);
        }

        for(int i=0;i<m;++i){
            cols[i] = new Node(-1);
            cols[i]->next[2] = new Node(m);
        }

        for(int i=0;i<n;++i){
            insert(i,i);
        }

        for(int i=0;i<m;++i){
            insert(i,i);
        }

        for(int i=0;i<q;++i){
            int x,y;
            cin>>x>>y;
            --x;--y;
            if(!check(x,y)){
                remove(x,y);
            }
        }

        int ans = 0;
        for(int i=0;i<n;++i){
            Node* cur = rows[i]->next[0];
            while(cur!=rows[i]->next[0]){
                ++ans;
                cur = cur->next[0];
            }
        }

        for(int i=0;i<m;++i){
            Node* cur = cols[i]->next[2];
            while(cur!=cols[i]->next[2]){
                ++ans;
                cur = cur->next[2];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout<<sol.solve();
    return 0;
}