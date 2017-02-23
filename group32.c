/************************************************************************************************************************************
Name: group32: vidit
Project : Compression-Decompression
Date: 4-12-2014
Status: Up and running
Project: Compression/Decompression
		 This program uses a simpler version of the Huffman algorithm to achive its goal.
		 The input file must exist in order to execute the program.

************************************************************************************************************************************/
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
FILE *f1 , *f2, *f3 , *f4;
 char fname1[20] , fname2[20] , fname3[20];
char ascii[256];
void asciicodes()
{
	int i;
	char ch ;
	for(i=1 ;i<256 ; i++ )
	{  ch=i;
	   ascii[i]=ch;

	}
/*	for(i=1 ;i<256 ; i++ )
	{
	printf("%d-- %c\n" ,i, ascii[i])	;
	}*/
}
void database()
{
    char c3;
	f1 = fopen(fname1, "r");
	f3=  fopen("databse.txt" , "w");
	c3=fgetc(f1);
	while(c3!=EOF)
	{
		  fputc(c3 , f3);

		  if(c3==' ')
		  {
		  	fputc('\n' , f3);
		  }
		  c3=fgetc(f1);
	}
	f3='\0';
		fclose(f1);
		fclose(f3);
}
void compression()
{
   char   c;
    int i;

    f1 = fopen(fname1, "r");
    f2 = fopen(fname2, "w");

    if (f1 == NULL)
   {

      printf("Cannot open %s for reading ", fname1);
      exit(1);
   }
   else if (f2 == NULL)
   {
      printf("Cannot open %s for writing ", fname2);
      exit(1);

  }
  else
  {
      c=fgetc(f1);
  	 while(!feof(f1))
  	 {
	    //printf("ASCII value of %c = %d\n",c,c);
  	    i=(int)c;
  	    fprintf(f2, "%d|",i);
		c=fgetc(f1);

	   }
	   database();
	   printf("\nCOMPRESSION IS WORKING");
  }
  fclose(f1);
  fclose(f2);
}
void decompression()
{

    int k , j=0 , result;
    char c2 , c3;
     int l=0;
    char string[3];

    f2 = fopen(fname2, "r");
    f4 = fopen(fname3, "w");
    if (f2 == NULL)
   {
      printf("Cannot open %s for reading ", fname2);
      exit(1);
   }
   else if(f4== NULL)
   {
      printf("Cannot open %s for writing ", fname3);
      exit(1);

  }
    else
    {
     asciicodes();
     c2=fgetc(f2);
    while(c2!=EOF)
    {
  	 string[j]=c2;
  	 j=j+1;

	  if(c2=='|')
  	{
  	     result = atoi(string);

		   for(k=1 ; k<256 ; k++)
	    {
		       if(result==k)
		       {
		         //  printf("%c" , ascii[k]);//for display decompressed code ojn screen
			        fputc(ascii[k], f4);//for putting decompressed code in file
			        k++;
			        l++;
			  }
	    }
  	    j=0;
		result=0;
  	}


  	c2=fgetc(f2);
  }
  if(l!=0)
  {
  	printf("\nDECOMPRESSION IS WORKING");
  }
  else
  {
  	printf("\nDECOMPRESSION IS NOT WORKING");
  }
}
fclose(f2);
fclose(f4);
}
 void main()
{
    char ch  ;
	int  choice;
	int i;

	while(1)
{
	printf("\n\n\t\tWELCOME TO THE COMPRESSION AND DECOMPRESSION");
	printf("\n\n1.COMPRESSION");
	printf("\n\n2.DECOMPRESSION");
	printf("\n\n3.EXIT");
	printf("\n\nenter your choice");
	scanf("%d" , &choice);
	switch(choice)
	{
		case  1  :printf("Enter name of  file containing code :");
                  scanf("%s" ,fname1);
                  printf("\nEnter name of compressed file:");
                  scanf("%s" , fname2);
		          compression();
		          break;
        case  2 :	printf("Enter name of  file containing compressed code :");
                   scanf("%s" ,fname2);
                   printf("\nEnter name of decompressed file:");
                  scanf("%s" ,fname3);
		         decompression();
                break;
        case 3 : exit(0);

         default:printf("\nWRONG CHOICE");
	}

}

getch();
}
