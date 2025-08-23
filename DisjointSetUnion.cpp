class DSU{
public:
	vector<int> parent;
	vector<int> rank;

	DSU(int n){
		parent.resize(n);
		rank.resize(n, 0);

		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int x){
		if(x == parent[x]) return x;
				
			parent[x] = find(parent[x]);

			return parent[x];
	}

	void join(int x, int y){
		int p1 = find(x), p2 = find(y);

		if(rank[p1] >= rank[p2]){
			parent[p2] = p1;
			rank[p1] += rank[p1] == rank[p2];
		}else{
			parent[p1] = p2;
		}
	}
}
