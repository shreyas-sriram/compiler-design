//
//  main.c
//  Compiler Lab
//
//  Created by Shreyas on 25/12/18.
//  Copyright © 2018 Shreyas. All rights reserved.
//

#include<stdio.h>
#include <ctype.h>

int main()
{
    char c;
    printf("\nEnter character: ");
    scanf("%c",&c);
    while(c!='\n')
    {
        if(isdigit(c))
            c='d';
        else if(isalpha(c))
            c='a';
        switch(c)
        {
            case '<':
                scanf("%c",&c);
                if(c=='=')
                    printf("\nLess than equal to ");
                else
                    printf("\nLess than ");
                break;
                
            case '>':
                scanf("%c",&c);
                if(c=='=')
                    printf("\nGreater than equal to ");
                else
                    printf("\nGreater than ");
                break;
                
            case '!':
                scanf("%c",&c);
                if(c=='=')
                    printf("\nNot equal to ");
                else
                    printf("\nNot ");
                break;
                
            case '=':
                scanf("%c",&c);
                if(c=='=')
                    printf("\nEqual to ");
                break;
                
            case '+':
                printf("\nAddition ");
                break;
                
            case '-':
                printf("\nSubtraction ");
                break;
                
            case '*':
                printf("\nMultiplication ");
                break;
                
            case '/':
                scanf("%c",&c);
                if(c == '/')
                {
                    goto c;//Control goes to case 'c'
                }
                else if(c == '*')
                {
                    goto m;//Control goes to case 'm'
                }
                else
                {
                    printf("\nDivision ");
                    break;
                }
                
            case '%':
                printf("\nMod ");
                break;
                
            case '&':
                scanf("%c",&c);
                if(c=='&')
                    printf("\nAND ");
                break;
                
            case '|':
                scanf("%c",&c);
                if(c=='|')
                    printf("\nOR ");
                break;
                
            //Identifier
            case 'a':
                scanf("%c",&c);
                if(c=='\n' || c==' ')
                {
                    printf("\nIdentifier ");
                    break;
                }
                else
                {
                    while(isalnum(c))
                    {
                        scanf("%c",&c);
                        if(c=='\n')
                        {
                            printf("\nIdentifier ");
                            break;
                        }
                    }
                }
                break;
            
            //Digit
            case 'd':
                scanf("%c",&c);
                if(c=='\n' || c==' ')
                {
                    printf("\nInteger ");
                    break;
                }
                else if(c == '.')
                    goto frac;
                else if(c == 'E')
                    goto exp;
                while(isdigit(c))
                {
                    scanf("%c",&c);
                    if(c=='\n' || c==' ')
                    {
                        printf("\nInteger");
                        break;
                    }
                    else if(c == '.')
                        goto frac;
                    else if(c == 'E')
                        goto exp;
                }
                break;
                
            frac:
                scanf("%c",&c);
                while(isdigit(c))
                {
                    scanf("%c",&c);
                    if(c=='\n' || c==' ')
                    {
                        printf("\nFractional");
                        break;
                    }
                }
                break;
                
            exp:
                scanf("%c",&c);
                if(isdigit(c) || c == '+' || c == '-')
                {
                    scanf("%c",&c);
                    while(isdigit(c))
                    {
                        scanf("%c",&c);
                        if(c=='\n' || c==' ')
                        {
                            printf("\nExponential");
                            break;
                        }
                    }
                    break;
                }
                
            //Comments
            case 'c':
                c:  printf("\nComment ");
                    scanf("%c",&c);
                    while(c!='\n')
                    {
                        scanf("%c",&c);
                    }
                    break;
                
            case 'm':
                m: scanf("%c",&c);
                    while(isalnum(c))
                    {
                        scanf("%c",&c);
                    }
                    if(c == '*')
                    {
                        scanf("%c",&c);
                        if(c == '/')
                        {
                            printf("\nMultiline Comment ");
                            break;
                        }
                    }
                    break;
                
            case '\'':
                scanf("%c",&c);
                if(isalpha(c))
                {
                    scanf("%c",&c);
                    if (c == '\'')
                    {
                        printf("\nCharacter Constant");
                    }
                    break;
                }
                
            case '\"':
                scanf("%c",&c);
                while(isalpha(c))
                {
                    scanf("%c",&c);
                }
                if (c == '\"')
                {
                    printf("\nString Constant");
                }
                break;
        }
        scanf("%c",&c);
    }
}
