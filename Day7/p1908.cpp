#include <bits/stdc++.h>

using namespace std;
struct seg_tree{
	// seg_tree* lson;
	// seg_tree* rson;
	int lson;
	int rson;
	int l,r;
	int cnt;
};
int n;
seg_tree nodes[9500006];
int ncnt;
int read() {
	int r=0,w=1;char ch=getchar();
	while(ch < '0' || ch > '9'){if (ch=='-') {w=-1;}ch=getchar();}
	while(ch >= '0' && ch <='9') {r = r*10+(ch-'0');ch=getchar();}
	return r*w;
}

long long ans;
void add(seg_tree& now,int x){
	// cout << now.l << " " << now.r << " " << x << "\n";
	if (now.l == now.r){
		now.cnt += 1;
		return ;
	}
	int mid = (now.l + now.r) / 2;
	if (x <= mid){
		if (now.rson != -1){
			ans += nodes[now.rson].cnt;
		}
		if (now.lson != -1){
			add(nodes[now.lson],x);
		} else {
			now.lson = ncnt++;
			nodes[now.lson].l = now.l;
			nodes[now.lson].r = mid;
			nodes[now.lson].cnt = 0;
			nodes[now.lson].lson = nodes[now.lson].rson = -1;
			add(nodes[now.lson],x);
		}
	} else {
		if (now.rson != -1){
			add(nodes[now.rson],x);
		}else {
			now.rson = ncnt++;
			nodes[now.rson].l = mid+1;
			nodes[now.rson].r = now.r;
			nodes[now.rson].cnt = 0;
			nodes[now.rson].lson = nodes[now.rson].rson = -1;
			add(nodes[now.rson],x);
		}
	}
	if (now.lson == -1){
		now.cnt = nodes[now.rson].cnt;
	} else if (now.rson == -1){
		now.cnt = nodes[now.lson].cnt;
	} else {
		now.cnt = nodes[now.lson].cnt + nodes[now.rson].cnt;
	}
}


int main(){	
	n = read();

	seg_tree& head = nodes[ncnt++];
	head.l = 1;
	head.r = 1000000000;
	head.cnt = 0;
	head.lson = head.rson = -1;

	for (int i = 1; i <= n; i++){
		add(head,read());
		// cout << "ans: " << ans << "\n";
	}
	printf("%lld",ans);

	
	return 0;
}