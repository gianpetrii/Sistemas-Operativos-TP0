#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	log_info(logger, "Hola! Soy un log");



	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Leo puerto y ip para la conexion por mas que no lo diga guia de tp xq lo pide comentario
	// de arriba
	puerto = config_get_string_value(config, "PUERTO");
	ip = config_get_string_value(config, "IP");
	log_info(logger, "Lei el IP = %s y el PUERTO %s\n", ip, puerto);

	// Por otro lado leo el valor de CLAVE en tp0.config
	valor = config_get_string_value(config, "CLAVE");
	log_info(logger, "Lei la CLAVE = %s\n", valor);



	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	// Inicializo mi nuevo logger
	t_log* nuevo_logger;

	// Chequeo que mi nuevo logger no sea nulo para asegurar no error
	if ((nuevo_logger = log_create("tp0.log", "TP0", 1, LOG_LEVEL_INFO)) == NULL){
		printf("No se creo bien el nuevo logger\n");
		exit(1);	// lo hago para que se pausee la ejecucion con error
	}
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;
	// hago lo mismo que con la creacion del log de testear por errores
	if((nuevo_config = config_create("./tp0.config")) == NULL) {
		printf("No se pudo levantar el config");
		exit(2);
	}

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */

	// Pregunto si tengo un logger existente y si lo tengo lo destruyo
	if (logger != NULL){
		log_destroy(logger);
	}

	// Pregunto si tengo un config existente y si lo tengo lo destruyo
	if (config != NULL){
		config_destroy(config);
	}
}
