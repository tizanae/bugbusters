#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

class Student
{
	char name[40];
	char usf_id[10];
	char email[40];
	int gradeOfPresentation;
	int gradeOfEssay;
	int gradeOfProject;
public:
	Student(char *na, char *id, char * em, int gpre, int ge, int gpro) : gradeOfPresentation(gpre), gradeOfEssay(ge), gradeOfProject(gpro){
		strcpy(name, na);
		strcpy(usf_id, id);
		strcpy(email, em);
	}

	void setName(char *na) {
		strcpy(name, na);
	}

	char *getName() {
		return name;
	}

	void setId(char *id) {
		strcpy(usf_id, id);
	}

	char *getId() {
		return usf_id;
	}

	void setEmail(char *em) {
		strcpy(email, em);		
	}

	char *getEmail() {
		return email;
	}

	void setGradeOfPresentation(int gpre) {
		gradeOfPresentation = gpre;
	}

	int getGradeOfPresentation() {
		return gradeOfPresentation;
	}

	void setGradeOfEssay(int ge) {
		gradeOfEssay = ge;
	}

	int getGradeOfEssay() {
		return gradeOfEssay;
	}

	void setGradeOfProject(int gro) {
		gradeOfProject = gro;
	}

	int getGradeOfProject() {
		return gradeOfProject;
	}

	string info() {
		ostringstream oss;
		oss << this->getName() << " " << this->getId() << " " << this->getEmail() << " " 
			<< this->getGradeOfPresentation() << " " << this->getGradeOfEssay() << " " << this->getGradeOfProject();
		return oss.str();
	}
};

class DataManager {
	vector<Student> studentDatabase;
public:
	DataManager() {}
	void readStudentData(string filename) {
		studentDatabase.clear();
		ifstream fin(filename);
		char temp_name[40];
		char temp_id[40];
		char temp_email[40];
		int gpre, ge, gp;
		while (fin >> temp_name >> temp_id >> temp_email >> gpre >> ge >> gp) {
			studentDatabase.push_back(Student(temp_name, temp_id, temp_email, gpre, ge, gp));
		}
		fin.close();
	}
	void writeStudentData(string filename) {
		ofstream fout(filename);
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			fout << it->info() << endl;
		}
		fout.close();
	}

	void addStudent(Student s) {
		studentDatabase.push_back(s);
	}

	bool deleteStudent(char *id) {
		vector<Student>::iterator erasePos = studentDatabase.end();
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				erasePos = it;
				break;
			}
		}
		return studentDatabase.erase(erasePos) == erasePos;
	}

	void serachByName(char *name) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getName(), name) == 0) {
				cout << it->info() << endl;
				return;
			}
		}
	}

	void serachById(char *id) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				cout << it->info() << endl;
				return;
			}
		}
	}

	void serachByEmail(char *email) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getEmail(), email) == 0) {
				cout << it->info() << endl;
				return;
			}
		}
	}

	void updateStudentName(char *id, char *newName) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setName(newName);
				return;
			}
		}
	}

	void updateStudentId(char *id, char *newId) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setId(newId);
				return;
			}
		}
	}

	void updateStudentEmail(char *id, char *newEmail) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setEmail(newEmail);
				return;
			}
		}
	}

	void updateStudentGradeOfPresentation(char *id, int grp) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfPresentation(grp);
				return;
			}
		}
	}

	void updateStudentGradeOfEssay(char *id, int ge) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfEssay(ge);
				return;
			}
		}
	}

	void updateStudentGradeOfProject(char *id, int gp) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfProject(gp);
				return;
			}
		}
	}
};

class TUI {
	DataManager manager;
public:
	TUI() {
		string file;
		cout << "Please enter the data file to initialize the database" << endl;
		cin >> file;
		manager.readStudentData(file);
	}
	void run() {
		while (true) {
			cout << "1.- Write students' data to file" << endl;
			cout << "2.- Add student" << endl;
			cout << "3.- Delete student by id" << endl;
			cout << "4.- Search student by name" << endl;
			cout << "5.- Search student by id" << endl;
			cout << "6.- Search student by email" << endl;
			cout << "7.- Update student info" << endl;
			cout << "Please select your choice or enter any other value to terminate the program" << endl;
			int choice;
			cin >> choice;
			cin.get();
			if (choice == 1) {
				cout << "Please enter the output file's name: ";
				string output;
				cin >> output;
				manager.writeStudentData(output);
				cout << "Done!" << endl << endl;
			}
			else if (choice == 2) {
				cout << "Please enter the student's information on 1 line( name id email presentationGrade essayGrade projectGrade):" << endl;
				string input;
				getline(cin, input);
				istringstream iss(input);
				char name[40], id[10], email[40];
				int gpre, ge, gpro;
				iss >> name >> id >> email >> gpre >> ge >> gpro;
				manager.addStudent(Student(name, id, email, gpre, ge, gpro));
				cout << "Done!" << endl << endl;
			}
			else if (choice == 3) {
				cout << "Please enter the student's id:" << endl;
				char id[10];
				cin >> id;
				if (manager.deleteStudent(id)) {
					cout << "Delete successfully." << endl;
				}
				else {
					cout << "Failed to delete" << endl;
				}
				cout << endl;
			}
			else if (choice == 4) {
				cout << "Please enter the student's name:" << endl;
				char name[30];
				cin >> name;
				manager.serachByName(name);
				cout << "Done!" << endl << endl;
			}
			else if (choice == 5) {
				cout << "Please enter the student's id:" << endl;
				char id[10];
				cin >> id;
				manager.serachById(id);
				cout << "Done!" << endl << endl;
			}
			else if (choice == 6) {
				cout << "Please enter the student's email:" << endl;
				char email[30];
				cin >> email;
				manager.serachByEmail(email);
				cout << "Done!" << endl << endl;
			}
			else if (choice == 7) {
				cout << "Please enter the student's id:" << endl;
				char id[10];
				cin >> id;
				manager.serachById(id);
				cout << "Please enter item you want to update: (1 name, 2 id, 3 email, 4 grade of presentation, 5 grade of essay, 6 grade of project" << endl;
				int item;
				cin >> item;
				if (item == 1) {
					char name[40];
					cin >> name;
					manager.updateStudentName(id, name);
				}
				else if(item == 2){
					char newid[10];
					cin >> newid;
					manager.updateStudentId(id, newid);
				}
				else if (item == 3) {
					char email[40];
					cin >> email;
					manager.updateStudentEmail(id, email);
				}
				else if(item == 4){
					int temp;
					cin >> temp;
					manager.updateStudentGradeOfPresentation(id, temp);
				}
				else if (item == 5) {
					int temp;
					cin >> temp;
					manager.updateStudentGradeOfEssay(id, temp);
				}
				else if (item == 6) {
					int temp;
					cin >> temp;
					manager.updateStudentGradeOfProject(id, temp);
				}
				cout << "Done!" << endl << endl;
			}
			else
			{
				cout << "Terminating program...\n\nSee you later!" << endl;
				exit(0);
			
			}
		}	
		
	}
};

int main() 
{
	TUI managerSystem;
	managerSystem.run();
	return 0;
}
