#include<iostream>
using namespace std;
#include<string>
//得到next数组的函数，子串是模板串，每个模板串会有一个next数组
void getNext(string& r, int* next)//r为模板串，next为需要求的数组
{
	int j = 0;//j从0开始，也表示前后缀没有一个匹配上的
	int i = 1;//数组从1开始存——更加大众，更加方便
	next[1] = 0;//啊喂，第一个就没有配对成功，当然用0来记录这个特殊情况了——那就是i要向后移1位了

	while (i < r[0] - '0')//假设r[0]存的是字符串长度，位置1已存，所以还剩长度减1个要存
	{
		if (j == 0 || r[i] == r[j])//j为0可以进入，此时i记为1（其实还是有可能存0，升级版会解决）
		{
			j++;
			i++;
			next[i] = j;
		}
		else//当前后缀相等的个数增中断时，j需要回溯
		{
			j = next[j];//现在还不清楚为什么这一句可以回溯，以后需要解决
		}
	}
	return;
}

void getNextval(string& r, int* next)//r为模板串，next为需要求的数组
{
	int j = 0;//j从0开始，也表示前后缀没有一个匹配上的
	int i = 1;//数组从1开始存——更加大众，更加方便
	next[1] = 0;//啊喂，第一个就没有配对成功，当然用0来记录这个特殊情况了——那就是i要向后移1位了

	while (i < r[0] - '0')//假设r[0]存的是字符串长度，位置1已存，所以还剩长度减1个要存
	{
		if (j == 0 || r[i] == r[j])//j为0可以进入，此时i记为1（其实还是有可能存0，升级版会解决）
		{
			j++;
			i++;
			next[i] = j;
			while (r[next[i]] == r[i])
			{
				next[i] = next[j];
			}
		}
		else//当前后缀相等的个数增中断时，j需要回溯
		{
			j = next[j];//现在还不清楚为什么这一句可以回溯，以后需要解决
		}
	}
	return;
}


int index(string& s, string& t, int pos)
{
	int i = pos;//主串起始
	int j = 1;//子串起始

	int next[255];
	getNextval(t, next);//得到next,如果用getNextval记得更改
	while (i <= s[0] - '0' && j <= t[0] - '0')
	{
		if (j == 0 || s[i] == t[j])//j等于0其实就是特殊情况——第一个没匹配上，i后移
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//j移动
		}
	}
	if (j > t[0] - '0')
	{
		return i - t[0] + '0';
	}
	else
	{
		return 0;
	}
}
int main()
{
	string a = "6abcabd";
	string b = "6aaaaab";
	cout << "子串在主串中的位置是: " << index(a, b,1) << endl;
	system("pause");
	return 0;
}