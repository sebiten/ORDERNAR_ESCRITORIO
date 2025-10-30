#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <windows.h>

void crearCarpeta(const char* ruta) {
  DWORD atributos = GetFileAttributes(ruta);
  if (atributos == INVALID_FILE_ATTRIBUTES) {
    mkdir(ruta);
  }
}

const char* obtenerExtension(const char* archivo) {
  const char* punto = strrchr(archivo, '.');
  if (!punto || punto == archivo) return "";
  return punto + 1;
}

const char* obtenerCategoria(const char* ext) {
  // PDF y documentos
  if (!strcmp(ext, "pdf") || !strcmp(ext, "docx") || !strcmp(ext, "doc") ||
      !strcmp(ext, "txt") || !strcmp(ext, "rtf"))
    return "Documentos";

  // Imágenes
  if (!strcmp(ext, "jpg") || !strcmp(ext, "jpeg") || !strcmp(ext, "png") ||
      !strcmp(ext, "bmp") || !strcmp(ext, "gif") || !strcmp(ext, "webp"))
    return "Imagenes";

  // Código y scripts
  if (!strcmp(ext, "c") || !strcmp(ext, "cpp") || !strcmp(ext, "h") ||
      !strcmp(ext, "js") || !strcmp(ext, "ts") || !strcmp(ext, "py") ||
      !strcmp(ext, "bat") || !strcmp(ext, "sh") || !strcmp(ext, "json"))
    return "Codigo";

  // Comprimidos
  if (!strcmp(ext, "zip") || !strcmp(ext, "rar") || !strcmp(ext, "7z"))
    return "Comprimidos";

  // Ejecutables y setups
  if (!strcmp(ext, "exe") || !strcmp(ext, "msi") || !strcmp(ext, "deb"))
    return "Instaladores";

  // Atajos y accesos directos
  if (!strcmp(ext, "lnk")) return "AccesosDirectos";

  // Otros (videos, audios, etc.)
  if (!strcmp(ext, "mp4") || !strcmp(ext, "mkv") || !strcmp(ext, "mov") ||
      !strcmp(ext, "mp3") || !strcmp(ext, "wav"))
    return "Multimedia";

  return "Otros";
}

int main() {
  char escritorio[MAX_PATH];
  snprintf(escritorio, sizeof(escritorio), "%s\\Desktop",
           getenv("USERPROFILE"));

  DIR* dir = opendir(escritorio);
  if (!dir) {
    printf("? No se pudo abrir el escritorio.\n");
    return 1;
  }

  struct dirent* entrada;
  while ((entrada = readdir(dir)) != NULL) {
    if (entrada->d_type != DT_REG) continue;  // ignorar carpetas

    const char* ext = obtenerExtension(entrada->d_name);
    if (strlen(ext) == 0) continue;  // sin extensión

    const char* categoria = obtenerCategoria(ext);
    char carpetaDestino[MAX_PATH], origen[MAX_PATH], destino[MAX_PATH];

    snprintf(carpetaDestino, sizeof(carpetaDestino), "%s\\%s", escritorio,
             categoria);
    crearCarpeta(carpetaDestino);

    snprintf(origen, sizeof(origen), "%s\\%s", escritorio, entrada->d_name);
    snprintf(destino, sizeof(destino), "%s\\%s", carpetaDestino,
             entrada->d_name);

    if (rename(origen, destino) == 0)
      printf("? %s ? %s\n", entrada->d_name, categoria);
    else
      printf("?? No se pudo mover %s\n", entrada->d_name);
  }

  closedir(dir);
  printf("\n?? Escritorio organizado con éxito.\n");
  return 0;
}
