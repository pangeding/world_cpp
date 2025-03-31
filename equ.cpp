#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//全局变量定义
string name[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };

class headquarter{
	private:
		string headquarterName;//司令部的名称
		int element;//司令部的生命元
		int time;//时间
		string warriorName[5];//每种战士的名称
		int warriorStrength[5];//每种战士的数量
		int warriorCount[5];//每种战士个数
		int count;//已经制造的战士总个数（从1开始）以及
		int num;//应该制造的战士种类（从0到4）
		void produceWarrior();//已经制造的战士总个数和应该制造的战士种类来制造战士的函数
	public:
		int decideWarrior();//考虑是否有足够的生命元继续制造战士，以及应该制造什么
		headquarter(string headquarterName, int element, string name[], int strength[]);//构造函数，用来初始化
		virtual void printInfo() const{}
};

class warrior: virtual public headquarter
{
    public:
		string weapon;
		float; 
		virtual void printInfo() const override{} 
};

class dragon: public warrior
{
	public:
		void printInfo() const override
		{
			cout << 
		}
};

class dragon: public warrior
{
	public:
		void printInfo() const override
		{
			cout << 
		}
};

class dragon: public warrior
{
	public:
		void printInfo() const override
		{
			cout << 
		}
};

class dragon: public warrior
{
	public:
		void printInfo() const override
		{
			cout << 
		}
};

class dragon: public warrior
{
	public:
		void printInfo() const override
		{
			cout << 
		}
};

headquarter::headquarter(string headquarterName, int element, string name[], int strength[]){
	int order[5];
	this->headquarterName = headquarterName;
	time = 0;
	count = 0;
	num = 0;
	this->element = element;
	if (this->headquarterName == "red")//红方司令部
	{//制造战士的顺序
		order[0] = 2;
		order[1] = 3;
		order[2] = 4;
		order[3] = 1;
		order[4] = 0;
	}
	else//蓝方司令部
	{//制造战士的顺序
		order[0] = 3;
		order[1] = 0;
		order[2] = 1;
		order[3] = 2;
		order[4] = 4;
	}
	for(int i = 0; i < 5; ++i){
		warriorCount[i] = 0;
		warriorName[i] = name[order[i]];
		warriorStrength[i] = strength[order[i]];
	}
}

void headquarter::produceWarrior(){
	++warriorCount[num];
	element -= warriorStrength[num];
	
	cout << setfill('0') << setw(3) << time << " " << headquarterName << " " << warriorName[num] << " ";
	++count;
	cout << count << "born with strength" << warriorStrength[num] << "," << warriorCount[num] << " " << warriorName[num] << " in " << headquarterName << "headquarter" << endl;
	++time;
	num = (++num) % 5;
}
//int 是是否需要总部继续制造战士的信号，1 or 0
int headquarter::decideWarrior(){
	int flagCon = 1;//决定是否继续的旗子，默认为1
	int numTmp = num;
	if(element >= warriorStrength[num]){
		produceWarrior();
	}
	else{
		for(numTmp = (num + 1) % 5; numTmp < 5; ++numTmp){
			if(element >= warriorStrength[numTmp]){
				num = numTmp;
				break;
			}
		}
		//看下一轮到目前截止点有没有能制造的
		if(numTmp == 4){
			for(numTmp = 0; numTmp < num; ++numTmp){
				if(element >= warriorStrength[numTmp]){
					num = numTmp;
					break;
				}
			}
		}
		
		if(numTmp = (num - 1) % 5){
			flagCon = 0;
		}
		
		if(flagCon == 0){
			cout << setfill('0') << setw(3) << time << " " << headquarterName << " headquarter stops making warriors" << endl;
		}
		else{
			produceWarrior();
		}
	}
	return flagCon;

}

void 

int main(){
	string name[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
	int caseTest, element, strength[5], flagRed, flagBlue;
	int caseCur = 0;//目前case数
	cin >> caseTest;
	while(caseTest > 0){
		--caseTest;
		++caseCur;
		flagRed = 1;
		flagBlue = 1;
		
		cin >> element >> strength[0] >> strength[1] >> strength[2] >> strength[3] >> strength[4];
		headquarter red("red", element, name, strength);
		headquarter blue("blue", element, name, strength);
		cout << "Case:" << caseCur << endl;
		while(flagRed == 1 || flagBlue == 1){
			if(flagRed == 1){
				flagRed = red.decideWarrior();
			}
			if(flagBlue == 1){
				flagBlue = blue.decideWarrior();
			}
		}
	}
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
