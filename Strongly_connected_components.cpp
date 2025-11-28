void dfs(vector<vector<int>>&v, int i, stack<int>&st, vector<int>&vis){
    vis[i]=1;
    for(auto &k:v[i]){
        if(!vis[k]){
            dfs(v,k,st,vis);
        }
    }
    st.push(i);
}
void strongly_connected_components(vector<vector<int>>&v2, int n, int m){
    vector<vector<int>>v(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[b].push_back(a);
    }
    
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(v2,i,st,vis);
        }
    }
    vector<int>vis2(n,0);
    vector<vector<int>>ans;
    while(!st.empty()){
        int i=st.top();
        st.pop();
        stack<int>st2;
        if(!vis2[i]){
            vector<int>temp;
            dfs(v,i,st2,vis2);
            while(!st2.empty()){
                temp.pb(st2.top());
                st2.pop();
            }
            ans.push_back(temp);
        }
    }
    for(auto &i:ans){
        // print ans ith elements
    }
    return;
}