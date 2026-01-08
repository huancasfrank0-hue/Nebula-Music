# 🌌 Nebula Music

Un reproductor de música ligero y elegante construido con **C++**, **Qt6** y **TagLib**. 

## 🚀 Características
- **Nativo:** Sin Electron, sin consumo excesivo de RAM.
- **Rápido:** Lectura de metadatos instantánea gracias a TagLib.
- **Estándar:** Cumple con las especificaciones de Freedesktop.

## 🛠️ Instalación (Compilación Manual)
Si no deseas usar el paquete Flatpak o usas una arquitectura de **32 bits**, puedes compilarlo tú mismo:

1. **Instalar dependencias (Arch Linux):**
   ```bash
   sudo pacman -S base-devel cmake qt6-base qt6-declarative taglib
