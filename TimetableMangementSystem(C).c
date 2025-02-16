#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define Decelerations
#define DAYS 5
#define PERIODS 5
#define MAX_SUBJECT_LENGTH 100
#define MAX_TEACHER_LENGTH 100
#define MAX_ROOM_LENGTH 100
#define  MAX_LEN 100

//structures decelerations
struct RollNumber {
    char rollNumber[MAX_LEN];
};

typedef struct {
    char name[MAX_SUBJECT_LENGTH];
} Subject;

typedef struct {
    char name[MAX_TEACHER_LENGTH];
} Teacher;

typedef struct {
    char number[MAX_ROOM_LENGTH];
} Room;

typedef struct {
    char classes[DAYS][PERIODS];
} Timetable;

typedef struct {
    int hour;
    int minute;
} TimeSlot;
// Function declarations
//function that prompt the main part(TimeTable Mangement)Depending upon the answer from prev function either of these are run:
char SectionA();
char SectionB();
char SectionC();
//RollNumber Functions:
char choosesemester();
char chooseyearofchoice();
char ChooseSubject();
//functions for Function A:
void printTimetableA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS],TimeSlot times[DAYS][PERIODS]);
char viewSubjectA(Subject timetable[DAYS][PERIODS],  Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char addNewSubjectA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char deleteSubjectA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char searchTimetableA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
void writeTimetableToFileA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
char readTimetableFromFileA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
void initializeTimeSlots(TimeSlot times[DAYS][PERIODS]);
//functions for FunctionB:
void printTimetableB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS],TimeSlot times[DAYS][PERIODS]);
char viewSubjectB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char addNewSubjectB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char deleteSubjectB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char searchTimetableB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
void initializeTimeSlotsB(TimeSlot times[DAYS][PERIODS]);
char writeTimetableToFileB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
char readTimetableFromFileB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
//functions for FunctionC:
void printTimetableC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS],TimeSlot times[DAYS][PERIODS]);
char viewSubjectC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char addNewSubjectC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char deleteSubjectC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char searchTimetableC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]);
char writeTimetableToFileC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
char readTimetableFromFileC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
void initializeTimeSlotsC(TimeSlot times[DAYS][PERIODS]);
//roll number functions:
char finalFunctionRollNumberGenerator(); // Function that returns an alphabet character ('A', 'B', or 'C');
void processRollNumberSection(char rollNumber[MAX_LEN]);
void getRollNumberFromStructure(struct RollNumber *roll);
//Main Function:

int main(){
    struct RollNumber rollNumberStruct;

    // Get roll number from structure
    getRollNumberFromStructure(&rollNumberStruct);

    // Process roll number and call appropriate section functions
    processRollNumberSection(rollNumberStruct.rollNumber);

    return 0;
}
//rollnumber generator code starts here
char choosesemester() {
    char semester;
    int validInput = 0;  

    do {
        printf("||ROLL NUMBER GENERATOR||\n");
        printf("Choose the Semester from Following:\n");
        printf("\t1) Spring(EVENING)\n");
        printf("\t2) Fall(MORNING)\n");    
        printf("Enter your choices from either (1 or 2): ");
        
        if (scanf(" %c", &semester) != 1) {
            printf("Invalid input! Please enter 1 or 2.\n");
            while (getchar() != '\n');  
            continue;  
        }
        switch (semester) {
            case '1':
                printf("SP\n");
                validInput = 1;
                break;
            case '2':
                printf("FA\n");
                validInput = 1;
                break;
            default:
                printf("Invalid choice! Please choose from 1 or 2.\n");
                while (getchar() != '\n');
                break;
        }
        
    } while (!validInput); 
    return semester;
}

char chooseyearofchoice() {
    char yochoice;
    int validInput = 0; 

    do {
        printf("Choose the Year from the Following:\n");
        printf("\t1) 2023 (EVENING)\n");
        printf("\t2) 2024 (MORNING)\n");    
        printf("Enter your choice (1 or 2): ");
        
        if (scanf(" %c", &yochoice) != 1) {
            printf("Invalid input! Please enter 1 or 2.\n");
            while (getchar() != '\n');  
            continue;  
        }
        
        switch (yochoice) {
            case '1':
                printf("2023\n");
                validInput = 1;
                break;
            case '2':
                printf("2024\n");
                validInput = 1;
                break;
            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
                while (getchar() != '\n');  
                break;
        }
        
    } while (!validInput);  
    return yochoice;
}

