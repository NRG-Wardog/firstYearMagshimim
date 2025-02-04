#include <stdio.h>

void tryDicrpt(char string[])
{
    char ch[1900] = { 0 };
    for (int i = 0;i < 1800;i++)
    {
        ch[i] = ((string[i] - 'a')+11) % 26  +'a';
    }
    printf("%s", ch);
}

int main()
{
    //FILE* udfile = fopen("reslt.txt", "w");
    FILE* detfile = fopen("newtext.txt", "r");
    char ch[1900] = {0};
    char let = ' ';
    
    for (int i = 0;i < 1900 && ((let = (char)fgetc(detfile)) != EOF);i=i+3)
    {
        if (let >= 'a' && let <= 'z')
        {
            ch[i] = let;
        }
    }
    tryDicrpt(ch);




    fclose(detfile);
    //fclose(udfile);
    getchar(); 
    return 0;
}
