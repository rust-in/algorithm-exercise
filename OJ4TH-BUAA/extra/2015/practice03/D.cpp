#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

string X;
string Y;
int table[10000][10000];
set<string> setOfLCS;      // set�������е�LCS

int max(int a, int b)
{
	return (a>b)? a:b;
}

/**
 * �����������X��Y��LCS�ĳ���
 */
int lcs(int m, int n)
{

	for(int i=0; i<m+1; ++i)
	{
		for(int j=0; j<n+1; ++j)
		{
			// ��һ�к͵�һ����0
			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if(X[i-1] == Y[j-1])
				table[i][j] = table[i-1][j-1] + 1;

			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}

	return table[m][n];
}

/**
 * �ַ�������
 */
string Reverse(string str)
{
	int low = 0;
	int high = str.length() - 1;
	while (low < high)
	{
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		++low;
		--high;
	}
	return str;
}

/**
 * ������е�����������У�������set��
 */
void traceBack(int i, int j, string lcs_str)
{
	while (i>0 && j>0)
	{
		if (X[i-1] == Y[j-1])
		{
			lcs_str.push_back(X[i-1]);
			--i;
			--j;
		}
		else
		{
			if (table[i-1][j] > table[i][j-1])
				--i;
			else if (table[i-1][j] < table[i][j-1])
				--j;
			else   // ��ȵ����
			{
				traceBack(i-1, j, lcs_str);
				traceBack(i, j-1, lcs_str);
				return;
			}
		}
	}

	setOfLCS.insert(Reverse(lcs_str));
}


int main()
{
    while(cin >> X >> Y)
    {
        int m = X.length();
        int n = Y.length();
        int length = lcs(m, n);
        setOfLCS.clear();
        string str;
        traceBack(m, n, str);
        // �������
        set<string>::iterator beg = setOfLCS.begin();
        for( ; beg!=setOfLCS.end(); ++beg)
            cout << *beg << endl;
    }
}