char ChooseSubject() {
    char subject;
    int validInput = 0;  
    
    do {
        printf("Choose the subject from the following:\n");
        printf("\t1) Computer Science (CS-7)\n");
        printf("\t2) Software Engineering (SE-31)\n");
        printf("\t3) Business Administration (BBA-13)\n");
        printf("\t4) Civil Engineering (CE-21)\n");
        printf("Enter your subject choice (1-4): ");
        
        if (scanf(" %c", &subject) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;  
        }
        
        switch (subject) {
            case '1':
                printf("Computer Science (CS-7)\n");
                break;
            case '2':
                printf("Software Engineering (SE-31)\n");
                break;
            case '3':
                printf("Business Administration (BBA-13)\n");
                break;
            case '4':
                printf("Civil Engineering (CE-21)\n");
                break;
            default:
                printf("Invalid choice! Please choose from 1 to 4.\n");
                continue; 
        }
        
        validInput = 1;  
        
    } while (!validInput); 
   return subject;
}

int RollNumberForComputerSciencestudents(char *section) {
    int rollNumber;
    int validInput = 0;  

    do {
        printf("Enter a roll number for Computer Science between 1 and 30: ");
        
        if (scanf("%d", &rollNumber) != 1) {
            printf("Invalid input! Please enter a number between 1 and 30.\n");
            while (getchar() != '\n');  
            continue; 
        }

        if (rollNumber < 1 || rollNumber > 30) {
            printf("Invalid range! Please enter a number between 1 and 30.\n");
            continue; 
        }

        validInput = 1;  
        
        if (rollNumber >= 1 && rollNumber <= 10) {
            *section = 'A';
        } else if (rollNumber >= 11 && rollNumber <= 20) {
            *section = 'B';
        } else if (rollNumber >= 21 && rollNumber <= 30) {
            *section = 'C';
        } else {
            printf("Unexpected error!\n");
            exit(1);  
        }

    } while (!validInput);
while (getchar() != '\n'); // Keep reading characters until newline is encountered
    return rollNumber;
}

int RollNumberForSoftwareStudents(char *section) {
    int rollNumber;
    int validInput = 0;  

    do {
        printf("Enter a roll number for Software Engineering between 31 and 60: ");
        
        if (scanf("%d", &rollNumber) != 1) {
            printf("Invalid input! Please enter a number between 31 and 60.\n");
            while (getchar() != '\n');  
            continue; 
        }

        if (rollNumber < 31 || rollNumber > 60) {
            printf("Invalid range! Please enter a number between 31 and 60.\n");
            continue; 
        }

        validInput = 1;  
        
        if (rollNumber >= 31 && rollNumber <= 40) {
            *section = 'A';
        } else if (rollNumber >= 41 && rollNumber <= 50) {
            *section = 'B';
        } else if (rollNumber >= 51 && rollNumber <= 60) {
            *section = 'C';
        } else {
            printf("Unexpected error!\n");
            exit(1);  
        }

    } while (!validInput);
while (getchar() != '\n'); // Keep reading characters until newline is encountered
    return rollNumber;
}

int RollNumberForBBAStudents(char *section) {
    int rollNumber;
    int validInput = 0;  

    do {
        printf("Enter a roll number for BBA between 61 and 100: ");
        
        if (scanf("%d", &rollNumber) != 1) {
            printf("Invalid input! Please enter a number between 61 and 100.\n");
            while (getchar() != '\n');  
            continue; 
        }

        if (rollNumber < 61 || rollNumber > 100) {
            printf("Invalid range! Please enter a number between 61 and 100.\n");
            continue; 
        }

        validInput = 1;  
        
        if (rollNumber >= 61 && rollNumber <= 70) {
            *section = 'A';
        } else if (rollNumber >= 71 && rollNumber <= 85) {
            *section = 'B';
        } else if (rollNumber >= 86 && rollNumber <= 100) {
            *section = 'C';
        } else {
            printf("Unexpected error!\n");
            exit(1);  
        }

    } while (!validInput);
    while (getchar() != '\n'); // Keep reading characters until newline is encountered
    return rollNumber;
}

