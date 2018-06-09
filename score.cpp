#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct student
{
	string name,gender,sct;
	double score;
	bool sex;
	student(){};
	student(string _s,string _g,string _sct,double _sc):name(_s),gender(_g),sct(_sct),score(_sc){};
	void calcsex() {sex=(gender=="Female");}
	bool operator <(const student &a) const
	{
		return (score>a.score)||((score==a.score) && (name<a.name));
	}
};
vector<student> all,male,female;
double average(const vector<student>& stu)
{
	double ans=0;
	for (auto x:stu)
	{
		ans+=x.score;
	}
	return ans/double(stu.size());
}
int main()
{
	freopen("score.csv","r",stdin);
	string line;
	getline(cin,line);
	string name,gender,score;
    while (getline(cin,line))
    {
    	stringstream ss(line);
    	getline(ss,name,',');
		getline(ss,gender,',');
		getline(ss,score,',');
		gender.erase(0,1);score.erase(0,1);
		double sc=stod(score);
		student tmp(name,gender,score,sc);
		tmp.calcsex();
		if (tmp.sex) female.push_back(tmp);else male.push_back(tmp);
		all.push_back(tmp);
	}
	cout<<fixed<<setprecision(1)<<average(all)<<endl<<average(male)<<endl<<average(female)<<endl;
	sort(all.begin(),all.end());
	for (auto x:all)
	{
		cout<<x.name<<" "<<x.gender<<" "<<x.sct<<endl;
	}
	return 0;
}
		
