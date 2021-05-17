/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "11-05-2021" 
Name: 
Link: 
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
#define PI 3.141592653589793238

#define pb push_back
#define mp make_pair
#define ll long long int

#define all(x) x.begin(), x.end()

#define clr(x) memset(&x, 0, sizeof(x))

#define srt(x) sort(all(x))
#define search(x, y) binary_search(all(x), y)

#define fr(x, n) for (ll i = x; i < n; i++)
#define frk(x, n, k) for (ll i = x; i < n; i += k)
#define frit(x) for (auto i = x.begin(); i != x.end(); ++i)

typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> ps(vec.size(), vector<int>(vec[0].size()));
    int x, y, z;
    for (auto i = 0; i < (int)vec.size(); i++)
    {
        for (auto j = 0; j < (int)vec[0].size(); j++)
        {
            if (i - 1 >= 0 && j >= 0)
                x = ps[i - 1][j];
            else
                x = 0;

            if (i >= 0 && j - 1 >= 0)
                y = ps[i][j - 1];
            else
                y = 0;

            if (i - 1 >= 0 && j - 1 >= 0)
                z = ps[i - 1][j - 1];
            else
                z = 0;

            ps[i][j] = x + y - z + vec[i][j];
        }
    }

    for (auto i : ps)
    {
        for (auto j : i)
            cout << j << " ";

        cout << "\n";
    }

    //need sum of submatrix (1,1)->(2,2)
    int r1 = 1;
    int c1 = 0;
    int r2 = 2;
    int c2 = 2;
    int sum = ps[r2][c2] - ps[r1 - 1][c2] - ps[r2][c1 - 1] + ps[r1 - 1][c1 - 1];
    cout <<"Sum: "<< sum<<"\n";

    return 0;
}