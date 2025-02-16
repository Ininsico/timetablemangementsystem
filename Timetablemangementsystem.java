import java.util.Random;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

// Interface representing user roles
interface UserRole {
    void name();

    void rollnumber();
}

// Admin class implementing UserRole interface
class Admin implements UserRole {
    @Override
    public void name() {
        System.out.println("Enter the name of the Admin : ");
        Scanner Scanner = new Scanner(System.in);
        String name = Scanner.nextLine();
    }

    @Override
    public void rollnumber() {
        System.out.println("Enter roll number info:");
        Scanner scanner = new Scanner(System.in);
        int rollnumber = scanner.nextInt();
    }
}

// Teacher class implementing UserRole interface
class Teacherinfo implements UserRole {
    @Override
    public void name() {
        System.out.println("Enter the name of the Teacher : ");
        Scanner Scanner = new Scanner(System.in);
        String name = Scanner.nextLine();
    }

    @Override
    public void rollnumber() {
        System.out.println("Enter roll number info:");
        Scanner scanner = new Scanner(System.in);
        int rollnumber = scanner.nextInt();
    }
}

// Student class implementing UserRole interface
class Studentinfo implements UserRole {
    @Override
    public void name() {
        System.out.println("enter the name of the student : ");
        Scanner Scanner = new Scanner(System.in);
        String name = Scanner.nextLine();
    }

    @Override
    public void rollnumber() {
        System.out.println("Enter roll number info:");
        Scanner scanner = new Scanner(System.in);
        int rollnumber = scanner.nextInt();
    }
}

// Generic class for managing user roles
class RoleManager<T extends UserRole> {
    private T userRole;

    // Constructor that accepts the user role
    public RoleManager(T userRole) {
        this.userRole = userRole;
    }

    // Method to delegate to the specific role's methods
    public void displayRoleDetails() {
        userRole.name();
        userRole.rollnumber();
    }
}

class Teacher {// checked
    ArrayList<String> Teachernames = new ArrayList<>();

    public void defaultteachers() {
        Teachernames.add("Umair");
        Teachernames.add("Mohsin");
        Teachernames.add("Javid");
        Teachernames.add("Ahmed");
        Teachernames.add("Shamas");
    }

    public ArrayList<String> getarraylist() {
        return Teachernames;
    }

    public void Displayteachernames() {
        System.out.println(Teachernames);
    }

    public void editteacherdata() {

        String Teachernametoedit;
        String newname;
        Scanner scanner = new Scanner(System.in);
        int choice;
        while (true) {
            Displayteachernames();
            System.out.println("Choose from above: ");
            int x = scanner.nextInt();
            choice = x - 1;
            scanner.nextLine();
            if (choice < Teachernames.size()) {
                break;
            } else {
                System.out.println("Invalid teacher");
            }
        }
        Teachernametoedit = Teachernames.get(choice);
        System.out.println("Enter the new teacher name : ");
        newname = scanner.nextLine();
        Teachernames.set(choice, newname);
        System.out.println("The teachername " + Teachernametoedit + "is changed to " + newname);

    }

    public void addnewteachername() {
        System.out.println("Enter new teacher name");
        Scanner scanner = new Scanner(System.in);
        String newteacher = scanner.nextLine();
        Teachernames.add(newteacher);
        System.out.println("Teachername " + newteacher + " Added");
    }

    public void deleteteachername() {
        String td;
        Scanner scanner = new Scanner(System.in);
        int choice;
        while (true) {
            Displayteachernames();
            int x = scanner.nextInt();
            choice = x - 1;
            if (choice < Teachernames.size()) {
                break;
            } else {
                System.out.println("Invalid teacher");
            }
        }
        td = Teachernames.get(choice);
        Teachernames.remove(choice);
        System.out.println("Teachername : " + td + " deleted");
    }
}

class courses {// checked
    private ArrayList<String> courses = new ArrayList<>();
    private ArrayList<Integer> credithours = new ArrayList<>();
    private ArrayList<String> teacherAssignments = new ArrayList<>();
    int minimumcredithours = 10;
    int maximumcredithours = 20;
    int currentcredithoursscore = 0;

