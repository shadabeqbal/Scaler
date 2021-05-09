/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "07-05-2021" 
Name: Range Minimum query
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
    int min_element;
    struct SegmentNode *left;
    struct SegmentNode *right;
};

struct SegmentNode *createSegmentTree(vi &vec, int low, int high)
{
    if (low == high)
    {
        SegmentNode *p = new SegmentNode();
        p->left_idx = low;
        p->right_idx = high;
        p->sum = vec[low];
        p->min_element = vec[low];
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
    x->min_element = min(x->left->min_element,x->right->min_element);
    return x;
}

void find_update(SegmentNode *root,vector<int> &A,int low,int high,int y,int z){
    
    if(low == high){
        root->sum=z;
        root->min_element=z;
        return;
    }
    int mid = low+(high-low)/2;
    if(y<=mid){
        find_update(root->left,A,low,mid,y,z);
        root->sum = root->left->sum + root->right->sum;
        root->min_element=min(root->left->min_element,root->right->min_element);
    }else{
        find_update(root->right,A,mid+1,high,y,z);
        root->sum = root->left->sum + root->right->sum;
        root->min_element=min(root->left->min_element,root->right->min_element);
    }
    
}
void find_min(SegmentNode *root,vector<int> &A,int low,int high,int y,int z,vector<int> &ans){
    if(y <= root->left_idx && z>=root->right_idx){
        ans.push_back(root->min_element);
        return;
    }else{
        int mid = low+(high-low)/2;
        
        if(y<=mid && z<=mid)
            find_min(root->left,A,low,mid,y,z,ans);
        if(y>mid && z>mid)
            find_min(root->right,A,mid+1,high,y,z,ans);
        if(y<=mid && z>mid){
            find_min(root->left,A,low,mid,y,z,ans);
            find_min(root->right,A,mid+1,high,y,z,ans);
            int x1=ans[ans.size()-1];
            int x2=ans[ans.size()-2];
            ans.pop_back();
            ans.pop_back();
            ans.push_back(min(x1,x2));
        }

    }
}
vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    SegmentNode *root=createSegmentTree(A,0,A.size()-1);
    vector<int> ans;
    for(int i=0;i<B.size();i++){
        int x=B[i][0];
        int y=B[i][1];
        int z=B[i][2];
        
        if(x == 0){
            find_update(root,A,0,A.size()-1,y-1,z);
        }else{
            find_min(root,A,0,A.size()-1,y-1,z-1,ans);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi A={18, 10, 1, 20, 25, 4, 9, 13, 15, 6, 21, 7};
    vvi B={{1, 8, 12},{0,4,7},{1,1,3},{1,5,11},{1,3,9},{1,7,12},{1,7,10},{0,12,20}};
    vi ans=solve(A,B);
    
    for(auto i:ans)
        cout<<i<<" ";
    
    return 0;
}