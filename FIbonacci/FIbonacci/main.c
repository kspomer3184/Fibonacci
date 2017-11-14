//Kyle Spomer
//U0000003184

//Fibonacci.c
//Submitted 11-12-17


#include "Fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>




HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q){
    HugeInteger * sum = malloc(sizeof(HugeInteger));
    int length, carry = 0, res;
    
    if(p->length > q->length)
        length = p->length;
    else{
        length = q->length;
    }
    
    
    
    for(int i = length - 1; i >= 0; i--){
        
        
        if(p->digits[i] + q->digits[i] > 9){
            res = p->digits[i] + q->digits[i] - 10 + carry;
            
            carry = 1;
        }
        else{
            res = p->digits[i] + q->digits[i];
            
            carry = 0;
        }
        
        sum->digits[i] = res + carry;
    }
    
    return sum;
}

HugeInteger *hugeDestroyer(HugeInteger *p){
    free(p);
    
    return NULL;
}

HugeInteger *parseString(char *str){
    if(str == NULL){
        return NULL;
    }
    if(str == ""){
        str = 0;
    }
    
    int length = strlen(str);
    
    HugeInteger * new = malloc(sizeof(HugeInteger));
    for(int i = 0; i < length; i++){
        new->digits = malloc(sizeof(int *) * length);
    }
    new->length = length;
    
    for (int i = 0; i <= length; i++){
        new->digits[i] = str[length - 1 -i] - '0';
    }
    
    return new;
}


HugeInteger *parseInt(unsigned int n){
    int length;
    unsigned int temp = n;
    
    for (length=0; temp!=0; length++, temp=temp/10){}
    
    if(n == 0){length = 1;}
    
    HugeInteger * new = malloc(sizeof(HugeInteger));
    for(int i = 0; i < length; i++){
        new->digits = malloc(sizeof(int *) * length);
    }
    
    new->length = length;
    
    for (int i = 0; i <= length; i++, n/=10){
        new->digits[i] =  (n % 10);
        //printf("%d", new->digits[i]);
    }
    
    return new;
}

unsigned int *toUnsignedInt(HugeInteger *p){
    unsigned int *result = calloc(1,sizeof(unsigned int));
    
    unsigned int count = 0;
    
    for (int i = p->length - 1; i >= 0; i--){
        count += (p->digits[i]  * (unsigned int) pow(10,i));
        
    }
    result = &count;
    
    return result;
}

HugeInteger *fib(int n){
    if(n == 0)
        return parseInt(0);
    if (n == 1)
        return parseInt(1);
    
    HugeInteger *first, *second, *third = malloc(sizeof(HugeInteger));
    first = parseInt(0);
    second = parseInt(1);
    
    
    for (int i = 2; i < n; i++){
        third = hugeAdd(first, second);
        first = second;
        second = third;
    }
    return third;
};


double difficultyRating(void){
    return 3;
}

double hoursSpent(void){
    return 4.5;
}
