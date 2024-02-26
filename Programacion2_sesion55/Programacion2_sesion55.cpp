#include <iostream>
using namespace std;
class Rectangulo {
private:
	int ladox;
	int ladoy;
public:
	Rectangulo() :ladox(0), ladoy(0) {};
	Rectangulo(int x, int y) :ladox(x), ladoy(y) {};
	void mostrarLados()const;
	int getladox()const;
	int getladoy()const;
	void setladox(int newladox);
	void setladoy(int newladoy);
	int calcularArea()const;
	int calcularPerimetro()const;
	Rectangulo suma(const Rectangulo& r);
	Rectangulo operator +(const Rectangulo& r1);
	Rectangulo operator ++(int);	//operador postfijo
	Rectangulo operator ++();	//operador prefijo
	Rectangulo operator --();
	Rectangulo operator --(int);
	Rectangulo operator -(const Rectangulo& r1);
	void operator >(const Rectangulo& r1);
	void operator <(const Rectangulo& r1);
	void operator ==(const Rectangulo& r1);

};

Rectangulo operator -(const Rectangulo& r1, const Rectangulo& r2)
{
	Rectangulo R(r1.getladox() - r2.getladox(), r1.getladoy() - r2.getladoy());
	cout << "funcion general" << endl;
	return R;
}
Rectangulo operator +(const Rectangulo& r1, const Rectangulo& r2) {
	Rectangulo R(r1.getladox() + r2.getladox(), r1.getladoy() + r2.getladoy());
	cout << "funcion general" << endl;
	return R;
}
void operator <(const Rectangulo& r1, const Rectangulo& r2) {
	if (r1.getladox() > r2.getladox())
	{
		cout << "El lado X del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado X del primer rectangulo es menor" << endl;
	}
	if (r1.getladox() > r2.getladoy())
	{
		cout << "El lado Y del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado Y del primer rectangulo es menor" << endl;
	}
}
void operator >(const Rectangulo& r1, const Rectangulo& r2) {
	if (r1.getladox() > r2.getladox())
	{
		cout << "El lado X del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado X del primer rectangulo es menor" << endl;
	}
	if (r1.getladox() > r2.getladoy())
	{
		cout << "El lado Y del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado Y del primer rectangulo es menor" << endl;
	}
}
void operator ==(const Rectangulo& r1, const Rectangulo& r2) {
	if (r1.getladox() == r2.getladox() && r1.getladox() == r2.getladoy()) {
		cout << "Los rectangulos son iguales" << endl;
	}
	else {
		cout << "Los rectangulos son diferentes" << endl;
	}
}
//Rectangulo& operator--(Rectangulo& r) {
//	int lx{ r.getladox() }, ly{ r.getladoy() };
//	lx--;
//	ly--;
//	r.setladox(lx);
//	r.setladoy(ly);
//	return r;
//}
int main()
{
	Rectangulo R1(5, 7), R2(20, 2), Rsuma1, Rsuma2, Rsuma3, Rsuma4;
	cout << "Datos del rectangulo 1:\t ";
	R1.mostrarLados();
	cout << "Datos del rectangulo 2:\t";
	R2.mostrarLados();
	Rsuma1 = R1.suma(R2);
	cout << "Lados de la suma:\t ";
	Rsuma1.mostrarLados();
	cout << "Area: " << Rsuma1.calcularArea() << "\tPerimetro: " << Rsuma1.calcularPerimetro() << endl;
	Rsuma2 = R1 + R2;
	cout << "Lados de la suma con la funcion exterior: " << endl;
	Rsuma2.mostrarLados();
	cout << "Operacion --" << endl;
	--Rsuma2;   //probando operador sobrecargado.
	Rsuma2.mostrarLados();
	Rsuma2--;   //probando operador sobrecargado.
	Rsuma2.mostrarLados();

	cout << "Operador ++:" << endl;
	Rsuma2++;
	Rsuma2.mostrarLados();
	++Rsuma2;
	Rsuma2.mostrarLados();  //Probando operador de sobrecarga ++

	Rsuma3 = R1;
	Rsuma4 = Rsuma3;
	cout << "Operadores de comparacion" << endl;
	cout << "Rectangulo 3:\t";
	Rsuma3.mostrarLados();
	cout << "Rectangulo 2:\t";
	Rsuma2.mostrarLados();
	Rsuma3 < Rsuma2;
	Rsuma3 > Rsuma2;
	Rsuma3 == Rsuma2;

	cout << "Datos de Rsuma3 y Rsuma4\t";
	Rsuma3 == Rsuma4;

	cout << "Rectangulo 2 menos Rectangulo 3" << endl;
	Rsuma1 = Rsuma2 - Rsuma3;
	Rsuma1.mostrarLados();

	return 0;
}

void Rectangulo::mostrarLados() const
{
	cout << "lado x: " << ladox << "\tlado y: " << ladoy << endl;
}

int Rectangulo::getladox() const
{
	return ladox;
}

int Rectangulo::getladoy() const
{
	return ladoy;
}

void Rectangulo::setladox(int newladox)
{
	ladox = newladox;
}

void Rectangulo::setladoy(int newladoy)
{
	ladoy = newladoy;
}

int Rectangulo::calcularArea() const
{
	return ladox * ladoy;
}

int Rectangulo::calcularPerimetro() const
{
	return 2 * (ladox + ladoy);
}

Rectangulo Rectangulo::suma(const Rectangulo& r)
{
	return Rectangulo(ladox + r.getladox(), ladoy + r.getladoy());
}

Rectangulo Rectangulo::operator+(const Rectangulo& r1)
{
	Rectangulo R(ladox + r1.getladox(), ladoy + r1.getladoy());
	cout << "metodo de la clase" << endl;
	return R;
}

Rectangulo Rectangulo::operator++(int)
{
	ladox++; ladoy++;
	return *this;
}

Rectangulo Rectangulo::operator++()
{
	return Rectangulo(++ladox, ++ladoy);
}

Rectangulo Rectangulo::operator--()
{
	return Rectangulo(--ladox, --ladoy);
}

Rectangulo Rectangulo::operator--(int)
{
	ladox--; ladoy--;
	return *this;
}

Rectangulo Rectangulo::operator-(const Rectangulo& r1)
{
	Rectangulo R(ladox - r1.getladox(), ladoy - r1.getladoy());
	cout << "metodo de la clase" << endl;
	return R;
}

void Rectangulo::operator>(const Rectangulo& r1)
{
	if (ladox > r1.getladox())
	{
		cout << "El lado X del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado X del primer rectangulo es menor" << endl;
	}
	if (ladoy > r1.getladoy())
	{
		cout << "El lado Y del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado Y del primer rectangulo es menor" << endl;
	}
}

void Rectangulo::operator<(const Rectangulo& r1)
{
	if (ladox > r1.getladox())
	{
		cout << "El lado X del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado X del primer rectangulo es menor" << endl;
	}
	if (ladoy > r1.getladoy())
	{
		cout << "El lado Y del primer rectangulo es mayor" << endl;
	}
	else {
		cout << "El lado Y del primer rectangulo es menor" << endl;
	}
}

void Rectangulo::operator==(const Rectangulo& r1)
{
	if (ladox == r1.getladox() && ladoy == r1.getladoy()) {
		cout << "Los rectangulos son iguales" << endl;
	}
	else {
		cout << "Los rectangulos son diferentes" << endl;
	}
}
