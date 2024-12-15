# Proyecto: Expansión del Kernel de Linux

Este proyecto tiene como objetivo principal personalizar y expandir el kernel de Linux mediante la implementación de nuevas funcionalidades y llamadas al sistema. Además, se desarrollaron módulos para recopilar estadísticas del sistema, modificando así el comportamiento estándar del kernel.

## Características principales

1. **Modificaciones del Kernel**
   - Cambio del nombre del sistema a `KernelUSAC-6.8`.
   - Mensajes personalizados durante el inicio del sistema.

2. **Nuevas llamadas al sistema (syscalls)**
   - `capture_memory_snapshot`: Captura el estado actual de la memoria del sistema.
   - `track_syscall_usage`: Rastrea cuántas veces se invoca una syscall específica.
   - `get_io_throttle`: Obtiene estadísticas de I/O por proceso.

3. **Módulos del Kernel**
   - Estadísticas de uso de CPU, memoria y almacenamiento.

## Requisitos del entorno

- Sistema operativo: Ubuntu 20.04 o superior / Linux Mint.
- Herramientas:
  - Make
  - GCC
  - GDB
  - QEMU
- Kernel base: Linux 6.8.0

## Estructura del proyecto

```
project-root/
├── src/
│   ├── kernel-modifications/
│   │   ├── syscalls/        # Implementación de las syscalls
│   │   └── boot/            # Archivos de inicialización del kernel
│   └── modules/             # Módulos del kernel para estadísticas
├── docs/                    # Documentación técnica
├── tests/                   # Scripts de pruebas
└── README.md                # Este archivo
```

## Instrucciones de uso

1. Clonar el repositorio:
   ```bash
   git clone <URL-del-repo>
   ```

2. Compilar el kernel modificado:
   ```bash
   cd src/kernel-modifications
   make
   ```

3. Cargar módulos personalizados:
   ```bash
   cd src/modules
   sudo insmod <modulo>.ko
   ```

4. Verificar logs:
   ```bash
   dmesg
   ```

## Créditos

Desarrollado por **Diego Ahtohil Noj Armira** para el curso de Sistemas Operativos 2, Facultad de Ingeniería, Universidad de San Carlos de Guatemala.

---
