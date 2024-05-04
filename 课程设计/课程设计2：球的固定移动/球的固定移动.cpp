#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#define High 480  // 游戏画面尺寸
#define Width 640

//请在下方编写代码，完成一个圆类CCircle的定义，为其添加合适的属性和方法，其中属性包含圆移动的速度vx和vy，用于更新圆心坐标
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

	//请在下方编写代码，生成一个CCircle类对象cobj

	while (1)
	{

		//请在下方编写代码，调用cobj的方法，擦除圆（就是用黑色把圆再画一遍）


		// 请在下方编写代码，调用updateWithoutInput函数，更新圆的坐标	


		//请在下方编写代码，调用cobj的方法，重新绘制圆


		FlushBatchDraw();
		// 延时
		Sleep(3);
	}



	gameover();
	return 0;
}
