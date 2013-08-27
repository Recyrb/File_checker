#include <stdio.h>
#include <string.h>

static int isName(char *str){
  return strncmp(str, "[name]", 6);
}

int main(int argc, char *argv[]){
  char *usage = "usage:\nFile_Checker -? : Help\nFile_Checker -f <filename>\n\n";
  char line[100];
  char a[100];
  char b[100];
  int count = 0;

  if (!((argc == 2) || (argc ==3))){
    printf("Invalid number of arguments.\n %s", usage);
    return 1;
  }
  if ((strcmp(argv[1], "-?") == 0) && (argc == 2)){
    printf("%s", usage);
    return 0;
  }
  if((strcmp(argv[1], "-f") == 0) && (argc == 3)){
    FILE *fpFile;
    char *fileName;
    int scan_result = 0;
    fileName = argv[2];
    fpFile = fopen(fileName,"r");
    if (fpFile==NULL){
      printf("ERROR: File \"%s\" not found\n", fileName);
      return 1;
    } else {
      printf("File \"%s\" found\n", fileName);
      while (fgets(line, 100, fpFile)){
        memset(&a[0], 0, sizeof(a));
        memset(&b[0], 0, sizeof(b));
        scan_result = sscanf(line, "%s %s", a, b);
        if (scan_result == 0){
          printf("Line was empty\n");
          continue; 
        }
        if ((scan_result != EOF) && (isName(a) == 0) && (strlen(b) != 0)){
          count++;
        }
      }
      (void)fclose(fpFile);
      printf("%d Names Found\n", count);
      return 0;
    }
  }
  if (argc == 2){
    printf("Invalid argument \"%s\".\n %s", argv[1], usage);
    return 1;
  } else {
    printf("Invalid arguments \"%s\", \"%s\".\n %s", argv[1], argv[2], usage);
    return 1;
  }
}
