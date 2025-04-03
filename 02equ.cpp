/*************************************************************************************
022:魔兽世界之二：装备
总时间限制: 1000ms 内存限制: 65536kB 
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。 

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。 
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。 

不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。 

在每个整点，双方的司令部中各有一个武士降生。 

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。 

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。 

制造武士需要生命元。 

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。 

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下： 

1) 武士降生 
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时： 
首先按时间顺序输出； 
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。
每组测试数据共两行。 
第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000) 
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始 
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
*************************************************************************************/
//引入相关库
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<iomanip>
using namespace std;

//全局变量定义
vector<string> name = { "dragon", "ninja", "iceman", "lion", "wolf" };
vector<string> arm = {"sword","bomb","arrow"};
vector<string> nameHq = {"red", "blue"};
vector<int> strengthHq(5);
vector<vector<int>> order = {{2,3,4,1,0},{3,0,1,2,4}};
int elementLife=0, flagRed=1, flagBlue=1;

//声明几个重要的类
class Headquarters;
class Warrior;
class Arm;

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
		vector<shared_ptr<Warrior>> warrior;//all the warriors
	public:
		int decideWarrior();//考虑是否有足够的生命元继续制造战士，以及应该制造什么
		Headquarters(string headquartersName, int element, vector<string> name, vector<int> strength);//构造函数，用来初始化
		virtual void printInfo() const{}
		int getElement() const{return element;}
		int getCount() const{return count;}//获取当前已经制造的战士个数
		vector<int> getWarriorStrength() const{return warriorStrength;}//每种战士的生命值
		void createWarrior(int num);//根据目前num来决定创造哪一种战士，加入到vector中

};
////////////////////////////////////////////////

//////////////////////////////define armament
class Arm
{
public:
	Arm(const string & k):kind(k){}
	string getKind(){return kind;}
protected:
	int ad;//attack
	string kind;
};

//define sword
class Sword: public Arm 
{
public:
	Sword():Arm("sword"){}
};

//define bomb
class Bomb: public Arm 
{
public:
	Bomb():Arm("bomb"){}
};

//define arrow
class Arrow: public Arm 
{
public:
	Arrow():Arm("arrow"){}

};
////////////////////////////////////////////////

///////////////////////////////define warrior
class Warrior
{
public:
	Warrior(){}
	Warrior(const Headquarters & hq):id(hq.getCount()){}
	int getId(){return id;}
	int getStrength(){return strength;}
	vector<shared_ptr<Arm>> getArm(){return arm;}
	void showArm() const;
	void equipArm(int i);
	virtual void printInfo() const {}
protected:
	int id;
	int strength;
	vector<shared_ptr<Arm>> arm;
	 
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

	cout << setfill('0') << setw(3) << time << " " << headquartersName << " " << warriorName[num] << " ";
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
			warrior.push_back(pDragon);
			pDragon->printInfo();
			break;
		}
		case 1:
		{
			auto pNinja = make_shared<Ninja>(static_cast<const Headquarters &>(*this));
			warrior.push_back(pNinja);
			pNinja->printInfo();
			break;
		}
		case 2:
		{
			auto pIceman = make_shared<Iceman>(static_cast<const Headquarters &>(*this));
			warrior.push_back(pIceman);
			pIceman->printInfo();
			break;
		}
		case 3:
		{
			auto pLion = make_shared<Lion>(static_cast<const Headquarters &>(*this));
			warrior.push_back(pLion);
			pLion->printInfo();
			break;
		}
		case 4:
		{
			auto pWolf = make_shared<Wolf>(static_cast<const Headquarters &>(*this));
			warrior.push_back(pWolf);
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
			cout << setfill('0') << setw(3) << time << " " << headquartersName << " headquarter stops making warriors" << endl;
		}
		else{
			num = numTmp;
			produceWarrior();
		}
	}
	return flagCon;

}
/////////////////////////////////////////

/////////////////////////////////////////functions of armament

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


//////////////////////////////////////////



//initialize input life element and strength every warrior use
void initialize()
{
	cin >> elementLife >> strengthHq[0] >> strengthHq[1] >> strengthHq[2] >> strengthHq[3] >> strengthHq[4];
}

//start preparing
void start()
{
	Headquarters red(nameHq[0], elementLife, name, strengthHq);
	Headquarters blue(nameHq[1], elementLife, name, strengthHq);	
	while(flagRed == 1 || flagBlue == 1){
		if(flagRed == 1){
			flagRed = red.decideWarrior();
		}
		if(flagBlue == 1){
			flagBlue = blue.decideWarrior();
		}
	}
}


//main
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
