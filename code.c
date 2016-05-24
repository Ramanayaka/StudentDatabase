#include <stdio.h>
#include<stdlib.h>

typedef struct _{   // create a structure to enter the student data.
	int batch;
	int regNo;
	char firstName[20];
	char lastName[20];
	float cGPA;
	struct _* next;
	}student_t;

static student_t* student=NULL; // initial the data array size
static student_t* CurrentStudent;
static int stuNumber=0;         // count the student number

void mainUI();          // call the use interface function
void addNew();          // cal the add new function
void showOneRec();
void showAllRec();
int searchEnumber(char * regno);    // get the use searching E number
int searchBatch(char * regno);      // get the use searching batch
void deteteEntry();

int main(){

	int optionNum;
	while (1) {
	mainUI();
	scanf("%d",&optionNum);
	if(optionNum==0){
		break;

	}else if(optionNum==1){
		addNew();

	}else if(optionNum==2){
		showOneRec();

	}else if(optionNum==3){
		showAllRec();

	}else if(optionNum==4){
        deteteEntry();
	}

	}

return 0;
}


void mainUI(){
	printf("---------------------------------------------\n");
	printf("A VOLATITLE STUDENT RECORD MAINTENANCE SYSTEM\n");
	printf("---------------------------------------------\n");
	printf("0. Quit\n");
	printf("1. Insert a Student Record\n");
	printf("2. Print a Student Record\n");
	printf("3. Print all Student Record\n");
	printf("4. Delete a Student Record\n");

	}

void addNew(){

		CurrentStudent = (student_t*)malloc(sizeof(student_t));

		printf("Enter the batch (11/12/13/14)\t: ");
		scanf("%d",&CurrentStudent ->batch);

		printf("Enter the registration number\t: ");
		scanf("%d",&CurrentStudent ->regNo);

		printf("Enter the first name\t\t: ");
		scanf("%s",CurrentStudent ->firstName);

		printf("Enter the last name\t\t: ");
		scanf("%s",CurrentStudent ->lastName);

		printf("Enter the cumulative GPA\t: ");
		scanf("%f",&CurrentStudent ->cGPA);
		CurrentStudent ->next = student;
		student=CurrentStudent;

	stuNumber++;
}

void showOneRec(){
		char REGNO[8];
		printf("Enter the registration number: ");
		scanf("%s",REGNO);
		int Enumber = searchEnumber(REGNO);
        int batch = searchBatch(REGNO);
		CurrentStudent = student;
        while(CurrentStudent!=NULL){
			if(CurrentStudent ->regNo==Enumber && CurrentStudent ->batch==batch){  // search the student
				printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",CurrentStudent ->firstName,CurrentStudent ->lastName,CurrentStudent ->batch,CurrentStudent ->regNo,CurrentStudent ->cGPA);
				break;
			}else if(CurrentStudent ->next==NULL && CurrentStudent->regNo!=Enumber){
				printf("There is no registration entry as %s\n",REGNO);
				}
				CurrentStudent =CurrentStudent -> next;
		}



}

void showAllRec(){
        CurrentStudent=student;
		while(CurrentStudent!=NULL){
			printf("The student %s %s (E/%d/%d) has a cumulative GPA of %f\n",CurrentStudent->firstName,CurrentStudent->lastName,CurrentStudent->batch,CurrentStudent->regNo,CurrentStudent->cGPA);
			CurrentStudent=CurrentStudent->next;
		}
}

void deteteEntry(){
		char REGNO[8];
		int entryNumber,i,icounter=0;
		printf("Enter the registration number: ");
		scanf("%s",REGNO);
        int Enumber = searchEnumber(REGNO);
        int batch = searchBatch(REGNO);
        CurrentStudent = student;
        while(CurrentStudent!=NULL){
			if(CurrentStudent ->regNo==Enumber && CurrentStudent ->batch==batch){  // search the student
				if(icounter==0){//delete first entry
                     CurrentStudent = student ->next;
                     free(student);
                     student=CurrentStudent;
				}else if(icounter== stuNumber-1){//delete last entry
                    student_t* previous;
                    int j;
                    previous = student;
                    for(j=0;j<(stuNumber-2);j++){
                        previous = previous->next;
                    }
                    previous -> next= NULL;
                    free(CurrentStudent);

				}else{//delete middle entry
				    student_t * tempStudent;
                    tempStudent = student -> next;
                    CurrentStudent = student -> next -> next;
                    student -> next = CurrentStudent;
                     free(tempStudent);
				}
				break;
			}else if(CurrentStudent ->next==NULL && CurrentStudent->regNo!=Enumber){
				printf("There is no registration entry as %s\n",REGNO);
				}
				CurrentStudent =CurrentStudent -> next;
				icounter++;
		}


        stuNumber--;

}

int searchBatch(char * regno){
    char batch[3];
    batch[0]=regno[2];
    batch[1]=regno[3];
	batch[2]='\0';
    int batNo=atoi(batch);
return batNo;
}


int searchEnumber(char * regno){
    char Enom[4];
    Enom[0]=regno[5];
    Enom[1]=regno[6];
    Enom[2]=regno[7];
    Enom[3]='\0';
    int Enumber=atoi(Enom);
return Enumber;
}

