#include <iostream>
#include <cstdlib>
#include <ctime>
#define n 4
using namespace std;

int arr[n][n];
struct point{
	int x;
	int y;
};
point init();
void show();
bool check();

int main(){
	int plus;
	point p,s,tem;
	s = init();
	while (!check()){
		show();
		cout<<"x y:";
		cin>>p.x>>p.y;
		p.x--;p.y--;
		if (p.x!=s.x&&p.y!=s.y||p.x>3||p.x<0||p.y>3||p.y<0){
			cout<<"ÊäÈë´íÎó!";
			continue;
		}
		if (p.y==s.y){
			plus=(p.x>s.x)?-1:1;
			for (int x=s.x;x==p.x;x+=plus){
				arr[p.y][x]=arr[p.y][x+plus];
			}
		}
		else if (p.x==s.x){
			plus=(p.y>s.y)?-1:1;
			for (int y=s.y;y==p.y;y+=plus){
				arr[p.x][y]=arr[p.x][y+plus];
			}
		}
	}
	return 0;
}

point init(){
	srand(time(NULL));
	point p;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			arr[j][i]=0;
		}
	}
	for (int i=1;i<=n*n-1;i++){
		do{
			p.x=rand()%n;
			p.y=rand()%n;
		}
		while (arr[p.y][p.x]==0);
		arr[p.y][p.x]=i;
	}
	for (p.x=0;p.x<n;p.x++){
		for (p.y=0;p.y<n;p.y++){
			if (arr[p.y][p.x]==0) return p;
		}
	}
}

void show(){
	point p;
	for (p.x=0;p.x<n;p.x++){
		for (p.y=0;p.y<n;p.y++){
			cout<<arr[p.y][p.x]<<" ";
		}
		cout<<endl;
	}
}

bool check(){
	point p;
	int i=1;
	for (p.y=0;p.y<n;p.y++){
		for (p.x=0;p.x<n;p.x++){
			if (arr[p.y][p.x]!=i) return false;
			i++;
		}
	}
	return true;
}
