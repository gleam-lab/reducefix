rep(k,4){
    int ni=i+dx[k];
    int nj=j+dy[k];
    if(ni>=0&&ni<H&&nj>=0&&nj<W){
        if(F[ni][nj]){
            F[ni][nj]=false;
            Q[max(A[ni][nj],y)].push({ni,nj});
        }
    }
}