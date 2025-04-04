/***********************************************************************************************
045:魔兽世界三(开战)
总时间限制: 2000ms 内存限制: 65536kB 

描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20)。
红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。

两军的司令部都会制造武士。武士一共有dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n 个武士，编号就是n。同样，蓝方制造出来的第n 个武士，编号也是n。

武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。
武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
sword的攻击力是使用者当前攻击力的20%(去尾取整)。
bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。
arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。

武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：
1.在奇数编号城市，红武士先发起攻击
2.在偶数编号城市，蓝武士先发起攻击
3.战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。若有多支arrow，用过的排在前面。
排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。每使用一件武器，被攻击者生命值要减去武器攻击力。
如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。
4.双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。
如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。
5.如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。
6.有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。
7.战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。如果有多件arrow，优先缴获没用过的。
8.如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。

不同的武士有不同的特点。
编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。

编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。

编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。

编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每前进一步忠诚度就降低K。
忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。

wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。
如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。

以下是不同时间会发生的不同事件：
在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf 的顺序制造武士。

制造武士需要生命元。
制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。
如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。

在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。
在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。 
在每个小时的第40分：在有两个武士的城市，会发生战斗。 
在每个小时的第50分，司令部报告它拥有的生命元数量。
在每个小时的第55分，每个武士报告其拥有的武器情况。
武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。 
任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。
任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：
1) 武士降生
输出样例：000:00 blue dragon 1 born 
表示在0点0分，编号为1的蓝魔dragon武士降生

如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24
表示该lion降生时的忠诚度是24

2) lion逃跑
输出样例：000:05 blue lion 1 ran away 
表示在0点5分，编号为1的蓝魔lion武士逃走

3) 武士前进到某一城市
输出样例：
000:10 red iceman 1 marched to city 1 with 20 elements and force 30
表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
对于iceman,输出的生命值应该是变化后的数值

4) wolf抢敌人的武器
000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4
表示在0点35分，4号城市中，红魔1号武士wolf 抢走蓝魔2号武士dragon 3个bomb。为简单起见，武器不写复数形式

5) 报告战斗情况
战斗只有3种可能的输出结果：
000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements 
表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20
000:40 both red iceman 1 and blue lion 12 died in city 2
注意，把红武士写前面
000:40 both red iceman 1 and blue lion 12 were alive in city 2
注意，把红武士写前面

6) 武士欢呼
输出样例：003:40 blue dragon 2 yelled in city 4

7) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值

8) 司令部被占领
输出样例：003:10 blue headquarter was taken

9)司令部报告生命元数量
000:50 100 elements in red headquarter 
000:50 120 elements in blue headquarter
表示在0点50分，红方司令部有100个生命元，蓝方有120个

10)武士报告情况
000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements
为简单起见，武器都不写复数形式。elements一律写复数，哪怕只有1个
交代武器情况时，次序依次是：sword,bomb, arrow。

输出事件时：
首先按时间顺序输出；
同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
在一次战斗中有可能发生上面的 5 至 6 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。
两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。
对于同一城市，同一时间发生的事情，先输出红方的，后输出蓝方的。
显然，8号事件发生之前的一瞬间一定发生了7号事件。输出时，这两件事算同一时间发生，但是应先输出7号事件
虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。


输入
第一行是t,代表测试数据组数
每组样例共三行。

第一行，4个整数 M,N,K, T。其含义为：
每个司令部一开始都有M个生命元( 1 <= M <= 100000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
lion每前进一步，忠诚度就降低K。(0<=K<=100)
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200


输出
对每组数据，先输出一行：
Case n:
如对第一组数据就输出 Case 1:
然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。

样例输入
1
20 1 10 400
20 20 30 10 20
5 5 5 5 5

样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:50 20 elements in red headquarter
000:50 10 elements in blue headquarter
000:55 blue lion 1 has 0 sword 1 bomb 0 arrow and 10 elements
001:05 blue lion 1 ran away
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
002:50 20 elements in red headquarter
002:50 10 elements in blue headquarter
003:50 20 elements in red headquarter
003:50 10 elements in blue headquarter
004:50 20 elements in red headquarter
004:50 10 elements in blue headquarter
005:50 20 elements in red headquarter
005:50 10 elements in blue headquarter
提示
请注意浮点数精度误差问题。OJ上的编译器编译出来的可执行程序，在这方面和你电脑上执行的程序很可能会不一致。
5 * 0.3 的结果，有的机器上可能是 15.00000001，去尾取整得到15,有的机器上可能是14.9999999，去尾取整后就变成14。
因此,本题不要写 5 * 0.3，要写 5 * 3 / 10。
************************************************************************************************/
//引入相关库
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<iomanip>
#include<cmath>
using namespace std;

