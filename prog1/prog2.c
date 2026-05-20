#include<stdio.h>
struct Students{
    int id;
    char name[20];
    float mark;
};

 void createPosition(FILE *fp,struct Students s[],long pos[],int n);
 void displayRecord(FILE *fp,long pos[],int n);

 int main(){
     struct Students s[100];
    FILE *fp;
    int n;
    fp = fopen("student.dat","w+");
    if(fp==NULL){
        printf("FILE in not exist\n");
        return 1;
    }
    printf("enter the n :\n");
    scanf("%d",&n);
    if(n<=0){
        printf("n cann't be zerror\n");
        return 1;
    }
    long pos[100];
    int index;
    createPosition(fp,s,pos,n);
    displayRecord(fp,pos,n);
    return 0;
 }

 void createPosition(FILE *fp, struct Students s[],long pos[],int n){
     for(int i=0;i<n;i++){
        pos[i] = ftell(fp);//Save the starting file position of every record using ftell()
        printf("Ented the ID:");
        scanf("%d",&s[i].id);
        printf("\nEnter Name:");
        scanf("%s",s[i].name);
        printf("\nEnter Mark:");
        scanf("%f",&s[i].mark);
        fprintf(fp,"%d %s %.2f\n",s[i].id,s[i].name,s[i].mark);
    }
 }

  void displayRecord(FILE *fp,long pos[],int n){
    int index;
    struct Students temp;//temp-This saves memory and makes code simpler.
    printf("enter the position to read:");
    scanf("%d",&index);
    if(index < 0 || index >=n){
   printf("invalid index\n");
   return;
    }
    fseek(fp,pos[index],SEEK_SET);
    fscanf(fp,"%d %s %.2f\n",&temp.id,temp.name,&temp.mark);

    printf("\n student Record\n");
    printf("ID: %d\n",temp.id);
    printf("Name : %s\n",temp.name);
    printf("mark : %,2f",temp.mark);
}