    public courses() {
        defaultcourses();
    }

    public void defaultcourses() {
        courses.add("oop");
        credithours.add(4);
        currentcredithoursscore += 4;
        teacherAssignments.add("Umair");

        courses.add("Database");
        credithours.add(4);
        teacherAssignments.add("Mohsin");
        currentcredithoursscore += 4;

        courses.add("cn");
        credithours.add(3);
        currentcredithoursscore += 3;
        teacherAssignments.add("Javid");

        courses.add("pp");
        credithours.add(2);
        currentcredithoursscore += 2;
        teacherAssignments.add("Ahmed");

        courses.add("Calculus");
        credithours.add(3);
        teacherAssignments.add("Shamas");
        currentcredithoursscore += 3;

    }

    public ArrayList<String> getTeacherAssignments() {
        return teacherAssignments;
    }

    public void Displaycoursenames() {
        System.out.println(courses);
    }

    public void Displaycredithours() {
        for (int i = 0; i < courses.size(); i++) {
            System.out.println(courses.get(i) + " : " + credithours.get(i) + teacherAssignments.get(i));
        }
    }

    public void editcoursesdata() {

        String coursetoedit;
        String newname;
        String teachertoedit;
        System.out.println("enter what u want to edit ");
        System.out.println("1: coursename");
        System.out.println("2: Credithours");
        System.out.println("3: Teacherdata");
        Scanner scanner = new Scanner(System.in);
        int choicer = scanner.nextInt();
        scanner.nextLine();
        int choice, x;
        if (choicer == 1) {
            while (true) {
                Displaycoursenames();
                System.out.println("Choose from above: ");
                x = scanner.nextInt();
                scanner.nextLine();
                choice = x - 1;
                if (choice < courses.size()) {
                    break;
                } else {
                    System.out.println("Invalid choice");
                }
            }
            coursetoedit = courses.get(choice);
            System.out.println("Enter the new course name : ");
            newname = scanner.nextLine();
            courses.set(choice, newname);
            System.out.println("The coursse " + coursetoedit + " is changed to " + newname);
        } else if (choicer == 2) {
            while (true) {
                Displaycredithours();
                System.out.println("choose which credithours u want to edit");
                x = scanner.nextInt();
                choice = x - 1;
                scanner.nextLine();
                if (choice < credithours.size()) {
                    break;
                } else {
                    System.out.println("Invalid choice");
                }
            }
            int credithourstoedit = credithours.get(choice);
            while (true) {
                System.out.println("enter the new credithours for the course :" + courses.get(choice));
                int newcredithours = scanner.nextInt();
                int availablecredithours = maximumcredithours - currentcredithoursscore;
                if (newcredithours <= availablecredithours) {
                    credithours.set(choice, newcredithours);
                    System.out.println("The credithours for Course : " + courses.get(choice) + " : " + credithourstoedit
                            + " have been changed to : " + newcredithours);
                    break;
                } else {
                    System.out.println("the given credit hours disrupts the credithours functionality");
                    System.out.println("Available Credits Hours: " + availablecredithours);
                }
            }
        } else if (choicer == 3) {
            while (true) {
                Displaycoursenames();
                System.out.println("Choose from above: ");
                x = scanner.nextInt();
                scanner.nextLine();
                choice = x - 1;
                if (choice < courses.size()) {
                    break;
                } else {
                    System.out.println("Invalid choice");
                }
            }
            teachertoedit = teacherAssignments.get(choice);
            System.out.println("Enter the new teacher name : ");
            newname = scanner.nextLine();
            teacherAssignments.set(choice, newname);
            System.out.println("The coursse " + teachertoedit + " is changed to " + newname);
        }
    }

