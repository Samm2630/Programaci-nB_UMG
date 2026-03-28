#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Alumno {
    int id;
    char nombre[50];
    float promedio;

};

// =========================
// CREAR ARCHIVO DE TEXTO
// =========================

void agregarAlumnoText(){
    ofstream archivo("alumnos.txt", ios::app);
    if (archivo.is_open()) {
        Alumno alumno;
        cout << "Ingrese el ID del alumno: ";
        cin >> alumno.id;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore(); // Limpiar buffer
        cin.getline(alumno.nombre, 50);
        cout << "Ingrese el promedio del alumno: ";
        cin >> alumno.promedio;

        archivo << alumno.id << "," << alumno.nombre << "," << alumno.promedio << endl;
        archivo.close();
        cout << "Alumno agregado al archivo de texto." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// =======================
// LISTAR ARCHIVO TEXTO
// =======================

void listarAlumnosText(){
    ifstream archivo("alumnos.txt");
    if (archivo.is_open()) {
        string linea;
        cout << "ID\tNombre\tPromedio" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// ===============
// BUSCAR POR ID
// ===============

void buscarAlumnoText(){
    ifstream archivo("alumnos.txt");
    if (archivo.is_open()) {
        int idBuscado;
        cout << "Ingrese el ID del alumno a buscar: ";
        cin >> idBuscado;
        string linea;
        bool encontrado = false;
        while (getline(archivo, linea)) {
            int id;
            char nombre[50];
            float promedio;
            sscanf(linea.c_str(), "%d,%49[^,],%f", &id, nombre, &promedio);
            if (id == idBuscado) {
                cout << "Alumno encontrado: ID: " << id << ", Nombre: " << nombre << ", Promedio: " << promedio << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Alumno no encontrado." << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// ============================
// ACTUALIZAR USANDO TEMPORAL
// ============================

void actualizarNotaText(){
    ifstream archivo("alumnos.txt");
    if (archivo.is_open()) {
        int idBuscado;
        cout << "Ingrese el ID del alumno para actualizar su nota: ";
        cin >> idBuscado;
        string linea;
        bool encontrado = false;
        ofstream tempArchivo("temp.txt");
        while (getline(archivo, linea)) {
            int id;
            char nombre[50];
            float promedio;
            sscanf(linea.c_str(), "%d,%49[^,],%f", &id, nombre, &promedio);
            if (id == idBuscado) {
                cout << "Alumno encontrado: ID: " << id << ", Nombre: " << nombre << ", Promedio: " << promedio << endl;
                cout << "Ingrese el nuevo promedio: ";
                cin >> promedio;
                tempArchivo << id << "," << nombre << "," << promedio << endl;
                encontrado = true;
            } else {
                tempArchivo << linea << endl;
            }
        }
        tempArchivo.close();
        archivo.close();
        remove("alumnos.txt");
        rename("temp.txt", "alumnos.txt");
        if (!encontrado) {
            cout << "Alumno no encontrado." << endl;
        } else {
            cout << "Promedio actualizado." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// =======================
// CREAR ARCHIVO BINARIO
// =======================

void agregarAlumnoBinario(){
    ofstream archivo("alumnos.bin", ios::app | ios::binary);
    if (archivo.is_open()) {
        Alumno alumno;
        cout << "Ingrese el ID del alumno: ";
        cin >> alumno.id;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore(); // Limpiar buffer
        cin.getline(alumno.nombre, 50);
        cout << "Ingrese el promedio del alumno: ";
        cin >> alumno.promedio;

        archivo.write((char*)&alumno, sizeof(Alumno));
        archivo.close();
        cout << "Alumno agregado al archivo binario." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// ==========================
// LEER REGISTRO ESPECÍFICO
// ==========================

void leerRegistroBinario(){
    ifstream archivo("alumnos.bin", ios::binary);
    if (archivo.is_open()) {
        int idBuscado;
        cout << "Ingrese el ID del alumno a buscar: ";
        cin >> idBuscado;
        Alumno alumno;
        bool encontrado = false;
        while (archivo.read((char*)&alumno, sizeof(Alumno))) {
            if (alumno.id == idBuscado) {
                cout << "Alumno encontrado: ID: " << alumno.id << ", Nombre: " << alumno.nombre << ", Promedio: " << alumno.promedio << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Alumno no encontrado." << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// ===============================
// RECORRER EL ARCHIVO BINARIO
// ===============================

void listarAlumnosBinario(){
    ifstream archivo("alumnos.bin", ios::binary);
    if (archivo.is_open()) {
        Alumno alumno;
        cout << "ID\tNombre\tPromedio" << endl;
        while (archivo.read((char*)&alumno, sizeof(Alumno))) {
            cout << alumno.id << "\t" << alumno.nombre << "\t" << alumno.promedio << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// ================
// MENÚ PRINCIPAL
// ================

int main() {
    int opcion;
    do {
        cout << "1. Agregar alumno (Texto)" << endl;
        cout << "2. Listar alumnos (Texto)" << endl;
        cout << "3. Buscar alumno por ID (Texto)" << endl;
        cout << "4. Actualizar nota (Texto)" << endl;
        cout << "5. Agregar alumno (Binario)" << endl;
        cout << "6. Listar alumnos (Binario)" << endl;
        cout << "7. Buscar alumno por ID (Binario)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarAlumnoText();
                break;
            case 2:
                listarAlumnosText();
                break;
            case 3:
                buscarAlumnoText();
                break;
            case 4:
                actualizarNotaText();
                break;
            case 5:
                agregarAlumnoBinario();
                break;
            case 6:
                listarAlumnosBinario();
                break;
            case 7:
                leerRegistroBinario();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
