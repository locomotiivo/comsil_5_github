#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include <cstdlib>
using namespace std;


//LinkedList Node
template <class T>
class Node
{
	public:
		T data;								// 데이터 저장
		Node *link;							// 다음노드의 주소 저장
		Node(T element)
		{
		  data = element;
		  link = 0;
		}
};

//LinkedList Class
template <class T>
class LinkedList
{
	protected:
		Node<T> *first;								// 첫 노드의 주소 저장
		int current_size;

	public:
		LinkedList()								// 생성자 -  초기화 
		{
			first = 0;
			current_size = 0;
		};
		int GetSize() { return current_size; };		// 노드 개수를 리턴
		void Insert(T element);						// 맨 앞에 원소를 삽입		
		virtual bool Delete(T &element);			// 맨 뒤의 원소를 삭제
		void Print();								// 리스트 출력
};

template <typename T>
void LinkedList<T>::Insert(T element)				// Push 함수
{
	Node<T> *newnode = new Node<T>(element);			// 노드 생성

	newnode -> link = first;							// 새 노드가 첫번째 노드를 가리킴
														// newnode는 포인터이기 때문에 '->'로 함수/ 변수를 불러온다
														// newnode.link와 뜻은 같다
	first = newnode;
	current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element)				// Pop 함수
{
	if (first == 0)
		return false;
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	while(1)											// 마지막 노드를 찾는 반복문
	{
		if (current->link == 0)
		{
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

template <typename T>
void LinkedList<T>::Print()							// List 출력용 Print 함수
{
	Node<T> *i;
	int index = 1;

	if (current_size != 0)
	{
		for( i = first; i != NULL; i = i->link)
		{
			if (i->link == NULL)
			{
				cout << "[" << index << "|";
				cout << i->data << "]";
			}
			else
			{
				if (index == current_size)
				{
					cout << "[" << index << "|";
					cout << i -> data << "]->";
				}	
				else
				{
					cout << "[" << index << "|";
					cout << i -> data << "]->";
					index++;
				}
			}
		}
		cout << endl;
	}
}

#endif
