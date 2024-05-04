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
class CCircle;



//请在下方编写代码，完成一个碰撞检测函数hit的实现，该函数检测传入的两个CCircle对象是否碰撞





void updateWithoutInput(CCircle& obj) // 与用户输入无关的更新
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
	startup();  // 数据初始化	
	srand((unsigned int)time(0));


	//请在下方编写代码，生成CCircle类对象数组，包含多个大小、位置、速度均随机的CCircle类对象




	while (1)
	{

		//请在下方编写代码，调用每个Circle对象方法，擦除圆（就是用黑色把圆再画一遍）




		// 请在下方编写代码，调用updateWithoutInput函数，更新每个对象的坐标	




		//请在下方编写代码，调用碰撞检测函数，判断是否有Circle对象发生碰撞
		//若碰撞，调用碰撞对象的爆炸显示函数，并退出游戏
		/*退出游戏前，可调用以下语句，提示用户游戏结束
		settextstyle(30, 0, L"微软雅黑");
		outtextxy(Width*0.4, High*0.45, TEXT("GAME OVER"));
		*/



		//若未发生碰撞，请在下方编写代码，调用每个Circle对象的方法，重新绘制圆



		FlushBatchDraw();
		Sleep(3);	// 延时
	}

	gameover();  // 游戏结束、后续处理
	return 0;
}

