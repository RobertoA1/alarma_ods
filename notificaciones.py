from plyer import notification

def notificar():
    notification.notify(
        app_name = "eyeHealth",
        title = '¡Es hora de levantarse!',
        timeout = 0,
        message = 'Han pasado 30 minutos, levántate y mira a otro lado para descansar tu vista...'
    )