int RollNumberForCivilEngineeringStudents(char *section) {
    int rollNumber;
    int validInput = 0;  

    do {
        printf("Enter a roll number for Civil Engineering between 101 and 150: ");
        
        if (scanf("%d", &rollNumber) != 1) {
            printf("Invalid input! Please enter a number between 101 and 150.\n");
            while (getchar() != '\n');  
            continue; 
        }

        if (rollNumber < 101 || rollNumber > 150) {
            printf("Invalid range! Please enter a number between 101 and 150.\n");
            continue; 
        }

        validInput = 1;  
        
        if (rollNumber >= 101 && rollNumber <= 120) {
            *section = 'A';
        } else if (rollNumber >= 121 && rollNumber <= 135) {
            *section = 'B';
        } else if (rollNumber >= 136 && rollNumber <= 150) {
            *section = 'C';
        } else {
            printf("Unexpected error!\n");
            exit(1);  
        }

    } while (!validInput);
    while (getchar() != '\n'); // Keep reading characters until newline is encountered

    return rollNumber;
}

char *FinalFunctionRollNumberGenerator() {
    static char rollNumberStr[20]; // Static array to store roll number as string
    char semester, yearChoice, subject, section;
    int rollNumber;

    semester = choosesemester();
    yearChoice = chooseyearofchoice();
    subject = ChooseSubject();
    fflush(stdin);

    switch (subject) {
        case '1':
            rollNumber = RollNumberForComputerSciencestudents(&section);
            break;
        case '2':
            rollNumber = RollNumberForSoftwareStudents(&section);
            break;
        case '3':
            rollNumber = RollNumberForBBAStudents(&section);
            break;
        case '4':
            rollNumber = RollNumberForCivilEngineeringStudents(&section);
            break;
        default:
            printf("Invalid subject choice!\n");
            exit(1);
    }

    char subjectCode[5];
    switch (subject) {
        case '1':
            subjectCode[0] = 'B';
            subjectCode[1] = 'C';
            subjectCode[2] = 'S';
            break;
        case '2':
            subjectCode[0] = 'B';
            subjectCode[1] = 'S';
            subjectCode[2] = 'E';
            break;
        case '3':
            subjectCode[0] = 'B';
            subjectCode[1] = 'B';
            subjectCode[2] = 'A';
            break;
        case '4':
            subjectCode[0] = 'B';
            subjectCode[1] = 'C';
            subjectCode[2] = 'E';
            break;
        default:
            printf("Invalid subject choice!\n");
            exit(1);
    }
    subjectCode[3] = '\0';

    char semesterCode[3];
    switch (semester) {
        case '1':
            semesterCode[0] = 'S';
            semesterCode[1] = 'p';
            break;
        case '2':
            semesterCode[0] = 'F';
            semesterCode[1] = 'a';
            break;
        default:
            printf("Invalid semester choice!\n");
            exit(1);
    }
    semesterCode[2] = '\0';

    char yearCode[5];
    switch (yearChoice) {
        case '1':
            yearCode[0] = '2';
            yearCode[1] = '3';
            break;
        case '2':
            yearCode[0] = '2';
            yearCode[1] = '4';
            break;
        default:
            printf("Invalid year choice!\n");
            exit(1);
    }
    yearCode[4] = '\0';

    sprintf(rollNumberStr, "%s%s%s%d-%c", semesterCode, yearCode, subjectCode, rollNumber, section);
    do{
        printf("Roll Number is %s\n", rollNumberStr);
    }
    while (getchar() != '\n'); // Keep reading characters until newline is encountered
    
    return rollNumberStr;
}
// Reverse Linear search to find roll number with specific section
void processRollNumberSection(char rollNumber[MAX_LEN]) {
    int len = strlen(rollNumber);
    if (len == 0) {
        printf("Roll number cannot be empty. Please enter a valid roll number.\n");
        return;
    }

    char lastChar = rollNumber[len - 1];

    switch (lastChar) {
        case 'A':
            printf("Running Section A functions.\n");
            SectionA(); // Call Section A functions
            break;
        case 'B':
            printf("Running Section B functions.\n");
            SectionB(); // Call Section B functions
            break;
        case 'C':
            printf("Running Section C functions.\n");
            SectionC(); // Call Section C functions
            break;
        default:
            printf("Invalid section detected in roll number.\n");
            break;
    }
}

void getRollNumberFromStructure(struct RollNumber *roll) {
      // Get roll number string from FinalFunctionRollNumberGenerator()
    const char* rollNumberString = FinalFunctionRollNumberGenerator();
    
    // Copy roll number string into roll->rollNumber
    strcpy(roll->rollNumber, rollNumberString);
}

