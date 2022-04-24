// bd_proveedoresconectar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <string.h>
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "127.0.0.1", "user_proveedor", "proveedor123", "bd_proveedor", 3306, NULL, 0);
	if (conectar) {
		

		//cout << "Conexion exitosa" << endl;	
		
		//inicio del insert------------------------------------------
		string proveedor, nit, direccion, telefono;

		cout << "Ingrese nombre del proveedor" << endl;
		cin >> proveedor;
		cout << "Ingrese nombre del nit" << endl;
		cin >> nit;
		cout << "Ingrese nombre del direccion" << endl;
		cin >> direccion;
		cout << "Ingrese nombre del telefono" << endl;
		cin >> telefono;

		string insert = "INSERT INTO bd_proveedor.proveedores(proveedor, nit, direccion, telefono) VALUES('" + proveedor + "', '" + nit + "','" + direccion + "', " + telefono + ");";
		const char* i = insert.c_str();

		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso exitoso" << endl;
		}
		else {
			cout << "error al ingresar " << endl;
		}
		//fin del insert-----------------------------------


		//inicio del select------------------------------------
		string consulta = "select * from proveedores";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " | " << fila[1] <<" | "<<fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << endl;
			}
		}
		else {
			cout << "error al consultar " << endl;
		}
	}
	else {
		cout << "Error en la conexion" << endl;
	} 
	//Fin de select-------------------------------------------
	
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
	string id = to_string(id)
	string actualizar = "UPDATE programacion.proveedores SET proveedor = '" + proveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = " + telefono + " WHERE id_proveedores = " + id + "";
	const char* i = insert.c_str();

	q_estado = mysql_query(conectar, i);
	if (!q_estado) {
		cout << "Ingreso exitoso" << endl;
	}
	else {
		cout << "error al ingresar " << endl;

	//fin del update

	system("pause");

	//inicio del delete------------------------------


	//fin del delete------------------------------


	return 0;
}


