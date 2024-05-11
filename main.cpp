/*
  24.4.5
  
 (开发过程中的自言自语)

 图形库 : easyx

 接口说明 : (带*为自定义函数)

	初始化init*
	  创建游戏窗口initgraph
	  加载背景/角色图片资源loadimage
	  获取图片的宽高数据getwidth, getheight

    控制帧间隔时间getDelay*
	  获取系统从启动到现在的毫秒数GetTickCount

	处理用户按键keyEvent*
	  kbhit  : 当检测到有任意按键输入, 返回ture, 可以避免阻塞程序
	  getch : 用于获取键盘上的字符, 与scanf相比它不需要按下回车键就可输入成功

	渲染图片updateBg*updateHero*updateEnemy*
	  确定图片加载位置putimage 
	  BeginBatchDraw和EndBatchDraw : 双缓冲技术, 减少播放帧动画时画面闪烁
  
	更新游戏的实时状态run*
     错落运动 : 每一张图片的x轴减去不同的数值
	 循环滚动 : 背景运动完一整个游戏窗口的宽度后将其重置
	 帧动画  : 每调用一次run()帧数加一, 使用模运算让帧数重置
	 更新敌人
	 碰撞检测
	 
 碎碎念:

    01
	动态数组std::vector ，它可以根据需要自动调整其大小,  从而节约内存空间
    语法 : std::vector<int> myVector;
	使用 : myVector.push_back( a[1] );

	02
	在c++编译环境里enum类型需要强转才能当int用, c语言好像可以直接用

	03
	关于C++的动态数组功能, 可以用C语言的malloc()和free()函数来实现 (指针和内存分配)
	但是, 指针尊都太麻烦了(个人感觉)
	用vector真的爽好吗

 未来改进 :(也可能不改了)

     1)优化人物跳跃(跳跃加速度, 跳跃动画)
	 2)增加敌人种类, 增加游戏道具
	 3)优化音效
	 4)优化菜单
	 5)增加BOSS系统

 打包流程 : 

	 1.安装IstallerProjects插件
	 2.创建新项目模板Setup Project
	 3.整合游戏资源并导入File System
	 4.创建快捷方式图标
	 5.将代码切换至Release模式, 更改项目属性(多字节字符集, 关闭sdl检查, 运行库(多线程/MT))
	 6.检查代码运行
	 7.点击重新生成并找到.exe文件

	 (以下弃用)
	  1. 将源代码文件全部复制到一个文件夹中
	  2. 打开命令行窗口, 进入该文件夹
	  3. 输入命令 : "C:\Program Files (x86)\Dev-Cpp\MinGW\bin\g++.exe" main.cpp -o main.exe -lgraphics -lconio -lwinmm -lstdc++ -luser32 -lgdi32 -lopengl32 -static -s -O2
	  4. 等待编译完成
	  5. 输入命令 : "upx -9 main.exe" (压缩可执行文件)
	  6. 等待压缩完成
	  7. 得到压缩后的可执行文件main.exe

*/



/*
	此项目根据B站视频教程编写，仅供学习参考。

	视频地址(BV号)：BV1XN4y1K7gW

  【C语言项目实战】天天酷跑小游戏，C语言项目实战项目详细教学，适合小白练手项目，快速掌握C语言！

*/



/*
	 # 代码说明

	## 简介
	这是一个基于C语言和EasyX图形库的基础跑酷游戏(小部分用了C++特性)。
	游戏中包括角色奔跑、跳跃、下蹲和障碍物的生成与规避等功能。
	躲避障碍物获得分数, 积累分数以获取胜利。


	## 使用的库

	- `stdio.h`: 标准输入输出库
	- `graphics.h`: EasyX图形库，用于处理图片、初始化图形窗口等
	- `conio.h`: 控制台输入输出库，用于处理键盘输入
	- `Windows.h`: Windows操作系统API库，用于获取系统时间
	- `vector`: 标准模板库中的动态数组
	- `tools.h`: 自定义工具函数库(不是我弄的, 找UP主白嫖的, 其中一些函数的原理我没弄懂, 管他呢, 用就完事了)

	## 代码结构

	- `init()`: 初始化游戏窗口、加载资源文件、初始化角色、初始化敌人、初始化计分数字、预加载音效
	- `getDelay()`: 获取系统从启动到现在的毫秒数
	- `updateBg()`: 更新背景动画
	- `updateHero()`: 更新角色动画
	- `updateEnemy()`: 更新敌人动画
	- `keyEvent()`: 处理用户按键事件
	- `run()`: 主循环，控制游戏的实时状态
	- `main()`: 程序入口

	## 游戏流程

	初始化游戏窗口和资源。
	进入游戏菜单界面。
	进入游戏主循环，在每帧更新中处理角色和敌人的移动，并进行碰撞检测。
	根据游戏状态判断游戏是否结束，展示游戏结束画面。

	## 游戏规则

	游戏根据角色与敌人的碰撞情况进行计分和生命值的变更，当生命值为零或达到一定分数时游戏结束。

*/



