#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

int main() 
{
	// 1. ?:
	int score;
	while (cin >> score && score < 100 && score >= 0) {
		string final_grade = (score > 90) ? "high pass" 
							: (score > 75) ? "pass"
							: (score >= 60) ? "low pass" : "fail";
		cout << score << ": " << final_grade << endl;
		cout << "Next: ";
	}
	
	cout << "if: " << endl;
	// 2. if
	while (cin >> score && score < 100 && score >= 0) {
		if (score > 90)
			cout << "high pass" << endl;
		else if (score > 75)
			cout << "pass" << endl;
		else if (score >= 60)
			cout << "low pass" << endl;
		else 
			cout << "fail" << endl;
		cout << "Next: ";
	}
	cout << "Done!" << endl;

	return 0;
}
