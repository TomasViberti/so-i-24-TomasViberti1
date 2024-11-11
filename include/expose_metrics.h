/**
 * @file expose_metrics.h
 * @brief Programa para leer el uso de CPU y memoria y exponerlos como métricas de Prometheus.
 */

#include "../include/metrics.h"
#include "metrics.h"
#include <errno.h>
#include <prom.h>
#include <promhttp.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para sleep

/**
 * @brief Tamaño del buffer utilizado para leer las métricas.
 */
#define BUFFER_SIZE 256

/**
 * @brief Actualiza la métrica de uso de CPU.
 */
void update_cpu_gauge(void);

/**
 * @brief Actualiza la métrica de uso de memoria.
 */
void update_memory_gauge(void);

/**
 * @brief Actualiza la métrica de uso de I/O del disco.
 */
void update_disk_io_gauge(void);

/**
 * @brief Actualiza la métrica de uso de I/O del disco.
 */
void update_red_gauge(void);

/**
 * @brief Actualiza la métrica de cantidad de procesos en ejecución.
 */
void update_proc_number(void);

/**
 * @brief Actualiza la métrica de cambios de contexto.
 */
void update_context_switches(void);

/**
 * @brief Función del hilo para exponer las métricas vía HTTP en el puerto 8000.
 * @param arg Argumento no utilizado.
 * @return NULL
 */
void* expose_metrics(void* arg);

/**
 * @brief Inicializar mutex y métricas.
 */
void init_metrics(void);

/**
 * @brief Destructor de mutex
 */
void destroy_mutex(void);