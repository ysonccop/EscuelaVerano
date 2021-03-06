#include <iostream>
#include <string>
#include "Persona.h"
#include "Alumno.h"
#include "Curso.h"
#include "Reserva.h"
#include "EscuelaVerano.h"

using namespace std;

int main(){
    bool exito;
    EscuelaVerano escV;

    string dni, names;

    cout<<"Ingrese DNI: "; cin>>dni;
    cin.ignore();
    cout<<"Ingrese nombres: "; getline(cin,names);
    escV.agregarAlumno(dni,names,"Alumno",1);
    escV.agregarAlumno("92837412","Christian Tarqui","Alumno",1);
    escV.agregarAlumno("08946195","Carlos Condori","Alumno",1);

    escV.agregarProfesor("08946194","German Malaga","Profesor");

    escV.crearCurso("Disenio grafico",200,false,"08946194");
    escV.crearCurso("Programacion de sitios web",100,false,"08946194");
    escV.crearCurso("Audio y video",150,false,"08946194");

    cout<<"LISTA DE PERSONAS ---------------------------"<<endl;
    escV.mostrarPersonas();
    cin.get();
    cout<<"LISTA DE CURSOS -----------------------------"<<endl;
    escV.mostrarCursos();
    cin.get();

    //cout<<"Posicion: "<<escV.buscarCurso("Programacion de sitios web");

    //Creacion de la reserva:
    cout<<"PROCESO DE RESERVA -----------------------------"<<endl;
    cout<<"01: Daniel Chique reservara el curso Disenio grafico"<<endl;
    cout<<"02: Carlos Condori reservara el curso Disenio grafico"<<endl<<endl;
    exito = escV.crearReserva("13/02/2021","87675645","Disenio grafico");
    if (exito == true)
        cout<<"Se creo correctamente la reserva 01"<<endl;
    else
        cout<<"Error en la busqueda del DNI o del nombre del curso"<<endl;

    exito = escV.crearReserva("13/02/2021","08946195","Disenio grafico");
    if (exito == true)
        cout<<"Se creo correctamente la reserva 02"<<endl;
    else
        cout<<"Error en la busqueda del DNI o del nombre del curso"<<endl;
    cin.get();

    cout<<"LISTA DE CURSOS CON RESERVAS ----------------"<<endl;
    escV.mostrarCursos();

    return 0;
}
