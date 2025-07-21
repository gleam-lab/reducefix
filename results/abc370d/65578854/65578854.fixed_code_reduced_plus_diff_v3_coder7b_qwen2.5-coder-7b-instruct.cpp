#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int size;
    vector<long long> sums;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0);
    }
    
    void add(int p, long long v){
        p += size;
        sums[p] += v;
        for(p /= 2; p > 0; p /= 2){
            sums[p] = sums[2*p] + sums[2*p+1];
        }
    }
    
    long long sum(int l, int r){
        l += size;
        r += size;
        long long res = 0;
        while(l < r){
            if(l % 2 == 1) res += sums[l++];
            if(r % 2 == 0) res += sums[--r];
            l /= 2;
            r /= 2;
        }
        if(l == r) res += sums[l];
        return res;
    }
};

vector<SegmentTree> rowSTs;
vector<SegmentTree> colSTs;

void updateRow(int r, int c, int n){
    long long prevSum = rowSTs[r].sum(max(0, c-1), min(n, c));
    long long currSum = rowSTs[r].sum(max(0, c), min(n, c+1));
    if(prevSum == 0 && currSum == 1) rowSTs[r].add(c, -1);
}

void updateCol(int c, int r, int m){
    long long prevSum = colSTs[c].sum(max(0, r-1), min(m, r));
    long long currSum = colSTs[c].sum(max(0, r), min(m, r+1));
    if(prevSum == 0 && currSum == 1) colSTs[c].add(r, -1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    rowSTs.resize(h);
    colSTs.resize(w);

    for(int i=0;i<h;++i){
        rowSTs[i].init(w);
    }

    for(int i=0;i<w;++i){
        colSTs[i].init(h);
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            rowSTs[i].add(j, 1);
            colSTs[j].add(i, 1);
        }
    }

    for(int i=0;i<q;++i){
        int r, c;
        cin >> r >> c;
        --r, --c;

        if(rowSTs[r].sum(c, c+1) == 0){
            rowSTs[r].add(c, 1);
            colSTs[c].add(r, 1);
        } else {
            updateRow(r, c, w);
            updateCol(c, r, h);
        }
    }

    long long totalWalls = 0;
    for(int i=0;i<h;++i){
        totalWalls += rowSTs[i].sum(0, w-1);
    }

    cout << totalWalls << '\n';

    return 0;
}