    public void addnewcoursename() {
        System.out.println("Enter new course name");
        Scanner scanner = new Scanner(System.in);
        String newcourse = scanner.nextLine();
        courses.add(newcourse);
        System.out.println("Coursename : " + newcourse + " Added");
        System.out.println("Enter the new teacher name for the course");
        String newteachername = scanner.nextLine();
        teacherAssignments.add(newteachername);
        System.out.println("Teacher for course " + newcourse + " added ");
        int newcoursecredithours;

        while (true) {
            System.out.println("enter the credit hours for the course " + newcourse);
            int availablecredithours = maximumcredithours - currentcredithoursscore;
            System.out.println("the available credithours are : " + availablecredithours);
            newcoursecredithours = scanner.nextInt();

            if (newcoursecredithours <= availablecredithours) {
                break;
            } else {
                System.out.println("the credithours u have told are exceeding the available limit");
            }
        }
        credithours.add(newcoursecredithours);
        System.out
                .println("The credithours for course " + newcourse + " : " + newcoursecredithours + " have been added");
    }

    public void deletecourse() {
        String cd;
        int ccd;
        String teach;
        Scanner scanner = new Scanner(System.in);
        int choice;

        while (true) {
            Displaycoursenames();
            int x = scanner.nextInt();
            choice = x - 1;
            if (choice < courses.size()) {
                break;
            } else {
                System.out.println("Invalid courses");
            }
        }
        cd = courses.get(choice);
        ccd = credithours.get(choice);
        teach = teacherAssignments.get(choice);
        while (true) {
            if (ccd - currentcredithoursscore < minimumcredithours) {
                courses.remove(choice);
                credithours.remove(choice);
                teacherAssignments.remove(choice);
                System.out
                        .println("courses : " + cd + "teachers" + teach + " and their credithours " + ccd + " deleted");
                break;
            } else {
                System.out.println(
                        "Can not delete more courses since the credithours will drop below the minimum amount");
                return;
            }
        }
    }

    public ArrayList<String> getCourses() {
        return courses;
    }
}

class Timetable {
    private courses courseData;
    private classnumbers classroomData;
    private Teacher teacherData; // Add Teacher data
    private String[][] timetable;
    private final String[] days = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    private final int PERIODS_PER_DAY = 5;

    // Constructor with Teacher, Classroom, and Course data
    public Timetable(courses course, classnumbers classroom, Teacher teacher) {
        this.courseData = course;
        this.classroomData = classroom;
        this.teacherData = teacher;
        this.timetable = new String[days.length][PERIODS_PER_DAY];
        generateTimetable();
    }