#include<stdio.h>         //......rand, 
#include<graphics.h>   //处理图片, initgraph, loadimage, getwidth, getheight, putimage, BeginBatchDraw, EndBatchDraw
#include<conio.h>       //处理键控, kbhit, getch
#include <Windows.h>//GetTickCount(获取从开机到现在的记时), mciSendString(媒体控制接口)
#include<vector>        //C++中的动态数组
#include "tools.h"        //putimagePNG2(识别透明通道), playSound(音效不会被打断), rectIntersect(判断矩形相交), preLoadSound(预加载音效)

using namespace std;  //将std命名空间中的所有名称都引入当前作用域, 而不必每次都加上std::前缀

#define WIN_WIDTH 1012//游戏窗口宽度
#define WIN_HEIGHT 396//游戏窗口高度
#define ALL_ENEMY_COUNT 10//敌人总数

int gameSpeed;//游戏速度(单位:mm/frame)
bool gameSpeedLevel1;//
bool gameSpeedLevel2;
bool gameSpeedLevel3;


IMAGE imgBgs[3];
int Bg_X[3];
int BgSpeed[3] = { 1,3,5 };//背景滚动速度

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
int victoryScore = 666;//胜利分数( 待修改 )



IMAGE imgNumber[10];

enum enemyType{
	TORTOISE,//0
	LION,        //1
	HAPPYCAT,
	MM,
	RUNNER,//
	MEDICALPACKGE,//医疗包
	HURDLE1,//---新敌人种类由此插入, 因为下面代码设定了(详见函数createEnemy(), 将敌人种类随机相关部分代码)
	HURDLE2,
	HURDLE3,
	HURDLE4,
	ENEMY_TYPE_COUNT//统计敌人种类
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

vector<vector<IMAGE>>enemyImage;//定义动态二维数组, 行代表敌人类型, 列存放该敌人的帧序列

bool update;    //控制帧刷新
int timer ;         //计时器, 累计一定毫秒数启动update



 void init() {	
	//创建游戏窗口
	initgraph(WIN_WIDTH, WIN_HEIGHT);

	//帧刷新控制
	update = false;
	timer = 0;

	//储存资源文件名
	char name[99];
	//背景动画
	for (int i = 0; i < 3; i++) {		
		sprintf(name, "res/bg%03d.png", i + 1);
		loadimage(& imgBgs[i], name);	

		Bg_X[i] = 0;
	}

	//角色跑步
	for (int i = 0; i < 12; i++) {
		sprintf(name, "res/hero%d.png", i+1);
		loadimage(&imgHero[i], name);
	}
	Hero_X = WIN_WIDTH * 0.5 - imgHero[0].getwidth() * 0.5;
	Hero_Y = 355 - imgHero[0].getheight();
	Hero_frame = 0;

	//角色跳跃
	for (int i = 0; i < 12; i++) {
		sprintf(name, "res/g0%d.png", i + 1);
		loadimage(&imgJump[i], name);
	}
	jumpFrame = 0;
	jumped = false;//是否跳跃到最高点
	heroJump = false;
	 jump = -7;                 //跳跃幅度  (px/每帧)
	 jumping = jump;
	 jumpMax = 355 - imgHero[0].getheight() - 140;
	 jumpMin = 355 - imgHero[0].getheight();

	 for (int i = 0; i < ALL_ENEMY_COUNT; i++) {
		 Enemies[i].exist = false;
	 }

	 //角色下蹲
	 for (int i = 0; i < 2; i++) {
		 sprintf(name, "res/d%d.png", i + 1);
		 loadimage(&imgDown[i], name);
	 }
	 heroDown = false;
	 downFrame = 0;

	
	 //加载敌人
	 IMAGE imgTortoise;
	 loadimage(&imgTortoise, "res/t1.png");    //加载图片
	 vector<IMAGE> imgTortoiseArray;            //定义动态一维数组
	 imgTortoiseArray.push_back(imgTortoise);//将图片推至一维数组
	 enemyImage.push_back(imgTortoiseArray);//再将一维数组推至二维数组
	 
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
		 loadimage(&imgHurdle, name,63,260,true);//将图片等比缩放为63,260
		 imgHurdleArray.push_back(imgHurdle);
		 enemyImage.push_back(imgHurdleArray);

	 }

	 //加载计分数字
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

