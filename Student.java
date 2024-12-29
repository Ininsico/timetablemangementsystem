import java.util.*;
abstract class Person{
    abstract public void name();
    abstract public void rollnumber();
}
class Student extends Person{
    private String name;
    private int Rollnumber;
    private char Section;
    @Override
    public void name(){
        System.out.println("Enter the name of the student");
        Scanner scanner = new Scanner(System.in);
         name = scanner.nextLine();
    }
    public String getname(){
        return name;
    }
    @Override
    public void rollnumber(){
         System.out.println("enter your roll number you want to choose between 1-100");
           Scanner scannner= new Scanner(System.in);
           Rollnumber = scannner.nextInt();
    }
    public int getrollnumber(){
        return Rollnumber;
    }
    public void Sectiongenerator(){
        if (Rollnumber>0 && Rollnumber<30){
            Section = 'A'; 
        }
        else if (Rollnumber>30 && Rollnumber<60){
            Section = 'B';
        }   
        else if(Rollnumber>60 && Rollnumber<100){
            Section = 'C';
        }
    }
    public char Section(){
        return Section;
    }
    public void Registrationinfo(){
           System.out.println("your Resgistration info is ");
           System.out.println("name:" + name);
           System.out.println("rollnumber: " +Rollnumber);
           System.out.println("Section is: "+Section);
    }
}

class Slot{
    private Courses course;
    private Teacher teacher;
    private ClassGroup classGroup;

    // Constructor
    public Slot(Courses course, Teacher teacher, ClassGroup classGroup) {
        this.course = course;
        this.teacher = teacher;
        this.classGroup = classGroup;
    }

