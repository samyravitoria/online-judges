/*
  Codeforces Beta Round #13 - Holes
  
  Task: sqrt decomposition
  Complexity: O(n*sqrt(n) + m*sqrt(n))
  
  Solution by Samyra Almeida
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10, root = 340;

int n, m;
int v[maxn], amf[maxn], lastb[maxn], nextb[maxn];

void build()
{
	for(int i = n ; i > 0 ; --i)
	{
		int bi, bf;
		bi = i/root;
		bf = bi + 1;

		bi *= root, bf *= root;

		for(int j = i ; j >= max(bi, 1) ; --j)
		{
			if(v[j] + j > n)
			{
				amf[j] = 1;
				lastb[j] = j;
			}
			else if(v[j] + j < bf)
			{
				amf[j] = amf[j + v[j]] + 1;
				lastb[j] = lastb[j + v[j]];
			}
			else
			{
				amf[j] = 1;
				lastb[j] = j;
			}
			
			nextb[j] = j + v[j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; ++i) cin >> v[i];

	build();

  for(int i = 0 ; i < m ; ++i)
	{
		int type, a;
		cin >> type >> a;

		if(type)
		{
			int am = 0, last = a;

			while(true)
			{
				am += amf[last];
				last = lastb[last];
				
				if(nextb[last] > n) break;

				last = nextb[last];
			}

			cout << last << " " << am << "\n";
		}
		else
		{
			int b; 
            cin >> b;

			v[a] = b;

			int bi, bf;
			
			bi = a/root;
			bf = bi + 1;

			bi *= root, bf *= root;

			for(int j = a ; j >= max(bi, 1) ; --j)
			{
				if(v[j] + j > n)
				{
					amf[j] = 1;
					lastb[j] = j;
				}
				else if(v[j] + j < bf)
				{
					amf[j] = amf[j + v[j]] + 1;
					lastb[j] = lastb[j + v[j]];
				}
				else
				{
					amf[j] = 1;
					lastb[j] = j;
				}

				nextb[j] = j + v[j];
			}		
		}
	}
}
