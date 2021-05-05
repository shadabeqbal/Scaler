/*  // //  
   // //        
   \\//       
	\>>      
	//\\    
   //  \\
Author: Shadab Eqbal 
Created on: "18-04-2021" 
Name: Create Segment Tree
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

struct node
{
    int left_idx;
    int right_idx;
    int sum;
    struct node *left;
    struct node *right;
};
struct node *foo(struct node *root, vi &vec, int low, int high)
{
    if (low == high)
    {
        node *p = new node();
        p->left_idx = low;
        p->right_idx = high;
        p->sum = vec[low];
        p->left=NULL;
        p->right=NULL;
        cout<<p->sum;
        return p;
    }
    node *x=new node();
    x->left_idx=low;
    x->right_idx=high;
    int mid = low + (high - low) / 2;
    
    x->left = foo(x->left, vec, low, mid);
    x->right = foo(x->right, vec, mid + 1, high);
    x->sum = (x->left->sum) + (x->right->sum);
    return x;
}
void display(struct node *p)
{
    if (p->left_idx == p->right_idx)
    {
        return;
    }
    display(p->left);
    cout << p->sum<<"\n";
    display(p->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi vec = {1, 5, 8, 7, 6, 3, 2};
    node *root = new node();
    int high = vec.size() - 1;
    int low = 0;
    root=foo(root, vec, low, high);
    display(root);
    return 0;
}