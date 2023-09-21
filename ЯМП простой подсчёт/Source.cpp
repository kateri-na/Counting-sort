#include <iostream>
#include <windows.h>

void print_arr(int* arr, int size)
{
		for (int i = 0; i < size; ++i)
				std::cout << arr[i] << ' ';
		std::cout << '\n';
}

int* create_arr(int size)
{
		int* arr = new int[size];
		for (int i = 0; i < size; ++i)
				arr[i] = 0;
		return arr;
}

void counting_sort(int* arr, int size)
{
		int* count = create_arr(size);
		int elem1, elem2;
		for (int i = size-1; i > 0; --i)
		{
				for (int j = 0; j < i; ++j)
				{
						if (arr[i] >= arr[j])
								count[i]=count[i]+1;
						else
								count[j]=count[j]+1;
				}
		}
		std::cout << "Массив рассчитанных позиций элементов:\n";
		print_arr(count, size);
		int i = 0, j=0, k=0;
		while (i < size)
		{
				elem1 = arr[i]; j = count[i];
				while (i != j)
				{
						elem2 = arr[j];
						arr[j] = elem1;
						elem1 = elem2;
						k = count[j];
						count[j] = j;
						j = k;
				}
				arr[i] = elem1;
				count[i] = i - 1;
				i = i + 1;
		}
		delete[] count;
}

int* make_rand(int size)
{
	int* arr = new int[size];
	srand(GetTickCount64());
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 10;
	return arr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	std::cout << "Введите количество элементов массива\n";
	std::cin >> size;
	
	int* arr = make_rand(size);
	std::cout << "Исходный массив:\n";
	print_arr(arr,size);

	counting_sort(arr, size);

	std::cout << "Отсортированный массив:\n";
	print_arr(arr, size);

	delete[] arr;
	std::cin.ignore().get();
	return 0;
}