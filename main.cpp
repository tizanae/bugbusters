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
		oss << endl << "Name: " << this->getName() << "\nID: " << this->getId() << "\nEmail address: " << this->getEmail() << 
			"\nPresentation Grade: " << this->getGradeOfPresentation() << "\nEssay Grade: " << this->getGradeOfEssay() << 
			"\nProject Grade: " << this->getGradeOfProject();
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

	//check if file exists
	bool file_exists( const string& file){
				ifstream f(file.c_str());
				return f.good();
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

	// Declaring and defining the function that add a student to the database //
	void addStudent(Student s) {
		studentDatabase.push_back(s);
	}

	// Declaring and defining the function that deletes a student by id //
	bool deleteStudent(char *id) {
		// Declaring and intializing a vector iterator //
		vector<Student>::iterator erasePos = studentDatabase.end();
		
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				erasePos = it;
				return studentDatabase.erase(erasePos) == erasePos;
			}
		}
		return false;
	}

	// Declaring and defining the function that searches a student by name //
	bool searchByName(char *name) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getName(), name) == 0) {
				cout << it->info() << endl;
				return true;
			}
		}
		return false;
	}

	// Declaring and defining the function that searches a student by id //
	bool searchById(char *id) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				cout << it->info() << endl;
				return true;
			}
		}
		return false;
	}

	// Declaring and defining the function that searches a student by email //
	bool searchByEmail(char *email) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getEmail(), email) == 0) {
				cout << it->info() << endl;
				return true;
			}
		}
		return false;
	}

	// Declaring and defining the function that updates a student's name //
	void updateStudentName(char *id, char *newName) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				it->setName(newName);
				return;
			}
		}
	}

	// Declaring and defining the function that updates a student's id //
	void updateStudentId(char *id, char *newId) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				it->setId(newId);
				return;
			}
		}
	}

	// Declaring and defining the function that updates a student's email //
	void updateStudentEmail(char *id, char *newEmail) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				it->setEmail(newEmail);
				return;
			}
		}
	}

	// Declaring and defining the function that updates a student's grade of the presentation //
	void updateStudentGradeOfPresentation(char *id, int grp) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfPresentation(grp);
				return;
			}
		}
	}

	// Declaring and defining the function that updates a student's grade of the essay //
	void updateStudentGradeOfEssay(char *id, int ge) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfEssay(ge);
				return;
			}
		}
	}

	// Declaring and defining the function that updates a student's grade of the project //
	void updateStudentGradeOfProject(char *id, int gp) {
		// Running through the vector of students //
		for (vector<Student>::iterator it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
			// Searching for the requested student //
			if (strcmp(it->getId(), id) == 0) {
				it->setGradeOfProject(gp);
				return;
			}
		}
	}
};

// Declaring and defining the TUI class //
class TUI {
	// Declaring a DataManager variable //
	DataManager manager;

	public:
	
	// Reading a file to initialize the database //
	TUI() {
		// Declaring a string variable //
		string file;
		string msg[] = {"Please enter the data/file/name.txt to initialize the database: ", "File does not exist, please enter a valid file/name.txt: "};
		int i = 0;
		while (true){
			// Prompting for and reading in user input //
			cout << msg[i];
			cin >> file;
			if (manager.file_exists(file) == false){
				i = 1;
			} else {
				break;
			}
		}
		// Passing user input to the data manager //
		manager.readStudentData(file);
	}
	
