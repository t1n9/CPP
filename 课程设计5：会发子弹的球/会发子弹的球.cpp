#include <graphics.h>		// ���� EasyX ͼ�ο�
#include <conio.h>
#include<time.h>
#define High 480  // ��Ϸ����ߴ�
#define Width 640

//�����·���д���룬���һ���ӵ���CBullet�Ķ��壬Ϊ����Ӻ��ʵ����Ժͷ���
//��Ϊ���ඨ��һ��set�������ú�������������Բ�����������ӵ������꣬�ӵ��İ뾶Ϊ������һ�룬�ӵ��ٶ�Ϊ-10��+10�������
//��Ϊ���ඨ��һ��updateXY�������ú��������ӵ��ٶȸ����ӵ������꣬���ӵ��ѵ���߽磬�����������ӵ�������Ϊ�������꣬�ӵ��ٶ�Ϊ-10��+10�������
class CBullet;

//�����·���д���룬���һ��������CCircle�Ķ��壬����һ��CBullet������ݳ�Ա�����������ʵ����Ժͷ���
//������CCircle�ĺ���λ�ã���д�������CBullet��Ա�����á����¡����ƺͲ�������
class CCircle;


void updateWithoutInput(CCircle& obj)
{
	// �����·���д���룬����obj�ķ���������Բ������


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

	//�����·���д���룬����CCircle�����



	while (1)
	{

		//�����·���д���룬����CCircle�����ķ���������Բ���ӵ��������ú�ɫ��Բ�ٻ�һ�飩




		// �����·���д���룬����CCircle�����ķ���������Բ���ӵ�������




		//�����·���д���룬����CCircle�����ķ��������»���Բ���ӵ�




		FlushBatchDraw();
		Sleep(3);// ��ʱ
	}


	gameover();  // ��Ϸ��������������
	return 0;
}
