/*
  24.4.5
  
 (���������е���������)

 ͼ�ο� : easyx

 �ӿ�˵�� : (��*Ϊ�Զ��庯��)

	��ʼ��init*
	  ������Ϸ����initgraph
	  ���ر���/��ɫͼƬ��Դloadimage
	  ��ȡͼƬ�Ŀ������getwidth, getheight

    ����֡���ʱ��getDelay*
	  ��ȡϵͳ�����������ڵĺ�����GetTickCount

	�����û�����keyEvent*
	  kbhit  : ����⵽�����ⰴ������, ����ture, ���Ա�����������
	  getch : ���ڻ�ȡ�����ϵ��ַ�, ��scanf���������Ҫ���»س����Ϳ�����ɹ�

	��ȾͼƬupdateBg*updateHero*updateEnemy*
	  ȷ��ͼƬ����λ��putimage 
	  BeginBatchDraw��EndBatchDraw : ˫���弼��, ���ٲ���֡����ʱ������˸
  
	������Ϸ��ʵʱ״̬run*
     �����˶� : ÿһ��ͼƬ��x���ȥ��ͬ����ֵ
	 ѭ������ : �����˶���һ������Ϸ���ڵĿ�Ⱥ�������
	 ֡����  : ÿ����һ��run()֡����һ, ʹ��ģ������֡������
	 ���µ���
	 ��ײ���
	 
 ������:

    01
	��̬����std::vector �������Ը�����Ҫ�Զ��������С,  �Ӷ���Լ�ڴ�ռ�
    �﷨ : std::vector<int> myVector;
	ʹ�� : myVector.push_back( a[1] );

	02
	��c++���뻷����enum������Ҫǿת���ܵ�int��, c���Ժ������ֱ����

	03
	����C++�Ķ�̬���鹦��, ������C���Ե�malloc()��free()������ʵ�� (ָ����ڴ����)
	����, ָ����̫�鷳��(���˸о�)
	��vector���ˬ����

 δ���Ľ� :(Ҳ���ܲ�����)

     1)�Ż�������Ծ(��Ծ���ٶ�, ��Ծ����)
	 2)���ӵ�������, ������Ϸ����
	 3)�Ż���Ч
	 4)�Ż��˵�
	 5)����BOSSϵͳ

 ������� : 

	 1.��װIstallerProjects���
	 2.��������Ŀģ��Setup Project
	 3.������Ϸ��Դ������File System
	 4.������ݷ�ʽͼ��
	 5.�������л���Releaseģʽ, ������Ŀ����(���ֽ��ַ���, �ر�sdl���, ���п�(���߳�/MT))
	 6.����������
	 7.����������ɲ��ҵ�.exe�ļ�

	 (��������)
	  1. ��Դ�����ļ�ȫ�����Ƶ�һ���ļ�����
	  2. �������д���, ������ļ���
	  3. �������� : "C:\Program Files (x86)\Dev-Cpp\MinGW\bin\g++.exe" main.cpp -o main.exe -lgraphics -lconio -lwinmm -lstdc++ -luser32 -lgdi32 -lopengl32 -static -s -O2
	  4. �ȴ��������
	  5. �������� : "upx -9 main.exe" (ѹ����ִ���ļ�)
	  6. �ȴ�ѹ�����
	  7. �õ�ѹ����Ŀ�ִ���ļ�main.exe

*/



/*
	����Ŀ����Bվ��Ƶ�̳̱�д������ѧϰ�ο���

	��Ƶ��ַ(BV��)��BV1XN4y1K7gW

  ��C������Ŀʵս���������С��Ϸ��C������Ŀʵս��Ŀ��ϸ��ѧ���ʺ�С��������Ŀ����������C���ԣ�

*/



