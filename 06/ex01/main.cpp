#include "serialization.hpp"

int	main()
{
	Data *data1 = new Data;
	
	data1->i = 65; data1->a = 1; data1->b = 0; data1->c = 0; data1->d = 0;
	std::cout << data1 << std::endl;
	uintptr_t ptr = serialize(data1);
	Data *data2 = deserialize(ptr);
	std::cout << data2 << std::endl;
	std::cout << *reinterpret_cast<int*>(ptr) << std::endl;
	std::cout << *reinterpret_cast<char*>(ptr) << std::endl;
	std::cout << *reinterpret_cast<int*>(ptr + 4) << std::endl;
	std::cout << data2->i << std::endl;
	delete data1;
	return (0);
}
