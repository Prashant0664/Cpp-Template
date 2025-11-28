void Dijstra(vector<vector<pair<int,int>>>&ad, int n, int m, int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    vector<int>ans(n,INT_MAX);
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        int x=t.second, dis=t.first;
        if(ans[x]<dis)continue;
        ans[x]=dis;
        for(auto &i:adj[x]){
            pq.push({dis+i.second,i.first});
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<": "<<ans[i]<<endl;
    }
    return;
}