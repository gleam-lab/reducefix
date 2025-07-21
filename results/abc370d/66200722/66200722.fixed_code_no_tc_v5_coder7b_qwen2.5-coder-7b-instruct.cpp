#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAXN = 400005;
int par[MAXN];

int find(int x) {
    if(par[x] < 0) return x;
    return par[x] = find(par[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    for(int i = 0; i < h; ++i) par[w*i] = -(w+1);
    for(int i = 0; i < w; ++i) par[i] = -(h+1);

    while(q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        int id = w*r + c;

        if(par[id] < 0) {
            int up = (id >= w) ? find(id-w) : -1;
            int down = (id < (h-1)*w) ? find(id+w) : -1;
            int left = (id % w > 0) ? find(id-1) : -1;
            int right = (id % w < w-1) ? find(id+1) : -1;

            if(up != -1) unite(up, id);
            if(down != -1) unite(down, id);
            if(left != -1) unite(left, id);
            if(right != -1) unite(right, id);
        } else {
            int root = find(id);
            if(root == -1) continue;
            int up = (root >= w) ? find(root-w) : -1;
            int down = (root < (h-1)*w) ? find(root+w) : -1;
            int left = (root % w > 0) ? find(root-1) : -1;
            int right = (root % w < w-1) ? find(root+1) : -1;

            if(up != -1 && find(up) == root) unite(up, root);
            if(down != -1 && find(down) == root) unite(down, root);
            if(left != -1 && find(left) == root) unite(left, root);
            if(right != -1 && find(right) == root) unite(right, root);
        }
    }

    int res = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            int id = w*i + j;
            if(find(id) < 0) res++;
        }
    }

    cout << res << endl;

    return 0;
}