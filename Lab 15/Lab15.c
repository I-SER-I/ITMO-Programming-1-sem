#include <stdio.h>

void Extract(char* arcname){
    FILE* arcfile = fopen(arcname, "rb");
    FILE* file;
    unsigned long long int nowposition = 0;
    unsigned long long int startposition = 0;
    unsigned long long int filesize;
    char filename[128];
    int temp;
    while ((temp = getc(arcfile)) != EOF) {
        startposition++;
        if (temp == '\n'){
            break;
        }
    }
    fseek(arcfile, 0, SEEK_SET);
    while (fscanf(arcfile, "<%s:%llu>", filename, &filesize) != 0){
        file = fopen(filename, "wb");
        if (file == NULL)
            break;
        nowposition = ftell(arcfile);
        fseek(arcfile, startposition, SEEK_SET);
        startposition += filesize;
        while (filesize-- > 0)
            putc((temp = getc(arcfile)), file);
        fseek(arcfile, nowposition, SEEK_SET);
        fclose(file);
    }
    printf("\n + Unzipping sucssess + \n");
}

void List(char* arcname){
    FILE* arcfile = fopen(arcname, "rb");
    char filename[128];
    int reading = 0;
    int temp;
    int i;
    printf("File list:\n");
    while ((temp = getc(arcfile)) != EOF) {
        if (temp == ':'){
            reading = 0;
            printf("\t%s\n", filename);
        }
        if (reading){
            filename[i] = temp;
            i++;
        }
        if (temp == '<'){
            reading = 1;
            i = 0;
        }
    }
    fclose(arcfile);
}

void Create(char* arcname, int filecount, char* files[]){
    int i;
    int temp;
    FILE* arcfile = fopen(arcname, "wb");
    FILE* file;
    unsigned long long int nameandsize[128];
    for (i = 5; i < filecount; i++){
        file = fopen(files[i], "rb");
        if (file == NULL)
            continue;
        fseek(file, 0, SEEK_END);
        nameandsize[i - 5] = ftell(file);
        fseek(file, 0, SEEK_SET);
        fclose(file);
    }
    for (i = 0; i < filecount - 5; i++)
        fprintf(arcfile, "<%s:%llu>", files[i + 5], nameandsize[i]);
    fprintf(arcfile, "\n");
    for (i = 5; i < filecount; i++){
        file = fopen(files[i], "rb");
        if (file == NULL){
            printf("File not added. ERROR. You're trying use a non-existent file\n");
            continue;
        }
        else{
            printf("File added\n");
        }
        while ((temp = getc(file)) != EOF)
            putc(temp, arcfile);
        fclose(file);
    }
    printf("\n + Zipping sucssess + \n");
}

int main(int argc, char* argv[]){
    FILE* arcfile;
    int i;
    char* arcname;
    printf("\n");
    for (i = 0; i < argc; i++){
        if(!strcmp("--file", argv[i])){
            arcname = argv[i + 1];
        }
        if(!strcmp("--create", argv[i])){
            Create(arcname, argc, argv);
            break;
        }
        if(!strcmp("--extract", argv[i])){
            Extract(arcname);
        }
        if(!strcmp("--list", argv[i])){
            List(arcname);
        }
    }
    return 0;
}
