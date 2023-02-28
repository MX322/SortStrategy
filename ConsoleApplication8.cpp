#include <iostream>
using namespace std;

class ISortStrategy
{
public:
	virtual void SetDefault(int* arr, int size) = 0;
	virtual void Sort(int* arr, int size) = 0;
	virtual void Print(int* arr, int size) = 0;
};


class QuickSort : public ISortStrategy
{

public:

	void SetDefault(int* arr, int size)
	{
		arr[0] = 14;
		arr[1] = 1;
		arr[2] = -4;
		arr[3] = 19;
		arr[4] = 8;
	}

	void Sort(int* arr, int size) override
	{
		int left = 0;
		int right = size - 1;
		int middle = arr[size / 2];
		int temp;

		do {

			while (arr[left] < middle)
			{
				left++;
			}

			while (arr[right] > middle)
			{
				right--;
			}

			if (left <= right) {
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
				left++;
				right--;
			}

		} while (left <= right);


		if (right > 0)
		{
			Sort(arr, right);
		}

		if (size > left)
		{
			Sort(arr + left, size - left);

		}
	}


	void Print(int* arr, int size) override
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};


class BubbleSort : ISortStrategy
{
public:

	void SetDefault(int* arr, int size)
	{
		arr[0] = 14;
		arr[1] = 1;
		arr[2] = -4;
		arr[3] = 19;
		arr[4] = 8;
	}

	void Sort(int* arr, int size) override
	{
		int tmp = 0;

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = size - 1; j > i; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					tmp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = tmp;
				}
			}
		}

	}

	void Print(int* arr, int size) override
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};


int main()
{
	int size = 5;
	int* arr = new int[size];

	QuickSort qs;
	qs.SetDefault(arr, size);
	qs.Print(arr, size);
	qs.Sort(arr, size);
	qs.Print(arr, size);

	cout << endl;

	BubbleSort bs;
	bs.SetDefault(arr, size);
	bs.Print(arr, size);
	bs.Sort(arr, size);
	bs.Print(arr, size);
}