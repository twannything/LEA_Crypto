#pragma once
#include "Arithmetic.h"
#include "test.h"
#include <time.h>

/**
* @brief add_test : ���� ������ ���� ��Ȯ�� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x �� y �׸��� x + y ���� ������ ��ѹ� z �� ����
* @brief x �� y�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x �� y�� wordlen : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void add_test(FILE* fp) {
	
	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL;
		bigint* y = NULL;
		bigint* z = NULL;

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		ADD(x, y, &z);

		//ADD_print(x, y, &z);

		

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("y=");
		bi_show_hex(y);
		printf("\n\n");	
		printf("x + y ==");
		bi_show_hex(z);
		printf("\n\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("print(x + y ==",fp);
		File_print(z,fp);
		fputs(")", fp);
		fprintf(fp, "\n");
		
		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&z);
	}
}

/**
* @brief sub_test : ���� ������ ���� ��Ȯ�� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x �� y �׸��� x - y ���� ������ ��ѹ� z �� ����
* @brief x �� y�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x �� y�� wordlen : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void sub_test(FILE* fp) {
	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL;
		bigint* y = NULL;
		bigint* z = NULL;

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		SUB(x, y, &z);
		//SUB_print(x, y, &z);	

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("y=");
		bi_show_hex(y);
		printf("\n\n");
		printf("x - y ==");
		bi_show_hex(z);
		printf("\n\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("print(x - y ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&z);
	}
}

/**
* @brief mul_test : ���� ������ ���� ��Ȯ�� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x �� y �׸��� x * y ���� ������ ��ѹ� z �� ����
* @brief x �� y�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x �� y�� wordlen : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void  mul_test(FILE* fp) {

	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL;
		bigint* y = NULL;
		bigint* z = NULL;

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		MUL(x, y, &z);
		//MUL_print(x, y, &z);		

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("y=");
		bi_show_hex(y);
		printf("\n");
		printf("x * y ==");
		bi_show_hex(z);
		printf("\n\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("print(x * y ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&z);
	}
}

/**
* @brief bi_binary_long_division_test : ���� �� ������ ������ ���� ��Ȯ�� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x �� y �׸��� x / y ���� �� �� �������� ������ ��ѹ� q, r �� ����
* @brief x �� y�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x �� y�� wordlen : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void bi_binary_long_division_test(FILE* fp) {
	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL;
		bigint* y = NULL;
		bigint* q = NULL;
		bigint* r = NULL;

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		printf("x = "); bi_show_hex(x); printf("\n");
		printf("y = "); bi_show_hex(y); printf("\n");


		bi_binary_long_division(x, y, &q, &r);
	

		if (bi_is_zero(q) && bi_is_zero(r)) {
			bi_delete(&x);
			bi_delete(&y);
			bi_delete(&q);
			bi_delete(&r);
		}
		else {
			bi_show_hex(x); printf("=="); printf("("); bi_show_hex(y);
			printf(" * ");
			bi_show_hex(q); printf(")"); printf("+");
			bi_show_hex(r); printf("\n");

			fputs("x=", fp);
			File_print(x, fp);
			fprintf(fp, "\n");
			fputs("y=", fp);
			File_print(y, fp);
			fprintf(fp, "\n");
			fputs("q=", fp);
			File_print(q, fp);
			fprintf(fp, "\n");
			fputs("r=", fp);
			File_print(r, fp);
			fprintf(fp, "\n");

			//print(x//y==q,x%y==r)
			fputs("print(x", fp);
			fputs("//y", fp);
			fputs("==q", fp);
			fputs(",x", fp);
			fputs("%y", fp);
			fputs("==r", fp);
			fputs(")\n", fp);

			bi_delete(&x);
			bi_delete(&y);
			bi_delete(&q);
			bi_delete(&r);
		}
	}
}

/**
* @brief div_test :
* @brief ���� : ��ѹ� x �� y �׸��� x / y ���� �� �� �������� ������ ��ѹ� q, r �� ����
* @brief x �� y�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x �� y�� wordlen : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void div_test(FILE* fp) {

	for (int i = 0; i <= TEST; i++) {

		bigint* x = NULL;
		bigint* y = NULL;
		bigint* q = NULL;
		bigint* r = NULL;
		
		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		printf("x = "); bi_show_hex(x); printf("\n");
		printf("y = "); bi_show_hex(y); printf("\n");

		bi_div(x, y, &q, &r);

		//bi_div_print(x, y, &q, &r);
		if (bi_is_zero(q) && bi_is_zero(r)) {
			bi_delete(&x);
			bi_delete(&y);
			bi_delete(&q); 
			bi_delete(&r);
		}
		else {
			bi_show_hex(x); printf("=="); printf("("); bi_show_hex(y);
			printf(" * ");
			bi_show_hex(q); printf(")"); printf("+");
			bi_show_hex(r); printf("\n");

			fputs("x=", fp);
			File_print(x, fp);
			fprintf(fp, "\n");
			fputs("y=", fp);
			File_print(y, fp);
			fprintf(fp, "\n");
			fputs("q=", fp);
			File_print(q, fp);
			fprintf(fp, "\n");
			fputs("r=", fp);
			File_print(r, fp);
			fprintf(fp, "\n");

			fputs("print(x", fp);
			fputs("//y", fp); 
			fputs("==q", fp);
			fputs(",x", fp); 
			fputs("%y", fp); 
			fputs("==r", fp);
			fputs(")\n", fp);

			bi_delete(&x);
			bi_delete(&y);
			bi_delete(&q);
			bi_delete(&r);
		}
	}
}

/**
* @brief Squaring_test : ��ѹ� ���� ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x �� x^2 ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND 
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void Squaring_test(FILE* fp) {

	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL;
		bigint* z = NULL;
		
		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		SQU(x, &z);
		//SQU_print(x, &z); 
		
		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("power(x,2) ==");
		bi_show_hex(z);
		printf("\n\n");
		
		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("print(x * x ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&z);
	}
}

/**
* @brief L2R_test : Left to Right ����� �ŵ����� ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ����Ƚ���� �����ϴ� n , x^n ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief n�� ��ȣ : NONNEGATIVE
* @brief n�� ���� : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void L2R_test(FILE* fp) {
	for (int i = 0; i <= TEST; i++) {
		
		bigint* x = NULL;
		bigint* z = NULL;
		
		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		int n = ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND);
		left_to_right(x, &z, n);

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("n=%d\n", n);
		printf("power(x,n) ==");
		bi_show_hex(z);
		printf("\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("n=", fp);
		fprintf(fp, "%d", n);
		fprintf(fp, "\n");
		fputs("print(power(x,n) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&z);
	}
}

/**
* @brief L2R_Modular_bi_test : Left to Right ����� ��ѹ� �ŵ����� ��ⷯ ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ����Ƚ���� �����ϴ� ��ѹ� y , ��ⷯ ������ �����ϴ� ��ѹ� p ,  x^y mod p ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief y�� ��ȣ : NONNEGATIVE
* @brief y�� ���� : LOWERBOUND ~ UPPERBOUND
* @brief p�� ��ȣ : NONNEGATIVE
* @brief p�� ���� : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void L2R_Modular_bi_test(FILE* fp) {


	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL; // �ŵ����� �� ��
		bigint* y = NULL; // �ŵ����� Ƚ ��
		bigint* z = NULL; // ��� ���� �� ��
		bigint* p = NULL; // mod ���� �� ����(=��)

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, NONNEGATIVE, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&p, NONNEGATIVE, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		left_to_right_mod_bi(x, y, p, &z);

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("y=");
		bi_show_hex(y);
		printf("\n");
		printf("p=");
		bi_show_hex(p);
		printf("\n");
		printf("power_mod(x,y,p) ==");
		bi_show_hex(z);
		printf("\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("p=", fp);
		File_print(p, fp);
		fprintf(fp, "\n");
		fputs("print(power_mod(x,y,p) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&p);
		bi_delete(&z);
	}

}

/**
* @brief R2L_test : Right to Left ����� �ŵ����� ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ����Ƚ���� �����ϴ� n , x^n ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief n�� ��ȣ : NONNEGATIVE
* @brief n�� ���� : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void R2L_test(FILE* fp) {

	for (int i = 0; i <= TEST; i++) {

		bigint* x = NULL;
		bigint* z = NULL;

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		int n = ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND);
		right_to_left_print(x, &z, n);

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("n=%d\n", n);
		printf("power(x,n) ==");
		bi_show_hex(z);
		printf("\n\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("n=", fp);
		fprintf(fp, "%d", n);
		fprintf(fp, "\n");
		fputs("print(power(x,n) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&z);
	}
}

/**
* @brief R2L_Modular_bi_test : Right to Left ����� ��ѹ� �ŵ����� ��ⷯ ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ����Ƚ���� �����ϴ� ��ѹ� y , ��ⷯ ������ �����ϴ� ��ѹ� p ,  x^y mod p ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief y�� ��ȣ : NONNEGATIVE
* @brief y�� ���� : LOWERBOUND ~ UPPERBOUND
* @brief p�� ��ȣ : NONNEGATIVE
* @brief p�� ���� : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void R2L_Modular_bi_test(FILE* fp) {

	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL; // �ŵ����� �� ��
		bigint* y = NULL; // �ŵ����� Ƚ ��
		bigint* z = NULL; // ��� ���� �� ��
		bigint* p = NULL; // mod ���� �� ����(=��)

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, NONNEGATIVE, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&p, NONNEGATIVE, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		right_to_left_mod_bi(x, y, p, &z);


		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("y=");
		bi_show_hex(y);
		printf("\n");
		printf("p=");
		bi_show_hex(p);
		printf("\n");
		printf("power_mod(x,y,p) ==");
		bi_show_hex(z);
		printf("\n");
		
		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("p=", fp);
		File_print(p, fp);
		fprintf(fp, "\n");
		fputs("print(power_mod(x,y,p) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&p);
		bi_delete(&z);
	}

}

/**
* @brief Mul_N_Squ_bi_test : Montgomery ����� ��ѹ� �ŵ����� ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ����Ƚ���� �����ϴ� ��ѹ� y , x ^ y ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief n�� ��ȣ : NONNEGATIVE
* @brief n�� ���� : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void Mul_N_Squ_test(FILE* fp) {

	for (int i = 0; i <= TEST; i++) {

		bigint* x = NULL;
		bigint* z = NULL;

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		int n = ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND);
		Mul_N_Squ(x, &z, n);

		//bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		//int n = 5;
		//Mul_N_Squ_print(x, &z, n);

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("n=%d\n", n);
		printf("power(x,n) ==");
		bi_show_hex(z);
		printf("\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("n=", fp);
		fprintf(fp, "%d", n);
		fprintf(fp, "\n");
		fputs("print(power(x,n) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&z);
	}

}

/**
* @brief Mul_N_Squ_mod_bi_test : Montgomery ����� ��ѹ� �ŵ����� ��ⷯ ������ ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ����Ƚ���� �����ϴ� ��ѹ� y , ��ⷯ ������ �����ϴ� ��ѹ� p ,  x^y mod p ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief y�� ��ȣ : NONNEGATIVE
* @brief y�� ���� : LOWERBOUND ~ UPPERBOUND
* @brief p�� ��ȣ : NONNEGATIVE
* @brief p�� ���� : LOWERBOUND ~ UPPERBOUND
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void Mul_N_Squ_mod_bi_test(FILE* fp) {
	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL; // �ŵ����� �� ��
		bigint* y = NULL; // �ŵ����� Ƚ ��
		bigint* z = NULL; // ��� ���� �� ��
		bigint* p = NULL; // mod ���� �� ����(=��)

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, NONNEGATIVE, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&p, NONNEGATIVE, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));

		Mul_N_Squ_mod_bi(x, y, p, &z);


		printf("x=");
		bi_show_hex(x);
		printf("\n");	
		printf("y=");
		bi_show_hex(y);
		printf("\n");
		printf("p=");
		bi_show_hex(p);
		printf("\n");
		printf("power_mod(x,y,p) ==");
		bi_show_hex(z);
		printf("\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("p=", fp);
		File_print(p, fp);
		fprintf(fp, "\n");
		fputs("print(power_mod(x,y,p) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&p);
		bi_delete(&z);
	}

}

/**
* @brief Mod_test : ��ⷯ ������ ���꿡 ���Ǵ� ��ⷯ �Լ��� ���� ��Ȯ���� �׽�Ʈ �ϴ� �Լ�
* @brief ���� : ��ѹ� x , ��ⷯ ������ �����ϴ� ��ѹ� y ,  x mod y ���� ������ ��ѹ� z
* @brief x�� ��ȣ : NONNEGATIVE or NEGATIVE
* @brief x�� wordlen : LOWERBOUND ~ UPPERBOUND
* @brief y�� ��ȣ : NONNEGATIVE
* @brief y�� ���� : x�� wordlen / 2 
* @param FILE* fp : sage�� ��Ȯ���� �����ϱ� ���� ���� fp�� ��� ����Ʈ
*/
void Mod_test(FILE* fp) {
	for (int i = 0; i <= TEST; i++) {
		bigint* x = NULL; // �ŵ����� �� ��
		bigint* y = NULL; // �ŵ����� Ƚ ��
		bigint* z = NULL; // ��� ���� �� ��
		bigint* p = NULL; // mod ���� �� ����(=��)

		bi_gen_rand(&x, rand() % 2, ((rand() % (UPPERBOUND + 1 - LOWERBOUND)) + LOWERBOUND));
		bi_gen_rand(&y, NONNEGATIVE, (x->wordlen / 2));
		bi_modular(x, y, &z);

		printf("x=");
		bi_show_hex(x);
		printf("\n");
		printf("y=");
		bi_show_hex(y);
		printf("\n");
		printf("mod(x,y) ==");
		bi_show_hex(z);
		printf("\n");

		fputs("x=", fp);
		File_print(x, fp);
		fprintf(fp, "\n");
		fputs("y=", fp);
		File_print(y, fp);
		fprintf(fp, "\n");
		fputs("print(mod(x,y) ==", fp);
		File_print(z, fp);
		fputs(")", fp);
		fprintf(fp, "\n");

		bi_delete(&x);
		bi_delete(&y);
		bi_delete(&z);
	}
}