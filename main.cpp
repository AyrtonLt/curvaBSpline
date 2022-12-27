#include <GL/glut.h>
#include <iostream>

void display();
void init();

void GoMenu(int value);
void crearMenu();

void ingresarPuntoControl();
void mostrarPuntoControl();
void mostrarPolilinea();
void moverPuntoControl();
void mostrarEjesCoordenados();

bool varMostrarPuntoControl = false;
bool varMostrarPolilinea = false;
bool varMostrarCurvaBSpline = false;
bool varMostrarMoverPuntoControl = false;
bool varMostrarEjesCoordenados = false;
int menu, subm1, subm2, subm3, subm4, subm5;

int cantidadPuntoControl;
int puntoControl[20][2];

using namespace std;

int main(int argc, char * args[]) {
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800,600);
    glutCreateWindow("Untitled2");
    init();
    crearMenu();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if(varMostrarPuntoControl == true) {
        mostrarPuntoControl();
    }
    if(varMostrarPolilinea == true) {
        mostrarPolilinea();
    }
    if(varMostrarCurvaBSpline == true) {

    }
    if(varMostrarMoverPuntoControl == true) {
        mostrarPuntoControl();
        mostrarPolilinea();
    }
    if(varMostrarEjesCoordenados == true) {
        mostrarEjesCoordenados();
    }
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glPointSize(15);
    glOrtho(-400.f, 400.f, -300.f, 300.f, -1.f, 1.f);
}

void GoMenu(int value) {
    switch (value) {
        case 1:
            ingresarPuntoControl();
            varMostrarPuntoControl = !varMostrarPuntoControl; break;
        case 2:
            varMostrarPuntoControl = !varMostrarPuntoControl; break;
        case 3:
            varMostrarPolilinea = !varMostrarPolilinea; break;
        case 4:
            varMostrarPolilinea = !varMostrarPolilinea; break;
        case 5:
            varMostrarCurvaBSpline = !varMostrarCurvaBSpline; break;
        case 6:
            varMostrarCurvaBSpline = !varMostrarCurvaBSpline; break;
        case 7:
            moverPuntoControl();
            varMostrarMoverPuntoControl = !varMostrarMoverPuntoControl; break;
        case 8:
            varMostrarMoverPuntoControl = !varMostrarMoverPuntoControl; break;
        case 9:
            varMostrarEjesCoordenados = !varMostrarEjesCoordenados; break;
        case 10:
            varMostrarEjesCoordenados = !varMostrarEjesCoordenados; break;
        case 11:
            exit(0);
        default:
            cout<<"Ha habido un problema al seleccionar la funcion, reinicie el programa.";
    }
    glutPostRedisplay();
}

void crearMenu() {
    subm1 = glutCreateMenu(GoMenu);
    glutAddMenuEntry("Activado", 1);
    glutAddMenuEntry("Desactivado", 2);

    subm2 = glutCreateMenu(GoMenu);
    glutAddMenuEntry("Activado", 3);
    glutAddMenuEntry("Desactivado", 4);

    subm3 = glutCreateMenu(GoMenu);
    glutAddMenuEntry("Activado", 5);
    glutAddMenuEntry("Desactivado", 6);

    subm4 = glutCreateMenu(GoMenu);
    glutAddMenuEntry("Activado", 7);
    glutAddMenuEntry("Desactivado", 8);

    subm5 = glutCreateMenu(GoMenu);
    glutAddMenuEntry("Activado", 9);
    glutAddMenuEntry("Desactivado", 10);

    menu = glutCreateMenu(GoMenu);
    glutAddSubMenu("Ingresar puntos de control", subm1);
    glutAddSubMenu("Mostrar polilinea", subm2);
    glutAddSubMenu("Mostrar Curva B-Spline", subm3);
    glutAddSubMenu("Mover puntos de control", subm4);
    glutAddSubMenu("Mostrar Ejes coordenados", subm5);
    glutAddMenuEntry("Salir de la aplicacion", 11);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void ingresarPuntoControl() {
    int x, y;
    do{
        cout<<"Ingrese la cantidad de puntos de control que desea agregar\n";
        cin>>cantidadPuntoControl;
    } while(cantidadPuntoControl < 3 && cantidadPuntoControl > 20);
    for (int i = 0; i < cantidadPuntoControl; i++) {
        cout<<"Ingrese la coordenada X del punto N"<<i+1<<"\n";
        cin>>x;
        cout<<"Ingrese la coordenada Y del punto N"<<i+1<<"\n";
        cin>>y;
        puntoControl[i][0]=x;
        puntoControl[i][1]=y;
    }
}

void mostrarPuntoControl() {
    int x, y;
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5.f);
    glBegin(GL_POINTS);
    for (int i = 0; i < cantidadPuntoControl; i++) {
        x = puntoControl[i][0];
        y = puntoControl[i][1];
        glVertex2i(x, y);
    }
    glEnd();
}

void mostrarPolilinea() {
    int x, y;
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < cantidadPuntoControl; i++) {
        x = puntoControl[i][0];
        y = puntoControl[i][1];
        glVertex2i(x, y);
    }
    glEnd();
}

void moverPuntoControl() {
    int indice, x, y;
    cout<<"A continuacion se mostraran todos los puntos de control y sus coordenadas respectivas\n";
    for (int i = 0; i < cantidadPuntoControl; i++) {
        cout<<"Punto N"<<i<<": ["<<puntoControl[i][0]<<"]["<<puntoControl[i][1]<<"]\n";
    }
    do{
        cout<<"Escriba el punto que desea mover\n";
        cin>>indice;
    } while(indice < 0 && indice > cantidadPuntoControl);
    cout<<"Ingrese la nueva coordenada X del punto:\n";
    cin>>x;
    cout<<"Ingrese la nueva coordenada Y del punto:\n";
    cin>>y;
    puntoControl[indice][0] = x;
    puntoControl[indice][1] = y;
    cout<<"Para visualizar los cambios, haga clic en la opcion DESACTIVADO del submenu";
}

void mostrarEjesCoordenados() {
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (int i = -400; i < 400; i++) {
        glVertex2i(i, 0);
    }
    glEnd();
    glBegin(GL_LINES);
    for (int i = -300; i < 300; i++) {
        glVertex2i(0, i);
    }
    glEnd();
}