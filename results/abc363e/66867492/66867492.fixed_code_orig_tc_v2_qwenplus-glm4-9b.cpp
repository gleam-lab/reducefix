while( !pq.empty() && pq.top()[0] <= i ){
    auto a = pq.top(); pq.pop(); 
    --ans;
    rep( d, 4 ){
        int ny = a[1] + dy[d], nx = a[2] + dx[d];
        if( ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
        if( chmax( used[ny][nx], 1 ) ) { pq.push( {A[ny][nx], ny, nx} ); }
        // if( chmax( used[ny][nx], 1 ) ) { pq.em( A[ny][nx], ny, nx ); }
    }
}