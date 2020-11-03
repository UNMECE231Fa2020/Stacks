#include <iostream>
#include "GenericStack.hpp"

int main() {
	Stack<float> r(3.14);

	r.push(4.72);
	std::cout << r.top() << '\n';

	r.push(9.38);
	std::cout << r.top() << '\n';
	std::cout << r << '\n';

	r.pop();
	r.print();

	Stack<float> q(r);
	std::cout << q << '\n';

	return 0;
}
