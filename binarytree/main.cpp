#include<iostream>
#include <ctime>
#include <algorithm>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
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
	int depth()const
	{
		return depth(this->Root);
	}
	void depth_print(int depth, int width = 8)const
	{
		depth_print(this->Root, depth,width);
		cout << endl;
	}
	void tree_print()const
	{
		tree_print(depth(Root), depth(Root) *8);
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
	int depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		//else return
			/*depth(Root->pLeft)  + 1 >
			depth(Root->pRight) + 1 ?
			depth(Root->pLeft)  + 1 :
			depth(Root->pRight) + 1;*/
		/*int l_depth = depth(Root->pLeft)+1;
		int r_depth = depth(Root->pRight) + 1;
		return l_depth > r_depth ? l_depth : r_depth;*/
		return Root == nullptr ? 0 : std::max(depth(Root->pLeft), depth(Root->pRight)) + 1;
	}

	void depth_print(Element* Root, int depth, int width =8)const
	{
		if (Root == nullptr)return;
		if (depth == 0)
		{
			cout.width(width);
			cout << Root->Data;
			cout.width(width);
			cout << "";
		}
		depth_print(Root->pLeft, depth - 1,width);
		depth_print(Root->pRight, depth - 1,width);
		
	}
	void tree_print(int depth, int width)const
	{
		if (depth == -1)return;
		depth_print(this->depth(this->Root)-depth, width);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		tree_print(depth - 1, width/2);
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

template<typename T>void measure(const char msg[], const Tree& tree, T(Tree::* member_function)()const)
{
	cout << msg << ": ";;
	clock_t start = clock();
	T value = (tree.*member_function)();
	clock_t end = clock();
	cout << ", выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}

//#define BASE_CHECK
//#define PREFORMANCE_CHECK
//#define ERASE_CHECK
#define BALANCE_CHECK
void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;

	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	clock_t start = clock();
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	clock_t end = clock();
	cout<<"Дерево заполнено за: " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	//tree.print();
	cout << endl;
#ifdef PREFORMANCE_CHECK
	cout << "Минимальное значение в дереве: \t";
	start = clock();
	cout << tree.MinValue() << "\t";
	end = clock();
	cout << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	////////////////////////////////////////////////////////////////////////////////////
	start = clock();
	cout << "Максимальное значение в дереве: " << tree.MaxValue() << "\t";
	end = clock();
	cout << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	////////////////////////////////////////////////////////////////////////////////////
	start = clock();
	cout << "Сумма элементов дерева: " << tree.sum() << "\t";
	end = clock();
	cout << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	////////////////////////////////////////////////////////////////////////////////////
	start = clock();
	cout << "Количество элементов дерева: " << tree.count() << "\t";
	end = clock();
	cout << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	////////////////////////////////////////////////////////////////////////////////////
	start = clock();
	cout << "Среднее арифметическое значение элементов дерева: " << tree.avg() << "\t";
	end = clock();
	cout << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	////////////////////////////////////////////////////////////////////////////////////
	cout << "Глубина дерева: \t";
	start = clock();
	cout << tree.depth() << "\t";
	end = clock();
	cout << "Выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд. \n";
	////////////////////////////////////////////////////////////////////////////////////

#endif // PREFORMANCE_CHECK

	measure("Минимальное значение в дереве", tree, &Tree::MinValue);
	measure("Максимальное значение в дереве", tree, &Tree::MaxValue);
	measure("Сумма элементов дерва", tree, &Tree::sum);
	measure("Количество элементов дерева", tree, &Tree::count);
	measure("Среднее арифметическое элементов дерева", tree, &Tree::avg);
	measure("Глубина дерева", tree, &Tree::depth);
	

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
	cout << "Глубина дерева: " << tree.depth() << endl;
#endif // BASE_CHECK


#ifdef ERASE_CHECK
	Tree tree = { 50,
			25,					75,
		16,			32,		64,		80,
			17,
				18 };
	tree.print();
	//int value;
	//cout << "Введите удаляемое значение: "; cin >> value;
	//tree.erase(value);
	tree.print();
	cout << "Глубина дерева: " << tree.depth() << endl;
	/*int depth;
	cout << "Введите желаемую глубину: "; cin >> depth;
	tree.depth_print(depth);*/
	tree.tree_print();
#endif // ERASE_CHECK


#ifdef BALANCE_CHECK
	Tree tree = { 55,34,21,13,8,5,3 };
	tree.tree_print();
#endif // BALANCE_CHECK

}