/*
	 # ����˵��

	## ���
	����һ������C���Ժ�EasyXͼ�ο�Ļ����ܿ���Ϸ(С��������C++����)��
	��Ϸ�а�����ɫ���ܡ���Ծ���¶׺��ϰ�����������ܵȹ��ܡ�
	����ϰ����÷���, ���۷����Ի�ȡʤ����


	## ʹ�õĿ�

	- `stdio.h`: ��׼���������
	- `graphics.h`: EasyXͼ�ο⣬���ڴ���ͼƬ����ʼ��ͼ�δ��ڵ�
	- `conio.h`: ����̨��������⣬���ڴ����������
	- `Windows.h`: Windows����ϵͳAPI�⣬���ڻ�ȡϵͳʱ��
	- `vector`: ��׼ģ����еĶ�̬����
	- `tools.h`: �Զ��幤�ߺ�����(������Ū��, ��UP�����ε�, ����һЩ������ԭ����ûŪ��, ������, �þ�������)

	## ����ṹ

	- `init()`: ��ʼ����Ϸ���ڡ�������Դ�ļ�����ʼ����ɫ����ʼ�����ˡ���ʼ���Ʒ����֡�Ԥ������Ч
	- `getDelay()`: ��ȡϵͳ�����������ڵĺ�����
	- `updateBg()`: ���±�������
	- `updateHero()`: ���½�ɫ����
	- `updateEnemy()`: ���µ��˶���
	- `keyEvent()`: �����û������¼�
	- `run()`: ��ѭ����������Ϸ��ʵʱ״̬
	- `main()`: �������

	## ��Ϸ����

	��ʼ����Ϸ���ں���Դ��
	������Ϸ�˵����档
	������Ϸ��ѭ������ÿ֡�����д����ɫ�͵��˵��ƶ�����������ײ��⡣
	������Ϸ״̬�ж���Ϸ�Ƿ������չʾ��Ϸ�������档

	## ��Ϸ����

	��Ϸ���ݽ�ɫ����˵���ײ������мƷֺ�����ֵ�ı����������ֵΪ���ﵽһ������ʱ��Ϸ������

*/



#include<stdio.h>         //......rand, 
#include<graphics.h>   //����ͼƬ, initgraph, loadimage, getwidth, getheight, putimage, BeginBatchDraw, EndBatchDraw
#include<conio.h>       //�������, kbhit, getch
#include <Windows.h>//GetTickCount(��ȡ�ӿ��������ڵļ�ʱ), mciSendString(ý����ƽӿ�)
#include<vector>        //C++�еĶ�̬����
#include "tools.h"        //putimagePNG2(ʶ��͸��ͨ��), playSound(��Ч���ᱻ���), rectIntersect(�жϾ����ཻ), preLoadSound(Ԥ������Ч)

using namespace std;  //��std�����ռ��е��������ƶ����뵱ǰ������, ������ÿ�ζ�����std::ǰ׺

#define WIN_WIDTH 1012//��Ϸ���ڿ��
#define WIN_HEIGHT 396//��Ϸ���ڸ߶�
#define ALL_ENEMY_COUNT 10//��������

int gameSpeed;//��Ϸ�ٶ�(��λ:mm/frame)
bool gameSpeedLevel1;//
bool gameSpeedLevel2;
bool gameSpeedLevel3;


IMAGE imgBgs[3];
int Bg_X[3];
int BgSpeed[3] = { 1,3,5 };//���������ٶ�

IMAGE imgHero[12];
int Hero_X;
int Hero_Y;
int Hero_frame;

IMAGE imgJump[12];
bool heroJump;
int jump, jumping, jumpMax, jumpMin;
int jumpFrame;
bool jumped;

IMAGE imgDown[2];
bool heroDown;
int downFrame;

int heroBoold;
int score;
int victoryScore = 666;//ʤ������( ���޸� )



IMAGE imgNumber[10];

enum enemyType{
	TORTOISE,//0
	LION,        //1
	HAPPYCAT,
	MM,
	RUNNER,//
	MEDICALPACKGE,//ҽ�ư�
	HURDLE1,//---�µ��������ɴ˲���, ��Ϊ��������趨��(�������createEnemy(), ���������������ز��ִ���)
	HURDLE2,
	HURDLE3,
	HURDLE4,
	ENEMY_TYPE_COUNT//ͳ�Ƶ�������
};

struct enemy {
	enemyType type;
	int frameSequence;
	int x, y;
	int speed;
	int damage;
	bool exist;
	bool hited;
	bool passed;
	int getScore;
};

enemy Enemies[ALL_ENEMY_COUNT];

vector<vector<IMAGE>>enemyImage;//���嶯̬��ά����, �д����������, �д�Ÿõ��˵�֡����

