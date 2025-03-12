#include "List.hpp"


List::List() : head(0) {}
List::~List() { freeList(); }
List::List(const List &other) { *this = other; }
List& List::operator=(const List &other)
{
	if (this != &other)
	{
		freeList();
		MateriaNode *current = other.head;
		while (current)
		{
			addMateria(current->materia->clone());
			current = current->next;
		}
	}
	return *this;
}

void List::freeList()
{
	MateriaNode *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp->materia;
		tmp->materia = 0;
		delete tmp;
		tmp = 0;
	}
	head = 0;
}

void List::addMateria(AMateria *newMateria)
{
	if (head == 0)
		head = new MateriaNode(newMateria);
	else
	{
		MateriaNode *current = head;
		while (current->next)
			current = current->next;
		current->next = new MateriaNode(newMateria);
	}
}