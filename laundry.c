#include<stdio.h>
#include<string.h>
//Date of deposite
struct da{
 int dd;
 int mm;
 int yy;
 };
//Date of delavry
struct de{
int dd;
 int mm;
 int yy;
 };  
// store customer data
struct custmor{
int id;
char name[20];
int num;
int srt;
int pnt;
struct da dpts;
struct de ddlry;
int bl;
char stetus[20];
};
struct custmor s[1000];

//rates
int rsrt=50,rpnt=50;
char uid[]="Admin";
char pswd[]="admin123";
//menu functions
void login();
void menu();
void custmors();
void record();
void search();
void setting();
void project();
//customer functions
void add();
void exite();
//searching functions.
void searchbyname();
void searchbyid();
void searchbynum();
void searchbydepositedate();
void searchbydelavrydate();
//id
int n=0;
void main()
{
    login ();
}
void login (){
    char euid[20];
    char epswd[20];
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t||          ---W E L C O M---          ||\n");
    printf("\t\t||        LAUNDRY MANAGEMENT SYSTEM    ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\tEnter Username : ");
    scanf("%s", euid);
    printf("\t\tEnter Password : ");
    scanf("%s", epswd);
    printf("\t\t|=======================================|\n");
    int ruid,rpwd;
    ruid = strcmp(uid,euid);
    rpwd = strcmp(pswd,epswd);
    if((ruid ==0)&&(rpwd==0)){
	    printf("\n\t\t successfully logged in \n");
	    menu();}
    else{
	    printf("\n\t\t Incorrect username and password\n");
	    login();}
}
void menu()
{
    int ch;
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t||        LAUNDRY MANAGEMENT SYSTEM    ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||          1.Customer section         ||\n");
    printf("\t\t||          2.Record section           ||\n");
    printf("\t\t||          3.Search section           ||\n");
    printf("\t\t||          4.Setting section          ||\n");
    printf("\t\t||          5.Log out                  ||\n");
    printf("\t\t||          6.Project info             ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t            Enter Choice : ");
    scanf("%d",&ch);
    switch (ch){
    case 1: custmors(); break;
    case 2: record(); break;
    case 3: search (); break;
    case 4: setting(); break;
    case 5: login(); break;
    case 6: project(); break;
    default : printf("\t\t Invalid choice please enter valid choice.");
	}
    menu();
}
	
void custmors()
{
    int ch;
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t||          --CUSTOMER SECTION--       ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||          1.Add Details              ||\n");
    printf("\t\t||          2.Complete Details         ||\n");
    printf("\t\t||          3.Back                     ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t            Enter Choice : ");
    scanf("%d",&ch);
    switch (ch){
    case 1: add(); break;
    case 2: exite(); break;
    case 3: menu(); break;
    default : printf("\t\t Invalid choice please enter valid choice.");
	custmors();}
}
	
void add() 
{
    int ch;
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t Id : %d \n", n + 1);
    s[n].id=n+1;
    printf("\t\t Enter name : ");
    scanf("%s", s[n].name);
    printf("\t\tEnter Mobile No :");
    scanf("%d",&s[n].num);
    printf("\t\t Enter shirts : ");
    scanf("%d", &s[n].srt);
    printf("\t\t Enter pants : ");
    scanf("%d", &s[n].pnt);
    printf("\t\t--Date of Deposite--\n");
    printf("\t\tDay:");
    scanf("%d", &s[n].dpts.dd);
    printf("\t\tmonth:");
    scanf("%d", &s[n].dpts.mm);
    printf("\t\tyear:");
    scanf("%d", &s[n].dpts.yy);
    printf("\t\t--Date of delavry--\n");
    printf("\t\tDay:");
    scanf("%d", &s[n].ddlry.dd);
    printf("\t\tmonth:");
    scanf("%d", &s[n].ddlry.mm);
    printf("\t\tyear:");
    scanf("%d", &s[n].ddlry.yy);
    s[n].bl = (s[n].srt * rsrt) + (s[n].pnt * rpnt);
    printf("\t\tbill : %d \n\t\tshirts (%d * %d)\n\t\tpants:(%d * %d)", s[n].bl, s[n].srt, rsrt, s[n].pnt, rpnt);
    strcpy(s[n].stetus, "pending"); 
    ++n;
    printf("\n\t\tDetails saved");
    custmors(); 
}

