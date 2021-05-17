/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "06-05-2021" 
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

struct SegmentNode
{
    int left_idx;
    int right_idx;
    int sum;
    struct SegmentNode *left;
    struct SegmentNode *right;
};

struct SegmentNode *createSegmentTree(vector<int> &vec, int low, int high)
{
    if (low == high)
    {
        SegmentNode *p = new SegmentNode();
        p->left_idx = low;
        p->right_idx = high;
        p->sum = vec[low];
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    SegmentNode *x = new SegmentNode();
    x->left_idx = low;
    x->right_idx = high;
    int mid = low + (high - low) / 2;

    x->left = createSegmentTree(vec, low, mid);
    x->right = createSegmentTree(vec, mid + 1, high);
    x->sum = (x->left->sum) + (x->right->sum);
    return x;
}

void find_update1(SegmentNode *root, vector<int> &A, int low, int high, int y, int z)
{

    if (low == high)
    {
        root->sum = 2 * A[y] + 1;
        return;
    }
    int mid = low + (high - low) / 2;
    if (y <= mid)
    {
        find_update1(root->left, A, low, mid, y, z);
        root->sum = root->left->sum + root->right->sum;
    }
    else
    {
        find_update1(root->right, A, mid + 1, high, y, z);
        root->sum = root->left->sum + root->right->sum;
    }
}

void find_update2(SegmentNode *root, vector<int> &A, int low, int high, int y, int z)
{

    if (low == high)
    {
        root->sum = floor(A[y] / 2);
        return;
    }
    int mid = low + (high - low) / 2;
    if (y <= mid)
    {
        find_update2(root->left, A, low, mid, y, z);
        root->sum = root->left->sum + root->right->sum;
    }
    else
    {
        find_update2(root->right, A, mid + 1, high, y, z);
        root->sum = root->left->sum + root->right->sum;
    }
}

void releaseNode(SegmentNode *n)
{
    if (!n)
        return;
    releaseNode(n->left);
    releaseNode(n->right);
    delete (n);
}

vector<int> solve(int A, vector<vector<int>> &B)
{
    vector<int> Tree(A, 0);
    SegmentNode *root = createSegmentTree(Tree, 0, Tree.size() - 1);
    vector<int> ans;
    for (int i = 0; i < (int)B.size(); i++)
    {
        int x = B[i][0];
        int y = B[i][1];
        int z = B[i][2];

        if (x == 1)
        {
            find_update1(root, Tree, 0, Tree.size() - 1, y - 1, z);
        }
        else if (x == 2)
        {
            find_update2(root, Tree, 0, Tree.size() - 1, y - 1, z);
        }
        else
        {
        }
    }

    releaseNode(root);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vvi vec = {{1, 1, -1}, {1, 2, -1}, {2, 1, -1}, {2, 2, 3}, {2, 4, 1}};
    vi ans = solve(5, vec);
    for (int i : ans)
        cout << i << " ";
    return 0;
}