#include <GL/glut.h>
#include <iostream>

void display();
void init();

void ingresarPuntoControl();
void mostrarPuntoControl();
void mostrarPolilinea();
void mostrarEjesCoordenados();

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
    ingresarPuntoControl();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    mostrarEjesCoordenados();
    mostrarPuntoControl();
    mostrarPolilinea();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glPointSize(15);
    glOrtho(-400.f, 400.f, -300.f, 300.f, -1.f, 1.f);
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
    cout<<"Para visualizar los puntos ingresados, haga clic en la opcion DESACTIVADO del submenu";
}

void mostrarPuntoControl() {
    int x, y;
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
    } while(indice >= 0 && indice < cantidadPuntoControl);
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