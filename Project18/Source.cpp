#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
#include <malloc.h>
int DET;
void printf_array(int *Parray, int string, int column ) {
	for (int i = 0; i < string; i++) {
		for (int j = 0; j < column; j++){
			printf("%d\t", *(Parray + column * i + j));
		}
		printf("\n");
	}
}
void printf_array_double(double *Parray, int string, int column) {
	for (int i = 0; i < string; i++) {
		for (int j = 0; j < column; j++) {
			printf("%lf\t", *(Parray + column * i + j));
		}
		printf("\n");
	}
}
void put_in_array(int *Parray,  int string, int column ) {
	
	for (int i = 0; i < string; i++) {

		for (int j = 0; j < column; j++)
		{
			scanf_s("%d\t", (Parray+i*column+j));
		}

	}
	printf("\n");
}

void composition(int *Parray_1, int *Parray_2, int string, int column) {
	
	for (int i = 0; i < string; i++) {

		for (int k = 0; k < column; k++) {
			int c = 0;
			for (int j = 0; j < column; j++) {
				int a = *(Parray_1 + i*column + j);
				int b = *(Parray_2 + k + j*column);
				c+=a*b;
			}
			printf("%d\t", c);
		}
		printf("\n");
			
	}
}

int determinant_po_minoram(int *Parray_1, int string, int column) {
	if (column != string) { printf("comilation error"); return 000; }
	
	if (column == 1)  return (*(Parray_1)); 
	//if (column == 1) { printf("%d", *Parray_1); return *(Parray_1); }
	int determinant = 0;
	for (int k = 0; k < column; k++) {
		int *Parray_dinamic = (int*)malloc((column - 1)*(column - 1) * sizeof(int));
		int g = 0;
		for (int i = 0; i < ((column)*(column)-column); i++) {
			if (i % column == k) g++; ///должен сосчитать цифру, которую исклюлючит из массива (вычеркиваем стобец)
			else {
				*(Parray_dinamic + i-g) = *(Parray_1 + i + column);
			}
		}//массив миноров дл€ элемента строки заполнен
		
		int z = *(Parray_1 + k);//запоминает элемент строки
		determinant += pow(-1.0, k)*z*determinant_po_minoram(Parray_dinamic, string - 1, column - 1);;//алгебраические дополнени€, умнооженные на соответсвующие миноры(по строке)
		free(Parray_dinamic);
	}//цикл повтор€етс€ дл€ каждого элемента строки
	return determinant;
}
int inverse_matrix(int *Parray_1, int string, int column) {
	double *Parray_inverse = (double*)malloc((column)*(column) * sizeof(int));// массив содержащий транспонированную  матрицу алгебраичскихдополнений
	if (DET == 0) { printf("complete error"); return 0; }
	for (int j = 0; j < string; j++) {
		for (int k = 0; k < column; k++) {
			int *Parray_minor = (int*)malloc((column - 1)*(column - 1) * sizeof(int));//динамический массив-минор
			int g = 0;
			for (int i = 0; i < ((column)*(column)); i++) {
				if ((i % string == k) || ((i >= j*column) && (i < (j + 1)*column)))  g++; 
				else
					*(Parray_minor + i-g) = *(Parray_1 + i);
			}
			*(Parray_inverse + k*column + j) = pow(-1.0, k + j)*determinant_po_minoram(Parray_minor, string - 1, column - 1)*pow(DET,-1);
		}
	}//заполнение массива алгебраических дополнений 	
	printf_array_double(Parray_inverse, string, column);
} 
int main() {
	int string;
	int column;
	printf("string=");
	scanf_s("%d", &string);
	printf("column=");
	scanf_s("%d", &column);

	int *array_1 =(int*) malloc(column*string * sizeof(int*));
	int *array_2 = (int*)malloc(column*string * sizeof(int*));
	
	put_in_array(array_1, string, column);
	printf_array(array_1, string, column);
	
	//put_in_array(array_2, string, column);
	//printf_array_2((int*)array_2, string, column);
 
	//composition((int*)array_1, (int*) array_2, string, column);
   
	DET = determinant_po_minoram(array_1, string, column);
	printf("DETERMINANT=%d\n", DET);
	inverse_matrix(array_1, string, column);
	_getch();

	return 0;
}