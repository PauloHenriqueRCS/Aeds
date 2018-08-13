// AedsProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

#pragma region Aquecimento
void lucroInMercadorias(double price, int qnt, double min = 0, double max = 0)
{
	srand(time(NULL));
	double totalBuyPriceUnit = 0,
		totalSoldPrice = 0,
		totalTaxaUnit = 0,
		unitSoldPrice = 0,
		lucroTotal = 0,
		taxa = min + rand() * (max - min) / RAND_MAX;
	if (qnt != 0)
	{
		totalBuyPriceUnit = price * qnt;
		totalTaxaUnit = (totalBuyPriceUnit * taxa) / qnt;
		unitSoldPrice = price + totalTaxaUnit;
		totalSoldPrice = unitSoldPrice * qnt;
		lucroTotal = totalSoldPrice - totalBuyPriceUnit;
		cout << "Preco de compra por unidade: " << price << endl;
		cout << "Preco de venda por unidade: " << unitSoldPrice << endl;
		cout << "Valor total da compra: " << totalBuyPriceUnit << endl;
		cout << "Valor total da venda: " << unitSoldPrice * qnt << endl;
		cout << "Lucro total: " << lucroTotal << endl;
		cout << "Percentual total: " << ((lucroTotal * 100) / totalBuyPriceUnit) << "%\n\n" << endl;
	}
}
void Aquecimento() {
	// lucro < 10%
	lucroInMercadorias(10.00, 300, 0, 0.9);
	// 10% <= lucro <= 20%.
	lucroInMercadorias(10.00, 300, 1, 2);
	// lucro > 20%.
	lucroInMercadorias(10.00, 300, 2.1, 3);
}
#pragma endregion
#pragma region Lista 1
#pragma region 1
double ReturnMidVetor(double vector[]) {
	double count = 0;
	for (size_t i = 0; i < 10; i++)
		count += vector[i];
	return (count / 10);
}
void MidVector() {
	double vector[10];
	for (size_t i = 0; i < 10; i++)
		vector[i] = ((0 + rand() * (10.0 - 1.0) / RAND_MAX));
	cout << ReturnMidVetor(vector) << endl;
}
#pragma endregion

#pragma region 2
int MDC(int value1, int value2) {
	int resto = value1 % value2;
	while (resto != 0)
	{
		value1 = value2;
		value2 = resto;
		resto = value1 % value2;
	}
	return value2;
}
void ReturnMdc() {
	int value1 = 2,
		value2 = 20;
	int mdc = MDC(value1, value2);
	cout << "MDC de " << value1 << " e " << value2 << " igual a " << mdc << endl;
}

#pragma endregion

#pragma region 3
bool MatchCharactere(string str) {
	return str.find('x');
}
void ReturnMatch() {
	if (MatchCharactere("xdcdge") == 0)
		cout << "Encontrado";
	else
		cout << "Nao encontrado";
}
#pragma endregion

#pragma region 4
int MDCRec(int value1, int value2) {
	if (value1 % value2 == 0)
		return value2;
	else
		return MDCRec(value2, value1 % value2);
}

void ReturnMdcRec() {
	int value1 = 2,
		value2 = 20;
	int mdc = MDCRec(value1, value2);
	cout << "MDC de " << value1 << " e " << value2 << " igual a " << mdc << endl;
}
#pragma endregion

#pragma region 5 e 6
double MinValueInVector(vector<double> v) {
	double min = v.at(0);
	for (double i : v){
		if (i < min)
			min = i;
	}
	return min;
}

double MinValueInVectorRec(vector<double> v, double min, int pos) {
	if (v.at(pos) < min)
		min = v.at(pos);
	if ((pos + 1) >= v.size())
		return min;
	else
		return MinValueInVectorRec(v, min, pos + 1);
}
void ReturnMinValue() {
	vector<double> v;
	for (size_t i = 0; i < 10; i++)
		v.push_back(((0 + rand() * (10.0 - 1.0) / RAND_MAX)));
	double min = v[0];

	cout << "Menor valor: " << MinValueInVector(v) << endl;
	cout << "Menor valor: " << MinValueInVectorRec(v, min, 1) << endl;
}

inline double* MinValueInVectorRecP(vector<double> *v, double *min, int pos) {
	if (v->at(pos) < *min)
		*min = v->at(pos);
	if ((pos + 1) >= v->size())
		return min;
	else
		return MinValueInVectorRecP(v, min, pos + 1);
}
void ReturnMinValueP() {
	vector<double> v;
	for (size_t i = 0; i < 10; i++)
		v.push_back(((0 + rand() * (10.0 - 1.0) / RAND_MAX)));
	double min = v[0];

	cout << "Menor valor: " << *MinValueInVectorRecP(&v, &min, 1) << endl;
}
#pragma endregion

#pragma endregion
#pragma region Lista 2
/*
1. Um ponteiro é:
a) O endereço de uma variável;
> b) Uma variável que armazena endereços;
c) O valor de uma variável;
d) Um indicador da próxima variável a ser acessada.

2. Escreva uma instrução em C++ que imprima o endereço da variável var do tipo int.
int var;
cout << &var;

3. Indique: (1) operador de endereços (2) operador de referência.
(1) a) p = &i;
(2) b) int &i = j;
(1) c) cout << &i;
(2) d) int *p = &i;
(1) e) int& func(void);
(2) f) void func(int &i);
(2) g) func (&i);

4. A instrução:
int *p;
a) cria um ponteiro com valor indefinido;
> b) cria um ponteiro do tipo int;
c) cria um ponteiro com valor zero;
d) cria um ponteiro que aponta para uma variável do tipo int.

5. O que é do tipo int na instrução a seguir?
int *p;
> a) A variável p;
b) O endereço de p;
c) A variável apontada por p;
d) O endereço da variável apontada por p.


6. Se o endereço de var foi atribuído a um ponteiro variável pvar, quais das seguintes
expressões são verdadeiras?
a) var == &pvar;
> b) var == *pvar;
c) pvar == *var;
> d) pvar == &var.

7. Qual é a saída deste programa?
 1-> endereço de var
 2-> valor apontado por p mais 2
 3-> valor apontado por p
 4-> 3 vezes o valor apontado por p
 5-> valor apontado por p mais 4
*/
#pragma endregion


int main()
{
	int vetor[10];

	for (size_t i = 0; i < 10; i++)
	{
		*(vetor + 1) = ((0 + rand() * (10 - 1) / RAND_MAX));
		cout << *vetor << " " << endl;
	}

	system("pause");
	return 0;
}