    // Generate a Weekly Timetable with Class Numbers and Teacher Assignments
    private void generateTimetable() {
        ArrayList<String> courses = courseData.getCourses();
        ArrayList<String> teachers = teacherData.getarraylist(); // Fetch teacher names from Teacher class
        ArrayList<Integer> classNumbers = classroomData.getarraylist();
        Random random = new Random();

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                int courseIndex = random.nextInt(courses.size());
                int classNumberIndex = random.nextInt(classNumbers.size());
                int teacherIndex = random.nextInt(teachers.size()); // Randomly assign a teacher

                // Assign course, teacher, and class number to the timetable
                timetable[i][j] = "Class " + classNumbers.get(classNumberIndex) + ": " +
                        courses.get(courseIndex) + " (" + teachers.get(teacherIndex) + ")";
            }
        }
    }

    // Display the Timetable with Class Numbers, Courses, and Teachers
    public void displayTimetable() {
        for (int i = 0; i < days.length; i++) {
            System.out.println("\n📅 " + days[i]);
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                System.out.println("   Period " + (j + 1) + ": " + timetable[i][j]);
            }
        }
    }

    public void userSearch() {
        Scanner scanner = new Scanner(System.in);

        // Get the day from the user
        System.out.println("Enter the day (1-5) for which you want to see the timetable:");
        for (int i = 0; i < days.length; i++) {
            System.out.println((i + 1) + ". " + days[i]);
        }

        int dayChoice = scanner.nextInt() - 1; // Convert user input to 0-based index

        // Validate day input
        if (dayChoice < 0 || dayChoice >= days.length) {
            System.out.println("Invalid day input.");
            return;
        }

        // Get the period from the user
        System.out.println("Enter the period (1-5) for which you want to see the timetable:");
        int periodChoice = scanner.nextInt() - 1; // Convert user input to 0-based index

        // Validate period input
        if (periodChoice < 0 || periodChoice >= PERIODS_PER_DAY) {
            System.out.println("Invalid period input.");
            return;
        }
        // Show the timetable slot for the selected day and period
        String slot = timetable[dayChoice][periodChoice];
        System.out.println("\n📅 " + days[dayChoice] + ", Period " + (periodChoice + 1) + ": " + slot);
    }

    public void editSlot() {
        Scanner scanner = new Scanner(System.in);

        // Get the day from the user
        System.out.println("Enter the day (1-5) for which you want to edit the timetable:");
        for (int i = 0; i < days.length; i++) {
            System.out.println((i + 1) + ". " + days[i]);
        }

        int dayChoice = scanner.nextInt() - 1; // Convert user input to 0-based index

        // Validate day input
        if (dayChoice < 0 || dayChoice >= days.length) {
            System.out.println("Invalid day input.");
            return;
        }

        // Get the period from the user
        System.out.println("Enter the period (1-5) for which you want to edit the timetable:");
        int periodChoice = scanner.nextInt() - 1; // Convert user input to 0-based index

        // Validate period input
        if (periodChoice < 0 || periodChoice >= PERIODS_PER_DAY) {
            System.out.println("Invalid period input.");
            return;
        }
        // Display the current slot
        String currentSlot = timetable[dayChoice][periodChoice];
        System.out.println("\nCurrent Slot: " + currentSlot);

        // Ask the user to enter new details for the course, teacher, and classroom
        scanner.nextLine(); // Consume the newline character

        System.out.println("Enter new course:");
        String newCourse = scanner.nextLine();

        System.out.println("Enter new teacher:");
        String newTeacher = scanner.nextLine();

        System.out.println("Enter new classroom number:");
        String newClassroom = scanner.nextLine();

        // Update the timetable slot with new data
        timetable[dayChoice][periodChoice] = "Classroom " + newClassroom + ": " + newCourse + " (" + newTeacher + ")";
        System.out.println("The slot has been updated.");
    }

    public void generateAndDisplayReport() {
        System.out.println("Timetable Report:");
        System.out.println("====================");
        displayTimetable();
    }

    // Function to display the timetable for a specific course
    public void displayCourseTimetable(String courseName) {
        System.out.println("Timetable for Course: " + courseName);
        System.out.println("====================");

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                if (timetable[i][j].contains(courseName)) {
                    System.out.println("📅 " + days[i] + " - Period " + (j + 1) + ": " + timetable[i][j]);
                }
            }
        }
    }

    // Function to display the timetable for a specific teacher
    public void displayTeacherTimetable(String teacherName) {
        System.out.println("Timetable for Teacher: " + teacherName);
        System.out.println("====================");

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                if (timetable[i][j].contains(teacherName)) {
                    System.out.println("📅 " + days[i] + " - Period " + (j + 1) + ": " + timetable[i][j]);
                }
            }
        }
    }

    // Function to display the timetable for a specific classroom
    public void displayClassroomTimetable(int classNumber) {
        System.out.println("Timetable for Classroom: " + classNumber);
        System.out.println("====================");

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                if (timetable[i][j].contains("Class " + classNumber)) {
                    System.out.println("📅 " + days[i] + " - Period " + (j + 1) + ": " + timetable[i][j]);
                }
            }
        }
    }

    // User input for displaying the timetable
    public void userDefinedTimetableView() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose the type of timetable to view:");
        System.out.println("1. Course Timetable");
        System.out.println("2. Teacher Timetable");
        System.out.println("3. Classroom Timetable");

        int choice = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        switch (choice) {
            case 1:
                System.out.println("Enter the course name to view its timetable:");
                String courseName = scanner.nextLine();
                displayCourseTimetable(courseName);
                break;
            case 2:
                System.out.println("Enter the teacher's name to view their timetable:");
                String teacherName = scanner.nextLine();
                displayTeacherTimetable(teacherName);
                break;
            case 3:
                System.out.println("Enter the classroom number to view its timetable:");
                int classNumber = scanner.nextInt();
                displayClassroomTimetable(classNumber);
                break;
            default:
                System.out.println("Invalid choice. Please try again.");
        }
    }

    // Function to display course statistics (count how many times each course is
    // scheduled)
    public void displayCourseStatistics() {
        Map<String, Integer> courseCount = new HashMap<>();

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                String entry = timetable[i][j];
                String courseName = entry.split(":")[1].split("\\(")[0].trim(); // Extract course name
                courseCount.put(courseName, courseCount.getOrDefault(courseName, 0) + 1);
            }
        }

        System.out.println("\nCourse Statistics:");
        for (Map.Entry<String, Integer> entry : courseCount.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue() + " times");
        }
    }

    // Function to display teacher statistics (count how many times each teacher is
    // scheduled)
    public void displayTeacherStatistics() {
        Map<String, Integer> teacherCount = new HashMap<>();

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                String entry = timetable[i][j];
                String teacherName = entry.split("\\(")[1].replace(")", "").trim(); // Extract teacher name
                teacherCount.put(teacherName, teacherCount.getOrDefault(teacherName, 0) + 1);
            }
        }

        System.out.println("\nTeacher Statistics:");
        for (Map.Entry<String, Integer> entry : teacherCount.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue() + " periods");
        }
    }

    // Function to display classroom statistics (count how many times each classroom
    // is used)
    public void displayClassroomStatistics() {
        Map<Integer, Integer> classroomCount = new HashMap<>();

        for (int i = 0; i < days.length; i++) {
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                String entry = timetable[i][j];
                int classNumber = Integer.parseInt(entry.split("Class ")[1].split(":")[0].trim()); // Extract class
                                                                                                   // number
                classroomCount.put(classNumber, classroomCount.getOrDefault(classNumber, 0) + 1);
            }
        }

        System.out.println("\nClassroom Statistics:");
        for (Map.Entry<Integer, Integer> entry : classroomCount.entrySet()) {
            System.out.println("Class " + entry.getKey() + ": " + entry.getValue() + " periods");
        }
    }

    // Method to allow user to choose and display statistics
    public void displayStatistics() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\nChoose the type of statistics you want to view:");
        System.out.println("1. Course Statistics");
        System.out.println("2. Teacher Statistics");
        System.out.println("3. Classroom Statistics");
        System.out.print("Enter your choice: ");
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                displayCourseStatistics();
                break;
            case 2:
                displayTeacherStatistics();
                break;
            case 3:
                displayClassroomStatistics();
                break;
            default:
                System.out.println("Invalid choice. Please try again.");
        }
    }

    // Function to display the timetable for a specific day
    public void displayDailyView(String day) {
        System.out.println("\n📅 " + day + " Schedule:");
        for (int i = 0; i < PERIODS_PER_DAY; i++) {
            System.out.println("   Period " + (i + 1) + ": " + timetable[getDayIndex(day)][i]);
        }
    }

    // Function to display the full weekly timetable
    public void displayWeeklyView() {
        System.out.println("\n📅 Full Weekly Timetable:");
        for (int i = 0; i < days.length; i++) {
            System.out.println("\n" + days[i]);
            for (int j = 0; j < PERIODS_PER_DAY; j++) {
                System.out.println("   Period " + (j + 1) + ": " + timetable[i][j]);
            }
        }
    }

    // Helper method to convert day name to index
    private int getDayIndex(String day) {
        for (int i = 0; i < days.length; i++) {
            if (days[i].equalsIgnoreCase(day)) {
                return i;
            }
        }
        return -1; // Return -1 if the day is not found
    }

}

