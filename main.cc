#include <iostream>
#include "NtupleProcessor.hh"
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    try
	{
		if (argv[1]) {
			cout << "\n";
			cout << "The file is processing: " << argv[1] << endl;
			cout << "\n";
		}
		else {
			throw 0;
		}

		cout << "======================================\n";
		cout << "============== XCAL SIM ==============\n"; 
		cout << "======================================\n";
		
		NtupleProcessor ntplproc(argv[1],"",-1);

		cout << "\n";
		cout <<	"======================================\n";

	}
	catch (int exc)
	{
		cout << "\n";
		switch (exc) {
		case 0:
			cout << "[Error 000] No inputs given.\n";
			break;
		case 1:
			cout << "[Error 001] File does not exist.\n";
			break;
		default:
			break;
		}
		cout << "\n";

	}
}