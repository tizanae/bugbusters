//===============================================================================================================================//
//=09/26/2017                                                                           	       			main.cpp=//
//=Alexander Alava                                                                                    		       U35432961=//
//=David Hoambrecker										      	               U09161932=//
//=Linqi Wang											      		       U03948584=//
//=Tizanae Nziramasanga										      		       U03337450=//
//=                                                                                                            			=//
//=                      This is the implementation file for the original version of the student database                       =//
//===============================================================================================================================//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

// Declaring and defining the Student class //
class Student
{
	// Declaring data members of the class //
	char name[40];
	char usf_id[10];
	char email[40];
	int gradeOfPresentation;
	int gradeOfEssay;
	int gradeOfProject;

	public:
	
	// Declaring and defining the constructor for the class //
	Student(char *na, char *id, char * em, int gpre, int ge, int gpro) : gradeOfPresentation(gpre), gradeOfEssay(ge), gradeOfProject(gpro){
		// Initializing data members from values passed as parameters //
		strcpy(name, na);
		strcpy(usf_id, id);
		strcpy(email, em);
	}

	// Declaring and defining the set method for the name //
	void setName(char *na) {
		strcpy(name, na);
	}

	// Declaring and defining the get method for the name //
	char *getName() {
		return name;
	}

	// Declaring and defining the set method for the ID //
	void setId(char *id) {
		strcpy(usf_id, id);
	}

	// Declaring and defining the get method for the ID //
	char *getId() {
		return usf_id;
	}

	// Declaring and defining the set method for the email //
	void setEmail(char *em) {
		strcpy(email, em);		
	}

	// Declaring and defining the get method for the email //
	char *getEmail() {
		return email;
	}

	// Declaring and defining the set method for the presentation grade //
	void setGradeOfPresentation(int gpre) {
		gradeOfPresentation = gpre;
	}

	// Declaring and defining the get method for the presentation grade //
	int getGradeOfPresentation() {
		return gradeOfPresentation;
	}

	// Declaring and defining the set method for the essay grade //
	void setGradeOfEssay(int ge) {
		gradeOfEssay = ge;
	}

	// Declaring and defining the get method for the essay grade //
	int getGradeOfEssay() {
		return gradeOfEssay;
	}

	// Declaring and defining the set method for the project grade //
	void setGradeOfProject(int gro) {
		gradeOfProject = gro;
	}

	// Declaring and defining the get method for the project grade //
	int getGradeOfProject() {
		return gradeOfProject;
	}

	// Declaring and defining the info function that returns all the information as a string //
	string info() {
		ostringstream oss;
		oss << this->getName() << " " << this->getId() << " " << this->getEmail() << " " 
			<< this->getGradeOfPresentation() << " " << this->getGradeOfEssay() << " " << this->getGradeOfProject();
		return oss.str();
	}
};

// Declaring and defining the data manager class that will maintain a vector storing the list of student's information //
class DataManager {
	// Declaring a vector of students //
	vector<Student> studentDatabase;

	public:
	
	// Declaring the constructor //
	DataManager() {}

	// Declaring and defining the function that reads student into database from file
	void readStudentData(string filename) {
		// Clearing current vector //
		studentDatabase.clear();

		// Receiving a file as an input stream //
		ifstream fin(filename);

		// Declaring temporary variables to process the file //
		char temp_name[40];
		char temp_id[40];
		char temp_email[40];
		int gpre, ge, gp;

		// Running through the inputted file and collecting information //
		while (fin >> temp_name >> temp_id >> temp_email >> gpre >> ge >> gp) {
			studentDatabase.push_back(Student(temp_name, temp_id, temp_email, gpre, ge, gp));
		}
	
		// Closing file input //
		fin.close();
	}

	// Declaring and defining the function that writes the current information to a text file // 
	void writeStudentData(string filename) {
		
		// Outputting information to output stream //
		ofstream fout(filename);

		// Running through all the current information in the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			fout << it->info() << endl;
		}

		// Closing file output //
		fout.close();
	}

	// add student to database
	void addStudent(Student s) {
		studentDatabase.push_back(s);
	}

	// delete student by id
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

	// search student by name
	void serachByName(char *name) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getName(), name) == 0) {
				cout << it->info() << endl;
				return;
			}
		}
	}

	//search student by id
	void serachById(char *id) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				cout << it->info() << endl;
				return;
			}
		}
	}

	//search student by email
	void serachByEmail(char *email) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getEmail(), email) == 0) {
				cout << it->info() << endl;
				return;
			}
		}
	}

	//update student name
	void updateStudentName(char *id, char *newName) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setName(newName);
				return;
			}
		}
	}

	//update student id
	void updateStudentId(char *id, char *newId) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setId(newId);
				return;
			}
		}
	}

	//update student email
	void updateStudentEmail(char *id, char *newEmail) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setEmail(newEmail);
				return;
			}
		}
	}

	//update student grade of presentation
	void updateStudentGradeOfPresentation(char *id, int grp) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfPresentation(grp);
				return;
			}
		}
	}

	//update student grade of essay
	void updateStudentGradeOfEssay(char *id, int ge) {
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfEssay(ge);
				return;
			}
		}
	}

	//update student grade of project
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
	//read file to initialize the database
	TUI() {
		string file;
		cout << "Please enter the data/file/name.txt to initialize the database: " ;
		cin >> file;
		manager.readStudentData(file);
	}
	
	//The system's running logic
	void run() {
		while (true) {
			cout << "1.- Write students' data to file" << endl;
			cout << "2.- Add student" << endl;
			cout << "3.- Delete student by id" << endl;
			cout << "4.- Search student by name" << endl;
			cout << "5.- Search student by id" << endl;
			cout << "6.- Search student by email" << endl;
			cout << "7.- Update student info" << endl;
			cout << "Please select your choice or enter any other value to terminate the program: " ;
			int choice;
			cin >> choice;
			cin.get();
			if (choice == 1) {
				cout << "Please enter the output/file/name.txt: ";
				string output;
				cin >> output;
				manager.writeStudentData(output);
				cout << "Done!" << endl << endl;
			}
			else if (choice == 2) {
				cout << "Please enter the student's information on 1 line in the following format:\n" <<
					"{Name(without spaces)   ID   Email   Presentation Grade   Essay Grade   Project Grade}" << endl;
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
