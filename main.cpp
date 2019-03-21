#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> shortestToChar(string S, char C)
{
    //指定字符（多个），存入索引
    vector<int> c;
    for(int i = 0;i < S.length(); ++ i)
    {
        if(S[i] == C)
        {
            c.push_back(i);
        }
    }
	
	vector<int> res(S.length(), 0);
    int n = c.size();
    for(int i = 0; i< S.length(); ++ i)
    {
    	//计算首字符距离
        int temp = abs(c[0] - i);
        //比较其它字符距离
        for(int j = 1; j < n; ++ j)
        {
            if (abs(c[j] - i) < temp)
            {
                temp = abs(c[j] - i);
            }
        }
        res[i] = temp;
    }
    return res;
}

//--------------------------------------------------------------------
struct Point {
	Point(int _x, int _y) : x(_x), y(_y){}

	int x;
	int y;
};

//最大公约数
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int maxPoints(vector<Point>& points) {
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
        map<pair<int, int>, int> m;

        //记录相同点的个数
        int duplicate = 1;
        for (int j = i + 1; j < points.size(); ++j) {
        	//处理相同的点
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                ++duplicate;
                continue;
            }

            //处理不同的点
            int dx = points[j].x - points[i].x;
            int dy = points[j].y - points[i].y;
            int d = gcd(dx, dy);
            ++ m[make_pair(dx / d, dy / d)];
        }

        res = max(res, duplicate);
        for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); ++it) {
            res = max(res, it->second + duplicate);
        }
    }
    return res;
}

int main()
{
	//计算给定字符串最短距离
	string S = "joycastleisnotacastle";
	char C = 't';
	vector<int> list = shortestToChar(S, C);

	for (vector<int>::iterator iter = list.begin(); iter != list.end(); ++ iter)
	{
		printf("%d\n", *iter);
	}

	//计算同一直线上最大点数
	vector<Point> vecPos = {Point(1, 1), Point(3, 2), Point(5, 3), Point(4, 1), Point(2, 3), Point(1, 4)};
	int n = maxPoints(vecPos);
	printf("%d\n", n);

	return 0;
}