// Code for Function A
void initializeTimeSlots(TimeSlot times[DAYS][PERIODS]) {
    for (int i = 0; i < DAYS; i++) {
        int hour = 8; // Start time for the first period
        int minute = 0;

        for (int j = 0; j < PERIODS; j++) {
            times[i][j].hour = hour;
            times[i][j].minute = minute;

            // Increment time by 1 hour and 30 minutes
            minute += 30;
            if (minute >= 60) {
                minute -= 60;
                hour++;
            }
            hour++; // Increment hour by 1
        }
    }
}

void printTimetableA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], TimeSlot times[DAYS][PERIODS]) {
    const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("\nCurrent Timetable:\n");

    for (int i = 0; i < DAYS; i++) {
        printf("%s:\n", days[i]);
        for (int j = 0; j < PERIODS; j++) {
            printf("  Period %d (%02d:%02d): %s (%s, %s)\n", j + 1, times[i][j].hour, times[i][j].minute, timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
        }
    }
}
char viewSubjectA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    int day, period;
    printf("Enter the day (1 for Monday, 2 for Tuesday, etc., up to 5 for Friday): ");
    scanf("%d", &day);
    printf("Enter the period (1 for first period, 2 for second period, etc., up to 5 for fifth period): ");
    scanf("%d", &period);
    printf("The subject for day %d, period %d is: %s\n", day, period, timetable[day - 1][period - 1].name);
    printf("The teacher for this subject is: %s\n", teachers[day - 1][period - 1].name);
    printf("The room number for this subject is: %s\n", rooms[day - 1][period - 1].number);
}

char addNewSubjectA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    int availableSlots[DAYS * PERIODS][2]; // Array to store available slots [day, period]
    int numAvailable = 0;

    // Find and store available slots
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcmp(timetable[i][j].name, "None") == 0) {
                availableSlots[numAvailable][0] = i + 1; // Day (1-indexed)
                availableSlots[numAvailable][1] = j + 1; // Period (1-indexed)
                numAvailable++;
            }
        }
    }

    // Show available slots
    printf("Available slots:\n");
    for (int k = 0; k < numAvailable; k++) {
        printf("Day %d, Period %d\n", availableSlots[k][0], availableSlots[k][1]);
    }

    if (numAvailable == 0) {
        printf("No available slots to add a new subject.\n");
    }

    int choice;
    printf("Enter the slot number to add the new subject: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numAvailable) {
        printf("Invalid choice.\n");
    }

    int day = availableSlots[choice - 1][0];
    int period = availableSlots[choice - 1][1];

    char newSubject[MAX_SUBJECT_LENGTH];
    char newTeacher[MAX_TEACHER_LENGTH];
    char newRoom[MAX_ROOM_LENGTH];

    printf("Enter the new subject: ");
    scanf("%s", newSubject);

    printf("Enter the teacher for the new subject: ");
    scanf("%s", newTeacher);

    printf("Enter the room number for the new subject: ");
    scanf("%s", newRoom);

    strcpy(timetable[day - 1][period - 1].name, newSubject);
    strcpy(teachers[day - 1][period - 1].name, newTeacher);
    strcpy(rooms[day - 1][period - 1].number, newRoom);

    printf("New subject added successfully.\n");
}

char deleteSubjectA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    char subjectToDelete[MAX_SUBJECT_LENGTH];
    printf("Enter the name of the subject to delete: ");
    scanf("%s", subjectToDelete);

    int found = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcasecmp(timetable[i][j].name, subjectToDelete) == 0) {
                strcpy(timetable[i][j].name, "None");
                strcpy(teachers[i][j].name, "None");
                strcpy(rooms[i][j].number, "None");
                found = 1;
            }
        }
    }

    if (found) {
        printf("Subject deleted successfully.\n");
    } else {
        printf("Subject not found in the timetable.\n");
    }
}

char searchTimetableA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    char keyword[MAX_SUBJECT_LENGTH];
    printf("Enter the subject name or teacher name to search for: ");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcasecmp(timetable[i][j].name, keyword) == 0 || strcasecmp(teachers[i][j].name, keyword) == 0) {
                printf("Found at day %d, period %d: %s (%s, %s)\n", i + 1, j + 1, timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No matching subject or teacher found in the timetable.\n");
    }
}

void writeTimetableToFileA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
    }

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            fprintf(file, "%s,%s,%s\n", timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
        }
    }

    fclose(file);
}

char readTimetableFromFileA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
    }

    char line[300];
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "%[^,],%[^,],%[^\n]", timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
            }
        }
    }

    fclose(file);
}

