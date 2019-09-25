// URI - Playing with Queries (ID: 2800)
// Solution by Samyra Almeida

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10, root = 320;

int n, q;
int v[maxn], freq[maxn][root];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> q;

    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> v[i];
        freq[v[i]][i/root]++;
    }

    for(int i = 0 ; i < q ; ++i)
    {
        int t;
        cin >> t;
 
        if(t == 1) // update
        {
            int x, w;
            cin >> x >> w;

            int b = x/root;

            freq[v[x]][b]--;

            v[x] = w;

            freq[v[x]][b]++;
        }
        else // query
        {
            int x, y, w;
            cin >> x >> y >> w;
            
            int bl = x/root;
            int br = y/root;

            int ans = y - x + 1;

            if(bl != br)
            {
                for(int j = x ; j < (bl + 1)*root ; ++j)
                {
                    if(v[j] == w) ans--;
                }

                for(int j = y ; j >= (br*root) ; --j)
                {
                    if(v[j] == w) ans--;
                }

                for(int j = bl + 1 ; j < br ; ++j)
                {
                    ans -= freq[w][j];
                }
            }
            else
            {
                for(int j = x ; j <= y ; ++j)
                    if(v[j] == w) ans--;
            }
            
            cout << ans << '\n';
        }
        
    }
    return 0;
}
