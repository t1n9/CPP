#include <graphics.h>		// ���� EasyX ͼ�ο�
#include <conio.h>
#include<time.h>
#include<math.h>
#define High 480  // ��Ϸ����ߴ�
#define Width 640

/*ʵ��ͨ����Ϸ
��һ�أ�����ƶ��ĵ���
�ڶ��أ���С����仯������ƶ��ĵ���
�����أ��ᷢ�ӵ�������ƶ��ĵ���
���Ĺأ���С����仯�һᷢ�ӵ�������ƶ��ĵ���
*/

//ʵ��������
class CPlayer;
class CCircle;
class CBullet;//�̳�CCircle
class CEnemy;//�̳�CCircle
class CEnemywithBullet;//�̳�CEnemy
class CEnemywithSize;//�̳�CEnemy
class CEnemyBoss;//�̳�CEnemywithBullet��CEnemywithSize



void updateWithoutInput(CCircle& obj)
{
	//�������ĸ���
}

void updateWithInput(CPlayer& obj)
{
	MOUSEMSG m;		// ���������Ϣ
	while (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			// ����λ�õ���������ڵ�λ��

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
	initgraph(Width, High);//// ��ʼ��640��480�Ļ���
	BeginBatchDraw();
}



int main()
{
	startup();
	srand((unsigned int)time(0));

	//�����·���д���룬����CPlayer�����

	int round = 0, flag = 0;
	while (round < 4) {

		int i, j;
		CEnemy* cobjrandom = NULL;

		switch (round) {
			//case 0:   ��һ�أ�����ƶ��ĵ���
			//case 1:   �ڶ��أ���С����仯������ƶ��ĵ���
			//case 2:   �����أ��ᷢ�ӵ�������ƶ��ĵ���
			//case 3:   ���Ĺأ���С����仯�һᷢ�ӵ�������ƶ��ĵ���
		}

		if (cobjrandom != NULL) {
			clock_t start = clock(), end = clock();
			double period = (double)(end - start) / CLOCKS_PER_SEC;
			while (period <= 5) {
				//�����·���д���룬����pobj�ķ���������Բ�������ú�ɫ��Բ�ٻ�һ�飩


				//�����·���д���룬����Circle���󷽷�������Բ�������ú�ɫ��Բ�ٻ�һ�飩


				// ���ڸ����������
				// ���û������޹صĸ���
				// �����·���д���룬����update����������ÿ�����������	



				//�ж��Ƿ�����ײ





				//��δ������ײ�������·���д���룬����ÿ��Circle����ķ��������»���Բ


				//�����·���д���룬����CPlayer���������»���Բ




				FlushBatchDraw();
				Sleep(3);	// ��ʱ
				end = clock();
				period = (double)(end - start) / CLOCKS_PER_SEC;
			}

			//������ײ����Ϸ����
			/*settextstyle(30, 0, L"΢���ź�");
			outtextxy(Width*0.4, High*0.45, TEXT("GAME OVER"));*/

			//���뵽��һ��
			/*settextstyle(30, 0, L"΢���ź�");
			outtextxy(Width*0.4, High*0.45, TEXT("NEXT ROUND"));
			FlushBatchDraw();
			Sleep(1000);
			*/

			//���سɹ�
			/*	settextstyle(30, 0, L"΢���ź�");
			outtextxy(Width*0.3, High*0.45, TEXT("CONGRADULATION!"));*/

			round++;
			cleardevice();
		}
	}
	gameover();  // ��Ϸ��������������
	return 0;
}

