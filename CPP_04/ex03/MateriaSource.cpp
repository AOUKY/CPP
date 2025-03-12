# include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for (int i = 0; i < 4; i++) {
        templates[i] = 0;
    }
    if(PRINT)
        std::cout<<"MateriaSource Default constructor called"<<std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.templates[i]) {
            templates[i] = other.templates[i]->clone(); 
        } else {
            templates[i] = 0;
        }
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        head.freeList();
        delete templates[i]; 
    }
    if(PRINT)
        std::cout<<"MateriaSource Defaoult destructor called"<<std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete templates[i]; 
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone(); 
            } else {
                templates[i] = 0;
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            if(PRINT)
                std::cout <<"MateriaSource learn the "<< m->getType() << " materia" << std::endl;
            templates[i] = m; 
            return ;
        }
    }
    head.addMateria(m);
    std::cout << "MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            if(PRINT)
                std::cout << "MateriaSource create the "<< type << " materia" << std::endl;
            return templates[i]->clone(); 
        }
    }
    std::cout << "MateriaSource can't create the "<< type << " materia" << std::endl;
    return 0; 
}