char SectionA() {
    Subject timetable[DAYS][PERIODS] = {
        {{"DLD"}, {"DLD"}, {"Enterpneurship"}, {"None"}, {"None"}},
        {{"PF"}, {"PF"}, {"None"}, {"None"}, {"None"}},
        {{"PF"}, {"English"}, {"DLD"}, {"Enterpneurship"}, {"None"}},
        {{"None"}, {"Civics"}, {"DLD"}, {"None"}, {"None"}},
        {{"Civics"}, {"PF"}, {"English"}, {"None"}, {"None"}}
    };

    Teacher teachers[DAYS][PERIODS] = {
        {{"Mohsin"}, {"Mohsin"}, {"Fayyaz"}, {"None"}, {"None"}},
        {{"Umair"}, {"Umair"}, {"None"}, {"None"}, {"None"}},
        {{"Umair"}, {"Namra"}, {"Mohsin"}, {"Fayyaz"}, {"None"}},
        {{"None"}, {"Noor"}, {"Mohsin"}, {"None"}, {"None"}},
        {{"Noor"}, {"Umair"}, {"Namra"}, {"None"}, {"None"}}
    };

    Room rooms[DAYS][PERIODS] = {
        {{"Z223"}, {"Z223"}, {"Z214"}, {"None"}, {"None"}},
        {{"ComputerLab1"}, {"ComputerLab1"}, {"None"}, {"None"}, {"None"}},
        {{"Z219"}, {"Z205"}, {"Z104"}, {"Z104"}, {"None"}},
        {{"None"}, {"Z209"}, {"Z104"}, {"None"}, {"None"}},
        {{"Z209"}, {"Z203"}, {"Z213"}, {"None"}, {"None"}}
    };
      TimeSlot times[DAYS][PERIODS];
       initializeTimeSlots(times);
    // Read timetable from file
    
    char readTimetableFromFileA(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
     
    int choice;
     const char* filename;
    while (1) {
        printf("\tTIMETABLE MANAGEMENT SYSTEM\n");
        printf("\nMenu:\n");
        printf("1. View Subject\n");
        printf("2. Add New Subject\n");
        printf("3. Delete Subject\n");
        printf("4. Print Timetable\n");
        printf("5. Search Timetable\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        switch (choice) {
            case 1:
                 viewSubjectA( timetable,teachers,rooms);
                break;
            case 2:
                 addNewSubjectA(timetable,teachers,rooms);
                 writeTimetableToFileA(timetable,teachers,rooms,filename);
                break;
            case 3:
                 deleteSubjectA(timetable,teachers,rooms);
                 writeTimetableToFileA(timetable,teachers,rooms,filename);
                break;
            case 4:
                 printTimetableA(timetable,teachers,rooms,times);
                break;
            case 5:
                 searchTimetableA(timetable,teachers,rooms);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

}

//code for function B 
// Function definitions
void initializeTimeSlotsB(TimeSlot times[DAYS][PERIODS]) {
    for (int i = 0; i < DAYS; i++) {
        int hour = 8; // Start time for the first period
        int minute = 0;

        for (int j = 0; j < PERIODS; j++) {
            times[i][j].hour = hour;
            times[i][j].minute = minute;

            // Increment time by 1 hour and 30 minutes
            minute += 30;
            if (minute >= 60) {
                minute -= 60;
                hour++;
            }
            hour++; // Increment hour by 1
        }
    }
}
void printTimetableB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], TimeSlot times[DAYS][PERIODS]) {
    const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("\nCurrent Timetable:\n");

    for (int i = 0; i < DAYS; i++) {
        printf("%s:\n", days[i]);
        for (int j = 0; j < PERIODS; j++) {
            printf("  Period %d (%02d:%02d): %s (%s, %s)\n", j + 1, times[i][j].hour, times[i][j].minute, timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
        }
    }
}

char viewSubjectB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    int day, period;
    printf("Enter the day (1 for Monday, 2 for Tuesday, etc., up to 5 for Friday): ");
    scanf("%d", &day);
    printf("Enter the period (1 for first period, 2 for second period, etc., up to 5 for fifth period): ");
    scanf("%d", &period);
    printf("The subject for day %d, period %d is: %s\n", day, period, timetable[day - 1][period - 1].name);
    printf("The teacher for this subject is: %s\n", teachers[day - 1][period - 1].name);
    printf("The room number for this subject is: %s\n", rooms[day - 1][period - 1].number);
}

char addNewSubjectB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    int availableSlots[DAYS * PERIODS][2]; // Array to store available slots [day, period]
    int numAvailable = 0;

    // Find and store available slots
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcmp(timetable[i][j].name, "None") == 0) {
                availableSlots[numAvailable][0] = i + 1; // Day (1-indexed)
                availableSlots[numAvailable][1] = j + 1; // Period (1-indexed)
                numAvailable++;
            }
        }
    }

    // Show available slots
    printf("Available slots:\n");
    for (int k = 0; k < numAvailable; k++) {
        printf("Day %d, Period %d\n", availableSlots[k][0], availableSlots[k][1]);
    }

    if (numAvailable == 0) {
        printf("No available slots to add a new subject.\n");
    }

    int choice;
    printf("Enter the slot number to add the new subject: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numAvailable) {
        printf("Invalid choice.\n");
    }

    int day = availableSlots[choice - 1][0];
    int period = availableSlots[choice - 1][1];

    char newSubject[MAX_SUBJECT_LENGTH];
    char newTeacher[MAX_TEACHER_LENGTH];
    char newRoom[MAX_ROOM_LENGTH];

    printf("Enter the new subject: ");
    scanf("%s", newSubject);

    printf("Enter the teacher for the new subject: ");
    scanf("%s", newTeacher);

    printf("Enter the room number for the new subject: ");
    scanf("%s", newRoom);

    strcpy(timetable[day - 1][period - 1].name, newSubject);
    strcpy(teachers[day - 1][period - 1].name, newTeacher);
    strcpy(rooms[day - 1][period - 1].number, newRoom);

    printf("New subject added successfully.\n");
}

