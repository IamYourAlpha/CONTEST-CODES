#include<stdio.h>


int main() {
    FILE *fp, *fp2;
    char ch,p;
    int flag_space =  0;
    int flag_blank = 0;

    fp=fopen("code.txt","r");
    fp2=fopen("t.txt","w");
    if(fp==NULL)
        printf("Opening error!!!!");
    if(fp2==NULL)
        printf("Opening error!!");
   // while(ch=fgetc(fp)=='\n' || ' ') {};
        while((ch=fgetc(fp))!=EOF) {
            flag_blank = 0;
            flag_space = 0;
            if (ch==' ') {
                flag_space = 1;
            }
            while(ch=fgetc(fp)==' ') {};
            if(flag_space==1) fputc(' ',fp2);

            if (ch=='\n') {
                flag_blank = 1;
            }
            while(ch=fgetc(fp)==' ') {};
            if(flag_blank==1) fputc('\n',fp2);

            fputc(ch,fp2);

            //fputc(ch,fp2);
        }
    fclose(fp);
    fclose(fp2);

    return 0;
}