    // Display Slot Details
    @Override
    public String toString() {
        return "Slot [Course=" + course.getCourseName() + ", Teacher=" + teacher.getTeacherName() + ", Class=" + classGroup.getClassName() + "]";
    }
 }

 class timeslot{
    int hour;
    int minute;
    public timeslot(int hour,int minute){
        this.hour = hour;
        this.minute = minute;
    }
    @Override
    public String toString(){
        return String.format("%02d:%02d", hour, minute);
    }
 }
 class Timetable{
    private Course[][] timetable;
    private String[][] classes;
    public static final int days=5;
    public static final int periods=6;
    // Constructor to initialize the timetable with DAYS and PERIODS
    public Timetable(int days,int periods) {
        classes = new String[days][periods];
    }
    public void courseTimetable(int days, int periods) {
        // Initialize timetable with null values (No course)
        timetable = new Course[days][periods];
    }
    public void setCourse(int day, int period, Course course) {
        timetable[day][period] = course;
    }
    public Course getCourse(int day, int period) {
        return timetable[day][period];
    }


    // Getter for the classes array
    public String[][] getClasses() {
        return classes;
    }
 }
 
 class Teacher {
    //create object to get instance of cousrses
    Courses courses=new Courses(); 
    // Store teacher names for each course
     private ArrayList<String> OOPteachers = new ArrayList<>();
     private ArrayList<String> Databaseteachers = new ArrayList<>();
     private ArrayList<String> CalculusTeachers = new ArrayList<>();
     private ArrayList<String> PPteachers = new ArrayList<>();
     private ArrayList<String> CNteachers = new ArrayList<>();
     private ArrayList<String> Newcoursenewteachers = new ArrayList<>();
     // Scanner instance for user input
     private Scanner scanner = new Scanner(System.in);
       
     // Constructor to initialize the teacher lists with default teachers
     public Teacher() {
         // Default teachers for courses
         OOPteachers.add("Umair Mujtaba");
         OOPteachers.add("Sara Shafique");
 
         Databaseteachers.add("Mohsin Fayyaz");
         Databaseteachers.add("Javid Ali");
 
         CalculusTeachers.add("Shamas-ul-Haq");
         CalculusTeachers.add("Ali Murtaza");
 
         PPteachers.add("Ahmed");
         PPteachers.add("Mustafa");

         CNteachers.add("Javid Raza");
         CNteachers.add("Ali Javid");
     }
 
     // Method to assign teacher for a course
     public void assignTeacher(String courseName) {
         ArrayList<String> teacherOptions = new ArrayList<>();
         String selectedTeacher = "";
 
         switch (courseName.toLowerCase()) {
             case "oop":
                 teacherOptions = OOPteachers;
                 break;
             case "database":
                 teacherOptions = Databaseteachers;
                 break;
             case "calculus":
                 teacherOptions = CalculusTeachers;
                 break;
             case "pp":
                 teacherOptions = PPteachers;
                 break;
             case "cn":
                 teacherOptions = CNteachers;
             case  "newcourseteacher":
                 teacherOptions = Newcoursenewteachers;
             default:
                 System.out.println("Course not recognized.");
                 return;
         }
 
         // Show available teachers and prompt the user to choose
         System.out.println("Choose a teacher for " + courseName + ":");
         for (int i = 0; i < teacherOptions.size(); i++) {
             System.out.println((i + 1) + ": " + teacherOptions.get(i));
         }
         System.out.println((teacherOptions.size() + 1) + ": Enter a new teacher name");
 
         int choice = scanner.nextInt();
         scanner.nextLine();  // Consume newline character
 
         if (choice >= 1 && choice <= teacherOptions.size()) {
             // Assign the selected teacher
             selectedTeacher = teacherOptions.get(choice - 1);
         } else if (choice == teacherOptions.size() + 1) {
             // Add a new teacher
             selectedTeacher = addNewTeacher(courseName);
         } else {
             System.out.println("Invalid choice. Please try again.");
             assignTeacher(courseName); // Retry
             return;
         }
 
         // Assign teacher to course
         System.out.println(courseName + " assigned to teacher: " + selectedTeacher);
     }
 
     // Method to add a new teacher for a given course
     private String addNewTeacher(String courseName) {
         System.out.println("Enter the name of the new teacher for " + courseName + ":");
         String newTeacher = scanner.nextLine();
 
         // Add the new teacher to the respective list
         switch (courseName.toLowerCase()) {
             case "oop":
                 OOPteachers.add(newTeacher);
                 break;
             case "database":
                 Databaseteachers.add(newTeacher);
                 break;
             case "calculus":
                 CalculusTeachers.add(newTeacher);
                 break;
             case "pp":
                 PPteachers.add(newTeacher);
                 break;
             case "cn":
                 CNteachers.add(newTeacher);
             case "newcourse":
                  Newcoursenewteachers.add(newTeacher);
                 default:
                 System.out.println("Course not recognized.");
                 return null;
         }
 
         // Return the name of the newly added teacher
         System.out.println("New teacher added: " + newTeacher);
         return newTeacher;
     }
 
     // Optionally, you can provide getter methods to retrieve teacher names for each course
     public ArrayList<String> getOOPTeachers() {
         return OOPteachers;
     }
 
     public ArrayList<String> getDatabaseTeachers() {
         return Databaseteachers;
     }
 
     public ArrayList<String> getCalculusTeachers() {
         return CalculusTeachers;
     }
 
     public ArrayList<String> getPPTeachers() {
         return PPteachers;
     }
     public ArrayList<String> getCNTeachers(){
         return CNteachers;
     }
     public ArrayList<String> getnewteachername(){
        return Newcoursenewteachers;
     }
 }
 class course{
    Map<String,String> courseteachers;
    public course(){
        this.courseteachers=new HashMap<>();
    }
        public void addTeacherToCourse(String coursename,String teachername){
                 courseteachers.put(coursename, teachername);x     bnnnnnnnnnnnnnnnn
        }
        public String getteacherforcourse(String coursename){
            return courseteachers.get(coursename);
        }
    }

 class courselinked{
      public void  courselinkingwithteachers(){
        course course = new course();
        Courses courses = new Courses();
        Teacher teacher = new Teacher();
      }
 }
 
 class Courses {
     private int maximumCreditHours = 20;
     private int minimumCreditHours = 10;
     private int totalCreditHours = 0;
     private String courseName;
     private int creditHours;
     private ArrayList<String> courses = new ArrayList<>();
     private ArrayList<Integer> creditHoursList = new ArrayList<>();
 
     // Instance of Teacher class to manage teacher assignments
     private Teacher teacherManager = new Teacher();
 
     // Default courses
     public void defaultCourses() {
         courses.add("Database");
         creditHoursList.add(4);  
         totalCreditHours += 4;
 
         courses.add("Calculus");
         creditHoursList.add(3);  
         totalCreditHours += 3;
 
         courses.add("OOP");
         creditHoursList.add(4);  
         totalCreditHours += 4;
 
         courses.add("CN");
         creditHoursList.add(3);  
         totalCreditHours += 3;
 
         courses.add("ProfessionalPractices");
         creditHoursList.add(2);  
         totalCreditHours += 2;
     }
 
     public ArrayList<String> getDefaultCourses() {
         return courses;
     }
 
     private String normalizeCourseName(String courseName) {
         return courseName.toLowerCase();  
     }
 
     public void addNewCourses() {
         System.out.println("How many courses do you want to add?");
         Scanner scanner = new Scanner(System.in);
         int choice = scanner.nextInt();
 
         for (int i = 0; i < choice; i++) {
             System.out.println("Enter the name of the course you want to add:");
             Scanner scanner2 = new Scanner(System.in);
             String newCourseName = scanner2.nextLine();
 
             newCourseName = normalizeCourseName(newCourseName);
 
             // Check if the course exists
             if (courses.stream().anyMatch(course -> normalizeCourseName(course).equals(newCourseName))) {
                 System.out.println("Course already exists.");
                 continue;
             }
 
             System.out.println("Enter the credit hours for the course (max 4): ");
             int creditHoursForNewCourse = scanner.nextInt();
 
             if (creditHoursForNewCourse < 1 || creditHoursForNewCourse > 4) {
                 System.out.println("Invalid credit hours. Max credit for a course is 4.");
                 continue;
             }
 
             if (totalCreditHours + creditHoursForNewCourse > maximumCreditHours) {
                 System.out.println("Cannot add this course. It will exceed the maximum credit hour limit.");
                 continue;
             }

 
             courses.add(newCourseName);
             creditHoursList.add(creditHoursForNewCourse);
             totalCreditHours += creditHoursForNewCourse;
 
             System.out.println("Course " + newCourseName + " added successfully.");
             
             // Ask for teacher assignment
             teacherManager.assignnewTeacher(newCourseName);
         }
     }
 
     // Display current courses and credit hours
     public void displayCourses() {
         System.out.println("Current courses and their credit hours:");
         for (int i = 0; i < courses.size(); i++) {
             System.out.println(courses.get(i) + " - " + creditHoursList.get(i) + " credit hours");
         }
         System.out.println("Total credit hours: " + totalCreditHours);
     }
 }
 
    // Method to delete a course
    public void deleteCourses() {
        System.out.println("How many courses do you want to delete?");
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();

        if (totalCreditHours - minimumCreditHours < totalCreditHours) {
            System.out.println("Cannot delete courses. It will drop below the minimum credit hours.");
            return;
        }

        System.out.println("Available courses: ");
        for (int i = 0; i < courses.size(); i++) {
            System.out.println((i + 1) + ": " + courses.get(i));
        }

        for (int i = 0; i < choice; i++) {
            System.out.println("Enter the index of the course you want to delete:");

            Scanner scanner2 = new Scanner(System.in);
            int courseIndex = scanner2.nextInt() - 1;

            if (courseIndex < 0 || courseIndex >= courses.size()) {
                System.out.println("Invalid index.");
                continue;
            }

            String courseToDelete = courses.get(courseIndex);
            int courseCreditHours = creditHoursList.get(courseIndex);

            // Ensure that deleting the course doesn't drop the total credit hours below the minimum
            if (totalCreditHours - courseCreditHours < minimumCreditHours) {
                System.out.println("Cannot delete " + courseToDelete + ". It will drop below the minimum credit hours.");
                continue;
            }

            // Remove the course and update total credit hours
            courses.remove(courseIndex);
            creditHoursList.remove(courseIndex);
            totalCreditHours -= courseCreditHours;
            System.out.println(courseToDelete + " deleted successfully.");
        }
    }

}
