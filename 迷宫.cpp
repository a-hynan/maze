#include<stdio.h>
int a,b[10][10],min=0,x[10][10],num=0,l=0;
//x数组相当于bool数组，记录该方格是否被走过 
//num记录所走的步数
//l记录所走的路线
//min记录路线最
void lemon(int m,int n)
{
	if(m==a-2 && n==a-2)//如果函数到达了终点，记录其走过的长度 
	{
		if(l==0)//记录第一次走到终点路线的长度，将他赋值给min。 
		{
			min=num;
		}
		if(num<min)//将走到终点的长度与min来对比 
		{
			min=num;
		}
		l++;//走到终点路线条数 
		return;
	}
	//接下来是移动方位控制 
	if(b[m][n]==0 && x[m][n]==0)//向上走 
	{
		num++;//记录走过的步数 
		x[m][n]=1;//将走过的方位标记，防止下一次移动重复。 
		lemon(m+1,n);//向上走 
		//如果运行到这里，说明前面所走的路都不通或者已经走到终点退回来，这时候就将所走的方位标记重置，并且走过的步数减1 
		x[m][n]=0;//将这次方位标记 
		num--;
	}
	if(b[m][n]==0 && x[m][n]==0)//向下走 
	{
	    num++;//记录走过的步数 
		x[m][n]=1;//将走过的方位标记，防止下一次移动重复。 
		lemon(m-1,n);//向上走 
		//如果运行到这里，说明前面所走的路都不通或者已经走到终点退回来，这时候就将所走的方位标记重置，并且走过的步数减1 
		x[m][n]=0;//将这次方位标记 
		num--;
	}
	if(b[m][n]==0 && x[m][n]==0)//向右走 
	{
	    num++;//记录走过的步数 
		x[m][n]=1;//将走过的方位标记，防止下一次移动重复。 
		lemon(m,n+1);//向上走 
		//如果运行到这里，说明前面所走的路都不通或者已经走到终点退回来，这时候就将所走的方位标记重置，并且走过的步数减1 
		x[m][n]=0;//将这次方位标记 
		num--;
	}
	if(b[m][n]==0 && x[m][n]==0)//向左走 
	{
	    num++;//记录走过的步数 
		x[m][n]=1;//将走过的方位标记，防止下一次移动重复。 
		lemon(m,n-1);//向上走 
		//如果运行到这里，说明前面所走的路都不通或者已经走到终点退回来，这时候就将所走的方位标记重置，并且走过的步数减1 
		x[m][n]=0;//将这次方位标记 
		num--;
	}
}
int main()
{
	scanf("%d",&a);//输入迷宫长度 
	for(int c=0;c<a;c++)//构造迷宫图形 
	{
		for(int d=0;d<a;d++)
		{
			scanf("%d",&b[c][d]);
		}
	}
	lemon(1,1);//将入口坐标传给函数 
	if(min) //如果min值依然为0，说明一直都没找到出口，输出No solution，如果min大于0，说明已经找到最短路线，则输出。 
	printf("%d",min);
	else
	printf("No solution");
}
