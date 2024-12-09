#include "ImageProxy.h"
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {

	if (argc <= 1) {
		std::cout << "no filenames were passed." << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		char* filename = argv[i];
		ImageProxy img(filename);
		std::cout << filename << " has size " << img.get_extent().width() << 'x' << img.get_extent().height() << std::endl;
	}
	return 0;
}