	// Declaring and defining the system's running logic //
	void run() {
		// Declaring and initializing boolean flag for message printing //
		bool flag = true;
		
		// Establishing constant while loop //
		while (true) {
			// Prompting for and reading in user input for a selection //
			cout << "1.- Write students' data to a file" << endl;
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

			// Checking if the user wants to write student's data to a file //
			if (choice == 1) {
				// Declaring a string variable //
				string output;

				// Prompting for and reading in the desired name of the output file //
				cout << "Please enter the output/file/name.txt: ";
				cin >> output;

				// Passing user input to the data manager //
				manager.writeStudentData(output);

				// Printing success message //
				cout << endl << "File creation done!" << endl << endl;
			}
			// Checking if the user wants to add a student //
			else if (choice == 2) {
				// Prompting for the new student information // 
				cout << "Please enter the student's information on 1 line in the following format:\n" <<
					"{Name(without spaces)   ID   Email   Presentation Grade   Essay Grade   Project Grade}" << endl;
				
				// Declaring variables and reading in the new student information //
                                string input;
                                getline(cin, input);
                                istringstream iss(input);
                                char name[40], id[10], email[40];
                                int gpre, ge, gpro;
				iss >> name >> id >> email >> gpre >> ge >> gpro;

				// Passing user input to the data manager //
				manager.addStudent(Student(name, id, email, gpre, ge, gpro));

				// Printing success message //
				cout << endl << "Student addition done!" << endl << endl;
			}
			// Checking if the user wants to delete a student by id //
			else if (choice == 3) {
				// Declaring and initializing a character array variable //
				char id[10] = {0};
						
				// Prompting for and reading in user input for the desired id //
				cout << "Please enter the student's id:" << endl;
				cin >> id;

				// Checking if user deletion is successful //
				if (manager.deleteStudent(id)) {
					cout << endl << "Deleted successfully!" << endl;
				}
				else {
					cout << endl << "Failed to delete a student with such ID!" << endl;
				}
				cout << endl;
			}
			// Checking if the user wants to search a student by name //
			else if (choice == 4) {
				// Prompting for and reading in user input for the student's name //
				cout << "Please enter the student's name:" << endl;
				char name[30];
				cin >> name;

				// Passing user input to the data manager and checking if it was found //
				if (manager.searchByName(name)) {
					// Printing success message //
					cout << endl << "Student search done!" << endl << endl;
				}
				else {
					// Printing error message //
					cout << endl << "No student was found under that name!" << endl << endl;
				}
			}
			// Checking if the user wants to search a student by id //
			else if (choice == 5) {
				// Prompting for and reading in user input for the student's id //
				cout << "Please enter the student's id:" << endl;
				char id[10];
				cin >> id;

				// Passing user input to the data manager and checking if it was found //
				if (manager.searchById(id)) {
					// Printing success message //
					cout << endl << "Student search done!" << endl << endl;
				}
				else {
					// Printing error message //
					cout << endl << "No student was found with that ID!" << endl << endl;
				}
			}
			// Checking if the user wants to search a student by email address //
			else if (choice == 6) {
				// Prompting for and reading in user input for the student's email address //
				cout << "Please enter the student's email:" << endl;
				char email[30];
				cin >> email;

				// Passing user input to the data manager and checking if it was found //
				if (manager.searchByEmail(email)) {
					// Printing success message //
					cout << endl << "Student search done!" << endl << endl;
				}
				else {
					cout << endl << "No student was found with that email address!" << endl << endl;
				}
			}
			// Checking if the user wants to update a student's information //
			else if (choice == 7) {
				// Prompting for and reading in user input for the student's id //
				cout << "Please enter the student's id:" << endl;
				char id[10];
				cin >> id;

				// Passing user input to the data manager and checking if it was found //
				if(manager.searchById(id)) {
					// Prompting for and reading in user input for update type //
					cout << "\n1.- Name\n2.- ID\n3.- Email\n4.- Presentation Grade\n5.- Essay Grade\n" << 
						"6.- Project Grade\n\nPlease enter item you want to update:" << endl;
					int item;
					cin >> item;

					// Checking if user wants to update the student's name //
					if (item == 1) {
						// Declaring a character array variable //
						char name[40];

						// Prompting for and reading in user input for the new name//
						cout << endl << "Please enter the updated name:" << endl;
						cin >> name;

						// Passing user input to the data manager //
						manager.updateStudentName(id, name);
					}
					// Checking if user wants to update the student's id //
					else if(item == 2){
						// Declaring a character array variable //
						char newid[10];

						// Prompting for and reading in user input for the new id //
						cout << endl << "Please enter the updated ID:" << endl;
						cin >> newid;

						// Passing user input to the data manager //
						manager.updateStudentId(id, newid);
					}
					// Checking if user wants to update the student's email address //
					else if (item == 3) {
						// Declaring a character array variable //
						char email[40];

						// Prompting for and reading in user input for the new email //
						cout << endl << "Please enter the updated email address:" << endl;
						cin >> email;

						// Passing user input to the data manager //
						manager.updateStudentEmail(id, email);
					}
					// Checking if user wants to update the student's presentation grade //
					else if(item == 4){
						// Declaring an integer variable //
						int temp;

						// Prompting for and reading in user input for the new presentation grade //
						cout << endl << "Please enter the updated presentation grade:" << endl;
						cin >> temp;

						// Passing user input to the data manager //
						manager.updateStudentGradeOfPresentation(id, temp);
					}
					// Checking if user wants to update the student's essay grade //
					else if (item == 5) {
						// Declaring an integer variable //
						int temp;

						// Prompting for and reading in user input for the new essay grade //
						cout << endl << "Please enter the updated essay grade:" << endl;
						cin >> temp;

						// Passing user input to the data manager //
						manager.updateStudentGradeOfEssay(id, temp);
					}
					// Checking if user wants to update the student's project grade //
					else if (item == 6) {
						// Declaring an integer variable //
						int temp;

						// Prompting for and reading in user input for the new project grade //
						cout << endl << "Please enter the updated project grade:" << endl;
						cin >> temp;

						// Passing user input to the data manager //
						manager.updateStudentGradeOfProject(id, temp);
					}
					else {
						// Printing error message and setting flag to false //
						cout << endl << "Invalid selection!\n\nReturning to main menu... << endl << endl";
						flag = false;
					}
				
					// Checking if any of the valid options was selected //
					if (flag) {
						// Printing success message //
						cout << endl << "Information update done!" << endl << endl;
					}
				}
				else {
					// Printing error message //
					cout << endl << "No student was found with that email address!\n\nReturning to main menu..." << endl << endl;
				}
			}
			else {
				// Printing termination message and terminating program //
				cout << endl << "Terminating program...\n\nSee you later!" << endl << endl;
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