bool update;    //����֡ˢ��
int timer ;         //��ʱ��, �ۼ�һ������������update



 void init() {	
	//������Ϸ����
	initgraph(WIN_WIDTH, WIN_HEIGHT);

	//֡ˢ�¿���
	update = false;
	timer = 0;

	//������Դ�ļ���
	char name[99];
	//��������
	for (int i = 0; i < 3; i++) {		
		sprintf(name, "res/bg%03d.png", i + 1);
		loadimage(& imgBgs[i], name);	

		Bg_X[i] = 0;
	}

	//��ɫ�ܲ�
	for (int i = 0; i < 12; i++) {
		sprintf(name, "res/hero%d.png", i+1);
		loadimage(&imgHero[i], name);
	}
	Hero_X = WIN_WIDTH * 0.5 - imgHero[0].getwidth() * 0.5;
	Hero_Y = 355 - imgHero[0].getheight();
	Hero_frame = 0;

	//��ɫ��Ծ
	for (int i = 0; i < 12; i++) {
		sprintf(name, "res/g0%d.png", i + 1);
		loadimage(&imgJump[i], name);
	}
	jumpFrame = 0;
	jumped = false;//�Ƿ���Ծ����ߵ�
	heroJump = false;
	 jump = -7;                 //��Ծ����  (px/ÿ֡)
	 jumping = jump;
	 jumpMax = 355 - imgHero[0].getheight() - 140;
	 jumpMin = 355 - imgHero[0].getheight();

	 for (int i = 0; i < ALL_ENEMY_COUNT; i++) {
		 Enemies[i].exist = false;
	 }

	 //��ɫ�¶�
	 for (int i = 0; i < 2; i++) {
		 sprintf(name, "res/d%d.png", i + 1);
		 loadimage(&imgDown[i], name);
	 }
	 heroDown = false;
	 downFrame = 0;

	
	 //���ص���
	 IMAGE imgTortoise;
	 loadimage(&imgTortoise, "res/t1.png");    //����ͼƬ
	 vector<IMAGE> imgTortoiseArray;            //���嶯̬һά����
	 imgTortoiseArray.push_back(imgTortoise);//��ͼƬ����һά����
	 enemyImage.push_back(imgTortoiseArray);//�ٽ�һά����������ά����
	 
	 IMAGE imgLion;
	 vector<IMAGE> imgLionArray;
	 for (int i = 0; i < 6; i++) {
		 sprintf(name, "res/p%d.png", i + 1);
		 loadimage(&imgLion, name);
		 imgLionArray.push_back(imgLion);
	 }
	 enemyImage.push_back(imgLionArray);

	 IMAGE imgHappyCat;
	 vector<IMAGE> imgHappyCatArray;
	 for (int i = 0; i < 19; i++) {
		 sprintf(name, "res/ca%d.png", i + 1);
		 loadimage(&imgHappyCat, name);
		 imgHappyCatArray.push_back(imgHappyCat);
	 }
	 enemyImage.push_back(imgHappyCatArray);

	 IMAGE imgMM;
	 vector<IMAGE> imgMMArray;
	 for (int i = 0; i < 16; i++) {
		 sprintf(name, "res/mm%d.png", i + 1);
		 loadimage(&imgMM, name);
		 imgMMArray.push_back(imgMM);
	 }
	 enemyImage.push_back(imgMMArray);

	 IMAGE imgRunner;
	 vector<IMAGE> imgRunnerArray;
	 for (int i = 0; i < 6; i++) {
		 sprintf(name, "res/t%d.png", i + 2);
		 loadimage(&imgRunner, name);
		 imgRunnerArray.push_back(imgRunner);
	 }
	 enemyImage.push_back(imgRunnerArray);

	 IMAGE imgMedicalPackage;
	 loadimage(&imgMedicalPackage, "res/medP.png");
	 vector<IMAGE> imgMedicalPackageArray;
	 imgMedicalPackageArray.push_back(imgMedicalPackage);
	 enemyImage.push_back(imgMedicalPackageArray);

	 IMAGE imgHurdle;
	 for (int i = 0; i < 4; i++) {
		 vector<IMAGE> imgHurdleArray;
		 sprintf(name, "res/h%d.png", i + 1);
		 loadimage(&imgHurdle, name,63,260,true);//��ͼƬ�ȱ�����Ϊ63,260
		 imgHurdleArray.push_back(imgHurdle);
		 enemyImage.push_back(imgHurdleArray);

	 }

	 //���ؼƷ�����
	 for (int i = 0; i < 10; i++) {
		 sprintf(name,"res/sz/%d.png", i);
		 loadimage(& imgNumber[i], name);
	 }

	 gameSpeed = 20;
	 gameSpeedLevel1 = false;
	 gameSpeedLevel2 = false;
	 gameSpeedLevel3 = false;

	 heroBoold = 100;
	 score = 0;

	 preLoadSound("res/hit.mp3");//Ԥ������Ч
	 preLoadSound("res/recover.mp3");
}


 //--------------------------------------------------------------------------------------------


 int getDelay() {
	 static unsigned long long lastTime = 0;
	 unsigned long long currentTime = GetTickCount();
	 if (lastTime == 0) {
		 lastTime = currentTime;
		 return 0;
	 }
	 else {
		 int ret = currentTime - lastTime;
		 lastTime = currentTime;
		 return ret;
	 }
 }


