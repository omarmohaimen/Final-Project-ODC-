#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Department
{
private:

    string name;
    int capacity;
    double required_gpa;

public:
    Department() {}

    Department(string name, int capacity, double required_gpa)
    {
        this->name = name;
        this->capacity = capacity;
        this->required_gpa = required_gpa;
    }

    void Set_Name(string name)
    {
        this->name = name;
    }
    void Set_Capacity(int capacity)
    {
        this->capacity = capacity;
    }
    void Set_Required_Gpa(double required_gpa)
    {
        this->required_gpa = required_gpa;
    }

    string Get_Name()
    {
        return name;
    }
    int Get_Capacity()
    {
        return capacity;
    }
    double Get_Required_Gpa()
    {
        return required_gpa;
    }

    ~Department() {
        cout << "Hello" << endl;
    }

};
class Person
{
protected:
    // variables
    int id, age;
    string name;
    char gender;

public:

    //constructors
    Person() {};
    Person(int id, string name, int age, char gender)
    {
        this->age = age;
        this->id = id;
        this->gender = gender;
        this->name = name;
    };
    virtual void Attend() = 0;

    //setter
    void Set_Name(string name)
    {
        this->name = name;
    }
    void Set_Gender(char gender)
    {
        this->gender = gender;
    }
    void Set_Id(int id)
    {
        this->id = id;
    }
    void Set_Age(int age)
    {
        this->age = age;
    }

    //getter
    string Get_Name()
    {
        return name;
    }
    char Get_Gender()
    {
        return gender;
    }
    int Get_Id()
    {
        return id;
    }
    int Get_Age()
    {
        return age;
    }

    ~Person() {};

};
class Student : public Person
{
private:
    int level;
    double gpa;

public:


    /// constructor
    Student() {};
    Student(int id, string name, int age, char gender, int level, double gpa)
    {
        this->level = level;
        this->gpa = gpa;
        this->name = name;
        this->id = id;
        this->gender = id;
        this->age = age;
    }


    // start getter and setter functions
    // getter
    int Get_Gpa()
    {
        return gpa;
    };
    int Get_Level()
    {
        return level;
    };
    // End Getter
    // Setter
    void Set_Gpa(int Gpa)
    {
        this->gpa = Gpa;
    };
    void Set_Level(int Level)
    {
        this->level = Level;
    };
    // End setter
    // Start Students Functions

    void Study()
    {

    };
    void Take_Lesson()
    {

    };
    void Attend()
    {
        cout << "hi" << endl;
    };

    ~Student()
    {
        cout << "Destructor from Student class" << endl;
    }
    // End Students Functions
};
class Professor :public Person
{
private:
    Department* department;
    double salary;
    string degree;
public:
    Professor()
    {

    }
    Professor(double salary, string degree, Department* department, int id, string name, int age, char gender)
    {
        this->degree = degree;
        this->department = department;
        this->salary = salary;
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void Set_Department(Department* department)
    {
        this->department = department;
    }
    void Set_Salary(double salary)
    {
        this->salary = salary;
    }
    void Set_Degree(string degree)
    {
        this->degree = degree;
    }

    Department* Get_department()
    {
        return department;
    }
    int Get_Salary()
    {
        return salary;
    }
    string Get_Degree()
    {
        return degree;
    }
    void Teach()
    {

    };
    void Make_Exam()
    {

    };
    void Attend()
    {

    }
    ~Professor()
    {
        cout << "Destractor from Professor class " << endl;
    }


};
class Course
{
    // Private Variables
private:
    string code;
    string name;
    int hours;
    vector<Course*> prerequisites;
    Professor* professor;
    vector<Student*> students;

public:
    // constructor
    Course();
    Course(string code, string name, int hours, vector<Course*> prerequisites, Professor* professor, vector<Student*> students)
    {
        this->code = code;
        this->name = name;
        this->hours = hours;
        this->prerequisites = prerequisites;
        this->professor = professor;
        this->students = students;
    }
    // Method to add a prerequisite course
    void Set_Prerequisite(vector<Course*> prerequisite)
    {
        this->prerequisites = prerequisite;
    }
    // Method to add a professor
    void Set_Professor(Professor* professor)
    {
        this->professor = professor;
    }
    // Method to add a code
    void Set_code(string c)
    {
        code = c;
    }
    // Method to add a name
    void Set_Name(string c)
    {
        name = c;
    }
    // Method to add a Hours
    void Set_Hours(int c)
    {
        hours = c;
    }
    // Method to add a student
    void Set_Student(vector<Student*> student)
    {
        this->students = student;
    }

    // Getter methods
    string Get_code()
    {
        return code;
    }

    string Get_Name()
    {
        return name;
    }

    int Get_Hours()
    {
        return hours;
    }

    vector<Course*> Get_Prerequisites()
    {
        return prerequisites;
    }