//全局变量定义
vector<string> name = { "dragon", "ninja", "iceman", "lion", "wolf" };
vector<string> arm = {"sword","bomb","arrow"};
vector<string> nameHq = {"red", "blue"};
vector<int> strengthHq(5);
vector<int> attckHq(5);
vector<vector<int>> order = {{2,3,4,1,0},{3,0,1,2,4}};
int elementLife=0, flagRed=1, flagBlue=1;

//声明几个重要的类
class Headquarters;
class Warrior;
class Arm;
class City;


//继续定义全局变量
int cityNum = 0;
vector<City *> allCity(cityNum);//注意后面要resize，这个cityNum只在开始定义allcity时起作用
vector<Arm *> armBin;//收集废弃的武器
vector<Warrior *> deadWarrior;//收集死掉的战士
int subLoyalty = 1;
int T = 0;
vector<int> minute = {0, 5, 10, 35, 40, 50, 55};
int hm = T/60;//hour max小时数，无需向上取整，因为时间从0开始
int mr = T % 60;//minute remain剩下的时间
bool GAMEOVER = false;//游戏结束标志

////////////////////////////////define headquarter
class Headquarters{
	private:
		string headquartersName;//司令部的名称(红蓝)
		int element;//司令部的生命元
		int time;//时间
		vector<string> warriorName;//每种战士的名称
		vector<int> warriorStrength;//每种战士的生命值
		vector<int> warriorCount;//每种战士个数
		vector<int> warriorOrder;//创造战士的顺序，即全局变量order的元素，本来在headquarters构造函数里作为局部变量，现在为了方便拿出来作为类的成员变量
		int count;//已经制造的战士总个数（从1开始）以及
		int num;//应该制造的战士种类（从0到4）
		void produceWarrior();//已经制造的战士总个数和应该制造的战士种类来制造战士的函数
		vector<shared_ptr<Warrior>> allWarrior;//all the warriors
	public:
		int decideWarrior();//考虑是否有足够的生命元继续制造战士，以及应该制造什么
		Headquarters(string headquartersName, int element, vector<string> name, vector<int> strength);//构造函数，用来初始化
		virtual void printInfo() const{}
		int getElement() const{return element;}
		int getCount() const{return count;}//获取当前已经制造的战士个数
		vector<int> getWarriorStrength() const{return warriorStrength;}//每种战士的生命值
		void createWarrior(int num);//根据目前num来决定创造哪一种战士，加入到vector中
		void copeDeadWarrior();//定期处理死掉的战士，放到全局变量中

};
////////////////////////////////////////////////

//////////////////////////////define armament
class Arm
{
public:
	Arm(const string & k):kind(k){avail = true;}
	string getKind(){return kind;}
	virtual void attackOnce(Warrior *pObj) {}//进攻 //传入实参还是指针呢,就传入指针
	virtual void setAttack(Warrior *owner){}
	virtual void isAvail(){}
	virtual void wear(){}
	void setOwner(Warrior *owner){this->owner = owner;}
	Warrior *getOwner(){return owner;}
protected:
	int attack;//attack
	string kind;
	Warrior *owner;
	bool avail;//是否可用，available
};