void updateBg() { 
	putimagePNG2(Bg_X[0],   0,   &imgBgs[0]);
	putimagePNG2(Bg_X[1], 119, &imgBgs[1]);
	putimagePNG2(Bg_X[2], 330, &imgBgs[2]);	
}


void updateHero() {
	
	if (heroDown) {
		int y = 350 + 5 - imgDown[downFrame].getheight();
		putimagePNG2(Hero_X, y, &imgDown[downFrame]);
	}
	else if (heroJump) {
		putimagePNG2(Hero_X, Hero_Y, &imgJump[jumpFrame]);
	}	
	else {
		putimagePNG2(Hero_X, Hero_Y, &imgHero[Hero_frame]);
	}

}


void updateEnemy() {
	
	for (int i = 0; i < ENEMY_TYPE_COUNT; i++) {
		if (Enemies[i].exist) {
			putimagePNG2(Enemies[i].x, Enemies[i].y, WIN_WIDTH, &enemyImage[Enemies[i].type][Enemies[i].frameSequence]);

		}
	}
}


void keyEvent() {
	char ch;

	if (kbhit()) {
		ch = getch();
		if (ch == ' ' || ch == 'j') {
			if (heroDown) {  // ������¶�״̬�°�������Ծ��
				Hero_Y = 355 - imgHero[0].getheight();
				heroJump = true;
				update = true;
				heroDown = false;  // ��Ӧ��Ծ��Ӧ��ȡ���¶�״̬
			}
			else {
				heroJump = true;
				update = true;
			}
		}
		else if (ch == 'k') {
			downFrame = 0;
			heroDown = true;
			update = true;
		}
	}
}



void createEnemy() {
	int i;
	for (i = 0; i < ALL_ENEMY_COUNT; i++) {//����������, Ѱ���Ѿ�׼���õĵ���
		if (Enemies[i].exist == false) {//���ҵ�, ����i����ֵ�˳�
			break;
		}
		if (i >= ALL_ENEMY_COUNT) {
			return;
		}
	}

	//��ʼ���ϰ���i

	Enemies[i].exist = true;
	Enemies[i].hited=false;
	Enemies[i].frameSequence = 0;
	Enemies[i].type = (enemyType)(rand() % (ENEMY_TYPE_COUNT-3));//���ϰ����������
	if (Enemies[i].type == HURDLE1) {
		Enemies[i].type = (enemyType)((int)(Enemies[i].type)+rand() % 4);
	}
	Enemies[i].x = WIN_WIDTH;
	Enemies[i].y = 350 + 5 - enemyImage[Enemies[i].type][0].getheight();
	Enemies[i].speed = 0;
	Enemies[i].damage = 0;

	if (Enemies[i].type == TORTOISE) {
		Enemies[i].speed = 0;
		Enemies[i].damage = 15;
		Enemies[i].getScore = 10;
	}
	if (Enemies[i].type == LION) {
		Enemies[i].speed = 7;
		Enemies[i].damage = 10;
		Enemies[i].getScore = 15;
	}
	if (Enemies[i].type == HAPPYCAT) {
		Enemies[i].speed = 3;
		Enemies[i].damage = 20;
		Enemies[i].getScore = 30;
		Enemies[i].y = 350 + 15 - enemyImage[Enemies[i].type][0].getheight();
		mciSendString("play res/nihao.mp3 ", 0, 0, 0);
	}
	if (Enemies[i].type == MM) {
		Enemies[i].speed = 5;
		Enemies[i].damage = 20;
		Enemies[i].getScore = 30;
		mciSendString("play res/mm.mp3 ", 0, 0, 0);
	}
	if (Enemies[i].type == RUNNER) {
		Enemies[i].speed = 1;
		Enemies[i].damage = 15;
		Enemies[i].getScore = 15;
	}
	if (Enemies[i].type == MEDICALPACKGE) {
		Enemies[i].speed = 0;
		Enemies[i].damage = -30;
		Enemies[i].getScore = 0;
		Enemies[i].y = 150;
	}
	if (Enemies[i].type >= HURDLE1 && Enemies[i].type <= HURDLE4) {
		Enemies[i].speed = 0;
		Enemies[i].damage = 30;
		Enemies[i].getScore = 10;
		Enemies[i].y = 0;
	}

	Enemies[i].passed = false;

}


