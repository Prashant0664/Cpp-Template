void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int i=0;
    int n=a.size();
    int m=b.size();
    int j=0;
    while(i<n && j<m){
        if(a[i]>b[j]){
            swap(a[i],b[j]);
            i++;
        }
        else{
            j++;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<m;i++){
    //     cout<<b[i]<<" ";
    // }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    // cout<<endl;
    return;
}