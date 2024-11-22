#include<stdio.h>
struct rectangle{
float length;
float width;
};
void area(float l , float w){
float area;
area=l*w;
printf("AREA = %.2f\n", area);

}
void perimeter(float l , float w){
float peri;
peri=2*(l+w);
printf("PERIMETER = %.2f", peri);

}
int main(){
struct rectangle data;
printf("Enter Length Of Rectangle : ");
scanf("%f", & data.length);
printf("Enter Width Of Rectangle : ");
scanf("%f",& data.width);
area(data.length,data.width);
perimeter(data.length,data.width);
return 0;
}
