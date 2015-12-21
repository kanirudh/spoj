#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<int> vi;

bool mycomp(pair<int,pair<int,int> > a ,pair<int,pair<int,int> > b){
	return a.second.second < b.second.second;
}

int get(vector<int> &tree,int idx){
	int answer = 0;
	while(idx){
		answer += tree[idx];
		idx -= (idx & -idx);
	}
	return answer;
}

void update(vector<int> &tree,int idx,int maxIdx,int val){
	while(idx <= maxIdx){
		tree[idx] += val;
		idx += (idx & -idx);
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	int test,n,q;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	cin >> q;
	vector<int> ans(q,0);
	vector<pair<int,pair<int,int> > > queries(q);
	for(int i=0;i<q;i++){
		queries[i].first = i;
		cin >> queries[i].second.first >> queries[i].second.second;
	}
	sort(queries.begin(),queries.end(),mycomp);
	//	for(int i=0;i<q;i++) cout << queries[i].first << queries[i].second.first << " " << queries[i].second.second << "\n";
	// Create fenwick tree
	int qN = 0;
	vector<int> lastOccurence(1e6 + 1,-1),cnt(1+n,0),tree(n+1,0);
	for(int i=1;i<=n;i++){
		if( lastOccurence[a[i-1]] != -1) update(tree,lastOccurence[a[i-1]],n,-1);
		lastOccurence[a[i-1]] = i;
		//cnt[i]++;
		update(tree,i,n,1);
		while(queries[qN].second.second < i) qN++;
		while(queries[qN].second.second == i){
			//for(int j=queries[qN].second.first;j <= i;j++) ans[queries[qN].first] += cnt[j];
			ans[queries[qN].first] = get(tree,queries[qN].second.second) - get(tree,queries[qN].second.first-1);	
			qN++;
		}	
	}
	for(int i=0;i<q;i++) cout << ans[i] << "\n";
	
	return 0;
}
