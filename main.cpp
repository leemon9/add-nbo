#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

uint32_t read_data(char *arg){
    FILE *fp;
    uint32_t tmp;
    if((fp=fopen(arg,"r")) == NULL){
        printf("Error : can't open file \n");
        exit(1);
    }
    if((fread(&tmp,1,sizeof (uint32_t),fp)) != 4){
        printf("Error : file error \n");
        exit(1);
    }
    fclose(fp);
    return tmp;
}

int main(int argc, char *argv[])
{
    uint32_t a, b;
    if (argc != 3){
        printf("syntax : ./add-nbo <file1> <file2>\n");
        printf("sample : ./add-nbo a.bin b.bin\n");
        exit(1);
    }
    a = ntohl(read_data(argv[1]));
    b = ntohl(read_data(argv[2]));
    printf("%d(%#x) + %d(%#x) = %d(%#x)\n",a,a, b,b, a+b,a+b);
}
