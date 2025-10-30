# 🗂️ Ordenador de Escritorio en C

## 📘 Descripción del programa

Este programa fue desarrollado en lenguaje **C** con el objetivo de **organizar automáticamente los archivos del Escritorio** del usuario.  
Clasifica los archivos según su **extensión** (por ejemplo `.jpg`, `.png`, `.mp3`, `.pdf`, `.docx`, etc.) y los **mueve a carpetas específicas** creadas automáticamente (por ejemplo: `Imagenes`, `Documentos`, `Musica`, `Videos`, `Otros`, etc.).

De esta forma, el usuario mantiene su escritorio limpio y ordenado sin necesidad de hacerlo manualmente.

---

## ⚙️ Funcionamiento general

1. El programa **recorre todos los archivos** del escritorio del usuario (carpeta indicada en la ruta).
2. **Detecta la extensión** de cada archivo.
3. Según la extensión, **crea una carpeta** (si no existe) correspondiente a la categoría del archivo.
4. **Mueve el archivo** hacia su carpeta correspondiente utilizando funciones del sistema.
5. Si la extensión no se encuentra en ninguna categoría conocida, el archivo se mueve a la carpeta **`Otros/`**.

---

## 🧩 Categorías predefinidas

| Tipo de archivo | Extensiones reconocidas | Carpeta destino |
|------------------|--------------------------|-----------------|
| Imágenes         | `.jpg`, `.jpeg`, `.png`, `.gif`, `.bmp` | `Imagenes/` |
| Documentos       | `.pdf`, `.doc`, `.docx`, `.txt`, `.odt` | `Documentos/` |
| Música           | `.mp3`, `.wav`, `.flac` | `Musica/` |
| Videos           | `.mp4`, `.avi`, `.mkv`, `.mov` | `Videos/` |
| Comprimidos      | `.zip`, `.rar`, `.7z`, `.tar` | `Comprimidos/` |
| Programas        | `.exe`, `.msi`, `.bat` | `Programas/` |
| Otros            | (cualquier otra extensión) | `Otros/` |

---

## 🖥️ Requisitos

- **Sistema operativo:** Windows 10 o superior  
- **Compilador:** GCC o cualquier compilador C estándar (ej. MinGW, MSYS2, TDM-GCC)
- **Entorno recomendado:** Visual Studio Code o Zinjai

---

## 🧠 Concep
