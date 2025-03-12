#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP


#include "IMateriaSource.hpp"
#include "List.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4]; 
    List head;
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    virtual ~MateriaSource();
    MateriaSource& operator=(const MateriaSource& other);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const& type);
};

#endif