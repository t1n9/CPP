#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#define High 480  // 游戏画面尺寸
#define Width 640

class CRect {
	int length, width;//长和宽
	int xleft, yleft, xright, yright;//左上角和右下角坐标
public:
	CRect(int xl = 0, int yl = 0, int xr = 100, int yr = 100) {//构造函数
		xleft = xl; yleft = yl; xright = xr; yright = yr;
		length = abs(xright - xleft); width = abs(yright - yleft);
	}
	void show() {//画图函数
		setcolor(YELLOW);     // 线条黄色
		setfillcolor(GREEN);    // 内部绿色填充
		fillrectangle(xleft, yleft, xright, yright);
	}
};

//请在下方编写代码，定义一个圆类CCircle，具有属性圆心的x和y坐标、圆的半径，及合适的方法
//圆的绘制语句为：fillcircle(x坐标,y坐标,半径)







void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}

void startup()
{
	initgraph(Width, High);//// 初始化640×480的画布
	BeginBatchDraw();
}

int main()
{
	startup();


	CRect rectobj(100, 200, 300, 300);
	rectobj.show();

	settextstyle(30, 0, L"微软雅黑");
	outtextxy(320, 150, TEXT("请在长方形的右边绘制一个圆"));

	//请在下方编写代码，生成一个CCircle类对象，并调用该对象的方法，将其绘制在长方形右边


	gameover();
	return 0;
}
