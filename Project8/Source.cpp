#include<iostream>
#include<cassert>
#include<vector>
using namespace std;
/*
pushFront - evveline element elave edir
misal: 6 cavab [6,34,67,58,99]
insert - istenilen indexe  element elave edir
misal: index 3 elem 777  [6,34,67,777,58,99]
popback - sondan  element silir
misal: [6,34,67,58]
pop_index - istenilen indexdeki elementi silir
misal: index 2 [6,34,58,99]

misal: [34,67,58,99]

*/
class Vector {
	int* array = nullptr;
	size_t size = 0;
	size_t capacity = 10;

public:
	Vector() {
		this->array = new int[capacity] {};
	};
	explicit Vector(size_t capacity):Vector() { //55 Vector v = 6 ;icaze vermir bele yaratmaga
		while (this->capacity < capacity) {
			this->capacity += 10;
		}
	}

	int* Get_Data()const {
		return array;
	}

	size_t Get_Size() const{
		return size;
	}

	size_t Get_Capacity() const {
		return capacity;
	}

	int& operator[](size_t index) {
		if (index >= 0 && index <= size) {
			return array[index];
		}
		else {
			assert(!"Index out of Range");
		}
	}
	

	Vector& Push_back(const int value) {  //vectorun sonuna element elave etmek
		if (size == capacity) {
			capacity += 10;
			int* new_array = new int [capacity] {};

			for (size_t i = 0; i < size; i++)
			{
				new_array[i] = array[i];
			}
			new_array[size] = value;
			delete array;
			array = new_array;
			size++;
		}
		else {
			array[size] = value;
			size++;
		}

		return *this;
	}

	Vector& Push_Front(const int value) {  //vectorun evveline element elave etmek
		if (size == capacity) {
			capacity += 10;
			int* new_array = new int [capacity] {};

			for (size_t i = 0; i < size; i++)
			{
				new_array[i + 1] = array[i];
			}
			new_array[0] = value;
			delete array;
			array = new_array;
			size++;
		}
		else {
			
			for (size_t i = 0; i < size; i++)
			{
				array[size-i] = array[size-i-1];
			}
			size++;
			array[0] = value;
			
		}

		return *this;
	}

	friend ostream& operator<<(ostream& out, const Vector& obj) {
		for (size_t i = 0; i < obj.size; i++)
		{
			out << obj.array[i] << "   ";
		}
		out << endl;
		return out;
	}

	~Vector() {
		delete[] array;
	}
};


void main() {
#pragma region MyVector
	//Vector v;
	//cout << "Capacity: " << v.Get_Capacity() << endl;
	//cout << "Size: " << v.Get_Size() << endl;
	//v.Push_back(90);
	//v.Push_back(55);
	//v.Push_back(66);
	//cout << "Capacity: " << v.Get_Capacity() << endl;
	//cout << "Size: " << v.Get_Size() << endl;
	//cout << v << endl;

	////v.Push_back(1);
	////v.Push_back(2);
	////v.Push_back(3);
	////v.Push_back(4);
	////v.Push_back(5);
	////v.Push_back(6);
	////v.Push_back(7);
	////v.Push_back(8);
	////v.Push_back(9);
	////v.Push_back(10);

	//for (size_t i = 1; i < 10; i++)
	//{
	//	v.Push_back(i);
	//}

	//cout << "Capacity: " << v.Get_Capacity() << endl;
	//cout << "Size: " << v.Get_Size() << endl;
	//cout << v << endl;
#pragma endregion

	//vector<int> v;
	//v.push_back(45);
	//v.push_back(999);
	//v.push_back(787);
	//v.push_back(787);
	//v.push_back(787);
	//v.push_back(787);
	//v.push_back(787);
	//
	//auto data = v.data();

	//cout << "Capacity: " << v.capacity() << endl;
	//cout << "Size: " << v.size() << endl;

	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	cout << data[i] << "  ";
	//}

	//cout << endl;

	
	Vector v;
	v.Push_back(90);
	v.Push_back(77);
	v.Push_back(56);
	v.Push_back(34);

	cout << v << endl;

	v.Push_Front(7777);
	cout << v << endl;


}