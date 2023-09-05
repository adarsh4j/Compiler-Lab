#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    FILE *filein = fopen("filein.txt", "r"); 
    FILE *fileout = fopen("fileout.txt", "w");
    int l=1,lineno = 1, tokno = 0, i,j, flag = 0; 
    char ch, str[100], keyword[50][50] = {"int", "main", "if", "else", "while", "for", "return", "do", "switch", "FILE", "printf", "scanf"}; 
    fprintf(fileout,"Line \t\t Token no. \t Token \t\t Lexeme\n");

    while (!feof(filein))
    {
        i = 0; flag = 0;
        ch = fgetc(filein);
         if (ch == '/')
               {
                ch = fgetc(filein);
                if (ch == '/')
                {
                   while ((ch = fgetc(filein)) != '\n')
                   {
                       if (ch == '\n')
                        break;
                    }
                l++;
                }
             else if (ch == '*')
              {
                while ((ch = fgetc(filein)) != '*')
                {
                    if (ch == EOF)
                        break;
                }
                ch = fgetc(filein);
                if (ch == '/')
                {
                    continue;
                }
            }
        }

        if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
        {
                        fprintf(fileout,"%d\t\t %d\t\t Operator\t %c\n",lineno,tokno,ch);
                        tokno++;
        }
       
        
        else if ( ch==';' || ch=='{' || ch=='}' || ch=='?' || ch=='|' || ch=='[' || ch==']'|| ch==':' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!' || ch=='%')
        {
            fprintf(fileout,"%d\t\t %d\t\t Special Symbol\t %c\n",lineno,tokno,ch);
            tokno++;
        }

        else if(isdigit(ch))
        {
                        fprintf(fileout,"%d\t\t %d\t\t Digit\t\t %c\n",lineno,tokno,ch);
                        tokno++;
        }
        
        else if (isalpha(ch))
        {
            str[i] = ch;
            i++;
            ch = fgetc(filein);

            while (isalnum(ch) && ch!=' ') 
            {
                str[i] = ch;
                i++;
                ch = fgetc(filein);
            }
            str[i] = '\0';
            
            for ( j = 0; j<50; j++)
            {
                if(strcmp(str, keyword[j]) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 1)
            {
                fprintf(fileout,"%d\t\t %d\t\t Keyword\t %s\n",lineno,tokno,str);
            }
            else {fprintf(fileout,"%d\t\t %d\t\t Identifier\t %s\n",lineno,tokno,str);}

            tokno++;
             if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
            {
                        fprintf(fileout,"%d\t\t %d\t\t Operator\t %c\n",lineno,tokno,ch);
                        tokno++;
            }
             if (ch=='=')
            {
                        fprintf(fileout,"%d\t\t %d\t\tSpecial symbol\t %c\n",lineno,tokno,ch);
                        tokno++;
            }

          
           if ( ch==';' || ch=='{' || ch=='}' || ch=='?' || ch=='|' || ch=='[' || ch==']'|| ch==':' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!' || ch=='%')
        {
            fprintf(fileout,"%d\t\t %d\t\tSpecial Symbol\t %c\n",lineno,tokno,ch);
            tokno++;
        }
            
        }
        else if(ch == '\n')
        {
            lineno++;
        }
        
    }
    

    fclose(fileout);
    fclose(filein);

    return 0;
}
