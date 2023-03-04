#include<iostream>

#include<SimpleEngineCore/Utils/test.hpp>

int main() {
	std::cout << "Hello from Simple Engine Editor\n";
	
	SimpleEngine::checkGLFW();

	std::cin.get();
	return 0;
}