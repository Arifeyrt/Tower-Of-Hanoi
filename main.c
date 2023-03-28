#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum shapes
{
 triangle = 1,quadrilateral,circle,pyramid,cylinder
};
enum calculator
{
 area = 1,perimeter,volume
};
int select_shape();
int select_calc();
float check();
int calculate(int(*sh)(),int (*sc)());
int calc_triangle(int sc); 
int calc_quadrilateral(int sc);
int calc_circle(int sc);
int calc_pyramid(int sc);
int calc_cylinder(int sc);



int main()
{
calculate(select_shape,select_calc);
 return 0;
}
// menu of shapes i will choose 
int select_shape()
{       int num;
   do{
   printf("select a shape to calculate: \n");
   printf("------------------------------\n");
   printf("1. Triangle\n");
   printf("2. Quanrilateral\n");
   printf("3. Circle\n");
   printf("4. Pyramid\n");
   printf("5. Cylinder\n");
   printf("0. Exit\n");
   printf("------------------------------\n");
   printf("Input : ");
   num = check();
   } while(num!=0 && num!=1 && num!=2 && num!=3 && num!=4 && num!=5);
return num;
}
// menu of calculator i will choose
int select_calc(){
int calc;

do{
printf("Select calculator: \n");
printf("--------------------\n");
printf("1. Area\n");
printf("2. Perimeter\n");
printf("3. Volume\n");
printf("0. Exit\n");
printf("--------------------\n");
printf("Input : ");
calc =check();
}while(calc!=0 && calc!=1 && calc!=2 && calc!=3);

return calc;
}

int calculate(int(*sh)(),int (*sc)()){
enum shapes x;
enum calculator y;
do{
x=sh();
switch(x){
 case triangle:
    y=sc();
    if(y != 0) calc_triangle(y);
  break;
 case quadrilateral:
      y=sc();
    if(y != 0) calc_quadrilateral(y);
  break;
 case circle:
         y=sc();
    if(y != 0)calc_circle(y);
  break;
 case pyramid:
         y=sc();
    if(y != 0)calc_pyramid(y);
  break;
 case cylinder:
        y=sc();
     if(y != 0) calc_cylinder(y);
  break;
 case 0:
     printf("exit");
    break;
 }
}while(x != 0 && y != 0);

}

float check(){
char c;
int x = 0;
float number;

while (x ==0){
    number = 0;
    fflush(stdin);
    c = getchar();
    x = 1;
    while (c!= '\n'){

      if (c < 48 || c > 57){
        x = 0;
      }
      else number = number * 10 + (c - '0');
      
      
      c = getchar();
}
    if (x == 0){
    printf("ERROR! Please enter a valid entry.\n");
    }
}

return number;
}
int calc_triangle(int sc){
    float a,b,c;
    float s;
    float result;
    float x;

    switch(sc){
  case area:
        printf("please enter three sides of triangle: \n");
        a=check();
        b=check();
        c=check();
        s=(a+b+c)/2;
       
       while(s <= a || s <= b || s <= c)
        { printf("ERROR ! please enter a valid triangle\n");     // condition of being a triangle
            a=check();
            b=check();
            c=check();
            s=(a+b+c)/2;
        }
        
       

        x=s*(s-a)*(s-b)*(s-c);
        result=sqrt(x);
        printf("Area of TRIANGLE : %f \n",result);

    break;
  case perimeter:
        printf("please enter three sides of triangle: \n");
        a=check();
        b=check();
        c=check();
            s=(a+b+c)/2;
        while(s<=a || s<=b || s<=c)
        {   printf("ERROR ! please enter a valid triangle.\n");
            a=check();
        b=check();
        c=check();
        }
       x=a+b+c;
       printf("perimeter of TRYANGLE : %f \n",x);
    break;
  case volume:
      printf("you cannot calculate the volume of a triangle. Please try again.\n");
    break;

    }
return 0;}


int calc_quadrilateral(int sc){
float a,b,c,d;
float s;
float result;
float x;

    switch (sc){

        
 case area:
        printf("please enter four sides of Quadrilateral\n");
        a=check();
        b=check();
        c=check();
        d =check();
     s=(a+b+c+d)/2;
     x=(s-a)*(s-b)*(s-c)*(s-d);    //area formula of a quadrilateral
     result=sqrt(x);
     printf("Area of the QUADRILATERAL: %f \n",result);
    break;
 case perimeter:
      printf("please enter four sides of Quadrilateral\n");
        a=check();
        b=check();
        c=check();
        d =check();
       
     result=a+b+c+d;
     printf("perimeter of yhe QUADRYLATERAL: %f \n",result);
    break;
 case volume:
     printf("you cannot calculatte the volume of a QUADRYLATERAL. Please try again.\n");
    break;

    }
}
int calc_circle(int sc){
float r;
float result;
float pi=3.14;

    switch(sc){
case area:
    printf("please enter the radius of Circle : ");
    r = check();
    while(r<=0)
    {
      printf("ERROR ! please enter a valid entery.\n");
      r = check();
    }
    result=pi*r*r;
    printf("area of CIRCLE: %f \n",result);

    break;
case perimeter:
     printf("please enter the radius of Circle : ");
    r = check();
    result=2*pi*r;
    printf("perimeter  of CIRCLE : %f \n",result);
    break;
case volume:
     printf("you cannot calculate the volume of a CIRCLE. Please try again.");
    break;
    }
    }


 int calc_pyramid(int sc){
 float a,h,l,p;
 float V;
 float B,L,BL;
     switch(sc){

 case area:
     printf("please enter the base side and slant height of a Pyramid: ");
     a = check();
     l = check();
     B=a*a;
     L=2*a*l;
     BL=B+L;
     printf("Base surface area of a PYRAMID: %f",B);
     printf("Lateral surface area of a PYRAMID: %f",L);
     printf("Surface Area of a PYRAMID: %f",BL);
    break;
 case perimeter:
      printf("please enter the base side\n");
      a=check();
      p=4*a;
      printf("base perimeter of a pyramid: %f ",p);

    break;
 case volume:
     printf("please enter the base side and height of a Pyramid: \n");
     a=check();
     h=check();
    
     V=(a*a*h)/3;
     printf("volume of a PYRAMID: %f\n",V);
    break;
     }
 }

 int calc_cylinder(int sc){
  float V,BS,LS,SA,BSP;
  float r,h;
  float pi=3.14;
   
     switch(sc){
 case area:
     printf("please enter the radius and height of a Cylinder : \n");
     r=check();
     h=check();
     BS=pi*r*r;
     printf("Base surface area of a CYLINDER: %f\n",BS);
     LS=2*pi*r*h;
     printf("Lateral surface area of a CYLINDER : %f\n",LS);
     SA=2*pi*r*(r+h);
     printf("Surface Area of a CYLINDER: %f\n",SA);
    break;
 case perimeter:
     printf("please enter the radius  of a Cylinder : \n");
     r=check();
     BSP=2*pi*r;
     printf("base surface perimeter of a CYLINDER: %f \n ",BSP);
    break;
 case volume:
    printf("please enter the radius and height of a Cylinder : \n");
     r=check();
     h=check();
     V=pi*r*r*h;
     printf("volume of a CYLINDER: %f\n",V);
    break;
     }
     }
