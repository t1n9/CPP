#include <graphics.h>		// ���� EasyX ͼ�ο�
#include <conio.h>
#define High 480  // ��Ϸ����ߴ�
#define Width 640

class CRect {
	int length, width;//���Ϳ�
	int xleft, yleft, xright, yright;//���ϽǺ����½�����
public:
	CRect(int xl = 0, int yl = 0, int xr = 100, int yr = 100) {//���캯��
		xleft = xl; yleft = yl; xright = xr; yright = yr;
		length = abs(xright - xleft); width = abs(yright - yleft);
	}
	void show() {//��ͼ����
		setcolor(YELLOW);     // ������ɫ
		setfillcolor(GREEN);    // �ڲ���ɫ���
		fillrectangle(xleft, yleft, xright, yright);
	}
};

//�����·���д���룬����һ��Բ��CCircle����������Բ�ĵ�x��y���ꡢԲ�İ뾶�������ʵķ���
//Բ�Ļ������Ϊ��fillcircle(x����,y����,�뾶)







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


	CRect rectobj(100, 200, 300, 300);
	rectobj.show();

	settextstyle(30, 0, L"΢���ź�");
	outtextxy(320, 150, TEXT("���ڳ����ε��ұ߻���һ��Բ"));

	//�����·���д���룬����һ��CCircle����󣬲����øö���ķ�������������ڳ������ұ�


	gameover();
	return 0;
}
