#include <iostream>
#include <fstream>
using namespace std;

struct Elem//структура каждого элемента списка
{
	int data;//значение элемента
	Elem* next;//ссылка на следующий элемент 
};

Elem* Head, * Tail;
int Count;//кол элем в списке

void Del(int pos);
void DelAll();
void AddTail(int n);
void Print();
int Search();

int main()
{
	setlocale(LC_ALL, "russian");
	;
	ifstream f("input.txt");//поток на считывания из файла 
	int e, n;
	while (!f.eof())//пока файл не закончился
	{
		f >> e;
		AddTail(e);
	}
	f.close();
	Print();
	cout << "Введите индекс элемента, который нужно удалить: ";
	cin >> n;
	Del(n);

	Print();
	cout << "Введите элемент, который нужно добавить: ";
	cin >> n;
	AddTail(n);
	Print();


	n = Search();

	cout << " Max элемент находится на " << n << " месте\n";
	DelAll();
	Print();
	system("pause");
	return 0;
}

void AddTail(int n)
{
	// создаём новый элемент
	Elem* temp = new Elem;//место под temp типа Elem в памяти 
	temp->next = 0; //temp последний элемент,следующего нет
	temp->data = n; // заполняем данные

	if (Tail != 0)//если хвост сущ
		Tail->next = temp;// добавляет указатель на следующий элемент
	if (Count == 0) //если список пустой, то добавляемый элемент одновременно начало и конец
		Head = Tail = temp;
	else
		//элемент хвостовой
		Tail = temp;
	Count++;
}
void DelAll()
{
	Elem* Del = NULL, * AfterDel = NULL;
	while (Count != 0)
	{
		Del = Head;
		AfterDel = Del->next;
		Head = AfterDel;
		delete Del;
		Count--;
	}
}
void Del(int pos)
{

	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}

	// Счетчик
	int i = 1;

	Elem* DelP = Head;
	Elem* Del = NULL;
	Elem* DelN;
	while (i < pos - 1)// Доходим до элемента, 
		// который удаляется
	{

		DelP = DelP->next;
		i++;
	}
	if (pos != 1)//иначе предыдущего перед удаляемым нет
	{
		Del = DelP->next;
		DelN = Del->next;

		// Доходим до элемента, 
		// который предшествует удаляемому

		// Доходим до элемента, который следует за удаляемым
	}

	else DelN = DelP->next;//если элемент первый записываем в следующий второй элемент списка
	DelP->next = DelN;


	// Удаляются крайние?
	if (pos == 1)
		Head = DelN;
	if (pos == Count)
		DelP->next = NULL;//удаляем ссылку на послдений
	if (pos != 1)
		// Удаление элемента
		delete Del;
	else delete DelP;

	Count--;
}

void Print()
{
	int i = 1;
	if (Head != NULL)
	{
		cout << "\nСписок:\n";
		Elem* temp = Head;
		while (temp->next != NULL)
		{
			cout << i << ": " << temp->data << endl;;
			temp = temp->next;
			i++;
		}
		cout << i << ": " << temp->data << endl << endl;
	}
	else cout << "\nСписок пустой!!\n\n";
}
int Search()
{

	int max = INT_MIN, i = 1, imax = 0;
	Elem* temp = Head;
	while (i != Count)
	{
		if (temp->data > max)
		{
			max = temp->data;
			imax = i;
		}
		i++;
		temp = temp->next;
	}
	return imax;
}