//define sword
class Sword: public Arm 
{
public:
	Sword():Arm("sword"){}
	virtual void attackOnce(Warrior *pObj);
	virtual void setAttack(){attack = owner->getAttack() * 2 / 10;}
	virtual void isAvail(){}
};

//define bomb
class Bomb: public Arm 
{
public:
	Bomb():Arm("bomb"){}
	virtual void attackOnce(Warrior *pObj);
	virtual void setAttack(){attack = owner->getAttack() * 4 / 10;}
	virtual void isAvail(){if(usage == 1){avail = false;}}
private:
	int usage;
};

//define arrow
class Arrow: public Arm 
{
public:
	Arrow():Arm("arrow"){}
	virtual void attackOnce(Warrior *pObj);
	virtual void setAttack(){attack = owner->getAttack() * 3 / 10;}
	virtual void isAvail(){if(usage == 2){avail = false;}}
private:
	int usage;
};
////////////////////////////////////////////////

///////////////////////////////define warrior
class Warrior
{
public:
	Warrior(){dead = false;}
	Warrior(const Headquarters & hq):id(hq.getCount()){dead = false;}
	int getId(){return id;}
	int getStrength(){return strength;}
    int getAttack(){return attack;}
	bool getDead(){return dead;}
	vector<shared_ptr<Arm>> getArm(){return arm;}
	void showArm() const;
	void equipArm(int i);
	virtual void printInfo() const {}
	void isDead();//在isHurt里被调用，是负责处理后事的
	void isHurt(int a);//受到攻击的时候调用，a是伤害
	virtual void march(){}
protected:
	int id;//编号
	int strength;//生命值
    int attack;//攻击力
	bool dead;//是否死亡，初始构造为false
	vector<shared_ptr<Arm>> arm;//
	City *pos;//目前处于的城市
	 
};

//define dragon
//dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
//dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
//如果造出的是dragon，那么还要输出一行，例：
//It has a arrow,and it's morale is 23.34
//表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
class Dragon: public Warrior
{
public:
	Dragon(const Headquarters & hq): Warrior(hq)
	{	
		equipArm(id % 3);
		int ele = hq.getElement();
		strength = hq.getWarriorStrength()[0];
		morale = (float)ele/strength;
	}
	float getMorale() const{return morale;}
	void printInfo() const override
	{
		(*this).showArm();
		cout << "it's morale is " << (*this).getMorale() << endl;
	}
private:
	float morale;
};

//define ninja
//ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
//如果造出的是ninja，那么还要输出一行，例：
//It has a bomb and a arrow
//表示该ninja降生时得到了bomb和arrow。
class Ninja: public Warrior
{
public:
	Ninja(const Headquarters & hq):Warrior(hq)
	{
		equipArm(id % 3);
		equipArm(id % 3 + 1);
		strength = hq.getWarriorStrength()[1];
	}
	void printInfo() const override
	{
		(*this).showArm();
	}
};

//define iceman
//iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
//如果造出的是iceman，那么还要输出一行，例：
//It has a sword
//表示该iceman降生时得到了sword。
class Iceman: public Warrior
{
public:
	Iceman(const Headquarters & hq):Warrior(hq)
	{
		equipArm(id % 3);
		strength = hq.getWarriorStrength()[2];
	}
	void printInfo() const override
	{
		(*this).showArm();
	}
};

//define lion
//lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
//如果造出的是lion，那么还要输出一行，例：
//It's loyalty is 24
//表示该lion降生时的忠诚度是24。
class Lion: public Warrior
{
private:
	int loyalty;
public:
	Lion(const Headquarters & hq):loyalty(hq.getElement())
	{
		strength = hq.getWarriorStrength()[3];
	}
	void printInfo() const override
	{
		cout << "it has loyalty of " << loyalty << endl;
	}
};

//define wolf
//wolf没特点。
class Wolf: public Warrior
{
public:	
	Wolf(const Headquarters & hq)
	{
		strength = hq.getWarriorStrength()[4];
	}
	void printInfo() const override{}
};
////////////////////////////////////////////////


