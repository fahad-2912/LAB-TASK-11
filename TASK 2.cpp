#include <stdio.h>

int main() {
    FILE *file;
    char filename[100], line[256];
    int lineNumber = 1;

    
    printf("Enter the filename: ");
    scanf("%s", filename);

 
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

  
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", lineNumber++, line);
    }

 
    fclose(file);

    return 0;
}

