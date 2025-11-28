#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> prefixSum2D(vector<vector<int>> a) 
{ 
    int R=a.size();
    int C=a[0].size();
	int psa[R][C]; 
	psa[0][0] = a[0][0]; 
    // Filling first row and first column 
	for (int i = 1; i < C; i++) 
		psa[0][i] = psa[0][i - 1] + a[0][i]; 
    // updating the values in the cells 
    // as per the general formula 
	for (int i = 1; i < R; i++) 
		psa[i][0] = psa[i - 1][0] + a[i][0]; 

	for (int i = 1; i < R; i++) { 
		for (int j = 1; j < C; j++) 

			psa[i][j] = psa[i - 1][j] + psa[i][j - 1] 
						- psa[i - 1][j - 1] + a[i][j]; 
	} 
    vector<vector<int>> v(R,vector<int>(C,0));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
            v[i][j]=psa[i][j];
    return v;
} 

int sumQuery(vector<vector<int>>aux, int tli, int tlj, int rbi, int rbj){ 
    // result is now sum of elements between (0, 0) and 
    // (rbi, rbj) 
    int res = aux[rbi][rbj]; 
  
    // Remove elements between (0, 0) and (tli-1, rbj) 
    if (tli > 0) 
       res = res - aux[tli-1][rbj]; 
  
    // Remove elements between (0, 0) and (rbi, tlj-1) 
    if (tlj > 0) 
       res = res - aux[rbi][tlj-1]; 
  
    // Add aux[tli-1][tlj-1] as elements between (0, 0) 
    // and (tli-1, tlj-1) are subtracted twice 
    if (tli > 0 && tlj > 0) 
       res = res + aux[tli-1][tlj-1]; 
  
    return res; 
} 