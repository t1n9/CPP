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

class CCircle {
protected:
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
	friend bool hit(CEnemy* c1, CPlayer& c2);
	CCircle() {
		radius = 10 + rand() % 100;
		x = radius + rand() % 640;
		y = radius + rand() % 480;
		vx = 5 + rand() % 5;
		vy = vx;
	}
	CCircle(int radius, int x, int y, int vx, int vy) {
		this->radius = radius;
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
	}
	virtual void position() {		//更新位置
		if (x + radius > 640) bx = 1;	//撞到右
		if (x - radius < 0) bx = 0;		//撞到左
		if (y + radius > 480)by = 1;		//撞到上
		if (y - radius < 0)by = 0;		//撞到下

		if (!bx) x += vx;
		else x -= vx;

		if (!by) y += vy;
		else y -= vx;

	}
	virtual void erase() {//擦除
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
	}
	virtual void show() {//显示
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, y, radius);
	}

};

class CPlayer {
	int x;
	int y;
	int radius;
public:
	friend bool hit(CEnemy* c1, CPlayer& c2);
	CPlayer() :x(0), y(0), radius(30) {}
	CPlayer(int _x, int _y, int r) :x(_x), y(_y), radius(r) {}
	void show() {
		setcolor(YELLOW);
		setfillcolor(BLUE);
		fillcircle(x, y, radius);
	}
	void boom() {
		setcolor(YELLOW);
		setfillcolor(RED);
		fillcircle(x, y, radius);
	}
	void position(int _x, int _y) {
		x = _x; y = _y;
	}
	void erase() {
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
	}

};

class CBullet : public CCircle {
	int vx, vy;
public:
	CBullet() {
		radius = 0;
		vx = rand() % 20 - 10;
		vy = rand() % 20 - 10;
	}
	friend class CEnemywithBullet;
	friend class CEnemyBoss;
	void position() {
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
	void show() {
		setcolor(YELLOW);
		setfillcolor(YELLOW);
		fillcircle(x, y, radius);
	}
	void set(int _x, int _y, int r) { x = _x; y = _y; radius = r / 2; }
	void erase() {
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
	}
};

class CEnemy :public CCircle {
public:
	CBullet bul;
	
};

class CEnemywithBullet : public CEnemy {
	int time = 70;
	bool fire = 0;
public:
	CEnemywithBullet() {
		bul.radius = radius / 2; 
		if (vx < 0)bx = 1; 
		if (vy < 0)by = 1;
	}
	void position() {
		bul.position();
		if (x + radius > 640) bx = 1;	//撞到右
		if (x - radius < 0) bx = 0;		//撞到左
		if (y + radius > 480)by = 1;		//撞到上
		if (y - radius < 0)by = 0;		//撞到下
		if (!bx) x += vx;
		else x -= vx;
		if (!by) y += vy;
		else y -= vx;
	}
	void erase() {
		bul.erase();
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
		if (!(time--)) {
			bul.set(x, y, radius); time = 70;
		}
	}
	void show() {
		bul.show();
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, y, radius);
	}
};

class CEnemywithSize : public CEnemy {
public:
	int i = 0;
	void erase() {//擦除
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
		if (i == 10) {
			radius = 10 + rand() % 100;
			i = 0;
		}
		i++;
	}
	
};

class CEnemyBoss : public CEnemy {
	int time = 10;
	int fire = 70;
public:
	CEnemyBoss() {
		bul.radius = radius / 2;
		if (vx < 0)bx = 1;
		if (vy < 0)by = 1;
	}
	void position() {
		bul.position();
		if (x + radius > 640) bx = 1;	//撞到右
		if (x - radius < 0) bx = 0;		//撞到左
		if (y + radius > 480)by = 1;		//撞到上
		if (y - radius < 0)by = 0;		//撞到下
		if (!bx) x += vx;
		else x -= vx;
		if (!by) y += vy;
		else y -= vx;
	}
	void erase() {
		bul.erase();
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, y, radius);
		if (!(fire--)) {
			bul.set(x, y,radius); 
			fire = 70;
		}
		if (!(time--)) {
			radius = 10 + rand() % 100;
			time = 10;
		}
	}
	void show() {
		bul.show();
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, y, radius);
	}
};