class classnumbers {// checked
    private ArrayList<Integer> classnumbers = new ArrayList<>();

    public ArrayList<Integer> getarraylist() {
        return classnumbers;
    }

    public void defaultcourses() {
        classnumbers.add(100);
        classnumbers.add(101);
        classnumbers.add(102);
        classnumbers.add(103);
        classnumbers.add(104);
    }

    public void Displayclassnumbers() {
        System.out.println(classnumbers);
    }

    public void editclassnumberdata() {

        int classnumbertoedit;
        int newname;
        Scanner scanner = new Scanner(System.in);
        int choice;
        while (true) {
            Displayclassnumbers();
            System.out.println("Choose from above: ");
            int x = scanner.nextInt();
            choice = x - 1;
            scanner.nextLine();
            if (choice < classnumbers.size()) {
                break;
            } else {
                System.out.println("Invalid classnumber");
            }
        }
        classnumbertoedit = classnumbers.get(choice);
        System.out.println("Enter the new classnumber  : ");
        newname = scanner.nextInt();
        classnumbers.set(choice, newname);
        System.out.println("The coursse " + classnumbertoedit + "is changed to " + newname);

    }

    public void addnewclassnumber() {
        System.out.println("Enter new classnumber ");
        Scanner scanner = new Scanner(System.in);
        int newclassnumber = scanner.nextInt();
        classnumbers.add(newclassnumber);
        System.out.println("Classnumber : " + newclassnumber + " Added");
    }

