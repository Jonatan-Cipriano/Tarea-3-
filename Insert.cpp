#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;
int main(){
	//inicio del update
	int id;
	cout << "Ingrese el id que desea modificar" << endl;
	cin >> id;
	string proveedor, nit, direccion, telefono;

	cout << "Ingrese nombre del proveedor" << endl;
	cin >> proveedor;
	cout << "Ingrese nombre del nit" << endl;
	cin >> nit;
	cout << "Ingrese nombre del direccion" << endl;
	cin >> direccion;
	cout << "Ingrese nombre del telefono" << endl;
	cin >> telefono;

	string insert = "INSERT INTO bd_proveedor.proveedores(id_proveedor,proveedor, nit, direccion, telefono) VALUES('" + id + "','" + proveedor + "', '" + nit + "','" + direccion + "', " + telefono + ");
	const char* i = insert.c_str();

	q_estado = mysql_query(conectar, i);
	if (!q_estado) {
		cout << "Ingreso exitoso" << endl;
	}
	else {
		cout << "error al ingresar " << endl;
}

	//fin del update------------