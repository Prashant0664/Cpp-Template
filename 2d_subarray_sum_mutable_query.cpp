#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Update query for Columns
void update_y(ll x, ll y, ll ele, vector<vector<ll> >& bit,
			ll n){
	while (y <= n) {
		bit[x][y] += ele;
		y += (y & -y);
	}
}

// Method to add ele to mat[x][y]
void update(ll x, ll y, ll ele, vector<vector<ll> >& bit,
			ll n){
	while (x <= n) {
		update_y(x, y, ele, bit, n);
		x += (x & -x);
	}
}

// Method to calculate prefix sum of columns
ll getSum_y(ll x, ll y, vector<vector<ll> >& bit){
	ll sum = 0;
	while (y) {
		sum += bit[x][y];
		y -= (y & -y);
	}
	return sum;
}

// Method to calculate prefix sum of mat[x][y]
ll getSum(ll x, ll y, vector<vector<ll> >& bit){
	ll sum = 0;
	while (x) {
		sum += getSum_y(x, y, bit);
		x -= (x & -x);
	}
	return sum;
}

int main(){
	// Number of rows and columns
	ll n = 3;
	vector<vector<ll> > mat(n + 1, vector<ll>(n + 1, 0));
	// vector to store 2D Fenwick tree
	vector<vector<ll> > bit(n + 1, vector<ll>(n + 1, 0));
	vector<vector<ll> > queries = { { 1, 2, 0, 2 },
									{ 2, 0, 0, 2, 2 },
									{ 1, 0, 0, 1 },
									{ 2, 0, 0, 2, 0 } };
	for (auto query : queries) {
		// Point Update Query
		if (query[0] == 1) {
			ll x = query[1] + 1;
			ll y = query[2] + 1;
			ll ele = query[3];
			update(x, y, ele - mat[x][y], bit, n);
			mat[x][y] = ele;
		}
		// Range Sum Query
		else {
			ll x1 = query[1] + 1;
			ll y1 = query[2] + 1;
			ll x2 = query[3] + 1;
			ll y2 = query[4] + 1;
			ll bottomRight = getSum(x2, y2, bit);
			ll topRight = getSum(x1 - 1, y2, bit);
			ll bottomLeft = getSum(x2, y1 - 1, bit);
			ll topLeft = getSum(x1 - 1, y1 - 1, bit);
			cout << bottomRight - topRight - bottomLeft
						+ topLeft
				<< " ";
		}
	}
}
