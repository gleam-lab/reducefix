if(cnt[ru].size()<cnt[rv].size()) swap(ru, rv);
uf.unite(ru, rv);
int rnew=uf.findRoot(ru);
int rold=(rnew==ru ? rv:ru);
for (int x:cnt[rv]) cnt[rnew].insert(x);