void exite(){
    int id;
    int r;
    char ch;
    printf("\n\t\tEnter ID :");
    scanf("%d",&id);
    printf("\n\t\t|=======================================|\n");
    for(int i=0;i<1000;++i){
        if(s[i].id==id){
            printf("\n\t\t\tId : %d\n\t\t\tName : %s\n\t\t\tMobile No : %d\n\t\t\tShirts : %d\n\t\t\tPants: %d\n\t\t\tDate of Deposite: %d/%d/%d\n\t\t\tDate of  Delavry : %d/%d/%d\n\t\t\tBill : %d\n\t\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);
    r=i;
    printf("\n\t\t|=======================================|\n");};}
    printf("\t\tDo you want to exit Details (Y/N): ");
    scanf(" %c",&ch);
    if((ch =='Y')||(ch =='y')){
    printf("\t\tDetails exited.");
    strcpy(s[r].stetus,"Completed");
    custmors();}
    else{
    printf("\t\tDetails not exited.");
    custmors();}
}


void record()
{
     for(int i=0;i<=1000;++i){ 
     if(s[i].id!= 0){   
     printf("\n\t\tId : %d\n\t\tName : %s\n\t\tMobile No : %d\n\t\tShirts : %d\n\t\tPants: %d\n\t\tDate of Deposite: %d/%d/%d\n\t\tDate of  Delavry : %d/%d/%d\n\t\tBill : %d\n\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);}
      else{break;}}
     printf("\n\t\t|=======================================|\n");
      menu();
}
void search() {  
    int ch;
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t||          --SEARCH  SECTION--        ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||      1.Search by Name               ||\n");
    printf("\t\t||      2.search by Id                 ||\n");
    printf("\t\t||      3.search by Mobile Num         ||\n");
    printf("\t\t||      4.Search by Deposite Date      ||\n");
    printf("\t\t||      5.Search by Delavry Date       ||\n");
    printf("\t\t||      6.Back                         ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t            Enter Choice : ");
    scanf("%d",&ch);
    switch (ch){
    case 1: searchbyname();; break;
    case 2: searchbyid();; break;
    case 3: searchbynum();; break;
    case 4: searchbydepositedate();; break;
    case 5: searchbydelavrydate();; break;
    case 6: menu();; break;
    default : printf("\t\t Invalid choice please enter valid choice."); search();}
}
void setting() {
    int ch;
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t||         --SETTING  SECTION--        ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||      1.Change Shirt Rate            ||\n");
    printf("\t\t||      2.Change Pant Rate             ||\n");
    printf("\t\t||      3.Change Username              ||\n");
    printf("\t\t||      4.Change Password              ||\n");
    printf("\t\t||      5.View Current Rates           ||\n");
    printf("\t\t||      6.Back                         ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t            Enter Choice : ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        printf("\t\tCurrent Shirt Rate : %d\n", rsrt);
        printf("\t\tEnter New Shirt Rate : ");
        scanf("%d",&rsrt);
        printf("\t\tShirt rate updated to %d\n", rsrt);
        setting();
        break;
    case 2:
        printf("\t\tCurrent Pant Rate : %d\n", rpnt);
        printf("\t\tEnter New Pant Rate : ");
        scanf("%d",&rpnt);
        printf("\t\tPant rate updated to %d\n", rpnt);
        setting();
        break;
    case 3:
        printf("\t\tCurrent Username : %s\n", uid);
        printf("\t\tEnter New Username : ");
        scanf("%s", uid);
        printf("\t\tUsername updated successfully.\n");
        setting();
        break;
    case 4:
        printf("\t\tEnter New Password : ");
        scanf("%s", pswd);
        printf("\t\tPassword updated successfully.\n");
        setting();
        break;
    case 5:
        printf("\n\t\t|=======================================|\n");
        printf("\t\t||   Current Shirt Rate  : Rs. %d       ||\n", rsrt);
        printf("\t\t||   Current Pant  Rate  : Rs. %d       ||\n", rpnt);
        printf("\t\t|=======================================|\n");
        setting();
        break;
    case 6:
        menu();
        break;
    default:
        printf("\t\t Invalid choice please enter valid choice.");
        setting();
    }
}

void project() {
    printf("\n\n\t\t|=======================================|\n");
    printf("\t\t||         -- PROJECT  INFO --         ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||  Project Name : Laundry Management  ||\n");
    printf("\t\t||                 System              ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||  Developer  : Shivanand Varpe (125) ||\n");
    printf("\t\t||             : Aditya Veer (127)     ||\n");
    printf("\t\t||  Language   : C Programming         ||\n");
    printf("\t\t||  Year       : 2026                  ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t||  Features:                          ||\n");
    printf("\t\t||  - Create & Complete Order          ||\n");
    printf("\t\t||  - View All Records                 ||\n");
    printf("\t\t||  - Search by Name/ID/Mobile/Date    ||\n");
    printf("\t\t||  - Bill Auto Calculation            ||\n");
    printf("\t\t||  - Status Tracking                  ||\n");
    printf("\t\t||  - Admin Login System               ||\n");
    printf("\t\t||  - Configurable Rates               ||\n");
    printf("\t\t|=======================================|\n");
    printf("\t\t Press Enter to go back...");
    getchar(); getchar();
    menu();
}
void searchbyname() 
{
    char sname[20];
    printf("\n\t\tEnter Name : ");
    scanf("%s",sname);
    for(int i=0;i<1000;++i){
    int r = strcmp(s[i].name,sname);
        if(r==0){
            printf("\n\t\t\tId : %d\n\t\t\tName : %s\n\t\t\tMobile No : %d\n\t\t\tShirts : %d\n\t\t\tPants: %d\n\t\t\tDate of Deposite: %d/%d/%d\n\t\t\tDate of  Delavry : %d/%d/%d\n\t\t\tBill : %d\n\t\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);
     printf("\n\t\t|=======================================|\n");};}
    search();
}

void searchbyid()
{
    int id;
    printf("\n\t\tEnter ID :");
    scanf("%d",&id);
    printf("\n\t\t|=======================================|\n");
    for(int i=0;i<1000;++i){
        if(s[i].id==id){
            printf("\n\t\t\tId : %d\n\t\t\tName : %s\n\t\t\tMobile No : %d\n\t\t\tShirts : %d\n\t\t\tPants: %d\n\t\t\tDate of Deposite: %d/%d/%d\n\t\t\tDate of  Delavry : %d/%d/%d\n\t\t\tBill : %d\n\t\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);
     printf("\n\t\t|=======================================|\n");};}
    search();
}
void searchbynum()
{
    int num;
    printf("\n\t\tEnter Mobile num : ");
    scanf("%d",&num);
    for(int i=0;i<1000;++i){
        if(s[i].num==num){
           printf("\n\t\t\tId : %d\n\t\t\tName : %s\n\t\t\tMobile No : %d\n\t\t\tShirts : %d\n\t\t\tPants: %d\n\t\t\tDate of Deposite: %d/%d/%d\n\t\t\tDate of  Delavry : %d/%d/%d\n\t\t\tBill : %d\n\t\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);
     printf("\n\t\t|=======================================|\n");};}
    search();
}
void searchbydepositedate()
{
    int dd,mm,yy;
    printf("\n\t\tEnter Deposite date");
    printf("\n\t\tDD : ");
    scanf("%d",&dd);
    printf("\t\tMM : ");
    scanf("%d",&mm);
    printf("\t\tYY : ");
    scanf("%d",&yy);
    for(int i=0;i<1000;++i){
        if((s[i].dpts.dd==dd)&&(s[i].dpts.mm==mm)&&(s[i].dpts.yy==yy)){
            printf("\n\t\t\tId : %d\n\t\t\tName : %s\n\t\t\tMobile No : %d\n\t\t\tShirts : %d\n\t\t\tPants: %d\n\t\t\tDate of Deposite: %d/%d/%d\n\t\t\tDate of  Delavry : %d/%d/%d\n\t\t\tBill : %d\n\t\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);
     printf("\n\t\t|=======================================|\n");};}
    search();

}
void searchbydelavrydate()
{
    int dd,mm,yy;
    printf("\n\t\tEnter Delavry  date-");
    printf("\n\t\tDD : ");
    scanf("%d",&dd);
    printf("\t\tMM : ");
    scanf("%d",&mm);
    printf("\t\tYY : ");
    scanf("%d",&yy);
    printf("\n\t\t|=======================================|\n");
    for(int i=0;i<1000;++i){
        if((s[i].ddlry.dd==dd)&&(s[i].ddlry.mm==mm)&&(s[i].ddlry.yy==yy)){
            printf("\n\t\t\tId : %d\n\t\t\tName : %s\n\t\t\tMobile No : %d\n\t\t\tShirts : %d\n\t\t\tPants: %d\n\t\t\tDate of Deposite: %d/%d/%d\n\t\t\tDate of  Delavry : %d/%d/%d\n\t\t\tBill : %d\n\t\t\tStetus : %s",s[i].id,s[i].name,s[i].num,s[i].srt,s[i].pnt,s[i].dpts.dd,s[i].dpts.mm,s[i].dpts.yy,s[i].ddlry.dd,s[i].ddlry.mm, s[i].ddlry.yy,s[i].bl,s[i].stetus);
     printf("\n\t\t|=======================================|\n");};}
    search();
}
