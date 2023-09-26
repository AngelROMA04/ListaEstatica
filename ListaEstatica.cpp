/*
LISTAS ESTATICAS
ANGEL GABRIEL RODRIGUEZ MARTINEZ
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int TAM = 10;

class Empleado {
public:
    std::string clave;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string reportaA;

    Empleado(string nom, string clv, string dom, float sue, string gfe) {
        nombre = nom;
        clave = clv;
        domicilio = dom;
        sueldo = sue;
        reportaA = gfe;
    }

    Empleado(){}

    friend std::ostream& operator<<(std::ostream& o, Empleado& wrk) {
        o << "\t\nClave de empleado: " << wrk.clave << "\t\nNombre: " << wrk.nombre << "\t\nDomicilio: " << wrk.domicilio << "\t\nSueldo: $" << wrk.sueldo << "\t\nSe reporta con: " << wrk.reportaA <<"\n"<< std::endl;
        return o;
    }

    bool operator ==(Empleado& emp) {
        return ((clave == emp.clave) && (nombre == emp.nombre) && (domicilio == emp.domicilio) && (sueldo == emp.sueldo) && (reportaA == emp.reportaA));
    }

    bool operator !=(Empleado& emp) {
        return ((clave != emp.clave) && (nombre != emp.nombre) && (domicilio != emp.domicilio) && (sueldo != emp.sueldo) && (reportaA == emp.reportaA));
    }

    Empleado operator+(const Empleado& sum) const {
        Empleado resultado(nombre + sum.nombre, clave + sum.clave, domicilio + sum.domicilio, sueldo + sum.sueldo, reportaA + sum.reportaA);
        return resultado;
    }

    bool operator<(const Empleado& menq) const {
        return sueldo < menq.sueldo;
    }

    bool operator>(const Empleado& mayq) const {
        return sueldo > mayq.sueldo;
    }
};

class Lista {
private:
    Empleado datos[TAM];
    int last;
public:
    Lista() :last(-1) {}
    bool vacia()const {
        if (last == -1)
            return true;
        return false;
    }
    bool llena()const {
        if (last == TAM - 1)
            return true;
        return false;
    }
    int inserta(Empleado elem, int pos) {
        int i = last + 1;
        while (i > pos) {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        last++;
        return 1;
    }

    bool elimina(int pos) {
        int i = pos;
        while (i < last) {
            datos[i] = datos[i + 1];
            i++;
        }
        last--;
        return false;
    }

    int ultimo()const {
        return last;
    }

    int buscar(Empleado elem){
        int i = 0;
        while (i <= last) {
            if (elem == datos[i]) 
                return i;
            i++;
        }
        return -1;
    }

    friend std::ostream &operator <<(std::ostream &out, Lista &L) {
        int i = 0;
        std::cout << "\n";
        while (i <= L.ultimo()) {
            out << L.datos[i];
            i++;
        }
        return out;
    };
};


int main()
{
    Lista lista1;
    Empleado x;
    int opc=-1,pos=-2,nEmps=0;

    while (1) {
        system("cls");
    std::cout << "\t\tLISTA ESTATICA DE EMPLEADOS\n\tEscoge una de las siguientes opciones:\n1. Agregar Empleado\n2. Buscar Empleado\n3. Eliminar Empleado\n4. Insertar Empleado en posicion especifica\n5. Mostrar Empleados\n6. SALIR";
    std::cout << "\n\tIngresa tu opcion: ";std::cin >> opc;cin.ignore();

        switch (opc) {
        case 1:system("cls");
            if (lista1.llena()) {
                std::cout << "ERROR DE INSERCION: La lista esta llena\n";system("PAUSE");break;
            }
            else {
            std::cout << "\tAGREGAR EMPLEADO:\nIngresa la clave del empleado: ";getline(cin, x.clave);
            std::cout << "Ingresa el nombre del empleado: ";getline(cin, x.nombre);
            std::cout << "Ingresa el domicilio del empleado: ";getline(cin,x.domicilio);
            std::cout << "Ingresa el sueldo del empleado: ";std::cin >> x.sueldo;cin.ignore();
            std::cout << "Ingresa a quien se reporta el empleado: ";getline(cin,x.reportaA);
                lista1.inserta(x, nEmps);nEmps++;
            }
            cout << "Empleado registrado con exito" << endl;
            system("PAUSE");
            break;

        case 2:system("cls");
            if (lista1.vacia()) {
                std::cout << "ERROR DE BUSQUEDA: La lista esta vacia\n";system("PAUSE");break;
            }
            else {
            std::cout << "\tBUSCAR EMPLEADO:\nIngresa la clave del empleado: ";getline(cin, x.clave);
            std::cout << "Ingresa el nombre del empleado: ";getline(cin, x.nombre);
            std::cout << "Ingresa el domicilio del empleado: ";getline(cin, x.domicilio);
            std::cout << "Ingresa el sueldo del empleado: ";std::cin >> x.sueldo;cin.ignore();
            std::cout << "Ingresa a quien se reporta el empleado: ";getline(cin, x.reportaA);
            
                pos=lista1.buscar(x);
                if (pos == -1) {
                    cout << "ERROR DE BUSQUEDA: El empleado no fue encontrado\n";system("PAUSE");break;
                }
                cout << "El empleado se encuentra en la posicion: " << pos+1 <<" de la lista" <<endl;
            }
            system("PAUSE");
            break;

        case 3:system("cls");
            if (lista1.vacia()) {
                std::cout << "ERROR DE BUSQUEDA: La lista esta vacia\n";system("PAUSE");break;
            }
            else {
            std::cout << "\tELIMINAR EMPLEADO:\nIngresa la clave del empleado: ";getline(cin, x.clave);
            std::cout << "Ingresa el nombre del empleado: ";getline(cin, x.nombre);
            std::cout << "Ingresa el domicilio del empleado: ";getline(cin, x.domicilio);
            std::cout << "Ingresa el sueldo del empleado: ";std::cin >> x.sueldo;cin.ignore();
            std::cout << "Ingresa a quien se reporta el empleado: ";getline(cin, x.reportaA);
                pos = lista1.buscar(x);
                if (pos == -1) {
                    cout << "ERROR DE ELIMINACION: El empleado no fue encontrado\n";system("PAUSE");break;
                }
                lista1.elimina(pos);cout << "Eliminacion exitosa"<<endl;
            }
            system("PAUSE");
            break;

        case 4:system("cls");
            if (lista1.llena()) {
                std::cout << "ERROR DE INSERCION: La lista esta llena\n";system("PAUSE");break;
            }
            std::cout << "\tAGREGAR EMPLEADO EN POSICION:\nIngresa la clave del empleado: ";getline(cin, x.clave);
            std::cout << "Ingresa el nombre del empleado: ";getline(cin, x.nombre);
            std::cout << "Ingresa el domicilio del empleado: ";getline(cin, x.domicilio);
            std::cout << "Ingresa el sueldo del empleado: ";std::cin >> x.sueldo;cin.ignore();
            std::cout << "Ingresa a quien se reporta el empleado: ";getline(cin, x.reportaA);
            std::cout << "\nIngresa la posicion de la lista para ingresar al empleado: ";std::cin >> pos;
            
            if(pos>nEmps+1) {
                std::cout << "ERROR DE INSERCION: La posicion es invalida\n";system("PAUSE");break;
            }
            else {
                lista1.inserta(x, pos-1);nEmps++;
            }
            cout << "Empleado registrado con exito" << endl;
            system("PAUSE");
            break;

        case 5:system("cls");
            std::cout << lista1;
            system("pause");
            break;

        case 6:exit(0);break;

        default: std::cout << "Ingresa una opcion valida";system("PAUSE");
        }
    }
    return 0;
}