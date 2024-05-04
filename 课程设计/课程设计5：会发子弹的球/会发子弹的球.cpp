#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#include<time.h>
#define High 480  // 游戏画面尺寸
#define Width 640

//请在下方编写代码，完成一个子弹类CBullet的定义，为其添加合适的属性和方法
//请为该类定义一个set函数，该函数根据宿主的圆心坐标设置子弹的坐标，子弹的半径为宿主的一半，子弹速度为-10到+10的随机数
//请为该类定义一个updateXY函数，该函数根据子弹速度更新子弹的坐标，若子弹已到达边界，则重新设置子弹的坐标为宿主坐标，子弹速度为-10到+10的随机数
class CBullet;

//请在下方编写代码，完成一个复合类CCircle的定义，包含一个CBullet类的数据成员，及其他合适的属性和方法
//请在类CCircle的合适位置，编写代码调用CBullet成员的设置、更新、绘制和擦除函数
class CCircle;


void updateWithoutInput(CCircle& obj)
{
	// 请在下方编写代码，调用obj的方法，更新圆的坐标


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

	//请在下方编写代码，生成CCircle类对象



	while (1)
	{

		//请在下方编写代码，调用CCircle类对象的方法，擦除圆及子弹（就是用黑色把圆再画一遍）




		// 请在下方编写代码，调用CCircle类对象的方法，更新圆及子弹的坐标




		//请在下方编写代码，调用CCircle类对象的方法，重新绘制圆及子弹




		FlushBatchDraw();
		Sleep(3);// 延时
	}


	gameover();  // 游戏结束、后续处理
	return 0;
}
