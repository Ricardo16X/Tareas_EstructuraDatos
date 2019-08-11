import listaDoble
tarea2 = listaDoble.listaDoble()

tarea2.insertar_inicio(10)
tarea2.insertar_inicio(20)
tarea2.insertar_inicio(30)
tarea2.insertar_inicio(40)
tarea2.insertar_inicio(50)

tarea2.insertar_final(100)
tarea2.insertar_final(200)
tarea2.insertar_final(300)
tarea2.insertar_final(400)
tarea2.insertar_final(500)
#graficar
tarea2.graficar()
tarea2.insertar_pos(3,777)
tarea2.insertar_pos(8,999)
#graficar
tarea2.graficar()
print(str(tarea2.obtener_pos(3)))

tarea2.eliminar(0)
tarea2.eliminar(4)
#graficar
tarea2.graficar()