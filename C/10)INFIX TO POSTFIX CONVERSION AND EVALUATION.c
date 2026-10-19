#include <stdio.h>
#include <math.h>
#include <string.h>
char A[20],p[20];
char s[20];
int s1[20];
int top=-1,top1=-1;

int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-': return 1;
		
		case '*':
		case '/':return 2;
		
		case '^': return 3;
	}
}

void infix_postfix()
{
	int i=0,j=0;
	char x,y;
	while(A[i]!='\0')
	{
		if (isdigit(A[i]))
		p[j++]=A[i];
		else if(A[i]=='(')
		s[++top]=A[i];
		else if(A[i]==')')
		{
			while (s[top]!='(')
			  p[j++]=s[top--];
			  top--;
		}
		else
		{
			x=A[i];
			y=s[top];
			if(top==-1 || y=='(' || precedence(y)<precedence(x))
			s[++top]=A[i];
			else
			{
				while(top!=-1 && y!='(' && precedence(y)<=precedence(x))
				{
					p[j++]=s[top--];
					y=s[top];
				}
				s[++top]=x;
			}
		}
		i++;
	}
	while(top!=-1)
		p[j++]=s[top--];
	p[j]='\0';
	printf("Postfix expression is:%s",p);
}

void postfix_eval()
{
	int i,op1,op2,result;
	char str[10];
	for(i=0;i<strlen(p);i++)
	{
		if(isdigit(p[i]))
		{
			str[0]=p[i];
			str[1]='\0';
			s1[++top1]=atoi(str);
			
		}
		else
		{
			op2=s1[top1--];
			op1=s1[top1--];
			switch(p[i])
			{
				case '+':result=op1+op2;
						break;
				case '-':result=op1-op2;
						break;
				case '*':result=op1*op2;
						break;
				case '/':result=op1/op2;
						break;
				case '^':result=pow(op1,op2);
						
				
						
			}
			s1[++top1]=result;
		}
	}
	printf("\nResult=%d",s1[0]);
}
void main()
{
	printf("Enter Infix expression:");
	gets(A);
	infix_postfix();
	postfix_eval();
}
