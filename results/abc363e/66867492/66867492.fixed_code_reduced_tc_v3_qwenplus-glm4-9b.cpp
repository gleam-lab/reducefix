rep( i, H ){
    pq.push( { A[i][0], i, 0 } ); 
    pq.push( { A[i][W-1], i, W-1 } ); 
    used[i][0] = 1; 
    used[i][W-1] = 1;
}
rep3( i, 1, W-1 ){
    pq.push( { A[0][i], 0, i } ); 
    pq.push( { A[H-1][i], H-1, i } ); 
    used[0][i] = 1; 
    used[H-1][i] = 1; 
}

// After the first year, push sections from priority queue only if their elevation is above sea level
rep( i, Y ) {
    while( !pq.empty() && pq.top()[0] <= i + 1 ){
        auto a = pq.top(); pq.pop(); 
        --ans;
        rep( d, 4 ){
            int ny = a[1] + dy[d], nx = a[2] + dx[d];
            if( ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if( A[ny][nx] > i + 1 && chmax( used[ny][nx], 1 ) ) { pq.push( {A[ny][nx], ny, nx} ); }
        }
    }
    cout << ans << endl;
}