	 preLoadSound("res/hit.mp3");//预加载音效
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
			if (heroDown) {  // 如果在下蹲状态下按下了跳跃键
				Hero_Y = 355 - imgHero[0].getheight();
				heroJump = true;
				update = true;
				heroDown = false;  // 响应跳跃后应该取消下蹲状态
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
	for (i = 0; i < ALL_ENEMY_COUNT; i++) {//遍历待机池, 寻找已经准备好的敌人
		if (Enemies[i].exist == false) {//若找到, 则保留i的数值退出
			break;
		}
		if (i >= ALL_ENEMY_COUNT) {
			return;
		}
	}

	//初始化障碍物i

	Enemies[i].exist = true;
	Enemies[i].hited=false;
	Enemies[i].frameSequence = 0;
	Enemies[i].type = (enemyType)(rand() % (ENEMY_TYPE_COUNT-3));//将障碍物类型随机
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
			int off = 30;//判定框偏移量
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
				printf("当前血量%d\n", heroBoold);
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

	//背景滚动
	for (int i = 0; i < 3; i++) {
		Bg_X[i] -= BgSpeed[i];
		if(Bg_X[i] < -WIN_WIDTH){
			Bg_X[i] = 0;
		}
	}

	//角色跳跃
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
		int delay[2] = { 4,35 };//下蹲技能持续时间
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
		//角色帧动画
		Hero_frame = (Hero_frame + 1) % 12;
	}

	static int frameCount = 0;
	static int eneemyFre = 100;
	frameCount++;
	if (frameCount > eneemyFre) {    //一定间隔后刷新敌人
		frameCount = 0;
		eneemyFre = 50 + rand() % 100;	

		createEnemy();	
	}

	//更新池子里所有exist敌人的坐标和帧
	for (int i = 0; i < ALL_ENEMY_COUNT; i++) {
		if (Enemies[i].exist ) {
			Enemies[i].x -= Enemies[i].speed + BgSpeed[2];
			if (Enemies[i].x < -enemyImage[Enemies[i].type][0].getheight() * 2) {
				Enemies[i].exist = false;
			}
		}

		int len = enemyImage[Enemies[i].type].size();//获取二维数组中敌人类型所在行的长度
		Enemies[i].frameSequence = (Enemies[i].frameSequence + 1) % len;
	}

	//碰撞检测系统
	checkHit();
}

void updateBoold() {
	drawBloodBar(10, 10, 200, 10, 2, BLUE, DARKGRAY, RED, heroBoold / 100.0);
}

void gameMenu() {//待替换
	loadimage(0, "res/menu.png");
	mciSendString("play res/menu1.mp3 repeat", 0, 0, 0);
	system("pause");
	mciSendString("play res/choose.mp3 ", 0, 0, 0);
	mciSendString("play res/start.mp3 ", 0, 0, 0);
	mciSendString("stop res/menu1.mp3 ", 0, 0, 0);
	mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
}

void checkGameOver() {
	//player死亡
	if (heroBoold <= 0) {
		//待添加音效
		mciSendString("stop res/bg.mp3 ", 0, 0, 0);
		mciSendString("play res/ngm.mp3 ", 0, 0, 0);
		mciSendString("play res/gameOver.mp3 ", 0, 0, 0);
		Sleep(2000);
		init();
		mciSendString("play res/gameOver2.mp3 ", 0, 0, 0);
		loadimage(0, "res/over.png");
		FlushBatchDraw();//即刻刷新图片缓存
		system("pause");
		mciSendString("play res/choose.mp3 ", 0, 0, 0);
		mciSendString("play res/start.mp3 ", 0, 0, 0);
		mciSendString("play res/bg.mp3 repeat", 0, 0, 0);
	}

	//player胜利
	if (score >= victoryScore) {
		//待添加音效
		score=victoryScore;
		FlushBatchDraw();
		mciSendString("stop res/bg.mp3 ", 0, 0, 0);
		mciSendString("play res/victory.wav ", 0, 0, 0);
		mciSendString("play res/victory1.wav ", 0, 0, 0);
		Sleep(2000);
		init();
		mciSendString("play res/victory2.wav ", 0, 0, 0);
		loadimage(0, "res/victory.png");//待替换
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
			printf("当前score: %d\n", score);
		}
		static int scoreTemp = 0;
		if (score > scoreTemp) {
			scoreTemp = score;
			mciSendString("play res/getScore.mp3 ", 0, 0, 0);
		}
	}

	//游戏速度控制(添加音效, 表情包等)(参数调试待优化)
	//阈值测试:  32(掉帧严重), 26-20(舒适速度), 15(略微提速), 14-0(大幅提速) )(根据代码增删可能会有变动)
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
	//分离各个位上的数字 : [得分] => [字符串]  => [用'数字'-'0'] => [数字(ASCLL码原理)]
	
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

		//帧间隔系统
		timer += getDelay();//待修改

		if (timer > gameSpeed) {
			timer = 0;
			update = true;
		}

		if (update) {
			update = false;

			BeginBatchDraw();//缓冲开始
			updateBg();
			updateHero();
			updateEnemy();
			updateBoold();
			updateScore();
			EndBatchDraw();//缓冲结束

			checkGameOver();
			checkScore();

			run();
		}

		
	}
	
	system("pause");

	return 0;
}