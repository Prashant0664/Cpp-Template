
struct comp_pair_int {
    bool operator()(const pair<int,string> &a, const int & b)
    {
        return (a.first < b);
    }
    bool operator()(const int & a,const pair<int,string> &b)
    {
        return (a < b.first);
    }
};
int i = upper_bound(um[key].begin(),um[key].end(),timestamp,comp_pair_int()) - um[key].begin()-1;