char deleteSubjectB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    char subjectToDelete[MAX_SUBJECT_LENGTH];
    printf("Enter the name of the subject to delete: ");
    scanf("%s", subjectToDelete);

    int found = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcasecmp(timetable[i][j].name, subjectToDelete) == 0) {
                strcpy(timetable[i][j].name, "None");
                strcpy(teachers[i][j].name, "None");
                strcpy(rooms[i][j].number, "None");
                found = 1;
            }
        }
    }

    if (found) {
        printf("Subject deleted successfully.\n");
    } else {
        printf("Subject not found in the timetable.\n");
    }
}

char searchTimetableB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    char keyword[MAX_SUBJECT_LENGTH];
    printf("Enter the subject name or teacher name to search for: ");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcasecmp(timetable[i][j].name, keyword) == 0 || strcasecmp(teachers[i][j].name, keyword) == 0) {
                printf("Found at day %d, period %d: %s (%s, %s)\n", i + 1, j + 1, timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No matching subject or teacher found in the timetable.\n");
    }
}

char writeTimetableToFileB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
    }

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            fprintf(file, "%s,%s,%s\n", timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
        }
    }

    fclose(file);
}

char readTimetableFromFileB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
    }

    char line[300];
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "%[^,],%[^,],%[^\n]", timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
            }
        }
    }

    fclose(file);
}

