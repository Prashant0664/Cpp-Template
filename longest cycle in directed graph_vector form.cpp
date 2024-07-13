vector<int> cycle(vector<int> &adj, int i, vector<int> &vis){
    if (vis[i] != -1){
        return {i, vis[i], 0};
    }
    vis[i] = 0;
    vector<int> v = cycle(adj[i]);
    if (v[2] == 1){
        return {v[0], v[1], 1};
    }
    vis[i] = 1 + v[1];
    return { v[0], vis[i], i == v[0] }
}