////////////////////////////////////////////////
class City
{
public:
	City()//initialize
	{
		pRed = NULL;
		pBlue = NULL;
	}
	bool checkTwo(){if(pRed != NULL && pBlue != NULL){return true;}else{return false;}}//检查是否有一红一蓝战士，可以打架
    void fight(Warrior *pRed, Warrior *pBlue);
	void redArrive(Warrior *pRed){this->pRed = pRed;}
	void blueArrive(Warrior *pBlue){this->pBlue = pBlue;}
private:
	Warrior *pRed;
	Warrior *pBlue;

};
////////////////////////////////////////////////


///////////////////////////////////////////////functions of headquarters
//create a headquarters
Headquarters::Headquarters(string headquartersName, int element, vector<string> name, vector<int> strength):time(0),count(0),num(0){
	warriorOrder.resize(5);
	this->headquartersName = headquartersName;
	this->element = element;
	if (this->headquartersName == "red")//红方司令部
	{//制造战士的顺序
		warriorOrder = order[0];
	}
	else//蓝方司令部
	{//制造战士的顺序
		warriorOrder = order[1];
	}
	warriorName.resize(5);
	warriorStrength.resize(5);
	warriorCount.resize(5);
	for(int i = 0; i < 5; ++i){
		warriorCount[i] = 0;
		warriorName[i] = name[warriorOrder[i]];
		warriorStrength[i] = strength[warriorOrder[i]];
	}
}

//produce warrior除了调用create warrior以外，还承担了输出时间，当前情况的任务，属于整体性的函数
void Headquarters::produceWarrior(){
	++warriorCount[num];
	element -= warriorStrength[num];

	//cout << setfill('0') << setw(3) << time << " " << headquartersName << " " << warriorName[num] << " ";
	cout << " " << headquartersName << " " << warriorName[num] << " ";
	++count;

	cout << count << "born with strength " << warriorStrength[num] << "," << warriorCount[num] << " " << warriorName[num] << " in " << headquartersName << "headquarters" << endl;
	createWarrior(num);
	++time;
	num = (++num) % 5;
}

//create warrior真正创造战士，并将它加入到headquarters的战士列表里的函数
void Headquarters::createWarrior(int num)
{
	switch (warriorOrder[num])
	{//vector<string> name = { "dragon", "ninja", "iceman", "lion", "wolf" };
		case 0:
		{
			auto pDragon = make_shared<Dragon>(static_cast<const Headquarters &>(*this));
			allWarrior.push_back(pDragon);
			pDragon->printInfo();
			break;
		}
		case 1:
		{
			auto pNinja = make_shared<Ninja>(static_cast<const Headquarters &>(*this));
			allWarrior.push_back(pNinja);
			pNinja->printInfo();
			break;
		}
		case 2:
		{
			auto pIceman = make_shared<Iceman>(static_cast<const Headquarters &>(*this));
			allWarrior.push_back(pIceman);
			pIceman->printInfo();
			break;
		}
		case 3:
		{
			auto pLion = make_shared<Lion>(static_cast<const Headquarters &>(*this));
			allWarrior.push_back(pLion);
			pLion->printInfo();
			break;
		}
		case 4:
		{
			auto pWolf = make_shared<Wolf>(static_cast<const Headquarters &>(*this));
			allWarrior.push_back(pWolf);
			pWolf->printInfo();
			break;
		}
	}

}
//int 是是否需要总部继续制造战士的信号，1 or 0
int Headquarters::decideWarrior(){
	int flagCon = 1;//决定是否继续的旗子，默认为1
	int numTmp = num;
	if(element >= warriorStrength[num]){
		produceWarrior();
	}
	else{
		for(int i = 1; i <= 5; ++i)
		{	
			numTmp = (numTmp + i) % 5;
			if(element >= warriorStrength[(numTmp + i) % 5])
				break;
		}
		
		if(numTmp == num){
			flagCon = 0;
		}
		
		if(flagCon == 0){
			//cout << setfill('0') << setw(3) << time << " " << headquartersName << " headquarter stops making warriors" << endl;
			cout << " " << headquartersName << " headquarter stops making warriors" << endl;
		}
		else{
			num = numTmp;
			produceWarrior();
		}
	}
	return flagCon;

}

