#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

struct slot
{
    int courseid;
    int teacherid;
    string section;
    bool isbreak;
    slot() : courseid(-1), teacherid(-1), section(""), isbreak(false) {}
};

class Course
{
public:
    string name;
    int credithours;
    int id;
    vector<int> enrolledStudents;
    vector<int> availablecourses;
    Course(string n, int cc, int i)
    {
        name = n;
        credithours = cc;
        id = i;
    }
};

class Teacher
{
public:
    string name;
    int id;
    vector<int> teachingcourses;
    Teacher(string n, int i)
    {
        name = n;
        id = i;
    }
};

class Student
{
public:
    string name;
    int id;
    vector<int> registeredcourses;
    Student(string n, int i)
    {
        name = n;
        id = i;
    }
};

class TimetableSystem
{
public:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;
    map<string, vector<vector<slot>>> timetable;

    void addStudent(string name, int id)
    {
        students.push_back(Student(name, id));
        cout << "The student " << name << " has been successfully added " << endl;
    }

    void displayStudents()
    {
        cout << "Displaying all the currently available students " << endl;
        for (size_t i = 0; i < students.size(); i++)
        {
            cout << i << ". ID: " << students[i].id
                 << ", Name: " << students[i].name << endl;
        }
    }

    void deleteStudent(int id)
    {
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->id == id)
            {
                cout << "Deleting the student " << it->name << endl;
                students.erase(it);
                return;
            }
        }
        cout << "No student found with id " << id << endl;
    }

    void editStudent(int id, string newname)
    {
        for (auto i = students.begin(); i != students.end(); ++i)
        {
            if (i->id == id)
            {
                cout << "Editing the student with id " << id << endl;
                i->name = newname;
                return;
            }
        }
        cout << "No student found with the id " << id << endl;
    }

    void addTeacher(string name, int id)
    {
        teachers.push_back(Teacher(name, id));
        cout << "Teacher " << name << " has been successfully added " << endl;
    }

    void displayTeachers()
    {
        cout << "Displaying all available Teachers " << endl;
        for (size_t i = 0; i < teachers.size(); i++)
        {
            cout << i << " : " << teachers[i].id << " :: " << teachers[i].name << endl;
        }
    }

    void deleteTeacher(int id)
    {
        for (auto i = teachers.begin(); i != teachers.end(); ++i)
        {
            if (i->id == id)
            {
                cout << "Deleting teacher with id " << id << endl;
                teachers.erase(i);
                return;
            }
        }
        cout << "No teacher with id " << id << " found " << endl;
    }

    void editTeacherName(int id, string newname)
    {
        for (auto i = teachers.begin(); i != teachers.end(); ++i)
        {
            if (i->id == id)
            {
                cout << "Updating teacher with id " << id << endl;
                i->name = newname;
                return;
            }
        }
        cout << "Teacher with id " << id << " not found " << endl;
    }

    void addCourse(string name, int cc, int id)
    {
        courses.push_back(Course(name, cc, id));
        cout << "Course " << name << " has been successfully added " << endl;
    }

    void deleteCourse(int id)
    {
        for (auto i = courses.begin(); i != courses.end(); ++i)
        {
            if (i->id == id)
            {
                cout << "Deleting course with id " << id << endl;
                courses.erase(i);
                return;
            }
        }
        cout << "The course with id " << id << " does not exist " << endl;
    }

    void updateCourseName(int id, string newname)
    {
        for (auto i = courses.begin(); i != courses.end(); ++i)
        {
            if (i->id == id)
            {
                cout << "Updating the name of course with id " << id << endl;
                i->name = newname;
                return;
            }
        }
        cout << "No course found with the entered id" << endl;
    }

    void updateCourseCreditHours(int id, int newcc)
    {
        for (auto i = courses.begin(); i != courses.end(); ++i)
        {
            if (i->id == id)
            {
                cout << "Updating the credithours of course with id " << id << endl;
                i->credithours = newcc;
                return;
            }
        }
        cout << "No course found with the entered id" << endl;
    }

    void displayCourses()
    {
        cout << "Displaying all available courses " << endl;
        for (size_t i = 0; i < courses.size(); i++)
        {
            cout << "[ID]: " << courses[i].id << "  [CC:] " << courses[i].credithours << " [NAME]: " << courses[i].name << endl;
        }
    }

    void assignTeacherToCourse(int teacherid, int courseid)
    {
        for (auto &t : teachers)
        {
            if (t.id == teacherid)
            {
                if (find(t.teachingcourses.begin(), t.teachingcourses.end(), courseid) != t.teachingcourses.end())
                {
                    cout << "Teacher " << t.name << " is already assigned to course " << courseid << endl;
                    return;
                }

                if (t.teachingcourses.size() >= 4)
                {
                    cout << "Teacher " << t.name << " cannot be assigned more than 4 courses!" << endl;
                    return;
                }

                t.teachingcourses.push_back(courseid);
                cout << "Course " << courseid << " assigned to teacher " << t.name << endl;
                return;
            }
        }

        cout << "No teacher found with ID " << teacherid << endl;
    }

    void assignCourseToStudent(int studentid, int courseid)
    {
        for (auto &s : students)
        {
            if (s.id == studentid)
            {
                if (find(s.registeredcourses.begin(), s.registeredcourses.end(), courseid) != s.registeredcourses.end())
                {
                    cout << "The course " << courseid << " is already registered for student " << s.name << endl;
                    return;
                }
                int totalCC = 0;
                for (int cid : s.registeredcourses)
                {
                    for (auto &c : courses)
                    {
                        if (c.id == cid)
                        {
                            totalCC += c.credithours;
                        }
                    }
                }
                int newCourseCC = -1;
                for (auto &c : courses)
                {
                    if (c.id == courseid)
                    {
                        newCourseCC = c.credithours;
                        break;
                    }
                }

                if (newCourseCC == -1)
                {
                    cout << "Course with ID " << courseid << " not found!" << endl;
                    return;
                }

                if (totalCC + newCourseCC > 20)
                {
                    cout << "Cannot register course " << courseid << " for student " << s.name
                         << " (would exceed 20 credit hours)" << endl;
                    return;
                }

                s.registeredcourses.push_back(courseid);
                cout << "Course " << courseid << " assigned to student " << s.name << endl;
                return;
            }
        }
        cout << "No student found with ID " << studentid << endl;
    }

    TimetableSystem()
    {
        courses.push_back(Course("Math", 3, 101));
        courses.push_back(Course("Physics", 4, 102));
        courses.push_back(Course("Programming", 3, 103));
        courses.push_back(Course("Database", 3, 104));
        courses.push_back(Course("English", 2, 105));

        teachers.push_back(Teacher("Dr. Smith", 201));
        teachers.push_back(Teacher("Prof. Johnson", 202));
        teachers.push_back(Teacher("Ms. Clark", 203));
        teachers.push_back(Teacher("Mr. Lee", 204));

        students.push_back(Student("Alice", 301));
        students.push_back(Student("Bob", 302));
        students.push_back(Student("Charlie", 303));
        initialTimetable({"A", "B", "C"});
        preloadTimetable({"A", "B", "C"});
    }

    void initialTimetable(vector<string> sections)
    {
        for (auto &sec : sections)
        {
            timetable[sec] = vector<vector<slot>>(5, vector<slot>(9));
            for (int d = 0; d < 5; d++)
            {
                timetable[sec][d][4].isbreak = true;
            }
        }
    }

    bool assignCourseToSlot(string section, int day, int slotIdx, int courseid, int teacherid)
    {
        if (timetable.find(section) == timetable.end())
        {
            cout << "Section " << section << " not found " << endl;
            return false;
        }
        if (timetable[section][day][slotIdx].isbreak)
        {
            cout << "Slot is at break, cannot assign any class" << endl;
            return false;
        }
        if (timetable[section][day][slotIdx].courseid != -1)
        {
            cout << "Slot already occupied! \n" << endl;
            return false;
        }
        timetable[section][day][slotIdx].courseid = courseid;
        timetable[section][day][slotIdx].teacherid = teacherid;
        timetable[section][day][slotIdx].section = section;
        cout << "Assigned course " << courseid << " to section " << section
             << " on day " << day << " slot " << slotIdx << endl;
        return true;
    }

    void displayTimetable(string section)
    {
        if (timetable.find(section) == timetable.end())
        {
            cout << "No timetable found for section " << section << endl;
            return;
        }
        vector<string> days = {
            "MON",
            "TUES",
            "WED",
            "THURS",
            "FRI"};
        for (int d = 0; d < 5; d++)
        {
            cout << days[d] << " : ";
            for (int s = 0; s < 9; s++)
            {
                if (timetable[section][d][s].isbreak)
                {
                    cout << " [Break] ";
                }
                else if (timetable[section][d][s].courseid == -1)
                {
                    cout << " [Free] ";
                }
                else
                {
                    cout << "[C:" << timetable[section][d][s].courseid
                         << " T:" << timetable[section][d][s].teacherid << "] ";
                }
            }
            cout << endl;
        }
    }

    void preloadTimetable(vector<string> sections)
    {
        srand((unsigned)time(0));
        for (auto &sec : sections)
        {
            if (timetable.find(sec) == timetable.end())
            {
                cout << "Section " << sec << " not initialized, skipping...\n";
                continue;
            }

            for (int d = 0; d < 5; d++)
            {
                vector<set<int>> busyTeachers(9);

                for (int s = 0; s < 9; s++)
                {
                    if (timetable[sec][d][s].isbreak)
                        continue;

                    int ci = rand() % courses.size();
                    int courseid = courses[ci].id;
                    int courseCC = courses[ci].credithours;

                    int teacherid = -1;
                    for (size_t tries = 0; tries < teachers.size(); tries++)
                    {
                        int ti = rand() % teachers.size();
                        if (busyTeachers[s].count(teachers[ti].id) == 0)
                        {
                            teacherid = teachers[ti].id;
                            busyTeachers[s].insert(teacherid);
                            break;
                        }
                    }
                    if (teacherid == -1)
                    {
                        cout << "No free teacher for Section " << sec
                             << " Day " << d << " Slot " << s << endl;
                        continue;
                    }

                    timetable[sec][d][s].courseid = courseid;
                    timetable[sec][d][s].teacherid = teacherid;
                    timetable[sec][d][s].section = sec;

                    int si = rand() % students.size();
                    Student &stud = students[si];

                    int totalCC = 0;
                    for (int cid : stud.registeredcourses)
                    {
                        for (auto &c : courses)
                        {
                            if (c.id == cid)
                                totalCC += c.credithours;
                        }
                    }

                    if (totalCC + courseCC <= 20)
                    {
                        stud.registeredcourses.push_back(courseid);
                        cout << "Assigned [C:" << courseid << "] [T:" << teacherid
                             << "] [Sec:" << sec << "] on Day " << d
                             << " Slot " << s << " (Student " << stud.name << " enrolled)\n";
                    }
                    else
                    {
                        cout << "Student " << stud.name << " skipped, credit limit exceeded\n";
                    }
                }
            }
        }
    }
};

