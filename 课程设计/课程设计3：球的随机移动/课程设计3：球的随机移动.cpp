#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#include<time.h>
#include<random>			// 引用随机库
#define High 480  // 游戏画面尺寸
#define Width 640

//请在下方编写代码，完成一个圆类CCircle的定义，为其添加合适的属性和方法
//请为圆类CCircle定义两个构造函数，不带参数的构造函数将生成大小、位置、速度均随机的圆（请保证在合理范围内随机）；
//带参数的构造函数将生成指定大小、位置和速度的圆。
class CCircle {
	//移动速度
	int vx;
	int vy;
	//圆心坐标、半径
	int x;
	int y;
	int r;
	bool bx = 0;
	bool by = 0;
public:
	CCircle() {
		r = 1 + rand() % 240;
		x = r + rand() % 640;
		y = r + rand() % 480;
		vx = 1 + rand() % 25;
		vy = vx;
	}
	CCircle(int r, int x, int y, int vx, int vy) {
		this->r = r;
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
	}
	void position() {		//更新位置
		if (x + r > 640) bx = 1;	//撞到右
		if (x - r < 0) bx = 0;		//撞到左
		if (y + r > 480)by = 1;		//撞到上
		if (y - r < 0)by = 0;		//撞到下

		if (!bx) x += vx;
		else x -= vx;

		if (!by) y += vy;
		else y -= vx;

	}
	void erase() {//擦除
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, r);
	}
	void show() {//显示
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, y, r);
	}


};


void updateWithoutInput(CCircle& obj)
{
	// 请在下方编写代码，调用obj的方法，更新圆的坐标
	obj.position();
}

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
	srand((unsigned int)time(0));

	//请在下方编写代码，生成一个指定大小、位置和速度的CCircle类对象cobj
	CCircle cobj(60, 60, 60, 6, 6);

	//请在下方编写代码，生成一个大小、位置、速度均随机的CCircle类对象cobjrandom
	CCircle cobjrandom;


	while (1)
	{

		//请在下方编写代码，调用两个Circle对象方法，擦除圆（就是用黑色把圆再画一遍）
		cobj.erase();
		cobjrandom.erase();


		// 请在下方编写代码，调用updateWithoutInput函数，更新两个Circle对象的坐标	
		updateWithoutInput(cobj);
		updateWithoutInput(cobjrandom);


		//请在下方编写代码，调用两个Circle对象的方法，重新绘制圆
		cobj.show();
		cobjrandom.show();

		FlushBatchDraw();
		Sleep(3);	// 延时
	}


	EndBatchDraw();
	closegraph();
	return 0;
}