#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;
int contadorCiclo=0;

void sonido30Minutos(){
    system("notificaciones.py");
    PlaySound(TEXT("alarma.wav"), NULL, SND_SYNC);
}

/* int continuar(){
    char valorContinuar;
    cout << "Deseas continuar? (S/N)";
    cin >> valorContinuar;

    if (valorContinuar == 'S' || valorContinuar == 's'){
        iniciar();
    }
} */

int iniciar(int status){ // * 0 = "Inicia o confirmó continuar" y si es 1 = "Continua", 2 = "Han pasado 2 horas, descansa 15"
    char valorContinuar;
    if (status == 0){
        int n;
        cout<<"El tiempo empieza a correr desde ahora. (30 minutos)" << endl;
        cout<<"Por favor, no cierres la consola." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        contadorCiclo +=1;

        std::thread notif(sonido30Minutos);
        notif.detach();
        if (contadorCiclo != 4){
            iniciar(1);
        } else {
            iniciar(2);
        }

        // continuar();
    } else if (status == 1) {
        cout << endl;
        cout << "Han pasado 30 minutos, debes descansar minimo 5 minutos." << endl;
        cout << "Deseas continuar? (S/N): ";
        cin >> valorContinuar;
        cout << endl;
        if (valorContinuar == 'S' || valorContinuar == 's'){
            iniciar(0);
        } else if (valorContinuar == 'N' || valorContinuar == 'n'){
            cout << "Hasta pronto.";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        } else {
            cout << "Opcion invalida.";
            iniciar(1);
        }
    } else {
        contadorCiclo = 0;
        cout << endl;
        cout << "INFO: Han pasado 2 horas (4 ciclos de 30min)." << endl;
        cout << "Debes pararte por al menos 15 minutos sin mirar la computadora para que descanses." << endl;
        cout << "Deseas continuar?: ";
        cin >> valorContinuar;
        cout << endl;
        if (valorContinuar == 'S' || valorContinuar == 's'){
            iniciar(0);
        } else if (valorContinuar == 'N' || valorContinuar == 'n'){
            cout << "Hasta pronto.";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        } else {
            cout << "Opcion invalida.";
            iniciar(1);
        }
    }
}

void debug(){
    int opcionDebug;
    cout << endl;
    cout << "Modo de desarrollador: Roberto:)" << endl;
    cout << "Forzar notificacion : 1 " << endl;
    cout << "Forzar iniciar / continuar : 2" << endl;
    cout << "Forzar continuar : 3" << endl;
    cout << "Forzar 2 horas : 4" << endl;
    cout << "Establecer numero de ciclos: 5" << endl;
    cin >> opcionDebug;
    if (opcionDebug == 1){
        sonido30Minutos();
        debug();
    } else if (opcionDebug == 2){
        iniciar(0);
    } else if (opcionDebug == 3){
        iniciar(1);
    } else if (opcionDebug == 4){
        iniciar(2);
    } else if (opcionDebug == 5){
        int valorNuevo;
        cout << "Nuevo valor: ";
        cin >> valorNuevo;
        contadorCiclo = valorNuevo;
    } else {
        cout << "Opcion incorrecta..." << endl;
        debug();
    }
}

int main() {
	char n, valorContinuar;
	cout << "Bienvenido a la alarma eyeHealth." << endl;
    cout << "Autores: De la Cruz J.W., Gomez A.F., Lucano D.A., Novoa B.J., Quezada R.E. & Velasquez T.J." << endl;
	cout<<"Quieres iniciar? (S/N): ";
	cin>>n;

    if (n == 'S' || n == 's'){
        iniciar(0);
    } else if (n == 'N' || n == 'n') {
        cout << "Hasta pronto.";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } else if (n == 'd'){
        debug();
    }
	
	return 0;
}