void checkHit() {
	for (int i = 0; i < ALL_ENEMY_COUNT; i++) {
		if (Enemies[i].exist && Enemies[i].hited == false) {
			int a1x, a1y, a2x, a2y;
			int off = 30;//�ж���ƫ����
			if (!heroDown) {
				a1x = Hero_X + off;
				a1y = Hero_Y + off;
				a2x = Hero_X + imgHero[Hero_frame].getwidth() - off;
				a2y = Hero_Y + imgHero[Hero_frame].getheight();
			}
			else {
				a1x = Hero_X + off;
				a1y = 350 - imgHero[downFrame].getheight() + off*2;
				a2x = Hero_X + imgHero[downFrame].getwidth() - off;
				a2y = 350;
			}
			IMAGE img = enemyImage[Enemies[i].type][Enemies[i].frameSequence];
			int b1x = Enemies[i].x + off;
			int b1y = Enemies[i].y + off;
			int b2x = Enemies[i].x + img.getwidth() - off;
			int b2y = Enemies[i].y + img.getheight() ;

			if (rectIntersect(a1x, a1y, a2x, a2y, b1x, b1y, b2x, b2y)) {
				heroBoold -= Enemies[i].damage;
				printf("��ǰѪ��%d\n", heroBoold);
				if (Enemies[i].type == MEDICALPACKGE) {
					mciSendString("play res/recover.mp3 ", 0, 0, 0);
					if (heroBoold >= 100) {
						heroBoold = 100;
					}
					Enemies[i].hited = true;
				}
				if (Enemies[i].type != MEDICALPACKGE) {
					playSound("res/hit.mp3");
					Enemies[i].hited = true;
				}
			}
		}
	}
}


void run() {

	//��������
	for (int i = 0; i < 3; i++) {
		Bg_X[i] -= BgSpeed[i];
		if(Bg_X[i] < -WIN_WIDTH){
			Bg_X[i] = 0;
		}
	}

	//��ɫ��Ծ
	if (heroJump) {
		Hero_Y += jumping;
		if (!jumped) {
			jumpFrame = 0;
		}
		else {
			jumpFrame = 9;
		}
		if (Hero_Y < jumpMax) {
			jumping = -jump;
			jumped = true;
		}
		if (Hero_Y > jumpMin-30) {
			jumped = false;
		}
		if (Hero_Y > jumpMin) {
			heroJump = false;
			jumping = jump;
		}
	}

	else if (heroDown) {
		static int count2 = 0;
		int delay[2] = { 4,35 };//�¶׼��ܳ���ʱ��
		count2++;
		if (count2 >= delay[downFrame]) {
			count2 = 0;
			downFrame++;
			if (downFrame >= 2) {
				downFrame = 0;
				heroDown = false;
			}
		}
	}

	else {
		//��ɫ֡����
		Hero_frame = (Hero_frame + 1) % 12;
	}

	static int frameCount = 0;
	static int eneemyFre = 100;
	frameCount++;
	if (frameCount > eneemyFre) {    //һ�������ˢ�µ���
		frameCount = 0;
		eneemyFre = 50 + rand() % 100;	

		createEnemy();	
	}

	//���³���������exist���˵������֡
	for (int i = 0; i < ALL_ENEMY_COUNT; i++) {
		if (Enemies[i].exist ) {
			Enemies[i].x -= Enemies[i].speed + BgSpeed[2];
			if (Enemies[i].x < -enemyImage[Enemies[i].type][0].getheight() * 2) {
				Enemies[i].exist = false;
			}
		}

		int len = enemyImage[Enemies[i].type].size();//��ȡ��ά�����е������������еĳ���
		Enemies[i].frameSequence = (Enemies[i].frameSequence + 1) % len;
	}

	//��ײ���ϵͳ
	checkHit();
}

void updateBoold() {
	drawBloodBar(10, 10, 200, 10, 2, BLUE, DARKGRAY, RED, heroBoold / 100.0);
}

