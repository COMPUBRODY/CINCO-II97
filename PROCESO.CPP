/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Funcion Procesing() cuya labor es procesar mensajes de la cola de Hardware
a Software, ademas de crear un mensaje multiple hacia la cola de Software a
Hardaware.
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
//#include <c:\bc4\irok\include\newarray.h>
#include <signal.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
//#include <header de arreglos, listas, tablas>

void Procesing()
{
// Supervisar la cola de mensajes
	char ch=signal.GetTypeOfChange();
	switch ch
	{
		case 'descolgo':
							 OffHook();
							 break;
		case 'digito':
							 Digit();
							 break;
		case 'ring':
							 Ring();
							 break;

		case 'colgo':
							 OnHook();
							 break;
		default:
					break;

	}
}

/* Funcion OffHook que procesa el mensaje de descolgo, oscultando al objeto
	signal sobre las caracteristicas del mensaje */
void OffHook()
{
	 char offHookTerminal;
	 char typeOfTerm;
	 char typeOfChange;
	 int  dtmfAssigned;
	 int  channelLowAssigned;
	 int  channelHighAssigned;

//<<<<<<<<<<<< Obtener las caracteristicas del mensaje >>>>>>>>>>>>>>>>>>

	 offHookTerm=signal.GetTerminal();
	 typeOfTerm=signal.GetTypeOfTerminal();
	 typeOfChange=signal.GetTypeOfChange();

/*<<<<<<<<<<< Crear al objeto llamada y añadirlo al arreglo de punteros
				  a objetos llamada >>>>>>>>>>>>>>>>> */

 Party a(offHookTerm);       // Creacion de un Objeto party
 Call call;                  // Creacion del Objeto llamada
 call.Add(&a);               // Añadir el objeto party al objeto llamada
 vector.Add(&call);          // Añadir el objeto llamada al arreglo de punteros
									  // a llamadas (Se supone que vector esta def.

/*<<<<<<<<<< Inicializacion del objeto party y objeto llamada >>>>>>>>>> */

 a.SetState(1);              // Fijar el estado del O. party en descolgado=1
 call.SetState(1);           // Fijar el estado del O. call en estado=1

/*<<<<<< Buscar y reservar un DTMF libre en la tabla de terminales >>>>>>>*/

 dtmfAssigned=tabla.FindFree(DTMF);

/*<<<<<< Busca y reserva dos canales en el Objeto Matrix >>>>>>>>>>>>>>>>*/

channelLowAssigned=5;          // Prueba.Channel1=matrix.GetChannel1();
channe1LowAssigned=21;
// Channel2=matrix.GetChannel2();
 a.SetLowChannel(channelLowAssigned);
 a.SetHighChannel(channelHighAssigned);

/*<<<<<< Prepara la comunicacion diciendole al activador de codecs que: >>>*/



}
