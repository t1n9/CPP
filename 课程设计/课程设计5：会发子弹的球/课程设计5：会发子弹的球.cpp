#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#include<time.h>
#include <iostream>
#define High 480  // 游戏画面尺寸
#define Width 640

//请在下方编写代码，完成一个子弹类CBullet的定义，为其添加合适的属性和方法
//请为该类定义一个set函数，该函数根据宿主的圆心坐标设置子弹的坐标，子弹的半径为宿主的一半，子弹速度为-10到+10的随机数
//请为该类定义一个updateXY函数，该函数根据子弹速度更新子弹的坐标，若子弹已到达边界，则重新设置子弹的坐标为宿主坐标，子弹速度为-10到+10的随机数
class CBullet {
	int vx, vy, x, y, radius;
	bool bx = 0, by = 0;
public:
	CBullet(int _x, int _y, int _r) :x(_x), y(_y), radius(_r / 2), vx(0), vy(0) {}
	CBullet() :x(0), y(0), radius(0), vx(0), vy(0) {}
	void set(int _x,int _y,int _r) {
		radius = _r / 2;
		x = _x; y = _y;
		vx = rand() % 20 - 10;
		vy = rand() % 20 - 10;
		if (vx < 0)bx = 1;
		if (vy < 0)by = 1;
	}
	void updateXY() {
		if (x + radius > 640) bx = 1;	//撞到右
		if (x - radius < 0) bx = 0;		//撞到左
		if (y + radius > 480)by = 1;	//撞到上
		if (y - radius < 0)by = 0;		//撞到下

		if (!bx) {		//由于子弹初速度有正有负，需要增加判定条件
			if (vx > 0)x += vx;
			else x -= vx;
		} 
		
		else {
			if (vx > 0)x -= vx;
			else x += vx;
		}

		if (!by) {
			if (vy > 0)y += vy;
			else y -= vy;
		}
		else {
			if (vy > 0)y -= vy;
			else y += vy;
		}
		
	}
	void erase() {
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
	}
	void show() {
		setcolor(YELLOW);
		setfillcolor(BLUE);
		fillcircle(x, y, radius);
	}
};

//请在下方编写代码，完成一个复合类CCircle的定义，包含一个CBullet类的数据成员，及其他合适的属性和方法
//请在类CCircle的合适位置，编写代码调用CBullet成员的设置、更新、绘制和擦除函数
class CCircle {
	//移动速度
	int vx;
	int vy;
	//圆心坐标、半径
	int x;
	int y;
	int radius;
	bool bx = 0;
	bool by = 0;
	CBullet blt;
public:
	CCircle() {
		radius = 20 + rand() % 40;
		x = radius + rand() % 640;
		y = radius + rand() % 480;
		vx = 1 + rand() % 10;
		vy = vx;
	}
	CCircle(int radius, int x, int y, int vx, int vy) {
		this->radius = radius;
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
	}
	void position() {		//更新位置
		if (x + radius > 640) bx = 1;	//撞到右
		if (x - radius < 0) bx = 0;		//撞到左
		if (y + radius > 480)by = 1;	//撞到上
		if (y - radius < 0)by = 0;		//撞到下

		if (!bx) x += vx;
		else x -= vx;

		if (!by) y += vy;
		else y -= vy;

	}
	void erase() {//擦除
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
		blt.erase();
	}
	void show() {//显示
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, y, radius);
	}
	void setBlt() {
		blt.set(x, y, radius);
	}
	void fire() {		//发射子弹函数，包括更新子弹坐标、绘制子弹
		blt.updateXY();
		blt.show();
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
	MOUSEMSG m;		// 定义鼠标消息

	//请在下方编写代码，生成CCircle类对象
	CCircle obj;

	int time = 50;		//子弹发射时间
	bool fire = 0;		//子弹发射状态
	while (1)
	{

		//请在下方编写代码，调用CCircle类对象的方法，擦除圆及子弹（就是用黑色把圆再画一遍）
		obj.erase();



		// 请在下方编写代码，调用CCircle类对象的方法，更新圆及子弹的坐标
		updateWithoutInput(obj);



		//请在下方编写代码，调用CCircle类对象的方法，重新绘制圆及子弹
		obj.show();

		if (MouseHit())  //这个函数用于检测当前是否有鼠标消息
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN) //若按下鼠标左键，则发射子弹
			{	
				if (fire == 0) {	//在规定时间内发射一枚子弹
					obj.setBlt();
					fire = 1;
				}
			}
		}

		if (fire == 1&&time != 0) {		//当子弹为发射状态且时间不为0时
			obj.fire();
			time--;
		}

		if (time == 0) {		//当时间为0时，重置时间
			time = 100;
			fire = 0;
		}

		FlushBatchDraw();
		Sleep(3);// 延时
	}


	gameover();  // 游戏结束、后续处理
	return 0;
}