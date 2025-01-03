#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template<typename T> 
class SimpleVector
{
private:
	T* data;
	int currentSize = 0;
	int currentCapacity = 0;

public:
	SimpleVector(int capacity = 10)
	{
		data = new T[capacity];
		currentSize = 0;
		currentCapacity = capacity;
	}
	SimpleVector(const SimpleVector& other)
	{
		currentCapacity = other.currentCapacity;
		currentSize = other.currentSize;
		data = new T[other.currentCapacity];
		for (int i = 0; i < currentCapacity; i++)
		{
			data[i] = other.data[i];
		}
	}
	~SimpleVector()
	{
		delete[] data;
	}

#pragma region printData
	////////////////////////////////////////////////////
	/////////////////배열 내 원소 확인용////////////////
	////////////////////////////////////////////////////
	T getData(int i) const
	{
		return data[i];
	}
#pragma endregion 
	

	void resize(int newCapacity)
	{
		if (currentCapacity < newCapacity)
		{
			int temp = currentSize;
			currentCapacity = newCapacity;
			T* arr = new T[newCapacity];
			for (int i = 0; i < temp; i++)
			{
				arr[i] = data[i];
			}
			delete[] data;
			data = arr;
		}
			
	}
	void push_back(const T& value)
	{
		if (currentSize < currentCapacity)
		{
			data[currentSize] = value;
			currentSize++;
		}
	}
	void pop_back()
	{
		if (currentSize > 0)
		{
			currentSize--;
		}
	}
	int size() const
	{
		return currentSize;
	}
	int capacity() const
	{
		return currentCapacity;
	}
	void sortData()
	{
		sort(data, data + currentSize);
	}
};



int main() 
{

	SimpleVector<int> s(10);
	
	s.push_back(5);
	s.push_back(3);
	s.push_back(4);
	s.pop_back();
	s.pop_back();
	s.push_back(7);
	s.push_back(1);


	for (int i = 0; i < 10; i++)
	{
		s.push_back(1);
	}
	for (int i = 0; i < 20; i++)
	{
		s.pop_back();
	}

	s.resize(15);
	for (int i = 0; i < 20; i++)
	{
		s.push_back(10);
	}
	
	for (int i = 0; i < s.size(); i++)
	{
		cout << s.getData(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		s.pop_back();
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s.getData(i) << " ";
	}
	cout << endl;

	s.push_back(10);
	s.push_back(11);
	s.push_back(9);
	s.sortData();
	SimpleVector<int> s2(s);
	for (int i = 0; i < s2.size(); i++)
	{
		cout << s2.getData(i) << " ";
	}
}