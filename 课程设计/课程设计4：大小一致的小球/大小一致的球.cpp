#include <graphics.h>		// ���� EasyX ͼ�ο�
#include <conio.h>
#include<time.h>
#define High 480  // ��Ϸ����ߴ�
#define Width 640

//�����·���д���룬���һ��Բ��CCircle�Ķ��壬Ϊ����Ӻ��ʵ����Ժͷ���
//��ΪԲ��CCircle���幹�캯������������������λ�á��ٶ������Բ���뱣֤�ں���Χ���������
//ΪCCircle������һ����̬���ݳ�Աradius�������ó�ʼֵΪ20
//ΪCCircle������һ����̬������ԱchangeRadius������ǰradiusΪ20�����Ϊ5�������Ϊ20
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
	MOUSEMSG m;		// ���������Ϣ

	//�����·���д���룬����CCircle��������飬���������С��λ�á��ٶȾ������CCircle�����





		while (1)
		{

			//�����·���д���룬����ÿ��Circle���󷽷�������Բ�������ú�ɫ��Բ�ٻ�һ�飩





			// �����·���д���룬����updateWithoutInput����������ÿ�����������	




			if (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
			{
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN) //����������������
				{
					// �����·���д���룬����CCircle�ľ�̬��Ա����changeRadius�����İ뾶



				}
			}





			//�����·���д���룬����ÿ��Circle����ķ��������»���Բ





			FlushBatchDraw();
			Sleep(3);	// ��ʱ


		}



	gameover();  // ��Ϸ��������������
	return 0;
}
