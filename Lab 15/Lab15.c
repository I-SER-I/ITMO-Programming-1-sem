#include <stdio.h>

void Extract(char* arcname){
    FILE* arch = fopen(arcname, "rb+wb");
    unsigned long long int  now_position = 0;
    unsigned long long int  start_position = 0;
    int c;
    while ((c = getc(arch)) != EOF) {
        start_position++;
        if (c == '\n') 
	        break;
    }
    fseek(arch, 0, SEEK_SET);
    char filename[128] = {0};
    unsigned long long int  filesize;
    FILE *file;
    while (fscanf(arch, "< %s : %llu >", filename, &filesize) != 0) {
        file = fopen(filename, "wb");
        if (file == NULL) 
			break;
        now_position = ftell(arch);
        fseek(arch, start_position, SEEK_SET);
        start_position += filesize;
        while (filesize-- > 0)
            putc((c = getc(arch)), file);
        fseek(arch, now_position, SEEK_SET);
        fclose(file);
    }
	printf("\n + Unzipping sucssess + \n");
}

void List(char* arcname){
    FILE* arcfile = fopen(arcname, "rb");
    char filename[128] = {0};
    unsigned long long int  filesize;
    printf("File list:\n");
    while (fscanf(arcfile, "< %s : %llu >", filename, &filesize) != 0) {
        printf("\t%s\n", filename);
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
        fprintf(arcfile, "< %s : %llu >", files[i + 5], nameandsize[i]);
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
