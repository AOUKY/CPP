# include "Serializer.hpp"

int main() {
    Data data = {42, "Alice"};
    Data* originalPtr = &data;

    
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized value :" << raw << std::endl;

    
    Data* restoredPtr = Serializer::deserialize(raw);

    
    std::cout << "Restored data: " << restoredPtr->name << " (" << restoredPtr->value << ")" << std::endl;
    std::cout << "Pointers match? " ;
	if(originalPtr == restoredPtr)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
    return 0;
}  