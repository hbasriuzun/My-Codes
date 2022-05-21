#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	double x;
	double y;
	double z;
} Vector;

void print_vector(const Vector v);
Vector sum(const Vector v1, const Vector v2);
Vector diff(const Vector v1, const Vector v2);
double dot_product(const Vector v1, const Vector v2);
Vector cross_product(const Vector v1, const Vector v2);
double norm(const Vector v);
int is_unitvector(const Vector v);
Vector unit(const Vector v);
Vector multiplyby_scalar(const Vector v1, const double c);
double angle(const Vector v1, const Vector v2);
double distance(const Vector v1, const Vector v2);
int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3);
int are_orthogonal(const Vector v1, const Vector v2, const Vector v3);
int are_orthonormal(const Vector v1, const Vector v2, const Vector v3);
Vector projection(const Vector v1, const Vector v2);
Vector orthogonal_projection(const Vector v1, const Vector v2);
int convert_2_orthogonal_basis(Vector *v1, Vector *v2, Vector *v3);
char* vector2str(const Vector v);

 
int main () 
{
	Vector v1 = {1, 2, 2}, v2 = {-1, 0, 2}, v3 = {0, 0, 1}, vunit = {1, 1, 1}; 
	double k = 2;

    printf("v1 = ");
    print_vector(v1);
    printf("v2 = ");
    print_vector(v2);
    printf("v3 = ");
    print_vector(v3);
	 
    printf("v1 + v2 = ");
	print_vector(sum(v1, v2));
	
	printf("v1 - v2 = ");
	print_vector(diff(v1, v2));
	
	printf("k * v1  = ");
	print_vector(multiplyby_scalar(v1, k));
	
	printf("v1 . v2 = %.2lf\n", dot_product(v1, v2));
	
	printf("v1 x v2 = ");
	print_vector(cross_product(v1, v2));
	
	printf("| v1 |  = %.2lf\n", norm(v1));
	
	if(is_unitvector(v1))
		printf("v1 is a unit vector.\n");
	else
		printf("v1 is not unit vector.\n");
	
	printf("unit( v1 ) = ");
	print_vector(unit(v1));
	
	printf("angle(v1, v2) = %.2lf\n", angle(v1, v2));
	
	printf("distance(v1, v2) = %.2lf\n", distance(v1, v2));
		
//	if(are_linearly_independent(v1, v2, v3))
//		printf("Vectors are linearly independent.\n");
//	else
//		printf("Vectors are not linearly independent.\n"); 
	
	if(are_orthogonal(v1, v2, v3))
		printf("Vectors are orthogonal.\n");
	else
		printf("Vectors are not orthogonal.\n");
		
//	if(are_orthonormal(v1, v2, v3))
//		printf("Vectors are orthonormal.\n");
//	else
//		printf("Vectors are not orthonormal.\n");	
		
	printf("Projection of v1 onto v2 is = ");
	print_vector(projection(v1, v2));
 /*
	
	printf("Orthogonal projection of v1 onto v2 is = ");
	print_vector(orthogonal_projection(v1, v2));
	
	
	if(convert_2_orthogonal_basis(&v1, &v2, &v3)){
		printf("Orthogonalization of vectors:\n");
		printf("v1 = ");
	    print_vector(v1);
	    printf("v2 = ");
	    print_vector(v2);
	    printf("v3 = ");
	    print_vector(v3);
	}		
    
    puts(vector2str(v1));*/
   
    return 0;  
}

    void print_vector(const Vector v)
    {
        printf("(%.2lf, %.2lf, %.2lf)\n",v.x, v.y, v.z);
    }
    Vector sum(const Vector v1, const Vector v2)
    {
        Vector sum;
        sum.x = v1.x + v2.x;
        sum.y = v1.y + v2.y;
        sum.z = v1.z + v2.z;
        return sum;
    }
    Vector diff(const Vector v1, const Vector v2)
    {
        Vector dif;
        dif.x = v1.x - v2.x;
        dif.y = v1.y - v2.y;
        dif.z = v1.z - v2.z;
        return dif;
    }
    double dot_product(const Vector v1, const Vector v2)
    {
        double sum=0;
        sum += v1.x * v2.x;
        sum += v1.y * v2.y;
        sum += v1.z * v2.z;
        return sum;
    }
    Vector cross_product(const Vector v1, const Vector v2)
    {
        Vector v3;
        v3.x = (v1.y * v2.z) - (v1.z * v2.y);
        v3.y = (v1.z * v2.x) - (v1.x * v2.z);
        v3.z = (v1.x * v2.y) - (v1.y * v2.x);
        return v3;

    }
    double norm(const Vector v)
    {
        return sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2));

    }
    int is_unitvector(const Vector v)
    {
        if (1==abs(sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2))))
            return 1;
        else
            return 0;
        
    }
    Vector unit(const Vector v)
    {
        Vector v3;
        v3.x =v.x / sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2));
        v3.y =v.y / sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2));
        v3.z =v.z / sqrt(pow(v.x,2)+pow(v.y,2)+pow(v.z,2));
        return v3;
    }
    Vector multiplyby_scalar(const Vector v1, const double c)
    {
        Vector multiply;
        multiply.x = v1.x*c;
        multiply.y = v1.y*c;
        multiply.z = v1.z*c;
        return multiply;
    }
    double angle(const Vector v1, const Vector v2)
    {
        return acos(dot_product(v1,v2) / (norm(v1) * norm(v2)));
    }
    double distance(const Vector v1, const Vector v2)
    {
        return norm(diff(v1,v2)) ;
    }
    int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3);
    int are_orthogonal(const Vector v1, const Vector v2, const Vector v3)
    {
        if (dot_product(v1,v2)==1 && dot_product(v1,v3)==1 && dot_product(v3,v2)==1)
            return 1;
        else
            return 0;
    }
    int are_orthonormal(const Vector v1, const Vector v2, const Vector v3)
    {
        if (dot_product(v1,v2)==1 && dot_product(v1,v3)==1 && dot_product(v3,v2)==1)
            return 1;
        else
            return 0;
    }
    Vector projection(const Vector v1, const Vector v2)
    {
        Vector v3;
        v3 = diff(v1,multiplyby_scalar(v2,(dot_product(v1,v2) / pow(norm(v1),2))));
        return v3; 
    }
    Vector orthogonal_projection(const Vector v1, const Vector v2);
    int convert_2_orthogonal_basis(Vector *v1, Vector *v2, Vector *v3);
    char* vector2str(const Vector v);
