/*
https://codeforces.com/contest/1915/problem/F
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;


/*
Policy-Based Data Structures (PBDS) provided by the GNU C++ Library (__gnu_pbds)
allows for logarithmic time complexity for insertion, deletion, and finding the order of a key.
*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int main(){
	// These lines optimize the input and output operations.
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		
		vector<pair<ll,ll> > v;
		/*
		declares an ordered set using the tree template provided by PBDS
		ll: type of elements stored
		null_type: type of the mapped value. there is no mapped value associated with each key.
		less<ll>: comparator. the set will be in ascending order. smallers go first
		rb_tree_tag: the underlying tree structure used. indicates a red-black tree, self-balancing binary search tree.
		tree_order_statistics_node_update: update policy that allows the tree to keep track of the number of nodes in the subtree rooted at each node. This information is useful for certain operations like finding the order of a key.
		*/
		tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> s;
		
		while(n--){
			cin>>j>>k;
			v.push_back({j,k});
		}
		sort(v.begin(),v.end()); k=0;
		for(auto [x,y]:v){
			// the number of elements greater than y already present in the set
			k+=s.size()-s.order_of_key(y);
			s.insert(y);
		}
		
		cout<<k<<'\n';
	}
}