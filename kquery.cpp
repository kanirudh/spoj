#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<int> vi;

struct query{
	int start,to,k,idx;
};

bool mycomp(const query &a,const query &b){
	return a.k < b.k;
}

void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

bool mycomp1(const pair<int,int> &a,const pair<int,int> &b){
	return a.first < b.first;	
}

void update(vector<int> &tree,int idx,int maxIdx,int val){
	while( idx <= maxIdx){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int get(vector<int> &tree,int idx){
	int ans = 0;
	while( idx){
		ans += tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

int main()
{
	int test,n,k;
	fastRead_int(n);
	vector<pair<int,int> > a(n);
	for(int i=0;i<n;i++){
		fastRead_int(a[i].first);
		a[i].second = i + 1 ;
	}
	sort(a.rbegin(),a.rend(),mycomp1);
	fastRead_int(k);
	vector<query> queries(k);
	for(int i =0;i<k;i++){
		fastRead_int(queries[i].start);
		fastRead_int(queries[i].to);
		fastRead_int(queries[i].k);
		queries[i].idx = i;
	}
	sort(queries.rbegin(),queries.rend(),mycomp);
	vector<int> tree(n+1,0),ans(k);
	int ia = 0;
	for(int i=0;i<k;i++){
		while(ia < n && a[ia].first > queries[i].k){
			update(tree,a[ia].second,n,1);
			ia++;
		}		
		ans[queries[i].idx] = get(tree,queries[i].to) - get(tree,queries[i].start -1);
	}
	for(int i=0;i<k;i++) cout << ans[i] << "\n";
	return 0;
}