    public void deleteclass() {
        int td;
        Scanner scanner = new Scanner(System.in);
        int choice;
        while (true) {
            Displayclassnumbers();
            int x = scanner.nextInt();
            choice = x - 1;
            if (choice < classnumbers.size()) {
                break;
            } else {
                System.out.println("Invalid classnumber");
            }
        }
        td = classnumbers.get(choice);
        classnumbers.remove(choice);
        System.out.println("classnumber : " + td + " deleted");
    }

}

class Tmrunner {
    public static void teachermenu() {
        Teacher teacher = new Teacher();
        teacher.defaultteachers();
        int choice;

        do {
            System.out.println("----Timetable Management System-----");
            System.out.println("1: Display Teachers");
            System.out.println("2: Add Teachers");
            System.out.println("3: Edit Teachers");
            System.out.println("4: Delete Teacher");
            System.out.println("5: Return to previous menu");
            Scanner scanner = new Scanner(System.in);
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    teacher.Displayteachernames();
                    break;
                case 2:
                    teacher.addnewteachername();
                    break;
                case 3:
                    teacher.editteacherdata();
                    break;
                case 4:
                    teacher.deleteteachername();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Invalid choice! Please select a valid option.");
                    break;
            }
        } while (choice != 5);
    }

    // Course menu
    public static void coursemenu() {
        courses courses = new courses();
        courses.defaultcourses();
        int choice;

        do {
            System.out.println("----Timetable Management System-----");
            System.out.println("1: Display Courses");
            System.out.println("2: Add Courses");
            System.out.println("3: Edit Courses");
            System.out.println("4: Delete Courses");
            System.out.println("5: Return to previous menu");
            Scanner scanner = new Scanner(System.in);
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    courses.Displaycredithours();
                    break;
                case 2:
                    courses.addnewcoursename();
                    break;
                case 3:
                    courses.editcoursesdata();
                    break;
                case 4:
                    courses.deletecourse();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Invalid choice! Please select a valid option.");
                    break;
            }
        } while (choice != 5);
    }

    // Class number menu
    public static void classnumbermenu() {
        classnumbers classnumbers = new classnumbers();
        classnumbers.defaultcourses();
        int choice;

        do {
            System.out.println("----Timetable Management System-----");
            System.out.println("1: Display Class Numbers");
            System.out.println("2: Add Class Numbers");
            System.out.println("3: Edit Class Numbers");
            System.out.println("4: Delete Class Numbers");
            System.out.println("5: Return to previous menu");
            Scanner scanner = new Scanner(System.in);
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    classnumbers.Displayclassnumbers();
                    break;
                case 2:
                    classnumbers.addnewclassnumber();
                    break;
                case 3:
                    classnumbers.editclassnumberdata();
                    break;
                case 4:
                    classnumbers.deleteclass();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Invalid choice! Please select a valid option.");
                    break;
            }
        } while (choice != 5);
    }

    // Main menu for choosing which submenu to navigate to
    public static void menu() {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("---------Timetable Management System-----------");
            System.out.println("Choose what you want to do:");
            System.out.println("1: Teacher Menu");
            System.out.println("2: Course Menu");
            System.out.println("3: Classrooms Menu");
            System.out.println("4: Going to previous Menu");

            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    teachermenu();
                    break;
                case 2:
                    coursemenu();
                    break;
                case 3:
                    classnumbermenu();
                    break;
                case 4:
                    System.out.println("Exiting system...");
                    return;
                default:
                    System.out.println("Invalid choice! Please select a valid option.");
                    return;
            }
        } while (choice != 4);
    }
}

