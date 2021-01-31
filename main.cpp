#include <iostream>
#include <vector>

using namespace std;


int F(int i) {
    return i&(i+1);
}

class Tree_Fenvik {
public: int size;
public: vector <int> t;

public :
    int Prefix_Xor(int r) {
        int result = 0;
        int i = r;
        while (i>=0) {
            result ^= t[i];
            i = F(i)-1;
        }
        return result;
    }

    int XorSrez (int l,int r) {
        int a=0,b=0;
        a=Prefix_Xor(l-1);
        b=Prefix_Xor(r);
        return a^b;
    }

    void XorToElem(int i, int val) {
        while (i<size) {
            t[i] ^= val;
            i = i | (i + 1);
        }
    }

    void ModifyElement(int i , int val) {
        int cur = Prefix_Xor(i) ^ Prefix_Xor(i-1);
        XorToElem(i,cur );
        XorToElem(i,val);
    }

};

int main() {
    vector <int> a;
    vector <int> otvet;
    int n=0,z=0,value=0;
    Tree_Fenvik tree;
    cin >> n;
    cin >> z;
    tree.size = n;
    int xorsum = 0;
    for (int i = 0;i<n;i++) {
        cin >> value;
        a.push_back(value);
        for (int j=F(i);j<=i;j++) {
            xorsum ^= a[j];
        }
        tree.t.push_back(xorsum);
        xorsum = 0;
    }

    int mode = 0;
    int ind=0,znach=0;
    int left=0,right=0;
    for (int i=0;i<z;i++) {
        cin >> mode;
        if (mode == 1) {
            cin >> left;
            cin >> right;
            otvet.push_back(tree.XorSrez(left,right));
        }
        else {
            cin >> ind;
            cin >> znach;
            tree.ModifyElement(ind,znach);
        }
    }

    for (int i = 0; i<otvet.size(); i++) {
        printf("%d\n",otvet[i]);
    }
    return 0;
}