#include <graphics.h>		// ���� EasyX ͼ�ο�
#include <conio.h>
#include<time.h>
#define High 480  // ��Ϸ����ߴ�
#define Width 640

//�����·���д���룬���һ��Բ��CCircle�Ķ��壬Ϊ����Ӻ��ʵ����Ժͷ���
//��ΪԲ��CCircle�����������캯�������������Ĺ��캯�������ɴ�С��λ�á��ٶȾ������Բ���뱣֤�ں���Χ���������
//�������Ĺ��캯��������ָ����С��λ�ú��ٶȵ�Բ��
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

	//�����·���д���룬����һ��ָ����С��λ�ú��ٶȵ�CCircle�����cobj


	//�����·���д���룬����һ����С��λ�á��ٶȾ������CCircle�����cobjrandom



	while (1)
	{

		//�����·���д���룬��������Circle���󷽷�������Բ�������ú�ɫ��Բ�ٻ�һ�飩




		// �����·���д���룬����updateWithoutInput��������������Circle���������	




		//�����·���д���룬��������Circle����ķ��������»���Բ



		FlushBatchDraw();
		Sleep(3);	// ��ʱ
	}


	EndBatchDraw();
	closegraph();
	return 0;
}
