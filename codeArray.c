#include <stdio.h>
#include<stdlib.h>

typedef struct _{   // create a structure to enter the student data.
	int batch;
	int regNo;
	char firstName[20];
	char lastName[20];
	float cGPA;
	}student_t;

static student_t student[1000]; // initial the data array size
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
	while (stuNumber!=1000) {
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

		printf("Enter the batch (11/12/13/14)\t: ");
		scanf("%d",&student[stuNumber].batch);

		printf("Enter the registration number\t: ");
		scanf("%d",&student[stuNumber].regNo);

		printf("Enter the first name\t\t: ");
		scanf("%s",student[stuNumber].firstName);

		printf("Enter the last name\t\t: ");
		scanf("%s",student[stuNumber].lastName);

		printf("Enter the cumulative GPA\t: ");
		scanf("%f",&student[stuNumber].cGPA);

	stuNumber++;
}

void showOneRec(){
		char REGNO[8];
		int i;
		printf("Enter the registration number: ");
		scanf("%s",REGNO);
		int Enumber = searchEnumber(REGNO);
        int batch = searchBatch(REGNO);

        for(i=0;i<=stuNumber;i++){
			if(student[i].regNo==Enumber){  // search the student
               if(student[i].batch==batch){
				printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",student[i].firstName,student[i].lastName,student[i].batch,student[i].regNo,student[i].cGPA);
				break;
               }
			}else if(i==stuNumber && student[i].regNo!=Enumber){
				printf("There is no registration entry as %s\n",REGNO);

				}

		}



}

void showAllRec(){
		int i;
		for(i=0;i<stuNumber;i++){
			printf("The student %s %s (E/%d/%d) has a cumulative GPA of %f\n",student[i].firstName,student[i].lastName,student[i].batch,student[i].regNo,student[i].cGPA);
		}
}

void deteteEntry(){
		char REGNO[8];
		int entryNumber,i;
		printf("Enter the registration number: ");
		scanf("%s",REGNO);
        int Enumber = searchEnumber(REGNO);
        int batch = searchBatch(REGNO);


		for(i=0;i<stuNumber;i++){
            if(student[i].regNo==Enumber){
                entryNumber=i;
                break;
            }
		}

        for(i=entryNumber;i<stuNumber;i++){
            student[i]=student[i+1];
        }

        stuNumber--;

}

int searchBatch(char * regno){
    char batch[2];
    batch[0]=regno[2];
    batch[1]=regno[3];

    int batNo=atoi(batch);
return batNo;
}


int searchEnumber(char * regno){
    char Enom[3];
    Enom[0]=regno[5];
    Enom[1]=regno[6];
    Enom[2]=regno[7];
    int Enumber=atoi(Enom);
return Enumber;
}

