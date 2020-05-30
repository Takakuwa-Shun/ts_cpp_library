// 蟻本P.84
struct UnionFind
{
	// 問題によって変える。
	static const int MAX_N = 50000;
	
	int n,
	par[MAX_N], // 親の値　par[i] = iのとき、iは親
	rank[MAX_N]; // 木のランク（深さ）

	UnionFind(): n(MAX_N){};
	UnionFind(const int n): n(n) {
		init(n);
	};

	void init(const int nn) {
		n = nn;
		for (int i=0; i<nn; i++) {
			par[i] = i;
			rank[i] = 0;
  	}
	}

	// xの親の値を返す
	int find(const int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	};

	// xとyが同じ親か判別する
	bool same(const int x, const int y) {
		return find(x) == find(y);
	};

	// xとyの属する集合を併合
	void unite(const int x, const int y) {
		int px = find(x);
		int py = find(y);
		if (px == py) return;
		
		if (rank[px] < rank[py]) {
			par[px] = py;
		} else {
			par[py] = px;
			if (rank[px] == rank[py]) rank[px]++; 
		}
	}
};

int main() {

}