char SectionB() {
    Subject timetable[DAYS][PERIODS] = {
        {{"PF"}, {"PF"}, {"None"}, {"English"}, {"None"}},
        {{"DLD"}, {"DLD"}, {"Enterpneurship"}, {"English"}, {"None"}},
        {{"DLD"}, {"Civics"}, {"Enterpneurship"}, {"None"}, {"None"}},
        {{"DLD"}, {"PF"}, {"None"}, {"None"}, {"None"}},
        {{"PF"}, {"None"}, {"None"}, {"Civics"}, {"None"}}
        
    };

    Teacher teachers[DAYS][PERIODS] = {
        {{"Umair"}, {"Umair"}, {"None"}, {"Muneeba"}, {"None"}},
        {{"Imran"}, {"Imran"}, {"Shazil"}, {"Muneeba"}, {"None"}},
        {{"Imran"}, {"Zaib"}, {"Shazil"}, {"None"}, {"None"}},
        {{"Imran"}, {"Umair"}, {"None"}, {"None"}, {"None"}},
        {{"Umair"}, {"None"}, {"None"}, {"Zaib"}, {"None"}}
    };

    Room rooms[DAYS][PERIODS] =  {
    {{"ComputerLab1"}, {"ComputerLab1"}, {"None"}, {"A219"}, {"None"}},
    {{"Z223"}, {"Z223"}, {"A228"}, {"Z213"}, {"None"}},
    {{"Z108"}, {"Z220"}, {"Z103"}, {"None"}, {"None"}},
    {{"Z204"}, {"Z204"}, {"None"}, {"None"}, {"None"}},
    {{"Z210"}, {"None"}, {"None"}, {"A203"}, {"None"}}
    };

    // Read timetable from file
    char readTimetableFromFileB(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
    
    TimeSlot times[DAYS][PERIODS];
    initializeTimeSlots(times);

    int choice;
    const char* filename;
    while (1) {
        printf("\tTIMETABLE MANAGEMENT SYSTEM\n");
        printf("\nMenu:\n");
        printf("1. View Subject\n");
        printf("2. Add New Subject\n");
        printf("3. Delete Subject\n");
        printf("4. Print Timetable\n");
        printf("5. Search Timetable\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        switch (choice) {
            case 1:
                 viewSubjectB(timetable,teachers,rooms);
                break;
            case 2:
                 addNewSubjectB(timetable,teachers,rooms);
                 writeTimetableToFileB(timetable,teachers,rooms,filename);
                break;
            case 3:
                 deleteSubjectB(timetable,teachers,rooms);
                 writeTimetableToFileB(timetable,teachers,rooms,filename);
                break;
            case 4:
                 printTimetableB(timetable,teachers,rooms,times);
                break;
            case 5:
                 searchTimetableB(timetable,teachers,rooms);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }
}
//code for Function C:
void initializeTimeSlotsC(TimeSlot times[DAYS][PERIODS]) {
    for (int i = 0; i < DAYS; i++) {
        int hour = 8; // Start time for the first period
        int minute = 0;

        for (int j = 0; j < PERIODS; j++) {
            times[i][j].hour = hour;
            times[i][j].minute = minute;

            // Increment time by 1 hour and 30 minutes
            minute += 30;
            if (minute >= 60) {
                minute -= 60;
                hour++;
            }
            hour++; // Increment hour by 1
        }
    }
}

void printTimetableC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], TimeSlot times[DAYS][PERIODS]) {
    const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("\nCurrent Timetable:\n");

    for (int i = 0; i < DAYS; i++) {
        printf("%s:\n", days[i]);
        for (int j = 0; j < PERIODS; j++) {
            printf("  Period %d (%02d:%02d): %s (%s, %s)\n", j + 1, times[i][j].hour, times[i][j].minute, timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
        }
    }
}

char viewSubjectC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    int day, period;
    printf("Enter the day (1 for Monday, 2 for Tuesday, etc., up to 5 for Friday): ");
    scanf("%d", &day);
    printf("Enter the period (1 for first period, 2 for second period, etc., up to 5 for fifth period): ");
    scanf("%d", &period);
    printf("The subject for day %d, period %d is: %s\n", day, period, timetable[day - 1][period - 1].name);
    printf("The teacher for this subject is: %s\n", teachers[day - 1][period - 1].name);
    printf("The room number for this subject is: %s\n", rooms[day - 1][period - 1].number);
}

char addNewSubjectC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    int availableSlots[DAYS * PERIODS][2]; // Array to store available slots [day, period]
    int numAvailable = 0;

    // Find and store available slots
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcmp(timetable[i][j].name, "None") == 0) {
                availableSlots[numAvailable][0] = i + 1; // Day (1-indexed)
                availableSlots[numAvailable][1] = j + 1; // Period (1-indexed)
                numAvailable++;
            }
        }
    }

    // Show available slots
    printf("Available slots:\n");
    for (int k = 0; k < numAvailable; k++) {
        printf("Day %d, Period %d\n", availableSlots[k][0], availableSlots[k][1]);
    }

    if (numAvailable == 0) {
        printf("No available slots to add a new subject.\n");
    }

    int choice;
    printf("Enter the slot number to add the new subject: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numAvailable) {
        printf("Invalid choice.\n");

    }

    int day = availableSlots[choice - 1][0];
    int period = availableSlots[choice - 1][1];

    char newSubject[MAX_SUBJECT_LENGTH];
    char newTeacher[MAX_TEACHER_LENGTH];
    char newRoom[MAX_ROOM_LENGTH];

    printf("Enter the new subject: ");
    scanf("%s", newSubject);

    printf("Enter the teacher for the new subject: ");
    scanf("%s", newTeacher);

    printf("Enter the room number for the new subject: ");
    scanf("%s", newRoom);

    strcpy(timetable[day - 1][period - 1].name, newSubject);
    strcpy(teachers[day - 1][period - 1].name, newTeacher);
    strcpy(rooms[day - 1][period - 1].number, newRoom);

    printf("New subject added successfully.\n");
}

