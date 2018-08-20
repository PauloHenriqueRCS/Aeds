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
	for (double i : v) {
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
#pragma region Lista 3
/*
1. Qual a diferença entre: mat[3] e *(mat + 3)?
Nenhuma, apenas anotação para imprimir a mesma saida, o valor do vetor na posição 3

2. Admitindo a declaração: int mat[8]; quais das seguintes expressões se referem ao
valor do terceiro elemento da matriz?
a) *(mat + 2);
> b) *(mat + 3);
c) mat + 2;
d) mat + 3.

3. imprime os valores das posições 0, 1, 2 do vetor de 3 posições com uma notação deponteiro

4. imprime os endereços de memória das posições 0, 1, 2 do vetor de 3 posições com uma notação deponteiro

5. imprime os valores das posições 0, 1, 2 do vetor de 3 posições com uma ponteiro

6.
a) imprime todos os caracteres
b) imprime todos os caracteres
c) imprime todos os caracteres a partir da posiçção 11
d) imprime o caractere da posicao 0

7. Escreva a expressão mat[i][j] em notação ponteiro.
m[ i * NC j]

8. Qual a diferença entre os seguintes protótipos de funções:
void func(char *p);
funcção que recebe um ponteiro do tipo char

void func(char p[]);
função que recebe um vetor de tipo char

9. Considerando a declaração:
char *items[5] = { "Abrir",
"Fechar",
"Salvar",
"Imprimir",
"Sair"
};
Para poder escrever a instrução p=items; a variável p deve ser declarada como:
a) char p;
b) char *p;
> c) char **p;
d) char ***p;
e) char *p[];
f) char **p[][];

10. O operador new:
a) Cria uma variável de nome new;
b) Retorna um ponteiro void;
> c) Aloca memória para uma nova variável;
d) Informa a quantidade de memória livre.

11. O operador delete:
a) Apaga um programa;
> b) Devolve memória ao sistema operacional;
c) Diminui o tamanho do programa;
d) Cria métodos de otimização.
*/



#pragma endregion
#pragma region Lista 4
/*
1. c)
2. c)
3. verdadeiro
4. d)
*/
// 5
// a)
struct Corpo {
	float altura;
	float peso;
}joao;
// b)
float getAltura() {
	joao.altura = 1.68;
	return joao.altura;
}
// c)
struct Casal {
	Corpo Maria;
	Corpo Jose;
};
// d)
Casal casal[10];
// e)
void initCasal() {
	casal[0].Maria.altura = 1.63;
	casal[0].Maria.peso = 59.5;
	casal[0].Jose.altura = 1.78;
	casal[0].Jose.peso = 82.6;
}
// 6. a) b)
// 7. verdadeiro
// 8. 
struct Tempo {
	int hora;
	int minuto;
	int segundo;
};
// 9. 
struct Estacionamento {
	int placa;
	int marca;
	Tempo entrada;
	Tempo saida;
};
// 10. c)

#pragma endregion
#pragma region Lista V
struct Pessoa {
	int Codigo;
	float CalcBase;
	string Nome;

	void Print() {
		cout << Codigo << ' ' << CalcBase << ' ' << Nome << endl;
	}
};

void GetLineStream(string line, Pessoa *pessoa) {
	stringstream ss(line);
	getline(ss, line, ',');
	pessoa->Codigo = atoi(line.c_str());
	getline(ss, line, ',');
	pessoa->CalcBase = atof(line.c_str());
	getline(ss, line, ',');
	pessoa->Nome = line;
}

void Print(Pessoa *pessoas) {
	for (size_t i = 0; i < sizeof(pessoas) - 1; i++)
		pessoas[i].Print();
}

void ReadPessoas(string path) {
	Pessoa* pessoas;
	string line;
	int size, count = 0;
	ifstream stream(path, ios::in);

	try
	{
		if (stream.is_open()) {
			getline(stream, line);
			size = atoi(line.c_str());
			pessoas = new Pessoa[size];
			while (getline(stream, line))
			{
				GetLineStream(line, &pessoas[count]);
				count++;
			}
			Print(pessoas);
		}
		stream.close();
	}
	catch (exception& e)
	{
		cout << "failed to open " << e.what() << endl;
		stream.close();
	}
}

#pragma endregion


int main()
{
	ReadPessoas("file.txt");
	//system("pause");
	return 0;
}
