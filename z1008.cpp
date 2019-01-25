/*
看不懂，为了不影响我的进度，跳过。附上能AC得代码。
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left, right, top, buttom;
    bool operator == (const Node &a) const {
        return left == a.left && right == a.right && top == a.top && buttom == a.buttom;
    }
};

Node E[35];
int Sum[35], Map[11][11], Num;

void GetE(int n) {
    memset(Sum, 0, sizeof(Sum));
    for(int i = 0; i < n*n; ++i) {
        cin >> E[i].top >> E[i].right >> E[i].buttom >> E[i].left;
        for(int j = 0; j <= i; ++j) {
            if(E[j] == E[i]) {
                Sum[j]++;
                break;
            }
        }
    }
}

bool DFS(int pos, int n) {
    if(pos == n*n) return true;
    int x = pos/n, y = pos%n;
    //cout << x << " " << y << endl;
    for(int i = 0; i < n*n; ++i) {
        if(Sum[i]) {
            if(x > 0 && E[i].top != E[Map[x-1][y]].buttom) continue;
            if(y > 0 && E[i].left != E[Map[x][y-1]].right) continue;
            Map[x][y] = i;
            --Sum[i];
            if(DFS(pos+1, n) == true) return true;
            else {
                ++Sum[i];
            }
        }
    }
    return false;
}

int main() {
    int Case = 0;
    while(cin >> Num && Num) {
        if(Case > 0) printf("\n");
        GetE(Num);
        //cout << "1" <<endl;
        if(DFS(0, Num)) printf("Game %d: Possible\n", ++Case);
        else printf("Game %d: Impossible\n", ++Case);
    }
    return 0;
}
