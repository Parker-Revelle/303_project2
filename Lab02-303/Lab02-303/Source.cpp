#include <iostream>
#include <string>
using namespace std;

struct assignment {
	string title;
	int assigned;
	int due;
	assignment* next;
};

class menu {
public:
	
	
	char printMenu() {
		char userInput;
		cout << "Assignment collection and info:" << endl;
		cout << "A - Add assignment" << endl;
		cout << "D - Delete Assignment" << endl;
		cout << "V - View all assignments" << endl;
		cout << "TODO S - Sort assignments by date due" << endl;
		cout << "F - find specific assignment" << endl;
		cout << "Q - Quit" << endl;
		cout << "Enter choice -->";
		cin >> userInput;
		while (toupper(userInput) != 'A' and toupper(userInput) != 'D' and toupper(userInput) != 'V' and toupper(userInput) != 'S' and toupper(userInput) != 'F' and toupper(userInput) != 'Q') {
			cout << "Please select a valid option -->";
			cin >> userInput;
		}
		return userInput;

	}

	void option(assignment* head) {


		char userInput = printMenu();
		while (toupper(userInput) != 'Q') {
			if (toupper(userInput) == 'A') {
				string Title, Completed;
				int Due, Assigned;
				cout << "Making new assignment. Please enter assignment title:" << endl;
				cin.ignore();
				getline(cin, Title);
				cout << endl;
				cout << "Enter date assigned in format DDMMYY:" << endl;
				cin >> Assigned;
				cout << endl;
				cout << "Enter date due in format DDMMYY:" << endl;
				cin >> Due;
				cout << endl;
				

				if (head->title == "NULL") {
					head->title = Title;
					head->assigned = Assigned;
					head->due = Due;
					

				}

				else {
					assignment* tp = new assignment();
					assignment* newAssign = new assignment();

					tp->next = head;
					newAssign->title = Title;
					newAssign->assigned = Assigned;
					newAssign->due = Due;
					
					newAssign->next = NULL;

					while (tp->next != NULL) {
						tp = tp->next;
					}

					tp->next = newAssign;


				}
				cout << endl;


			}

			if (toupper(userInput) == 'V') {
				cout << endl;
				cout << "Assignments:" << endl;
				assignment* tp = new assignment();
				tp->next = head;
				while (tp->next != NULL) {
					cout << "Title: " << tp->next->title << endl;
					cout << "Assigned date: " << tp->next->assigned << endl;
					cout << "Due date: " << tp->next->due << endl;
					
					cout << endl;
					tp = tp->next;
				}
			}

			if (toupper(userInput) == 'F') {
				string Title;
				cout << endl;
				cout << "Enter assignment title:" << endl;
				cin.ignore();
				getline(cin, Title);
				assignment* tp = new assignment();
				tp->next = head;
				while (tp->next != NULL) {
					if (tp->next->title == Title) {
						cout << "Title: " << tp->next->title << endl;
						cout << "Assigned date: " << tp->next->assigned << endl;
						cout << "Due date: " << tp->next->due << endl;
						
						cout << endl;
						break;
					}
					tp = tp->next;
				}
			}

			if (toupper(userInput) == 'D') {
				string Title;
				cout << endl;
				cout << "Enter assignment title to remove:" << endl;
				cin.ignore();
				getline(cin, Title);
				assignment* tp = new assignment();
				tp->next = head;
				while (tp->next != NULL) {
					if (tp->next->title == Title) {
						if (tp->next->next == NULL) {
							tp->next = NULL;
						}
						else {
							tp->next = tp->next->next;
						}
						break;
					}
					tp = tp->next;
				}
			}

			if (toupper(userInput) == 'S') {

			}

			userInput = printMenu();
		}
		
	}
};

void main() {
	assignment* head;
	head = new assignment();
	head->title = "NULL";
	head->next = NULL;
	menu x = menu();
	x.option(head);
	

}