//请在下方编写代码，完成一个碰撞检测函数hit的实现，该函数检测传入CPlayer对象是否与CCircle对象碰撞
bool hit(CEnemy* c1, CPlayer& c2) {
	float dir1 = sqrt(pow(c1->x - c2.x, 2) + pow(c1->y - c2.y, 2));
	float dir2 = sqrt(pow(c1->bul.x - c2.x, 2) + pow(c1->bul.y - c2.y, 2));
	if (dir1 < c1->radius + c2.radius || dir2 < c1->bul.radius + c2.radius) {
		c2.boom();
		return 1;
	}
	else return 0;
}



void updateWithoutInput(CCircle* obj) // 与用户输入无关的更新
{
	// 请在下方编写代码，调用obj的方法，更新圆的坐标
	obj->position();
	
}


void updateWithInput(CPlayer& obj)// 与用户输入有关的更新
{
	MOUSEMSG m;		// 定义鼠标消息
	while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			// 请在下方编写代码，调用obj的方法，更新圆的坐标等于鼠标所在的位置m.x和m.y
			obj.position(m.x, m.y);
		}
	}
}

void gameover(int flag)		//0胜利，1失败

{
	if (flag == 1) {
		settextstyle(30, 0, L"微软雅黑");
		outtextxy(Width * 0.4, High * 0.45, TEXT("GAME OVER"));
	}
	else if (flag == 0) {
		settextstyle(30, 0, L"微软雅黑");
		outtextxy(Width * 0.3, High * 0.45, TEXT("CONGRADULATION!"));
	}
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
	CPlayer player(0, 0, 30);

	int round = 0, flag = 0;
	while (round < 4) {

		int i, j;
		CEnemy* cobjrandom = NULL;
		
		switch (round) {
			//case 0:   第一关：随机移动的敌人
		case 0:cobjrandom = new CEnemy();
			break;
			//case 1:   第二关：大小随机变化且随机移动的敌人
		case 1:cobjrandom = new CEnemywithSize();
			break;
			//case 2:   第三关：会发子弹且随机移动的敌人
		case 2:cobjrandom = new CEnemywithBullet();
			break;
			//case 3:   第四关：大小随机变化且会发子弹且随机移动的敌人
		case 3:cobjrandom = new CEnemyBoss();
			break;
		}

		if (cobjrandom != NULL) {
			clock_t start = clock(), end = clock();
			double period = (double)(end - start) / CLOCKS_PER_SEC;
			while (period <= 5) {
				//请在下方编写代码，调用pobj的方法，擦除圆（就是用黑色把圆再画一遍）
				cobjrandom->erase();
				//请在下方编写代码，调用Circle对象方法，擦除圆（就是用黑色把圆再画一遍）
				player.erase();

				// 请在更新球的坐标
				// 与用户输入无关的更新
				// 请在下方编写代码，调用update函数，更新每个对象的坐标	

				updateWithoutInput(cobjrandom);
				updateWithInput(player);
				


				//判断是否发生碰撞
				if (hit(cobjrandom, player)) {
					FlushBatchDraw();
					gameover(1);
					return 0;
				}




				//若未发生碰撞，请在下方编写代码，调用每个Circle对象的方法，重新绘制圆
				cobjrandom->show();


				//请在下方编写代码，调用CPlayer方法，重新绘制圆
				player.show();



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
			if (round < 3) {
				settextstyle(30, 0, L"微软雅黑");
				outtextxy(Width * 0.4, High * 0.45, TEXT("NEXT ROUND"));
				FlushBatchDraw();
				Sleep(1000);
			}
			
			//闯关成功
			/*	settextstyle(30, 0, L"微软雅黑");
			outtextxy(Width*0.3, High*0.45, TEXT("CONGRADULATION!"));*/

			round++;
			cleardevice();
		}
	}


	gameover(0);
	return 0;
}
