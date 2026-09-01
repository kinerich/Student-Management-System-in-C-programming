#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


/*
    display student

    printf("*------*--------------------*------*-------*\n");
    printf("| %-4s | %-18s | %-4s | %-4s |\n", "ID", "Student Name", "Age", "Grade");
    printf("+------+--------------------+------+-------+\n");
    printf("| %-4d | %-18s | %-4d | %-4.2f |\n", id, name, age, grade);
    printf("+------+--------------------+------+-------+\n");

*/

#define SIZE 40

typedef struct {
    int ID;
    char NAME[40];
    int AGE;
    float GRADES;
} identification;

void display(identification student[], int filled_slots) {
    printf("*------*------------------------------*------*-------*\n");
    printf("| %-4s |         %-20s | %-4s | %-4s |\n", "ID", "Student Name", "Age", "Grade");
   
    for(int i = 0; i < filled_slots; i++) {

    printf("+------+------------------------------+------+-------+\n");
    printf("| %-4d | %-28s | %-4d | %-4.2f |\n", student[i].ID, student[i].NAME, student[i].AGE, student[i].GRADES);
    }
     printf("+------+------------------------------+------+-------+\n");
    printf("Success Command\n");
}

void search(identification search[], int count) {

    int ID_num;

    printf("Search ID: ");
    scanf("%d", &ID_num);    

    for(int i = 0; i <= count; i++) {
        if(ID_num == search[i].ID) {
            printf("+------+------------------------------+------+-------+\n");
            printf("| %-4d | %-28s | %-4d | %-4.2f |\n", search[i].ID, search[i].NAME, search[i].AGE, search[i].GRADES);
            printf("+------+------------------------------+------+-------+\n");
    
        }
    }
}

void update(identification *update, int count) {
    int entered;
    printf("Enter User ID: ");
    scanf("%d",&entered);

    for(int i = 0; i < count; i++) {
        if(entered == update[i].ID) {
            printf("Enter new ID: ");
            scanf("%d", &update[i].ID);
            getchar();
            printf("Enter new name :");
            fgets(update[i].NAME, sizeof(update[i].NAME), stdin);
            update[i].NAME[strcspn(update[i].NAME, "\n")] = '\0'; 
            printf("Enter Age : ");
            scanf("%d", &update[i].AGE);
            printf("Enter Grades : ");
            scanf("%f", &update[i].GRADES); 
        }
    }


}

void delete(identification *delete, int *index) {
    int entered;
    printf("Enter ID : ");
    scanf("%d", &entered);

    for(int i = 0; i < *index; i++) {
    if(entered == delete[i].ID)
    {
        for(int j = i; j < *index - 1; j++) {
            delete[i].ID = delete[i+1].ID;
        }
        delete[*index - 1].ID = 0;

        (*index)--;
    }
    }

}

void classification(identification *class, int *count) {
    for(int i = 0; i < *count; i++) {
        int temp;
        for(int j = i; j < *count; j++) {
            if(class[i].GRADES < class[j].GRADES) {
                temp = class[i].GRADES;
                class[i].GRADES = class[j].GRADES;
                class[j].GRADES = temp;

            }

        }
        
    }
    printf("*------*------------------------------*------*-------*\n");
    printf("| %-4s |         %-20s | %-4s | %-4s |\n", "ID", "Student Name", "Age", "Grade");
    for(int i = 0; i < *count; i++) {

    printf("+------+------------------------------+------+-------+\n");
    printf("| %-4d | %-28s | %-4d | %-4.2f |\n", class[i].ID, class[i].NAME, class[i].AGE, class[i].GRADES);
    }
     printf("+------+------------------------------+------+-------+\n");
}

int main() {
    bool running = true;
    int option;

    identification student[10];
    int count = 0;
    student[count].ID = 0001;
    strcpy(student[count].NAME, "Biason, Kine Rich L");
    student[count].AGE = 18;
    student[count].GRADES = 95.8;
    count++;

    char dummy;
    int status;
    char user_char;

    while(running) {
        printf("========================\n");
        printf("    Student Management  \n");
        printf("========================\n");
        printf("| 1. Add Student       |\n");
        printf("| 2. Display Student   |\n");
        printf("| 3. Search student    |\n");
        printf("| 4. Update Student    |\n");
        printf("| 5. Delete Student    |\n");
        printf("| 6. Class Statistics  |\n");
        printf("| 7. Exit              |\n");
        printf("========================\n");
        printf("| Enter option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
            printf("========================\n");
            while(1) {
                

            printf("Enter ID : ");
            status = scanf("%d%c", &student[count].ID, &dummy);
            printf("========================\n");

            if(status == 2 && dummy == '\n') {
                bool catch = true;
                    for(int i = 0; i < count; i++) {
                        if(student[count].ID == student[i].ID) {
                            catch = false;
                            break;
                        }
                    }

                    if(!catch) {
                        continue;
                    }
            break;
                
            } else {
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }

            }
            while(1) {
                
            printf("Enter Name: ");

            if(fgets(student[count].NAME, sizeof(student[count].NAME), stdin) == NULL) {
               continue;
            }
            student[count].NAME[strcspn(student[count].NAME, "\n")] = '\0';
            if(strlen(student[count].NAME) > 0) {
                break;
            }
            }

            printf("========================\n");
            while(1) {
            printf("Enter Age : ");

            status = scanf("%d%c", &student[count].AGE, &dummy);
            printf("========================\n");

            if(status == 2 && dummy == '\n') {
                break;
            } else {
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }

            }


            printf("Enter Grade : ");
            getchar();
            scanf("%f", &student[count].GRADES);
            count++;
            break;
            case 2:
                display(student, count);
                break;
            case 3:
                search(student, count);
                break;
            case 4:
            update(student, count);
                break;
            case 5:
            delete(student, &count);
                break;
            case 6:
            classification(student, &count);
                break;

            default:
            running = false;

        }


        
        
    }

}