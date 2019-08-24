#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define interest 0.14
struct bank
  {
    char name[60];
    int age;
    long long accountNo;
    long long aadhar;
    char ifsc[12];
    char address[30];
    char mail[20];
    long long phoneNo;
    char type[30];
    int deposit;
    char userName[10];
    char  password[20];
    long long loan;
    float emi;
  }first,exist;

int main()
{
      int opt;
      home:
      printf("Welcome to BINARY PULSE bank management system\n");
      printf("\nEnter a choice 1)Banker 2)client\n");
      scanf("%d",&opt);
      if(opt==1)
      {
           banker();
      }
      else if(opt==2)
      {
         client();
      }
      else
	goto home;
      return 0;
}
int client()
{
    int user;
    clienthome:
    printf("Enter the choice 1)New user 2)Existing user\n");
    scanf("%d",&user);
    if(user==1)
    {
        system("cls");
         newuser();
    }
    else if(user==2)
    {
        system("cls");
         existuser();
    }
    else
	goto clienthome;
}
int newuser()
{
    system("cls");
    FILE *ptr;
    int flag=1,toc,mflag=0,nflag=0;
    char c;
    int len,i,flag1=0,flag2=0,flag3=0,flag4=0;
    ptr=fopen("bank.dat","a+");
    printf("Enter Your First Name\n");
    smile:
    scanf("%s",first.name);
    for(i=0;i<strlen(first.name);i++)
    {
        if(!((first.name[i]>=65 && first.name[i]<=90) || (first.name[i]>=97 && first.name[i]<=122)))
        {
            printf("Please Enter a valid name\n");
            goto smile;
        }
    }
    age:
    printf("Enter Your Age\n");
    scanf("%d",&first.age);
    if(first.age>100 || first.age<3)
    goto age;
    if(first.age<18)
    {
      flag=0;
      strcpy(first.type,"ChildSavingAccount");
      printf("\nChildSavingAccount\n");
    }
    aadhar:
    printf("Enter your exact 12 digit Aadhar Number\n");
    scanf("%lld",&first.aadhar);
    if(!(first.aadhar>=100000000000 && first.aadhar<=999999999999))
        goto aadhar;
    phone:
    printf("Enter your Mobile Number\n");
    scanf("%lld",&first.phoneNo);
    if(!(first.phoneNo>=1000000000 && first.phoneNo<=9999999999))
      goto phone;
    email();
    printf("Enter your City\n");
    area:
    scanf("%s",first.address);
    for(i=0;i<strlen(first.address);i++)
    {
        if(!((first.address[i]>=65 && first.address[i]<=90) || (first.address[i]>=97 && first.address[i]<=122)))
        {
            printf("Please Enter a Valid city\n");
            goto area;
        }
    }
    if(flag)
    {
      printf("Enter the Type of account needed\n");
      printf("1-Savings account\n2-Current account\n");
      scanf("%d",&toc);
      switch(toc)
      {
        case 1:
          strcpy(first.type,"SavingAccount");
	  printf("\nSavingAccount\n");
          break;
        case 2:
          strcpy(first.type,"CurrentAccount");
	  printf("\nCurrentAccount\n");
	default:
	  printf("Enter correct choice!");
      }
    }
    printf("Enter the deposit amount\n");
    deposit:
    scanf("%d",&first.deposit);
    if(first.deposit<3000)
    {
      printf("Please Enter the Amount gretaer than 3000\n");
      goto deposit;
    }
    strcpy(first.ifsc,"BIPU0102451");
    first.accountNo=123450011111111+first.phoneNo;
    printf("Your Account Number : %lld\n",first.accountNo);
    printf("Enter Your UserName\n");
    user:
    scanf("%s",first.userName);
    len=strlen(first.userName);
    if(len<5)
    {
      printf("Re-enter your Username\n");
      goto user;
    }
    printf("Enter your Password\n");
    password:
    scanf("%s",first.password);
    len=strlen(first.password);
    if(len<8)
    flag1=1;
    else
    {
        for(i=0;i<len;i++)
        if((first.password[i]>=48&&first.password[i]<=58))
        {
            flag2=0;
            break;
        }
        else
        flag2=1;
        for(i=0;i<len;i++)
        if((first.password[i]>=65&&first.password[i]<=90))
        {
            flag3=0;
            break;
        }
        else
        flag3=1;
        for(i=0;i<len;i++)
        if(first.password[i]=='@' ||first.password[i]=='#' ||first.password[i]=='$'||first.password[i]=='*'||first.password[i]=='&')
        {
            flag4=0;
            break;
        }
        else
        flag4=1;
    }
    if(flag1==1||flag2==1||flag3==1||flag4==1)
    {
      printf("%d %d %d %d\n",flag1,flag2,flag3,flag4);
      printf("Enter the proper password\n");
      printf("Hint:Enter your password that should satisfy the following criteria\n1.Password should contain atleast one capital letter\n2.Should have one digit from(o-9)\n3.Atleast one special charecter($,*,#,&,@)\n4.Length should be atleast 8.\n");
      goto password;
    }
    else
    {
        system("cls");
        printf("Your password is successfully created\n");
    }
    first.emi=0;first.loan=0;
    fprintf(ptr,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",first.accountNo,first.ifsc,first.name,first.age,first.aadhar,first.phoneNo,first.mail,first.address,first.type,first.deposit,first.loan,first.emi,first.userName,first.password);
    fclose(ptr);
    int g;
    printf("\nPress 1 to continue\n");
    scanf("%d",&g);
    if(g==1)
        newuser();
    return 0;
}
int existuser()
{
    int choice;
    EU:
    printf("Enter the choice\n1)Loan\n2)Transaction\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        loan();
    }
    else if(choice==0)
    {
        system("cls");
        transaction();
    }
    else
        goto EU;
    return 0;
}
int transaction()
{
    FILE *ptr1,*ptr2;
    int amount,test=1,i=0;long long int recacno;
    ptr1=fopen("bank.dat","r");
    ptr2=fopen("rem.dat","w");
    printf("Enter Account Number\n");
    scanf("%lld",&exist.accountNo);
    printf("Enter the account number to be send\n");
    reco:
    scanf("%lld",&recacno);
    if(!(recacno>=1000000000000000 && recacno<=9999999999999999))
    {
        printf("Enter the valid Account Number\n");
        goto reco;
    }
    if(recacno==exist.accountNo)
    {
        printf("Both the account number are same\nplease enter another valid account number\n");
        goto reco;
    }
    while(fscanf(ptr1,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",&first.accountNo,first.ifsc,first.name,&first.age,&first.aadhar,&first.phoneNo,first.mail,first.address,first.type,&first.deposit,&first.loan,&first.emi,first.userName,first.password)!=EOF)
    {


        if(first.accountNo==exist.accountNo)
        {

            test=0;
            printf("Enter the amount to be sent\n");
            scanf("%d",&amount);
            if(first.deposit<amount)
            {
                printf("Insufficient Balance\n");//printf("%d",first.deposit);break;
                //break;
            }
            else
            {
                if(strcmp(first.type,"CurrentAccount")==0)
                {
                    if(amount>50000)
                        {
                            printf("You cannot transact above Rs.50000 per day\n");//break;
                           // printf("%d",first.deposit);break;
                        }
                    else
                    {
                        printf("Transaction Completed\n");
                        first.deposit=first.deposit-amount;//break;
                       // printf("%d",first.deposit);break;
                    }
                }
               else if(strcmp(first.type,"SavingAccount")==0)
                {
                    if(amount>20000)
                        {
                            printf("You cannot transact above Rs.20000 above per day\n");//break;
                            //printf("%d",first.deposit);break;
                        }
                    else
                    {
                        printf("Transaction Completed\n");
                        first.deposit=first.deposit-amount;//break;
                        //printf("%d",first.deposit);break;
                    }
                }
            }
            fprintf(ptr2,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",first.accountNo,first.ifsc,first.name,first.age,first.aadhar,first.phoneNo,first.mail,first.address,first.type,first.deposit,first.loan,first.emi,first.userName,first.password);
        }
        else if(recacno==first.accountNo)
        {
           first.deposit=first.deposit+amount;
           fprintf(ptr2,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",first.accountNo,first.ifsc,first.name,first.age,first.aadhar,first.phoneNo,first.mail,first.address,first.type,first.deposit,first.loan,first.emi,first.userName,first.password);

        }
        else
        {
            fprintf(ptr2,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",first.accountNo,first.ifsc,first.name,first.age,first.aadhar,first.phoneNo,first.mail,first.address,first.type,first.deposit,first.loan,first.emi,first.userName,first.password);
        }

    }
   // printf("%d",&first.deposit);
    if(test==1)
          {
        printf("Account Number does not exist\n");

        }

    fclose(ptr1);
    fclose(ptr2);
   remove("bank.dat");
   rename("rem.dat","bank.dat");
}
int loan()
{

FILE *fp,*fp1;int flag=0;
	fp=fopen("bank.dat","r");
	fp1=fopen("remo.dat","w");
	long long principle;int loanTerm,c;
	float lemi;
	pwd:
    	printf("Enter User Name\n");
    	scanf("%s",exist.userName);
		printf("Enter the password\n");
		scanf("%s",exist.password);
		//printf("\n%s %s",exist.userName,exist.password);

while(fscanf(fp,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",&first.accountNo,first.ifsc,first.name,&first.age,&first.aadhar,&first.phoneNo,first.mail,first.address,first.type,&first.deposit,&first.loan,&first.emi,first.userName,first.password)!=EOF)
{
    if((strcmp(exist.userName,first.userName)==0)&&(strcmp(exist.password,first.password)==0))
    {
            flag=1;
			printf("Enter the Principal Amount:\n");
			amo:
            scanf("%lld",&principle);
            if(principle<100)
            {
                printf("Enter the valid Principle Amount\n");
                goto amo;
            }
			printf("Enter the Loan in terms of months:\n");
			loa:
            scanf("%d",&loanTerm);
             if(loanTerm<0)
            {
                printf("Enter the correct period of months\n");
                goto loa;
            }
            lemi = principle*interest/loanTerm;

			if(lemi > 0 && lemi <= first.deposit && principle>first.deposit)
			{
				first.emi=lemi;
        		first.loan=principle;
    			printf("Loan sanctioned\n");
			}

		else
		{
			printf("Sorry! Loan cannot be sanctioned!\n");
		}
	}



	fprintf(fp1,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",first.accountNo,first.ifsc,first.name,first.age,first.aadhar,first.phoneNo,first.mail,first.address,first.type,first.deposit,first.loan,first.emi,first.userName,first.password);
}
if(flag==0)
{
		printf("Username and password incorrect\n");
		goto pwd;
}
fclose(fp);
fclose(fp1);
remove("bank.dat");
rename("remo.dat","bank.dat");
return 0;
}
int email()
{
    char mail[30];
    int len,i,j,count1=0,count2=0;
    printf("Enter your mail ID\n");
    mailid:
    count1=0,count2=0,i=0;j=0,len=0;
    scanf("%s",mail);
    len=strlen(mail);
    for(j=0;j<len;j++)
    {
        if(mail[j]=='.')
        {
            goto invalid;
        }
        if(mail[j]=='@')
        {
            count1+=1;
            break;
        }    
    }
    for(i=j+1;i<len;i++)
    {
        if(mail[i]=='@')
            goto invalid;
        if(mail[i]=='.')
            break;
    }
    if(mail[i-1]=='@' && mail[i]=='.')
        goto invalid;
    if(mail[i+1]=='c' && mail[i+2]=='o' && mail[i+3]=='m')
        count2=1;
    if(mail[i+1]=='i' && mail[i+2]=='n')
        count2=1;
    if(mail[i+1]=='o' && mail[i+2]=='r' && mail[i+3]=='g')
        count2=1;
    if(count1==1 && count2==1)
    {
        printf("Mail is verified\n");
    }
    else
    {   invalid:
        printf("Please Enter a valid Mail ID\n");
        goto mailid;
    }
}
int banker()
{
  FILE *ptr1;
  int n=1,i,c,q=1;
  char un[50],p[50];
  in:
  printf("Enter Username and Password\n");
  scanf("%s",un);
  scanf("%s",p);
if(strcmp(un,"employee")==0&&strcmp(p,"banker")==0)
{
  while(n)
  {
      choice:
      n=0;
    printf("\nEnter a choice\n1.Total number of accounts..\n2.Accounts with loan..\n3.Account without any loan..\n4.Accounts eligible for loan\n5.Exit\n");
    scanf("%d",&n);
    switch(n)
    {
case 1:
    {
          ptr1=fopen("bank.dat","r");
         i=1;
         while(fscanf(ptr1,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",&first.accountNo,first.ifsc,first.name,&first.age,&first.aadhar,&first.phoneNo,first.mail,first.address,first.type,&first.deposit,&first.loan,&first.emi,first.userName,first.password)!=EOF)
      {
          printf("\n%d) AccountNumber:%lld \tName:%s\tPhoneNo:%lld",i,first.accountNo,first.name,first.phoneNo);
          ++i;
      }
      fclose(ptr1);
      break;
    }
case 2:
    {
          ptr1=fopen("bank.dat","r");
        i=1;
        while(fscanf(ptr1,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",&first.accountNo,first.ifsc,first.name,&first.age,&first.aadhar,&first.phoneNo,first.mail,first.address,first.type,&first.deposit,&first.loan,&first.emi,first.userName,first.password)!=EOF&&(first.loan!=0))
      {
          printf("\n%d) AccountNumber:%lld \tName:%s\tPhoneNo:%lld",i,first.accountNo,first.name,first.phoneNo);
          ++i;
      }
      fclose(ptr1);
      break;
    }
case 3:
    {
          ptr1=fopen("bank.dat","r");
        i=1;
        while(fscanf(ptr1,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",&first.accountNo,first.ifsc,first.name,&first.age,&first.aadhar,&first.phoneNo,first.mail,first.address,first.type,&first.deposit,&first.loan,&first.emi,first.userName,first.password)!=EOF&&(first.loan==0))
      {
          printf("\n%d) AccountNumber:%lld \tName:%s\tPhoneNo:%lld",i,first.accountNo,first.name,first.phoneNo);
          ++i;
      }
      fclose(ptr1);
      break;
    }
case 4: i=1;
    {
          ptr1=fopen("bank.dat","r");
        while(fscanf(ptr1,"%lld %s %s %d %lld %lld %s %s %s %d %lld %f %s %s\n",&first.accountNo,first.ifsc,first.name,&first.age,&first.aadhar,&first.phoneNo,first.mail,first.address,first.type,&first.deposit,&first.loan,&first.emi,first.userName,first.password)!=EOF&&(first.deposit>=20000))
      {
          printf("\n%d) AccountNumber:%lld \tName:%s\tPhoneNo:%lld",i,first.accountNo,first.name,first.phoneNo);
          ++i;
      }
      fclose(ptr1);
      break;
    }
case 5:
    {
    printf("exiting......");
       n=0;
       q=0;
       break;
    }
default:
    printf("\nPlease enter a correct choice");
    goto choice;
    }
    if(q)
    {
    printf("\nPress 1 to continue\n");
    scanf("%d",&c);
    if(c==1)
        goto choice;
    }
    else
    {
        break;
    }
}
}
else
{
    printf("\nUsername and password incorrect\n");
  goto in;
}
}