    Professor* Get_Professor()
    {
        return professor;
    }

    vector<Student*> Get_Students() const
    {
        return students;
    }
}; // add , delete , update ; in university class
class University
{
private:
    University()
    {
        addData();
    };
    static University* ptr;
    vector<Student> students;
    vector<Department> departments;
    vector<Professor> professors;
    vector<Course> courses;

public:
    University(const University& obj) = delete;
    static University* get_pointer()
    {
        if (ptr == NULL)
        {
            ptr = new University();
            return ptr;
        }
        else
            return ptr;

    }
    ~University();

    // add course function to class course
    void Add_Course(string code, string name, int hours, vector<Course*> prerequisites, Professor* professor, vector<Student*> students)
    {
        Course course = Course(code, name, hours, prerequisites, professor, students);
        courses.push_back(course);
    }
    // update hours of course function to class course
    void Update_Course_Hours(string code, int newhours)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].Get_code() == code)
            {
                courses[i].Set_Hours(newhours);
            }
        }
    }
    // delete course function to class course
    void Delete_Course(string code)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].Get_code() == code)
            {
                courses.erase(courses.begin() + i);
            }
        }
    }
    void Add_Professor(double salary, string degree, Department* department, int id, string name, int age, char gender) {
        Professor p1(salary, degree, department, id, name, age, gender);//object from class professor

        professors.push_back(p1);


    }
    void Update_Professor(int id, double salary) {
        for (int i = 0; i < professors.size(); i++) {
            if (professors[i].Get_Id() == id) {
                professors[i].Set_Salary(salary);
                return;
            }
        }
    }
    void Delete_Professor(int id) {
        for (int i = 0; professors.size(); i++) {
            if (professors[i].Get_Id() == id) {
                professors.erase(professors.begin() + i);
                return;
            }

        }
        cout << "no professor with the same id " << endl;
    }
    void Add_Student(int id, string name, int age, char gender, int level, double gpa)
    {
        Student Student_Information(id, name, age, gender, level, gpa);
        students.push_back(Student_Information);
    }
    bool Update_Student(int id, double gpa) {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].Get_Id() == id)
            {
                students[i].Set_Gpa(gpa);
                return true;
            }
        }
        cout << "No Student with the same id";
        return false;
    }
    void Delete_Gpa(int id, double gpa) {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].Get_Id() == id)
            {
                students.erase(students.begin() + i);
                return;
            }
        }
        cout << "No Student with the same id";

    }
    void Add_Department(string name, int capacity, double required_gpa)
    {
        Department obj1 (name, capacity, required_gpa);
        departments.push_back(obj1);


    }
    void Update_Depatrment(string name, int capacity) {
        for (int i = 0; i < departments.size(); i++) {
            if (departments[i].Get_Name() == name) {
                departments[i].Set_Capacity(capacity);
                return;
            }

        }
        cout << "No Department With This Name Is Found !" << endl;

    }
    void Remove_Department(string name) {
        for (int i = 0; i < departments.size(); i++) {
            if (departments[i].Get_Name() == name) {
                departments.erase(departments.begin() + i);
                return;
            }
        }
        cout << "No Department With This Name Is Found !" << endl;
    }


    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1, "Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2, "Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3, "Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4, "Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5, "Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6, "Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7, "Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8, "Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(12000.0, "Masters", &d1, 1, "Mohamed Ali", 56, 'M');
        professors.push_back(p1);
        Professor p2(8500, "Masters", &d2, 2, "Ehsan Ahmed", 43, 'F');
        professors.push_back(p2);
        Professor p3(12000.0, "Masters", &d3, 1, "Ahmed Mohsen", 56, 'M');
        professors.push_back(p3);
        Professor p4(12000.0, "Masters", &d4, 1, "Mohamed Ali", 56, 'M');
        professors.push_back(p4);
        Professor p5(12000.0, "Masters", &d2, 1, "Mohamed Ali", 56, 'M');
        professors.push_back(p5);

        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML123", "HTML", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS123", "CSS", 9, crs1, &p3, st2);
        courses.push_back(c2);
        Course c3("Net521", "Networks", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for (int i = 0; i < departments.size(); i++)
        {
            cout << "Department: " << departments[i].Get_Name() << endl;
        }
        for (int i = 0; i < professors.size(); i++)
        {
            cout << "Professor Name: " << professors[i].Get_Name() << endl;
        }
        for (int i = 0; i < students.size(); i++)
        {
            cout << "Student Name: " << students[i].Get_Name() << endl;
        }
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Course Name: " << courses[i].Get_Name() << endl;
        }
    }
};

University* University::ptr = NULL;
//main function
int main()
{
    University* uni = University::get_pointer();
    uni->printAll();
    uni->Delete_Course("Net521");
    uni->Delete_Professor(1);
    uni->Delete_Gpa(1, 2.5);
    uni->Remove_Department("Web Development");
   uni->printAll();

}
