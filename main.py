import os
import time
import pygame
import notificaciones

alarmaPath = os.path.realpath('alarma.mp3')

contadorCiclo : int = 0
tiempo : int = 1800 
pygame.init()

def sonido():
    pygame.mixer.music.load('alarma.mp3')
    pygame.mixer.music.play()

def cerrar():
    print("¡Hasta pronto!")
    time.sleep(2)

def aviso():
    global contadorCiclo
    notificaciones.notificar()
    sonido()
    
    if contadorCiclo != 4:
        print("\nHan pasado 30 minutos, debes de descansar tus ojos como mínimo 5 minutos.")
        print("Te recomendamos alejarte de la pantalla, enfocar la vista en un objeto lejano y hacer ejercicios de estiramiento para el cuello y los hombros.")
        valorContinuar = input("¿Deseas continuar? (S/N): ")
        
        if valorContinuar.lower() == 's':
            iniciarTiempo()
        elif valorContinuar.lower() == 'n':
            cerrar()
        else:
            print("Opción inválida")
            aviso()
    else:
        print("\nHan pasado 2 horas, debes de descansar tus ojos al menos 15 minutos, para evitar problemas visuales a largo plazo.")
        print("Te recomendamos alejarte de la pantalla, enfocar la vista en un objeto lejano y hacer ejercicios de estiramiento para el cuello y los hombros.")
        valorContinuar = input("¿Deseas continuar? (S/N): ")
        
        if valorContinuar.lower() == 's':
            valorContinuar = 0
            iniciarTiempo()
        elif valorContinuar.lower() == 'n':
            cerrar()
        else:
            print("Opción inválida")
            aviso()

def iniciarTiempo():
    global contadorCiclo
    print("\nEl tiempo empezó a contar. (30 minutos)")
    print("Por favor, no cierres la consola.")
    time.sleep(int(tiempo)) # Tiempo de espera de contador
    contadorCiclo += 1
    aviso()
    
def debug():
    global tiempo
    print("")
    print("Modo de desarrollador: Roberto:")
    print("Forzar notificacion : 1")
    print("Forzar iniciar / continuar : 2")
    print("Forzar continuar : 3")
    print("Forzar 2 horas : 4")
    print("Establecer numero de ciclos: 5")
    print("Establecer tiempo personalizado: 6")
    opcionDebug = input("Opción: ")
    if int(opcionDebug) == 1:
        notificaciones.notificar()
        debug();
    elif int(opcionDebug) == 2:
        iniciar(0);
    elif int(opcionDebug) == 3:
        iniciar(1);
    elif int(opcionDebug) == 4:
        iniciar(2);
    elif int(opcionDebug) == 5:
        valorNuevo = input("Nuevo valor: ")
        contadorCiclo = valorNuevo;
    elif int(opcionDebug) == 6:
        tiempo = input("Coloca el nuevo tiempo (en s): ")
        iniciarTiempo()
    else:
        print("ERROR: Opción inválida.")
        debug();
         
def main():
    def preguntar():
        
        valorContinuar = input("¿Deseas iniciar? (S/N): ")
        if valorContinuar.lower() == 's':
            iniciarTiempo()
        elif valorContinuar.lower() == 'n':
            cerrar()
        elif valorContinuar.lower() == 'debug':
            debug()
        else:
            print("ERROR: Opción inválida.")
            preguntar()
            
    print("¡Bienvenido a la alarma eyeHealth!")
    print("Autores: De la Cruz J.W., Gomez A.F., Lucano D.A., Novoa B.J., Quezada R.E. & Velasquez T.J.")
    print("Esperamos esta herramienta sea de tu agrado.")

    preguntar()
    
main()