//自己写的算法，看看有没有问题
void Headquarters::copeDeadWarrior()//定期处理死掉的战士
{
	auto firstDead = allWarrior.begin();

	for(auto it = allWarrior.begin(); it !=allWarrior.end(); ++it)
	{
		if(!(*it)->getDead())
		{
			if(it != firstDead){iter_swap(it, firstDead);}
			++firstDead;
		}
	}

	for(auto it = firstDead; it != allWarrior.end(); ++it){deadWarrior.push_back(it->get());}

	allWarrior.erase(firstDead, allWarrior.end());
}
/////////////////////////////////////////

/////////////////////////////////////////functions of armament

void Sword::attackOnce(Warrior *pObj)
{
	pObj->isHurt(attack);
}

void Bomb::attackOnce(Warrior *pObj)
{
	pObj->isHurt(attack);
}

void Arrow::attackOnce(Warrior *pObj)
{
	pObj->isHurt(attack);
}

/////////////////////////////////////////


/////////////////////////////////////////functions of warrior
void Warrior::equipArm(int i)
{
	switch(i)
	{
		case 0:
			arm.push_back(make_shared<Sword>());
			break;
		case 1:
			arm.push_back(make_shared<Bomb>());
			break;
		case 2:
			arm.push_back(make_shared<Arrow>());
			break;
	}
};

void Warrior::showArm() const
{
	int n = arm.size();
	cout << "It has a ";
	for(int i = 0; i < n; ++i)
	{
		if(i < n - 2){cout << arm[i]->getKind() << ", a ";}
		else if(i == n - 2){cout << arm[i]->getKind() << " and a ";}
		else{cout << arm[i]->getKind() << endl;}
	}
}

void Warrior::isDead(){dead = true;}//只负责死，由总部来处理后事，由于战士的vector在headquarters

void Warrior::isHurt(int a)
{
	if(strength <= a){strength = 0;isDead();}else{strength -= a;}
}

void Warrior::march()
{

}
//////////////////////////////////////////

//////////////////////////////////////////city functions
void City::fight(Warrior *red, Warrior *blue)
{

}
//////////////////////////////////////////


//////////////////////////////////////overall functions
//initialize input life element and strength every warrior use
void initialize()
{
	cin >> elementLife >> strengthHq[0] >> strengthHq[1] >> strengthHq[2] >> strengthHq[3] >> strengthHq[4];
}

//start preparing
void start()
{
	static Headquarters red(nameHq[0], elementLife, name, strengthHq);
	static Headquarters blue(nameHq[1], elementLife, name, strengthHq);	
	for(int i = 0; i <= hm;++i)
	{
		for(int j = 0; j < minute.size();++j)
		{
			if(i * 60 + j > T){break;}
			switch(j)
			{
				case 0:
				{
					while(flagRed == 1 || flagBlue == 1){
						cout << setfill('0') << setw(3) << i << " " << setfill('0') << setw(2) << minute[j];
						if(flagRed == 1){
							flagRed = red.decideWarrior();
						}
						cout << setfill('0') << setw(3) << i << " " << setfill('0') << setw(2) << minute[j];
						if(flagBlue == 1){
							flagBlue = blue.decideWarrior();
						}
					}
				}

				case 1:
				{

				}
			}
		}
	}
	while(flagRed == 1 || flagBlue == 1){
		if(flagRed == 1){
			flagRed = red.decideWarrior();
		}
		if(flagBlue == 1){
			flagBlue = blue.decideWarrior();
		}
	}
}
///////////////////////////////////////


/////////////////////////////////////////main
int main(){
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; ++i)
	{
		cout << "Case " << i << " : " << endl;

		initialize();
		start();

	}
	return 0;
}
////////////////////////////////////////////