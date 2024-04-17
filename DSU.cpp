class DSU{
    vector<int> parent, rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y){
            return;
        }
        if(rank[x] < rank[y]){
            parent[x]=y;
            rank[y]+=rank[x]+1;
        }
        else if(rank[y]<rank[x]){
            parent[y]=x;
            rank[x]+=rank[y]+1;
        }
        else{
            parent[y]=x;
            rank[x]+=rank[y]+1;
        }
    }
};