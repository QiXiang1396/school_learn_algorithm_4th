#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxBit(vector<int> data)
{
	int n = data.size();
	//�ҵ�maxdata
	int maxData = data[0];
	for (int i = 1;i < n;i++)
	{
		if (maxData < data[i])
			maxData = data[i];
	}

	int d = 1;    //d�����������ֵ��λ��
	while (maxData >= 10)  //�����ֵ����/10������λ�� 
	{
		maxData /= 10;
		d++;
	}
	return d;
}

void radixsort(vector<int>& data)  //�������� 
{
	int temp[100]{0}, bucket[20]{0};
	int n = data.size();
	int i(0), j(0), k(0), radix = 1;

	for (i = 1;i <= maxBit(data);i++)   //����maxBit������
	{
		for (j = 0; j < 20; j++)   bucket[j] = 0;  //ÿ�η���ǰ��ռ�����
			
		for (j = 0; j < n; j++)    //ͳ��ÿ��Ͱ��Ԫ�ظ��� 
		{
			k = (data[j] / radix) % 10;
			bucket[k]++;
		}

		for (j = 1; j < 20; j++)
			bucket[j] = bucket[j - 1] + bucket[j];

		for (j = n - 1; j >= 0; j--)
		{
			k = (data[j] / radix) % 10;
			temp[bucket[k] - 1] = data[j];
			bucket[k]--;
		}

		for (j = 0; j < n; j++)   data[j] = temp[j];   
			
		radix = radix * 10;  //��λ  -> ʮλ  -> ��λ ->�� 
	}
}

int main()
{
	vector<int> a(10);
	for (size_t i = 0; i < 10; i++)
	{
		a[i] = abs(rand());
	}
	for (auto i : a)
		cout << i << " ";
	cout << endl;

	radixsort(a);

	for (auto i : a)
		cout << i << " ";
	return 0;
}