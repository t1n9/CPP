#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#include<time.h>
#include<math.h>
#define High 480  // 游戏画面尺寸
#define Width 640

//请在下方编写代码，完成一个圆类CCircle的定义，为其添加合适的属性和方法，使程序可以运行并达到指定效果
//请为圆类CCircle定义构造函数，不带参数的构造函数将生成大小、位置、速度均随机的圆（请保证在合理范围内随机）；
//为该类增加更新圆心坐标的方法，可以按指定速度更新坐标，也可以由参数传入指定坐标
//声明碰撞检测函数为该类的友元函数
//增加一个爆炸显示函数，绘制该圆，线条黄色，内部红色填充
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
public:
	friend bool hit(CCircle& c1, CCircle& c2);
	CCircle() {
		radius = 10 + rand() % 30;
		x = radius + rand() % 640;
		y = radius + rand() % 480;
		vx = 1 + rand() % 5;
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
		if (y + radius > 480)by = 1;		//撞到上
		if (y - radius < 0)by = 0;		//撞到下

		if (!bx) x += vx;
		else x -= vx;

		if (!by) y += vy;
		else y -= vx;

	}
	void erase() {//擦除
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
	}
	void show() {//显示
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, y, radius);
	}
	void changeRadius() {
		if (radius == 20)
			radius = 5;
		else
			radius = 20;
	}
	void boom() {
		setcolor(YELLOW);
		setfillcolor(RED);
		fillcircle(x, y, radius);
	}
};



//请在下方编写代码，完成一个碰撞检测函数hit的实现，该函数检测传入的两个CCircle对象是否碰撞
bool hit(CCircle& c1, CCircle& c2) {
	float dir = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
	if (dir < c1.radius + c2.radius) return 1;
	else return 0;
}




void updateWithoutInput(CCircle& obj) // 与用户输入无关的更新
{
	// 请在下方编写代码，调用obj的方法，更新圆的坐标
	obj.position();

}


void gameover()
{
	settextstyle(30, 0, L"微软雅黑");
	outtextxy(Width * 0.4, High * 0.45, TEXT("GAME OVER"));
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
	startup();  // 数据初始化	
	srand((unsigned int)time(0));


	//请在下方编写代码，生成CCircle类对象数组，包含多个大小、位置、速度均随机的CCircle类对象
	CCircle obj[3];

	int flag = 3;	//标记哪两个球相撞
	

	while (1)
	{
		//请在下方编写代码，调用每个Circle对象方法，擦除圆（就是用黑色把圆再画一遍）
		int i;
		for (i = 0; i < 3; i++) { obj[i].erase(); }
		if (flag != 3) {
			if (flag == 0) {
				obj[1].boom();
				obj[2].boom();
				FlushBatchDraw();
				break;
			}
			if (flag == 1) {
				obj[0].boom();
				obj[2].boom();
				FlushBatchDraw();
				break;
			}
			if (flag == 2) {
				obj[0].boom();
				obj[1].boom();
				FlushBatchDraw();
				break;
			}
		}
		
			
		// 请在下方编写代码，调用updateWithoutInput函数，更新每个对象的坐标	
		for (i = 0; i < 3; i++) { updateWithoutInput(obj[i]); }


		//请在下方编写代码，调用碰撞检测函数，判断是否有Circle对象发生碰撞
		//若碰撞，调用碰撞对象的爆炸显示函数，并退出游戏
		/*退出游戏前，可调用以下语句，提示用户游戏结束
		settextstyle(30, 0, L"微软雅黑");
		outtextxy(Width*0.4, High*0.45, TEXT("GAME OVER"));
		while()*/
		if (hit(obj[0], obj[1])) { flag = 2; continue; }
		if (hit(obj[0], obj[2])) { flag = 1; continue; }
		if (hit(obj[1], obj[2])) { flag = 0; continue; }


		//若未发生碰撞，请在下方编写代码，调用每个Circle对象的方法，重新绘制圆
		for (i = 0; i < 3; i++) { obj[i].show(); }


		FlushBatchDraw();
		Sleep(3);	// 延时
	}

	gameover();  // 游戏结束、后续处理
	return 0;
}

