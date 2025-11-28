class DSU{
    vector<int> parent, rank, size;

public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y){
            return;
        }
        if (rank[x] < rank[y]){
            parent[x] = y;
            size[y] += size[x];
        }
        else if (rank[y] < rank[x]){
            parent[y] = x;
            size[x] += size[y];
        }
        else{
            parent[y] = x;
            size[x] += size[y];
            rank[x]++;
        }
    }
    int getSize(int x){
        return size[find(x)];
    }
};
