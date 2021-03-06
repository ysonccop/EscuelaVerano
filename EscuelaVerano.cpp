#include "EscuelaVerano.h"
#include "Persona.h"
#include "Reserva.h"
#include "Alumno.h"
#include "Administrador.h"
#include "Profesor.h"
#include "Curso.h"
#include <iostream>
using namespace std;

void EscuelaVerano::crearCurso(string name, double price, bool cancel, string dni){
    int indP, n;
    Profesor *objP;
    indP = buscarProfesor(dni);

    objP = (Profesor*) listaPersonas[indP];
    listaCursos.push_back(new Curso(name, price, cancel, objP));
    n = listaCursos.size();
    objP->aniadirCurso(listaCursos[n-1]);
}

void EscuelaVerano::agregarAlumno(string dni, string names, string type, int tD){
    listaPersonas.push_back(new Alumno(dni, names, type, tD));
}

void EscuelaVerano::agregarAdministrador(string dni, string names, string type){
    listaPersonas.push_back(new Administrador(dni, names, type));
}

void EscuelaVerano::agregarProfesor(string dni, string names, string type){
    listaPersonas.push_back(new Profesor(dni, names, type));
}

void EscuelaVerano::mostrarCursos(){
    for(int i=0; i<listaCursos.size(); i++){
        listaCursos[i]->mostrarDatos();
    }
}

void EscuelaVerano::mostrarPersonas(){
    for(int i=0; i<listaPersonas.size(); i++){
        listaPersonas[i]->mostrarDatos();
    }
}

bool EscuelaVerano::crearReserva(string fecha, string dni, string nombreC){
    Reserva *reserva;
    Alumno *objA;
    int indA, indC;
    indA = buscarAlumno(dni);
    indC = buscarCurso(nombreC);

    if(indA == -1 || indC == -1)
        return false;

    objA = (Alumno*) listaPersonas[indA];
    reserva = new Reserva(fecha, objA , listaCursos[indC]);
    listaCursos[indC]->aniadirReserva(reserva);
    objA->aniadirReserva(reserva);
    return true;
}

int EscuelaVerano::buscarAlumno(string dni){
    for(int i = 0; i < listaPersonas.size(); i++){
        if(listaPersonas[i]->getDNI() == dni)
            return i;
    }
    return -1;
}
int EscuelaVerano::buscarCurso(string nombreC){
    for(int i = 0; i < listaCursos.size(); i++){
        if(listaCursos[i]->getNombre() == nombreC)
            return i;
    }
    return -1;
}

int EscuelaVerano::buscarProfesor(string dni){
    for(int i = 0; i < listaPersonas.size(); i++){
        if(listaPersonas[i]->getDNI() == dni)
            return i;
    }
    return -1;
}

vector<string*> EscuelaVerano::listarCursosAdministrador(string dni){
    vector<string*> listaCursosxAdm;
    string datosCompletos[5];
    for(int i = 0; i < listaCursos.size(); i++){
        if(listaCursos[i]->ofertadoPorAdministrador(dni) == true){
            aniadirListaCursosxAdm(listaCursos[i]->obtenerDatosCompletos(), listaCursosxAdm);
        }
    }
    return listaCursosxAdm;
}

void EscuelaVerano::aniadirListaCursosxAdm(string* datosCompletos, vector<string*> &listaCursosxAdm){
    listaCursosxAdm.push_back(datosCompletos);
}
