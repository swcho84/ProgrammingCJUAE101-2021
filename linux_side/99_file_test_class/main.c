#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct 
{
  double dLabel;
  double xmin;
  double ymin;
  double xmax;
  double ymax;
} BboxInfo;

typedef struct 
{
	double dRadius;
	double dXcen;
	double dYcen;
} CircleInfo;

typedef struct 
{
	double dX;
	double dY;
	double dZ;
} ThreeDim;



// writing data using fprintf in the txt file
int WritingTxtFile()
{
  // opening the file with the write mode
  char *strFileInfo = "hello.txt";
  printf("File opening..:%s\n", strFileInfo);
  FILE *fp = fopen(strFileInfo, "w+");

  // excepting the NULL case
  if (fp == NULL)
  {
    printf("Please check file status..\n");
    return 1;
  }
  
  // do something
  // based on the variable type
  printf("Success:starting file writing.., %s\n", strFileInfo);
  int nTemp = 100;
  char *strTemp = "Hello,world!!(feat.file i/o)";
  fprintf(fp, "%s %d\n", strTemp, nTemp);
  fprintf(fp, "second line: %s\n", strTemp);

  // closing file
  fclose(fp);
  printf("File closing..\n");  

  return 0;
}

// reading data using getline from the txt file
int ParsingLineExample1()
{
  // assigning variables
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  // opening the file with the read mode
  char *strFileInfo = "yolo_label_data.txt";
  printf("File opening..:%s\n", strFileInfo);  
  fp = fopen(strFileInfo, "r");
  if (fp == NULL)  
  {
    printf("Please check file status..\n");
    return 1;
  }    

  // reading the label data
  const int nMaxLabel = 10;
  char *strRes[nMaxLabel] = {NULL, };
  int nCounter = 0;
  while ((read = getline(&line, &len, fp)) != -1) 
  { 
    // for debugging
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);

    // assigning the string label to the variable
    // using dynamic memory
    char* newstrptr = (char*)(malloc(sizeof(char) * (strlen(line) + 1)));
    char *ptr = strtok(line, "\n");
    while (ptr != NULL)
    {
      // for debugging
      printf("[%d]curr. string: %s\n", nCounter, ptr); 

      strcpy(newstrptr, ptr);
      strRes[nCounter] = newstrptr;
      nCounter++;
      ptr = strtok(NULL, "\n");
    }
  }

  // for debugging
  printf("\nResult: reading the label info:\n");
  for(int i = 0; i < nCounter; i++)
    printf("[%d]%s\n", i, strRes[i]);

  // free heap memory
  free(line);

  // closing file
  fclose(fp);
  printf("File closing..\n");  
  return 0;
}

// reading data using getline from the txt file
// spliting data using strtok
int ParsingLineExample2()
{
  // assigning variables
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;
  
  // opening the file with the read mode
  char *strFileInfo = "yolo_bbox_data.txt";
  printf("File opening..:%s\n", strFileInfo);  
  fp = fopen(strFileInfo, "r");
  if (fp == NULL)  
  {
    printf("Please check file status..\n");
    return 1;
  }    

  // reading the bbox data
  const int nMaxBboxData = 20;
  const int nBboxDataSize = 5;
  double *dRes[nMaxBboxData] = {NULL, };
  int nCounter = 0;  
  while ((read = getline(&line, &len, fp)) != -1) 
  {
    // for debugging
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);

    // assigning the string label to the variable
    // until getting the NULL pointer
    char *ptr = strtok(line, " ");
    double* newdBboxPtr = (double*)(malloc(sizeof(double) * (nBboxDataSize)));
    int i = 0;
    while (ptr != NULL)   
    {
      // for debugging
      printf("[%d]curr. string: %s\n", i, ptr); 

      // saving the single line data from string to double
      newdBboxPtr[i] = (double)(atof(ptr));
      ptr = strtok(NULL, " ");
      i++;
    }
  
    // saving the single file data
    dRes[nCounter] = newdBboxPtr;
    nCounter++;
  }

  // for debugging
  printf("\nResult: reading the bbox info:\n");
  for(int ii = 0; ii < nCounter; ii++)
  {
    printf("[%d]bbox(label, xmin, ymin, xmax, ymax)\n", ii);
    for(int jj = 0; jj < nBboxDataSize; jj++)
    {
      printf("[%d]%.4lf\n", ii, dRes[ii][jj]);
    }
  }

  // free heap memory
  free(line);

  // closing file
  fclose(fp);
  printf("File closing..\n");    
  return 0;
}

