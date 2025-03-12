#ifndef LIST_HPP
#define LIST_HPP

# include"AMateria.hpp"

struct MateriaNode {
    AMateria* materia; 
    MateriaNode* next; 

    MateriaNode(AMateria* m) : materia(m), next(0) {}
};


class List
{
private:
    MateriaNode *head;
public:
    List();
    ~List();
    List(const List &other);
    List& operator=(const List &other);
    
    void freeList();
    void addMateria(AMateria* newMateria);
};

#endif