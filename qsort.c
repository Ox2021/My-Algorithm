#include<stdio.h>
int a[100];//����ȫ�ֱ������Ϳ���������������ʹ���� 
void quicksort(int left, int right)//���������еĵ�һ��ֵ���±�����һ��ֵ���±� 
{
	int i, j, temp, t;

	temp = a[left];//��������ߵ�����Ϊ��׼ 
	i = left;
	j = right;

	if (left >= right)
		return;
	while (i != j)
	{
		while (a[j] >= temp && i < j)//���������ұ߿�ʼ���ұߵ������ڱ�׼����ô�����±��һ 
			j--;
		while (a[i] <= temp && i < j)//��ߵ������ڱ�׼����ô�����±��һ 
			i++;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quicksort(0, n - 1);
	for (i = 0; i < n; i++)
		printf("%-4d", a[i]);
}
