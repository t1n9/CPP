#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#include<time.h>
#define High 480  // 游戏画面尺寸
#define Width 640

//请在下方编写代码，完成一个圆类CCircle的定义，为其添加合适的属性和方法
//请为圆类CCircle定义构造函数，不带参数，生成位置、速度随机的圆（请保证在合理范围内随机）；
//为CCircle类增加一个静态数据成员radius，并设置初始值为20
//为CCircle类增加一个静态函数成员changeRadius，若当前radius为20，则改为5；否则改为20
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
	MOUSEMSG m;		// 定义鼠标消息

	//请在下方编写代码，生成CCircle类对象数组，包含多个大小、位置、速度均随机的CCircle类对象





		while (1)
		{

			//请在下方编写代码，调用每个Circle对象方法，擦除圆（就是用黑色把圆再画一遍）





			// 请在下方编写代码，调用updateWithoutInput函数，更新每个对象的坐标	




			if (MouseHit())  //这个函数用于检测当前是否有鼠标消息
			{
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN) //若按下鼠标左键，则
				{
					// 请在下方编写代码，调用CCircle的静态成员函数changeRadius，更改半径



				}
			}





			//请在下方编写代码，调用每个Circle对象的方法，重新绘制圆





			FlushBatchDraw();
			Sleep(3);	// 延时


		}



	gameover();  // 游戏结束、后续处理
	return 0;
}