void gameMenu() {//���滻
	loadimage(0, "res/menu.png");
	mciSendString("play res/menu1.mp3 repeat", 0, 0, 0);
	system("pause");
	mciSendString("play res/choose.mp3 ", 0, 0, 0);
	mciSendString("play res/start.mp3 ", 0, 0, 0);
	mciSendString("stop res/menu1.mp3 ", 0, 0, 0);
	mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
}

void checkGameOver() {
	//player����
	if (heroBoold <= 0) {
		//�������Ч
		mciSendString("stop res/bg.mp3 ", 0, 0, 0);
		mciSendString("play res/ngm.mp3 ", 0, 0, 0);
		mciSendString("play res/gameOver.mp3 ", 0, 0, 0);
		Sleep(2000);
		init();
		mciSendString("play res/gameOver2.mp3 ", 0, 0, 0);
		loadimage(0, "res/over.png");
		FlushBatchDraw();//����ˢ��ͼƬ����
		system("pause");
		mciSendString("play res/choose.mp3 ", 0, 0, 0);
		mciSendString("play res/start.mp3 ", 0, 0, 0);
		mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
	}

	//playerʤ��
	if (score >= victoryScore) {
		//�������Ч
		score=victoryScore;
		FlushBatchDraw();
		mciSendString("stop res/bg.mp3 ", 0, 0, 0);
		mciSendString("play res/victory.wav ", 0, 0, 0);
		mciSendString("play res/victory1.wav ", 0, 0, 0);
		Sleep(2000);
		init();
		mciSendString("play res/victory2.wav ", 0, 0, 0);
		loadimage(0, "res/victory.png");//���滻
		system("pause");
		mciSendString("play res/choose.mp3 ", 0, 0, 0);
		mciSendString("play res/start.mp3 ", 0, 0, 0);
		mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
	}

}

void checkScore() {
	for (int i = 0; i < ALL_ENEMY_COUNT; i++) {
		if (Enemies[i].exist 
			&& Enemies[i].passed == false 
			&& Enemies[i].hited == false
			&& Enemies[i].x + enemyImage[Enemies[i].type][0].getwidth() < Hero_X) {
			score+= Enemies[i].getScore;
			Enemies[i].passed = true;
			printf("��ǰscore: %d\n", score);
		}
		static int scoreTemp = 0;
		if (score > scoreTemp) {
			scoreTemp = score;
			mciSendString("play res/getScore.mp3 ", 0, 0, 0);
		}
	}

	//��Ϸ�ٶȿ���(�����Ч, �������)(�������Դ��Ż�)
	//��ֵ����:  32(��֡����), 26-20(�����ٶ�), 15(��΢����), 14-0(�������) )(���ݴ�����ɾ���ܻ��б䶯)
	if (score >= victoryScore / 20 && !gameSpeedLevel1) {
		gameSpeed = 15;
		printf("gameSpeed: %d\n", gameSpeed);
		gameSpeedLevel1 = true;
		mciSendString("play res/speed1.mp3 ", 0, 0, 0);
	}
	else if (score >= victoryScore / 2 && !gameSpeedLevel2) {
		gameSpeed = 14;
		printf("gameSpeed: %d\n", gameSpeed);
		gameSpeedLevel2 = true;
		mciSendString("play res/speed2.mp3 ", 0, 0, 0);
	}
	else if (score >= victoryScore / 1.2 && !gameSpeedLevel3) {
		gameSpeed = 0;
		printf("gameSpeed: %d\n", gameSpeed);
		gameSpeedLevel3 = true;
	}
}

void updateScore() {
	//�������λ�ϵ����� : [�÷�] => [�ַ���]  => [��'����'-'0'] => [����(ASCLL��ԭ��)]
	
	char str[8];
	sprintf(str, "%d", score);

	int x = 20;
	int y = 25;

	for (int i = 0; str[i] != '\0'; i++) {
		int sz = str[i] - '0';
		putimagePNG(x, y, &imgNumber[sz]);
		x += imgNumber[sz].getwidth() + 6;
	}
	
}

//----------------------------------------------------------------------------------------------


int main() {
	init();

	gameMenu();

	while (1) {		

		keyEvent();

		//֡���ϵͳ
		timer += getDelay();//���޸�

		if (timer > gameSpeed) {
			timer = 0;
			update = true;
		}

		if (update) {
			update = false;

			BeginBatchDraw();//���忪ʼ
			updateBg();
			updateHero();
			updateEnemy();
			updateBoold();
			updateScore();
			EndBatchDraw();//�������

			checkGameOver();
			checkScore();

			run();
		}

		
	}
	
	system("pause");

	return 0;
}