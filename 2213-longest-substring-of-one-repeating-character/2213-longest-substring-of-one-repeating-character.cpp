class Solution {
public:
    struct Node{
        int val, l , r;
        Node(): val(1), l(1), r(1) {}
    };
    vector<Node> tree;
    string s;

    void calculate(int ind, int tl, int tr, int mid) {
        Node& curr=tree[ind];
        Node& left=tree[ind*2+1];
        Node& right=tree[ind*2+2];

        curr.val=max(left.val,right.val);
        curr.l=left.l;
        curr.r=right.r;

        if(s[mid]==s[mid+1]) {
            curr.val=max(curr.val,left.r+right.l);

            if(left.l==mid-tl +1) curr.l=left.l+right.l;
            if(right.r==tr-mid) curr.r=left.r+right.r;

        }
    }

    void build(int ind, int tl, int tr) {
        if(tl==tr) {
            tree[ind]=Node();
            return;
        }
        int mid=tl+(tr-tl)/2;
        build(2*ind+1,tl,mid);
        build(2*ind+2,mid+1,tr);
        calculate(ind,tl,tr,mid);
    }
    void update(int i,char ch, int tl, int tr, int ind) {
        if(tl==tr) {
            s[i]=ch;
            tree[ind]=Node();
            return;
        }
        int mid=tl+(tr-tl)/2;
        if(i<=mid) update(i,ch,tl,mid,2*ind+1);
        else update(i,ch,mid+1,tr,2*ind+2);

        calculate(ind,tl,tr,mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        this->s=s;
        tree.resize(4*n);

        build(0,0,n-1);
        vector<int> ans;

        for(int i=0;i<queryIndices.size();i++) {
            update(queryIndices[i],queryCharacters[i],0,n-1,0);
            ans.push_back(tree[0].val);
        }
        return ans;

    }
};