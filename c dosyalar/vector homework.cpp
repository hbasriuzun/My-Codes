#include <stdio.h>
#include <math.h>

struct vector{
    float i;
    float j;
    float k;
};
typedef  struct vector vector;
void print_vector(const vector v){
    printf("the vector is %f  %f  %f \n", v.i,v.j,v.k);
}
vector sum(const vector v1, const vector v2){
    vector result;
    result.i= v1.i + v2.i;
    result.j= v1.j +v2.j;
    result.k= v1.k + v2.k;
    return result;
}
vector diff(const vector v1, const vector v2){
    vector result;
    result.i= v1.i - v2.i;
    result.j= v1.j - v2.j;
    result.k= v1.k - v2.k;
    return result;
}
double dot_product(const vector v1, const vector v2){
    double result,a,b,c;
    a = v1.i * v2.i;
    b = v1.j * v2.j;
    c = v1.k * v2.k;
    result=a+b+c;
    return result;
}
vector cross_product(const vector v1, const vector v2){
    vector result;
    result.i = v1.j*v2.k - v2.j*v1.k;
    result.j = v1.k*v2.i - v1.i*v2.k;
    result.k = v1.i*v2.j - v1.j*v2.i;
    return result;
}
double norm(const vector v){
    double result,a,b,c,x;
    a = v.i*v.i;
    b = v.j*v.j;
    c = v.k*v.k;
    x = a+b+c;
    result = sqrt(x);
    return result;
}
void is_unitvector(const vector v){
    int result=0;
    result+= v.i*v.i;
    result += v.j*v.j;
    result+= v.k*v.k;
    result = sqrt(result);
    if(result==1) printf("it is a unit vector. \n");
    else printf("it is not a unit vector \n");
}
vector unit(const vector v){
    float norm=0;
    vector result;
    norm+= v.i*v.i;
    norm += v.j*v.j;
    norm+= v.k*v.k;
    norm = sqrt(norm);
    result.i = v.i/norm;
    result.j = v.j/norm;
    result.k = v.k/norm;
    return result;
}
vector multiplyby_scalar(const vector v, const double c){
    vector result;
    result.i = c * v.i;
    result.j = c * v.j;
    result.k = c * v.k;
    return result;
}
double angle(const vector v1, const vector v2){
    float a;
    a= acos(dot_product(v1, v2)/(norm (v1)*norm(v2)));
    return a;
}
double distance(const vector v1, const vector v2){
    vector a=diff(v1,v2);
    double b=norm(a);
    return b;
}
int are_linearly_independent(const vector v1, const vector v2, const vector v3){
    double a = v1.i*v2.j*v3.k + v1.j*v2.k*v3.i + v1.k*v2.i*v3.j;
    double b = -v1.j*v2.i*v3.k - v1.i*v2.k*v3.j - v1.k*v2.j*v3.i;
    if(a+b!=0) return 1;
    else return 0;
}
int are_orthogonal(const vector v1, const vector v2, const vector v3){
    double a,b,c;
    a = dot_product(v1,v2);
    b= dot_product(v1,v3);
    c= dot_product(v2,v3);
    if(a==0 && b==0 && c==0) return 1;
    else return 0;
}
int are_orthonormal(const vector v1, const vector v2, const vector v3){
    if(are_orthogonal(v1,v2,v3)==1 && are_linearly_independent(v1,v2,v3)==1) return 1;
    else return 0;
}
vector projection(const vector v1, const vector v2){
    vector result;
    float a;
    a = dot_product(v1,v2)/(norm(v2)*norm(v2));
    result = multiplyby_scalar(v2,a);
    return result;
}
vector orthogonal_projection(const vector v1, const vector v2){
    vector result;
    vector a=projection(v1,v2);
    result = diff(v1,a);
    return result;
}
int convert_2_orthogonal_basis(vector *v1, vector *v2, vector *v3){
    if (are_linearly_independent(*v1,*v2,*v3)==1) {
        vector a,b,c;
        a=*v1;
        b=diff(*v2, projection(a,*v2));
        c= diff(diff(*v3 , projection(a,*v3)) , projection(b,*v3));
        printf("v1 = %f  %f  %f\n", a.i,a.j,a.k);
        printf("v2 = %f  %f  %f\n", b.i,b.j,b.k);
        printf("v3 = %f  %f  %f\n", c.i,c.j,c.k);
        return 1;
    }
    else return 0;
}
char* vector2str(const vector v){
    int a,b,c;
    char *vec[100];
    a= v.i;
    b=v.j;
    c=v.k;
    sprintf(*vec, "in string, the vector is %f %f %f \n", a, b, c);
    return *vec;
}

int main(){
    int c=2;
    vector v1,v2,v3;
    v1.i = 1.00;
    v1.j = 2.00;
    v1.k = 2.00;
    v2.i = -1.00;
    v2.j = 0.00;
    v2.k = 2.00;
    v3.i = 0.00;
    v3.j = 0.00;
    v3.k = 1.00;
    print_vector(v1);
    print_vector(v2);
    print_vector(v3);
    vector a=sum(v1,v2);
    printf("sum is %f  %f  %f \n", a.i,a.j,a.k);
    a=diff(v1,v2);
    printf("diff is %f  %f  %f \n", a.i,a.j,a.k );
    printf("dot product is %lf \n" , dot_product(v1,v2));
    a=cross_product(v1,v2);
    printf("cross product is %f  %f  %f \n",a.i,a.j,a.k);
    printf("norm is %lf \n", norm(v1));
    is_unitvector(v1);
    a=unit(v1);
    printf("unit is %f  %f  %f \n",a.i,a.j,a.k);
    a=multiplyby_scalar(v1,c);
    printf("%f  %f  %f \n",a.i,a.j,a.k);
    printf("the angle is %f \n",angle(v1,v2));
    printf("the distance is %lf \n", distance(v1,v2));
    if(are_linearly_independent(v1,v2,v3)==1)  printf("these 3 vectors are linearly independant \n");
    if (are_linearly_independent(v1,v2,v3)==0)  printf("these 3 vectors are linearly dependant \n");
    if(are_orthogonal(v1,v2,v3)==1) printf("these 3 vectors are orthogonal \n");
    if(are_orthogonal(v1,v2,v3)==0) printf("these 3 vectors are not orthogonal \n");
    if(are_orthonormal(v1,v2,v3)==1) printf("these 3 vectors are orthonormal \n");
    if(are_orthonormal(v1,v2,v3)==0) printf("these 3 vectors are not orthonormal \n");
    a=projection(v1,v2);
    printf("the projection of v1 onto v2 is %f %f %f\n",a.i,a.j,a.k);
    a=orthogonal_projection(v1,v2);
    printf("the orthogonal projection of v1 onto v2 is %f %f %f\n",a.i,a.j,a.k);
    if(convert_2_orthogonal_basis(&v1,&v2,&v3)==1){
        printf("these vectors can get orthogonal, new vectors are :\n");
    }
    if(convert_2_orthogonal_basis(&v1,&v2,&v3)==0) printf("these vectors can not get orthogonal\n");
    printf("%s",vector2str(v1));
}
