#include <graphics.h>		// ���� EasyX ͼ�ο�
#include <conio.h>
#define High 480  // ��Ϸ����ߴ�
#define Width 640

//�����·���д���룬���һ��Բ��CCircle�Ķ��壬Ϊ����Ӻ��ʵ����Ժͷ������������԰���Բ�ƶ����ٶ�vx��vy�����ڸ���Բ������
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

	//�����·���д���룬����һ��CCircle�����cobj

	while (1)
	{

		//�����·���д���룬����cobj�ķ���������Բ�������ú�ɫ��Բ�ٻ�һ�飩


		// �����·���д���룬����updateWithoutInput����������Բ������	


		//�����·���д���룬����cobj�ķ��������»���Բ


		FlushBatchDraw();
		// ��ʱ
		Sleep(3);
	}



	gameover();
	return 0;
}
