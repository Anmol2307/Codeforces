#include <bits/stdc++.h>
using namespace std;

#define max 200001
int s[max], in[max], out[max], bit[max];
int k = 1;
vector<int> edge[max];

void dfs(int u, int v, int f) {
	s[u] = f;
	in[u] = k++;
	for (int i = 0; i < edge[u].size(); i++)
		if (edge[u][i] != v)
			dfs(edge[u][i],u, !f);
	out[u] = k;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[max];
	for (int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n; ++i) {
		int v, u;
		scanf("%d %d", &v, &u);
		edge[v].push_back(u);
		edge[u].push_back(v);
	}
	
	dfs(1, 0, 0);
	
	while (m--) {
		int y, x;
		scanf("%d %d", &y, &x);
		if (y == 1) {
			int val;
			scanf("%d", &val);
			if (s[x])
				val = -val;
			for (int i = in[x]; i <= n; i += i & -i)
				bit[i] += val;
			for (int i = out[x]; i <= n; i += i & -i)
				bit[i] -= val;
		}
		else {
			int ans = 0;
			for (int i = in[x]; i; i ^= i & -i)
				ans += bit[i];
			if (s[x])
				ans = -ans;
			printf("%d\n", arr[x] + ans);
		}
	}
}
