import ctypes
import tkinter as tk
from tkinter import messagebox

# Proporciona la ruta completa a la DLL
lib = ctypes.CDLL('D:\\ISFT151\\AyED3\\TP_2.1\\control_casa.dll')

# Definir las funciones de la API en C
lib.armar_total.argtypes = []
lib.armar_total.restype = None

lib.armar_parcial.argtypes = []
lib.armar_parcial.restype = None

lib.desactivar.argtypes = []
lib.desactivar.restype = None

lib.anular_zona.argtypes = [ctypes.c_int]
lib.anular_zona.restype = None

lib.panico.argtypes = []
lib.panico.restype = None

lib.emergencia_medica.argtypes = []
lib.emergencia_medica.restype = None

# Funciones para los botones
def armar_total():
    lib.armar_total()
    messagebox.showinfo("Info", "Sistema armado totalmente")

def armar_parcial():
    lib.armar_parcial()
    messagebox.showinfo("Info", "Sistema armado parcialmente")

def desactivar():
    lib.desactivar()
    messagebox.showinfo("Info", "Sistema desactivado")

def anular_zona():
    zona = int(entry_zona.get())
    lib.anular_zona(zona)
    messagebox.showinfo("Info", f"Zona {zona} anulada")

def panico():
    lib.panico()
    messagebox.showinfo("Info", "Alarma de pánico activada")

def emergencia_medica():
    lib.emergencia_medica()
    messagebox.showinfo("Info", "Alarma de emergencia médica activada")

# Crear la ventana principal
root = tk.Tk()
root.title("Control de Casa")

# Crear botones y entradas
btn_armar_total = tk.Button(root, text="Armado total", command=armar_total)
btn_armar_total.grid(row=0, column=0, padx=10, pady=10)

btn_armar_parcial = tk.Button(root, text="Armado parcial", command=armar_parcial)
btn_armar_parcial.grid(row=0, column=1, padx=10, pady=10)

btn_desactivar = tk.Button(root, text="Desactivar", command=desactivar)
btn_desactivar.grid(row=1, column=0, padx=10, pady=10)

label_zona = tk.Label(root, text="Zona a anular:")
label_zona.grid(row=1, column=1, padx=10, pady=10)
entry_zona = tk.Entry(root)
entry_zona.grid(row=1, column=2, padx=10, pady=10)
btn_anular_zona = tk.Button(root, text="Anular zona", command=anular_zona)
btn_anular_zona.grid(row=1, column=3, padx=10, pady=10)

btn_panico = tk.Button(root, text="Panico", command=panico)
btn_panico.grid(row=2, column=0, padx=10, pady=10)

btn_emergencia_medica = tk.Button(root, text="Emergencia Medica", command=emergencia_medica)
btn_emergencia_medica.grid(row=2, column=1, padx=10, pady=10)

# Ejecutar la aplicación
root.mainloop()
