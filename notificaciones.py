from plyer import notification

notification.notify(
    app_name = "eyeHealth",
    title = '¡Es hora de levantarse!',
    timeout = 0,
    message = 'Han pasado 30 minutos, levántate y relaja un poco las piernas...'
)