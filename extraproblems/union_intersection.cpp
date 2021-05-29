/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "30-05-2021" 
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

void arr_union(vi &vec, vi &vec1)
{
    vi vu;
    int x = 0, y = 0;
    while (x < vec.size() && y < vec1.size())
    {
        if (vec[x] < vec1[y])
            vu.push_back(vec[x++]);
        else if (vec[x] > vec1[y])
            vu.push_back(vec1[y++]);
        else
        {
            vu.push_back(vec[x]);
            x++;
            y++;
        }
    }

    while (x < vec.size())
        vu.push_back(vec[x++]);

    while (y < vec1.size())
        vu.push_back(vec1[y++]);

    for (auto i : vu)
        cout << i << " ";
}

void arr_intersection(vi &vec, vi &vec1)
{
    vi vu;
    int x = 0, y = 0;
    while (x < vec.size() && y < vec1.size())
    {
        if (vec[x] < vec1[y])
            x++;
        else if (vec[x] > vec1[y])
            y++;
        else
        {
            vu.push_back(vec[x]);
            x++;
            y++;
        }
    }

    for (auto i : vu)
        cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi vec = {1, 2, 3, 4};
    vi vec1 = {4, 5, 6, 7};
    arr_union(vec, vec1);
    cout << "\n";
    arr_intersection(vec, vec1);

    return 0;
}