char deleteSubjectC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    char subjectToDelete[MAX_SUBJECT_LENGTH];
    printf("Enter the name of the subject to delete: ");
    scanf("%s", subjectToDelete);

    int found = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcasecmp(timetable[i][j].name, subjectToDelete) == 0) {
                strcpy(timetable[i][j].name, "None");
                strcpy(teachers[i][j].name, "None");
                strcpy(rooms[i][j].number, "None");
                found = 1;
            }
        }
    }

    if (found) {
        printf("Subject deleted successfully.\n");
    } else {
        printf("Subject not found in the timetable.\n");
    }
}

char searchTimetableC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS]) {
    char keyword[MAX_SUBJECT_LENGTH];
    printf("Enter the subject name or teacher name to search for: ");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (strcasecmp(timetable[i][j].name, keyword) == 0 || strcasecmp(teachers[i][j].name, keyword) == 0) {
                printf("Found at day %d, period %d: %s (%s, %s)\n", i + 1, j + 1, timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No matching subject or teacher found in the timetable.\n");
    }
}

char writeTimetableToFileC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
    }

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            fprintf(file, "%s,%s,%s\n", timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
        }
    }

    fclose(file);
}

char readTimetableFromFileC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
    }

    char line[300];
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < PERIODS; j++) {
            if (fgets(line, sizeof(line), file) != NULL) {
                sscanf(line, "%[^,],%[^,],%[^\n]", timetable[i][j].name, teachers[i][j].name, rooms[i][j].number);
            }
        }
    }

    fclose(file);
}

char SectionC() {
    Subject timetable[DAYS][PERIODS] = {
        {"English", "DLD", "None", "Enterpneurship", "None"},
        {"Civics", "None", "PF", "None", "None"},
        {"DLD", "DLD", "English", "None", "None"},
        {"None", "DLD", "PF", "None", "Enterpneurship"},
        {"Civics", "None", "PF", "PF", "None"}
    };


    Teacher teachers[DAYS][PERIODS] = {
        {"Amma", "Zia", "None", "Jamil", "None"},
        {"Ayesha", "None", "KashifBilal", "None", "None"},
        {"Zia", "Zia", "Amma", "None", "None"},
        {"None", "Zia", "KashifBilal", "None", "Jamil"},
        {"Ayesha", "None", "KashifBilal", "KashifBilal", "None"}
    };

    Room rooms[DAYS][PERIODS] =  {
    {{"Z214"}, {"Z108"}, {"None"}, {"A211"}, {"None"}},
    {{"Z209"}, {"None"}, {"Z207"}, {"None"}, {"None"}},
    {{"Z223"}, {"Z223"}, {"P2"}, {"None"}, {"None"}},
    {{"None"}, {"Z108"}, {"Z213"}, {"None"}, {"Z207"}},
    {{"Z204"}, {"None"}, {"ComputerLab2"}, {"ComputerLab2"}, {"None"}}
     };

    TimeSlot times[DAYS][PERIODS];
    initializeTimeSlots(times);
    // Read timetable from file
    char readTimetableFromFileC(Subject timetable[DAYS][PERIODS], Teacher teachers[DAYS][PERIODS], Room rooms[DAYS][PERIODS], const char* filename);
    const char* filename;
    int choice;

    while (1) {
        printf("\tTIMETABLE MANAGEMENT SYSTEM\n");
        printf("\nMenu:\n");
        printf("1. View Subject\n");
        printf("2. Add New Subject\n");
        printf("3. Delete Subject\n");
        printf("4. Print Timetable\n");
        printf("5. Search Timetable\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        switch (choice) {
            case 1:
                 viewSubjectC(timetable,teachers,rooms);
                break;
            case 2:
                 addNewSubjectC(timetable,teachers,rooms);
                 writeTimetableToFileC(timetable,teachers,rooms,filename);
                break;
            case 3:
                 deleteSubjectC(timetable,teachers,rooms);
                 writeTimetableToFileC(timetable,teachers,rooms,filename);
                break;
            case 4:
                 printTimetableC(timetable,teachers,rooms,times);
                break;
            case 5:
                 searchTimetableC(timetable,teachers,rooms);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

}