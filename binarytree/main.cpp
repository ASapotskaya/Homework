#include<iostream>
using namespace std;

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	//                  type               name
	Tree(initializer_list<int> il) :Tree()
	{
		//begin()- возвращает итератор на начало контейнера;
		//end()-возвращает итератор на конец контейнера;
		for (int const* it = il.begin(); it != il.end(); ++it)
		insert(*it, Root);
	}
	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
	int MinValue()const
	{
		return MinValue(Root);
	}
	int MaxValue()const
	{
		return MaxValue(Root);
	}
	int sum()const
	{
		return sum(Root);
	}
	int count()const
	{
		return count(Root);
	}
	double avg()const
	{
		return (double)sum(Root)/count(Root);
	}
	
	void erase(int Data)
	{
		erase(Data, Root);
	}
	int depth()const
	{

	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	void erase(int Data, Element*& Root)const
	{
		if (Root == nullptr)return;
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (count(Root->pLeft) > count(Root->pRight))
				{
					Root->Data = MaxValue(Root ->pLeft);
					erase(MaxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = MinValue(Root->pRight);
					erase(MinValue(Root->pRight), Root->pRight);
				}
			}
		}
		if (Root)erase(Data, Root->pLeft);
		if (Root)erase(Data, Root->pRight);
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
		Root = nullptr;
	}
	int MinValue(Element* Root)const
	{
		if (Root == nullptr)return 0; 
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return MinValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : MinValue(Root->pLeft);
	}
	 int MaxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pRight == nullptr)return Root->Data;
		else return MaxValue(Root->pRight);*/
		return Root->pRight ? MaxValue(Root->pRight) : Root->Data;
		//return Root->pRight == nullptr ? Root->Data : MaxValue(Root->pRight) : ;
	}
	int sum(Element* Root)const
	{
		/*if (Root == nullptr)return 0;
		else return sum(Root->pLeft) + sum(Root->pRight) + Root->Data;*/
		return Root == nullptr ? 0 : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}
	int count(Element* Root)const
	{
		return Root == nullptr ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
	}
	
	int depth(Element* Root)const
	{

	}

};
class UniqueTree :public Tree
{

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};

//#define BASE_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;

	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.MinValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.MaxValue() << endl;
	cout << "Сумма элементов дерева: " << tree.sum() << endl;
	cout << "Количество элементов дерева: " << tree.count() << endl;
	cout << "Среднее арифметическое значение элементов дерева: " << tree.avg() << endl;


	UniqueTree u_tree;

	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	u_tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: " << u_tree.MinValue() << endl;
	cout << "Максимальное значение в дереве: " << u_tree.MaxValue() << endl;
	cout << "Сумма элементов дерева: " << u_tree.sum() << endl;
	cout << "Количество элементов дерева: " << u_tree.count() << endl;
	cout << "Среднее арифметическое значение элементов дерева: " << u_tree.avg() << endl;
#endif // BASE_CHECK


	Tree tree = {				50,
						25,				75,
					16,		32,		64,		80 };
	tree.print();
	int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();
}