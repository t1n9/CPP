#include <graphics.h>		// 引用 EasyX 图形库
#include <conio.h>
#include<time.h>
#include<math.h>
#define High 480  // 游戏画面尺寸
#define Width 640

/*实现通关游戏
第一关：随机移动的敌人
第二关：大小随机变化且随机移动的敌人
第三关：会发子弹且随机移动的敌人
第四关：大小随机变化且会发子弹且随机移动的敌人
*/

//实现以下类
class CPlayer;
class CCircle;
class CBullet;//继承CCircle
class CEnemy;//继承CCircle
class CEnemywithBullet;//继承CEnemy
class CEnemywithSize;//继承CEnemy
class CEnemyBoss;//继承CEnemywithBullet和CEnemywithSize



void updateWithoutInput(CCircle& obj)
{
	//随机对象的更新
}

void updateWithInput(CPlayer& obj)
{
	MOUSEMSG m;		// 定义鼠标消息
	while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			// 更新位置等于鼠标所在的位置

		}
	}
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

	//请在下方编写代码，生成CPlayer类对象

	int round = 0, flag = 0;
	while (round < 4) {

		int i, j;
		CEnemy* cobjrandom = NULL;

		switch (round) {
			//case 0:   第一关：随机移动的敌人
			//case 1:   第二关：大小随机变化且随机移动的敌人
			//case 2:   第三关：会发子弹且随机移动的敌人
			//case 3:   第四关：大小随机变化且会发子弹且随机移动的敌人
		}

		if (cobjrandom != NULL) {
			clock_t start = clock(), end = clock();
			double period = (double)(end - start) / CLOCKS_PER_SEC;
			while (period <= 5) {
				//请在下方编写代码，调用pobj的方法，擦除圆（就是用黑色把圆再画一遍）


				//请在下方编写代码，调用Circle对象方法，擦除圆（就是用黑色把圆再画一遍）


				// 请在更新球的坐标
				// 与用户输入无关的更新
				// 请在下方编写代码，调用update函数，更新每个对象的坐标	



				//判断是否发生碰撞





				//若未发生碰撞，请在下方编写代码，调用每个Circle对象的方法，重新绘制圆


				//请在下方编写代码，调用CPlayer方法，重新绘制圆




				FlushBatchDraw();
				Sleep(3);	// 延时
				end = clock();
				period = (double)(end - start) / CLOCKS_PER_SEC;
			}

			//发生碰撞，游戏结束
			/*settextstyle(30, 0, L"微软雅黑");
			outtextxy(Width*0.4, High*0.45, TEXT("GAME OVER"));*/

			//进入到下一关
			/*settextstyle(30, 0, L"微软雅黑");
			outtextxy(Width*0.4, High*0.45, TEXT("NEXT ROUND"));
			FlushBatchDraw();
			Sleep(1000);
			*/

			//闯关成功
			/*	settextstyle(30, 0, L"微软雅黑");
			outtextxy(Width*0.3, High*0.45, TEXT("CONGRADULATION!"));*/

			round++;
			cleardevice();
		}
	}
	gameover();  // 游戏结束、后续处理
	return 0;
}