// reading data using getline from the txt file
// spliting data using strtok
int ParsingLineExample3()
{
  // assigning variables
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;
  
  // opening the file with the read mode
  char *strFileInfo = "yolo_bbox_data.txt";
  printf("File opening..:%s\n", strFileInfo);  
  fp = fopen(strFileInfo, "r");
  if (fp == NULL)  
  {
    printf("Please check file status..\n");
    return 1;
  }    

  // reading the bbox data
  const int nMaxBboxData = 20;
  BboxInfo *dRes[nMaxBboxData] = {NULL, };
  int nCounter = 0;  
  while ((read = getline(&line, &len, fp)) != -1) 
  {
    // for debugging
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);

    // assigning the string label to the variable
    // until getting the NULL pointer
    char *ptr = strtok(line, " ");
    int i = 0;
    BboxInfo* newdBboxPtr = (BboxInfo*)(malloc(sizeof(BboxInfo)));
    while (ptr != NULL)   
    {
      // for debugging
      printf("[%d]curr. string: %s\n", i, ptr); 

      switch(i)
      {
        case 0:
          newdBboxPtr->dLabel = atof(ptr);
          break;
        case 1:
          newdBboxPtr->xmin = atof(ptr);
          break;
        case 2:
          newdBboxPtr->ymin = atof(ptr);
          break;
        case 3:
          newdBboxPtr->xmax = atof(ptr);
          break;
        case 4:
          newdBboxPtr->ymax = atof(ptr);
          break;                                        
      }   
      ptr = strtok(NULL, " ");
      i++;      
    }     
   
    // saving the single file data
    dRes[nCounter] = newdBboxPtr;    
    nCounter++;
  }

  // for debugging
  printf("\nResult: reading the bbox info:\n");
  for(int ii = 0; ii < nCounter; ii++)
  {
    printf("[%d]bbox(label, xmin, ymin, xmax, ymax)\n", ii);
    printf("[%d]%.4lf\n", ii, dRes[ii]->dLabel);
    printf("[%d]%.4lf\n", ii, dRes[ii]->xmin);
    printf("[%d]%.4lf\n", ii, dRes[ii]->ymin);
    printf("[%d]%.4lf\n", ii, dRes[ii]->xmax);
    printf("[%d]%.4lf\n", ii, dRes[ii]->ymax);                
  }

  // free heap memory
  free(line);

  // closing file
  fclose(fp);
  printf("File closing..\n");    
  return 0;
}


// Report problem: parsing data
int ParsingDataToSavingStructDB()
{
  // assigning file pointer
  FILE *fpLabel;
  FILE *fpData;

  // opening txt file, for label and data
  char *strLabelFileInfo = "yolo_label_data.txt";
  printf("File opening..:%s\n", strLabelFileInfo);
  fpLabel = fopen(strLabelFileInfo, "r");

  // opening txt file, for label and data
  char *strBboxDataFileInfo = "yolo_bbox_data.txt";
  printf("File opening..:%s\n", strBboxDataFileInfo);
  fpData = fopen(strBboxDataFileInfo, "r");  

  // excepting the NULL case
  if ((fpLabel == NULL) || (fpData == NULL))
  {
    printf("Please check file status..\n");
    return 1;
  }

  // for debugging
  printf("Success:file opening.., %s, %s\n", strLabelFileInfo, strBboxDataFileInfo);

  // do something











  // closing file
  printf("File closing..\n");  
  fclose(fpLabel);
  fclose(fpData);

  return 0;
}

int main()
{
  // WritingTxtFile();
  // ParsingLineExample1();
  // ParsingLineExample2();
  ParsingLineExample3();
  // ParsingDataToSavingStructDB();
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}