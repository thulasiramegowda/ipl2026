// taking student details as an example.
#include<stdio.h>
#include<stdlib.h>
struct Student{
    int id;
    char name[20];
    float marks;
};
  
void getRecord(int m);
void deleteRecord(int deleteID);

int main(){
    FILE *fp;
    struct Student s;
    int n,i,m,deleteID;
    
    fp = fopen("student.dat","wb");
    if(fp==NULL){
        printf("File cannot be opened it is empty\n");
        return 1;  // some error happened.
    }

    printf("Enter the number of records:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\n ENTER ID:");
        scanf("%d",&s.id);
        printf("Enter Name:");
        scanf("%s",s.name);
        printf("Enter MArks:");
        scanf("%f",&s.marks);
        fwrite(&s,sizeof(struct Student),1,fp); //to write 1 student at a time 1(inside the formula) will be ysed
    }
    fclose(fp);

    printf("\nEnter record number to display:");
    scanf("%d",&m);

    getRecord(m); //first function.
    printf("Enter ID to delete:");
    scanf("%d",&deleteID);
    deleteRecord(deleteID); // secound funtion.
    return 0;
}
//to read the record.
void getRecord(int m){
 FILE *fp;
 struct Student s;

 fp = fopen("student.dat","rb");

 if(fp==NULL){
    printf("File not found\n");
    return;
 } 
 fseek(fp,(m-1)*sizeof(struct Student),SEEK_SET);

 fread(&s,sizeof(struct Student),1,fp);

 printf("\nRecord Fount:\n");
 printf("ID = %d\n",s.id);
 printf("Name = %s\n",s.name);
 printf("Marks = %.2f",s.marks);

 fclose(fp);
}

//to delete the file and name temp file as main file .

void deleteRecord(int deleteID){
    FILE *fp,*temp;
    struct Student s;
    
    fp = fopen("student.dat","rb");
    temp = fopen("temp.dat","wb");

    if(fp==NULL){
        printf("file is not found\n");
        return;
    }

    while(fread(&s, sizeof(struct Student),1,fp)){
        if(s.id != deleteID){
         fwrite(&s, sizeof(struct Student),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("student.dat");
    rename("temp.dat","student.dat");
     printf("Recode deleted Successfully\n");
}