#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceFilename[100], destFilename[100];
    char ch;

   
    printf("Enter source filename: ");
    scanf("%s", sourceFilename);
    printf("Enter destination filename: ");
    scanf("%s", destFilename);


    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    
    destFile = fopen(destFilename, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

   
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(isalpha(ch) ? toupper(ch) : ch, destFile);
    }

  
    fclose(sourceFile);
    fclose(destFile);

    printf("File copied successfully with lowercase converted to uppercase.\n");

    return 0;
}