int main()
{
    TimetableSystem sys;
    int choice;

    do
    {
        cout << "\n===== TIMETABLE SYSTEM MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Edit Student Name\n";
        cout << "5. Add Teacher\n";
        cout << "6. Display Teachers\n";
        cout << "7. Delete Teacher\n";
        cout << "8. Edit Teacher Name\n";
        cout << "9. Add Course\n";
        cout << "10. Display Courses\n";
        cout << "11. Delete Course\n";
        cout << "12. Update Course Name\n";
        cout << "13. Update Course Credit Hours\n";
        cout << "14. Assign Teacher to Course\n";
        cout << "15. Assign Course to Student\n";
        cout << "16. Display Timetable (by Section)\n";
        cout << "17. Regenerate Timetable (init sections + randomize)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int id;
            cout << "Enter student name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter student id: ";
            cin >> id;
            sys.addStudent(name, id);
            break;
        }
        case 2:
            sys.displayStudents();
            break;

        case 3:
        {
            int id;
            cout << "Enter student id: ";
            cin >> id;
            sys.deleteStudent(id);
            break;
        }
        case 4:
        {
            int id;
            string newname;
            cout << "Enter student id: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> ws;
            getline(cin, newname);
            sys.editStudent(id, newname);
            break;
        }
        case 5:
        {
            string name;
            int id;
            cout << "Enter teacher name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter teacher id: ";
            cin >> id;
            sys.addTeacher(name, id);
            break;
        }
        case 6:
            sys.displayTeachers();
            break;

        case 7:
        {
            int id;
            cout << "Enter teacher id: ";
            cin >> id;
            sys.deleteTeacher(id);
            break;
        }
        case 8:
        {
            int id;
            string newname;
            cout << "Enter teacher id: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> ws;
            getline(cin, newname);
            sys.editTeacherName(id, newname);
            break;
        }
        case 9:
        {
            string name;
            int id, cc;
            cout << "Enter course name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter course id: ";
            cin >> id;
            cout << "Enter credit hours: ";
            cin >> cc;
            sys.addCourse(name, cc, id);
            break;
        }
        case 10:
            sys.displayCourses();
            break;

        case 11:
        {
            int id;
            cout << "Enter course id: ";
            cin >> id;
            sys.deleteCourse(id);
            break;
        }
        case 12:
        {
            int id;
            string newname;
            cout << "Enter course id: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> ws;
            getline(cin, newname);
            sys.updateCourseName(id, newname);
            break;
        }
        case 13:
        {
            int id, cc;
            cout << "Enter course id: ";
            cin >> id;
            cout << "Enter new credit hours: ";
            cin >> cc;
            sys.updateCourseCreditHours(id, cc);
            break;
        }
        case 14:
        {
            int tid, cid;
            cout << "Enter teacher id: ";
            cin >> tid;
            cout << "Enter course id: ";
            cin >> cid;
            sys.assignTeacherToCourse(tid, cid);
            break;
        }
        case 15:
        {
            int sid, cid;
            cout << "Enter student id: ";
            cin >> sid;
            cout << "Enter course id: ";
            cin >> cid;
            sys.assignCourseToStudent(sid, cid);
            break;
        }
        case 16:
        {
            string sec;
            cout << "Enter section name: ";
            cin >> sec;
            sys.displayTimetable(sec);
            break;
        }
        case 17:
        {
            int n;
            cout << "How many sections to initialize? ";
            cin >> n;
            vector<string> secs;
            for (int i = 0; i < n; ++i)
            {
                string s;
                cout << "Section " << (i + 1) << ": ";
                cin >> s;
                secs.push_back(s);
            }
            sys.initialTimetable(secs);
            sys.preloadTimetable(secs);
            cout << "Timetable regenerated for given sections.\n";
            break;
        }
        case 0:
            break;

        default:
            cout << "Invalid choice\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