class displayingLoginDataScreen {
    private int choice;

    public void chooseLoginType() {
        // Create instances of user roles
        Admin admin = new Admin();
        Teacherinfo teacherinfo = new Teacherinfo();
        Studentinfo studentinfo = new Studentinfo();

        System.out.println("\n=== Timetable Management System ===");
        System.out.println("Choose who is logging in:");
        System.out.println("1: Admin");
        System.out.println("2: Teacher");
        System.out.println("3: Student");

        Scanner scanner = new Scanner(System.in);
        choice = scanner.nextInt();

        // Based on the choice, create the appropriate RoleManager and call
        // displayRoleDetails()
        switch (choice) {
            case 1:
                RoleManager<Admin> adminRoleManager = new RoleManager<>(admin);
                adminRoleManager.displayRoleDetails();
                break;
            case 2:
                RoleManager<Teacherinfo> teacherRoleManager = new RoleManager<>(teacherinfo);
                teacherRoleManager.displayRoleDetails();
                break;
            case 3:
                RoleManager<Studentinfo> studentRoleManager = new RoleManager<>(studentinfo);
                studentRoleManager.displayRoleDetails();
                break;
            default:
                System.out.println("Invalid choice! Please select a valid option.");
                break;
        }
    }

    public int getChoice() {
        return choice;
    }
}

public class Timetablemangementsystem {

    public static void main(String[] args) {
        // Initialize the data
        courses course = new courses();
        classnumbers classroom = new classnumbers();
        Teacher teacher = new Teacher();
        Tmrunner tmrunner = new Tmrunner();
        displayingLoginDataScreen displayingLoginDataScreen = new displayingLoginDataScreen();
        // Initialize the data for courses, classrooms, and teachers
        course.defaultcourses();
        classroom.defaultcourses();
        teacher.defaultteachers(); // Add default teachers

        // Create a timetable instance
        Timetable timetable = new Timetable(course, classroom, teacher);
        displayingLoginDataScreen.chooseLoginType();
        // Create a scanner for user input
        Scanner scanner = new Scanner(System.in);
        while (true) {
            // Display the main menu
            System.out.println("\n=== Timetable Management System ===");
            System.out.println("1. Display Timetable");
            System.out.println("2. Search for a Specific Timetable Slot");
            System.out.println("3. Edit a Timetable Slot");
            System.out.println("4. Generate and Display Report");
            System.out.println("5. View Timetable (Weekly or Daily)");
            System.out.println("6. View Timetable Statistics");
            System.out.println("7: Edit the Components of timetable");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();

            // Handle user choice
            switch (choice) {
                case 1:
                    // Display the generated timetable
                    timetable.displayTimetable();
                    break;
                case 2:
                    // Allow the user to search for a specific timetable slot
                    timetable.userSearch();
                    break;
                case 3:
                    // Allow the user to edit a timetable slot
                    timetable.editSlot();
                    break;
                case 4:
                    // Generate and display the timetable report
                    timetable.generateAndDisplayReport();
                    break;
                case 5:
                    // Let the user choose Weekly or Daily View
                    System.out.println("Choose view type:");
                    System.out.println("1. Weekly View");
                    System.out.println("2. Daily View");
                    System.out.print("Enter your choice: ");
                    int viewChoice = scanner.nextInt();
                    if (viewChoice == 1) {
                        timetable.displayWeeklyView();
                    } else if (viewChoice == 2) {
                        System.out.print("Enter the day (e.g., Monday): ");
                        String day = scanner.next();
                        timetable.displayDailyView(day);
                    } else {
                        System.out.println("Invalid choice.");
                    }
                    break;
                case 6:
                    // Display statistics
                    timetable.displayStatistics();
                    break;
                case 7:
                    tmrunner.menu();
                    break;
                case 8:
                    // Exit the program
                    System.out.println("Exiting the program. Goodbye!");
                    scanner.close();
                    return; // Exit the while loop and end the program
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }

}