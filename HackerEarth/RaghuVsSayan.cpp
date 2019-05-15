// HackerEarth - Raghu Vs Sayan 
// By Samyra Almeida
// Ps. Solution uses Heapsort, but can be done using the sort function

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int t, a, b, n;
int vet[maxn];

void BuildHeap(int u, int s)
{
	int e = (u << 1) + 1;
	int d = e + 1;

	int g = u;

	if(e < s && vet[g] < vet[e])
		g = e;
	if(d < s && vet[g] < vet[d])
		g = d;

	if(g != u)
	{
		vet[g] = vet[g]^vet[u];
		vet[u] = vet[g]^vet[u];
		vet[g] = vet[g]^vet[u];
		BuildHeap(g, s);
	}
}

void BuildMaxHeap(int s)
{
	for(int i = (s >> 1) ; i >= 0 ; --i)
		BuildHeap(i, s);
}

void HeapSort(int s)
{
	BuildMaxHeap(s);

	for(int i = s - 1 ; i >= 1 ; --i)
	{
		vet[0] = vet[0]^vet[i];
		vet[i] = vet[0]^vet[i];
		vet[0] = vet[0]^vet[i];

		s--;

		BuildHeap(0, s);
	}
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		memset(vet, 0, sizeof vet);

		scanf("%d %d %d", &a, &b, &n);

		for(int i = 0 ; i < n ; ++i) 
			scanf("%d", &vet[i]);

		HeapSort(n);

		int sa = 0, sb = 0;
		int qa = 0, qb = 0;

		for(int i = 0 ; sa + vet[i] <= a && i < n; ++i)
			sa+=vet[i], qa++;
		for(int i = 0 ; sb + vet[i] <= b && i < n; ++i)
			sb+=vet[i], qb++;

		if(qa > qb) printf("Raghu Won\n");
		else if(qb > qa) printf("Sayan Won\n");
		else printf("Tie\n");
	}

	return 0;
}
