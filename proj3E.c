#include <stdio.h>
#include <stdlib.h>
#define STACK_CAPACITY 100


typedef struct {
    int top;
    float values[STACK_CAPACITY];
} Stack;

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
    /* Implement me! */
	if(op[1] != '\0')
	{
		return UNSUPPORTED;
	}
	switch (*op)
	{
	case '+':
		return ADD;
	case 'x':
		return MULT;
	case '-':
		return SUBTRACT;
	case '/':
		return DIV;
	}
	return UNSUPPORTED;
}		


double StringToDouble(char *str)
{
	int symbol = 1;
	double val = 0.0;
	int i = 0;
	int dec = 0;
	int fract = 1; 
	if (str[i] == '-')
	{
		symbol = -1.0;
		i++;
	}
	while(str[i] != '\0')
	{
		if (str[i] == '.')
		{	
			if (dec == 1)
				IssueBadNumberError();
			i++;
			dec = 1;
			continue; 
		}
		if (str[i] >='0' && str[i] <= '9')
		{
			val = val*10 + (str[i] - '0');
	
		}
		else
			IssueBadNumberError();
		
		if (dec == 1)
			fract *= 10;	
		i++;
	}
	//	val = (10^(-1*count))*val;
	val = val/fract;
	return val * symbol;
}



void Initialize(Stack *s)
{
    s->top = 0;
    
}
void push(Stack* s, float item)
{
    if (s->top < STACK_CAPACITY)
    {   
        s->values[s->top] = item;
        s->top  ++;
    }
}

float pop(Stack* s)
{
    if (s->top == 0)
    {
        printf("trying to pop when there are no elements\n");
        exit(EXIT_FAILURE);
    }
    float val = s->values[s->top-1];
    s->top --;
    return val;
}

float calc(Stack* s, MathOperation op)
{
    float v = pop(s);
    float v2 = pop(s);
    float result = 0.0;
    switch (op)
    {
	case ADD:
         result = v+v2;
         break;
	case SUBTRACT:
	 result = v2-v;
	 break;
	case MULT:
	 result = v*v2;
	 break;
    default:
     printf("Unsupported Operation\n");
     break;
    }
    push(s,result);
    return result;
}

int main(int argc, char *argv[])
{
    Stack s;
    Initialize(&s);
    if (argc == 1)
    {
        printf("Not enough arguments\n");
        exit(EXIT_FAILURE);
    }
    float val = 0.0;
    for (int i = 1; i < argc; i++)
    {
       
        MathOperation op = GetOperation(argv[i]);
        if (op == UNSUPPORTED)
        {
            float v =(float) StringToDouble(argv[i]);
            push(&s,v);
            continue;
        } 
        val = calc(&s, op);
    }
    printf("The total is %d\n",(int) val);
    return 0; 
}
