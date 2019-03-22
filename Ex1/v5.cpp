//Lexical Analyser to identify elements of C code

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char c;
    fptr = fopen("Code.txt", "r");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(0);
    }
    //printf("\nEnter character: ");
    //fscanf(fptr, "%c", &c);
    
    while(fscanf(fptr, "%c", &c) != EOF)
    {
        //printf("%c", c);
        if(isdigit(c))
            c='d';
        else if(isalpha(c) && c != 'i' && c != 'f' && c != 'w' && c != 'c' && c != 'p' && c != 's' && c != 'm')
            c='a';
        switch(c)
        {
            case '<':
                fscanf(fptr, "%c", &c);
                if(c=='=')
                    printf(" LessThanEqualTo");
                else
                    printf(" LessThan");
                break;
                
            case '>':
                fscanf(fptr, "%c", &c);
                if(c=='=')
                    printf(" GreaterThanEqualTo");
                else
                    printf(" GreaterThan");
                break;
                
            case '!':
                fscanf(fptr, "%c", &c);
                if(c=='=')
                    printf(" NotEqualTo");
                else
                    printf(" Not");
                break;
                
            case '=':
                fscanf(fptr, "%c", &c);
                if(c=='=')
                    printf(" EqualTo");
                else
                    printf(" ASSIGN");
                break;
                
            case '+':
                printf(" ADD");
                break;
                
            case '-':
                printf(" SUBTRACT");
                break;
                
            case '*':
                printf(" MULTIPLY ");
                break;
                
            case '/':
                fscanf(fptr, "%c", &c);
                if(c == '/')
                {
                    goto q;//Control goes to case 'q'
                }
                else if(c == '*')
                {
                    goto u;//Control goes to case 'u'
                }
                else
                {
                    printf(" DIVIDE");
                    break;
                }
                
            case '%':
                printf(" MOD");
                break;
                
            case '&':
                fscanf(fptr, "%c", &c);
                if(c=='&')
                    printf(" AND");
                break;
                
            case '|':
                fscanf(fptr, "%c", &c);
                if(c=='|')
                    printf(" OR");
                break;
                
            //Identifier
            case 'a':
            a:
                if(c=='\n' || c==' ')
                {
                    printf(" ID");
                    break;
                }
                fscanf(fptr, "%c", &c);
                if(c=='\n' || c==' ')
                {
                    printf(" ID");
                    break;
                }
                else
                {
                    while(isalnum(c))
                    {
                        fscanf(fptr, "%c", &c);
                        if(c=='\n')
                        {
                            printf(" ID");
                            break;
                        }
                    }
                }
                break;
                
            //Digit
            case 'd':
                fscanf(fptr, "%c", &c);
                if(c=='\n' || c==' ')
                {
                    printf(" IntConst");
                    break;
                }
                else if(c == '.')
                    goto frac;
                else if(c == 'E')
                    goto exp;
                while(isdigit(c))
                {
                    fscanf(fptr, "%c", &c);
                    if(c=='\n' || c==' ')
                    {
                        printf(" IntConst");
                        break;
                    }
                    else if(c == '.')
                        goto frac;
                    else if(c == 'E')
                        goto exp;
                }
                break;
                
            frac:
                fscanf(fptr, "%c", &c);
                while(isdigit(c))
                {
                    fscanf(fptr, "%c", &c);
                    if(c=='\n' || c==' ')
                    {
                        printf(" FracConst");
                        break;
                    }
                }
                break;
                
            exp:
                fscanf(fptr, "%c", &c);
                if(isdigit(c) || c == '+' || c == '-')
                {
                    fscanf(fptr, "%c", &c);
                    if(c=='\n' || c==' ')
                    {
                        printf(" ExpConst");
                        break;
                    }
                    else
                    {
                        while(isdigit(c))
                        {
                            fscanf(fptr, "%c", &c);
                            if(c=='\n' || c==' ')
                            {
                                printf(" ExpConst");
                                break;
                            }
                        }
                        break;
                    }
                }
                
                //Comments
            case 'q':
            q:  printf(" Single Line Comment");
                fscanf(fptr, "%c", &c);
                while(c!='\n')
                {
                    fscanf(fptr, "%c", &c);
                }
                break;
                
            case 'u':
            u: fscanf(fptr, "%c", &c);
                while(!(c == '*'))
                {
                    fscanf(fptr, "%c", &c);
                }
                if(c == '*')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == '/')
                    {
                        printf(" Multiline Comment");
                    }
                }
                break;
                
            case '\'':
                fscanf(fptr, "%c", &c);
                if(isalpha(c))
                {
                    fscanf(fptr, "%c", &c);
                    if (c == '\'')
                    {
                        printf(" CharConstant");
                    }
                    break;
                }
                
            case '\"':
                fscanf(fptr, "%c", &c);
                while(isalpha(c))
                {
                    fscanf(fptr, "%c", &c);
                }
                if (c == '\"')
                {
                    printf(" StringConstant");
                }
                break;
                
                
                //Keywords
            case 'i':
                fscanf(fptr, "%c", &c);
                if(c == 'f')
                {
                    printf(" KW");//IF
                    break;
                }
                else if(c == 'n')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 't')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == ' ')
                        {
                            printf(" KW");//INT
                            break;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 'f':
                fscanf(fptr, "%c", &c);
                if(c == 'o')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'r')
                    {
                        printf(" KW");//FOR
                        break;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(c == 'l')
                    goto f;
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 'j':
            f:
                fscanf(fptr, "%c", &c);
                if(c == 'o')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'a')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == 't')
                        {
                            fscanf(fptr, "%c", &c);
                            if(c == ' ')
                            {
                                printf(" KW");//FLOAT
                                break;
                            }
                            else if(isalnum(c) || c == ' ' || c == '\n')
                                goto a;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 'w':
                fscanf(fptr, "%c", &c);
                if(c == 'h')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'i')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == 'l')
                        {
                            fscanf(fptr, "%c", &c);
                            if(c == 'e')
                            {
                                printf(" KW");//WHILE
                                break;
                                /*fscanf(fptr, "%c", &c);
                                if(c == ' ')
                                {
                                    printf(" KW");//WHILE
                                    break;
                                }
                                else if(isalpha(c))
                                    goto a;*/
                            }
                            else if(isalnum(c) || c == ' ' || c == '\n')
                                goto a;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 'c':
                fscanf(fptr, "%c", &c);
                if(c == 'h')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'a')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == 'r')
                        {
                            fscanf(fptr, "%c", &c);
                            if(c == ' ')
                            {
                                printf(" KW");//CHAR
                                break;
                            }
                            else if(isalnum(c) || c == ' ' || c == '\n')
                                goto a;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 'm':
                fscanf(fptr, "%c", &c);
                if(c == 'a')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'i')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == 'n')
                        {
                            fscanf(fptr, "%c", &c);
                            if(c == '(')
                            {
                                while(1)
                                {
                                    fscanf(fptr, "%c", &c);
                                    if(c == ')')
                                    {
                                        printf(" FN");//MAIN
                                        break;
                                    }
                                }
                                break;
                            }
                            else if(isalnum(c) || c == ' ' || c == '\n')
                                goto a;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 'p':
                fscanf(fptr, "%c", &c);
                if(c == 'r')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'i')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == 'n')
                        {
                            fscanf(fptr, "%c", &c);
                            if(c == 't')
                            {
                                fscanf(fptr, "%c", &c);
                                if(c == 'f')
                                {
                                    fscanf(fptr, "%c", &c);
                                    if(c == '(')
                                    {
                                        fscanf(fptr, "%c", &c);
                                        while(c != ';')
                                        {
                                            fscanf(fptr, "%c", &c);
                                        }
                                        printf(" FN SP");//PRINTF
                                        break;
                                    }
                                    else if(isalnum(c) || c == ' ' || c == '\n')
                                        goto a;
                                }
                                else if(isalnum(c) || c == ' ' || c == '\n')
                                    goto a;
                            }
                            else if(isalnum(c) || c == ' ' || c == '\n')
                                goto a;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalpha(c) || c == ' ' || c == '\n')
                    goto a;
                
            case 's':
                fscanf(fptr, "%c", &c);
                if(c == 'c')
                {
                    fscanf(fptr, "%c", &c);
                    if(c == 'a')
                    {
                        fscanf(fptr, "%c", &c);
                        if(c == 'n')
                        {
                            fscanf(fptr, "%c", &c);
                            if(c == 'f')
                            {
                                fscanf(fptr, "%c", &c);
                                if(c == '(')
                                {
                                    while(1)
                                    {
                                        fscanf(fptr, "%c", &c);
                                        while(c != ';')
                                        {
                                            fscanf(fptr, "%c", &c);
                                        }
                                        printf(" FN SP");//SCANF
                                        break;
                                    }
                                    break;
                                }
                                else if(isalnum(c) || c == ' ' || c == '\n')
                                    goto a;
                            }
                            else if(isalnum(c) || c == ' ' || c == '\n')
                                goto a;
                        }
                        else if(isalnum(c) || c == ' ' || c == '\n')
                            goto a;
                    }
                    else if(isalnum(c) || c == ' ' || c == '\n')
                        goto a;
                }
                else if(isalnum(c) || c == ' ' || c == '\n')
                    goto a;
                
            case ',':
            case ';':
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
                printf(" SP");
                break;
        }
        if(c == '\n')
        {
            printf("\n");
        }
    }
    fclose(fptr);
}
