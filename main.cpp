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
bool check(int arr[4][4]);
point init();
void show()

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

