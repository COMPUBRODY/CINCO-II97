#include <c:\bc4\pbx\include\signal.h>
#include <c:\bc4\pbx\include\newarray.h>
#include <c:\bc4\pbx\include\signal.cpp>
#include <classlib\time.h>
#include <classlib\timer.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
/*#include <c:\paquetes\bc4\pbxlib\signal.h>
#include <c:\paquetes\bc4\pbxlib\newarray.h>
#include <c:\paquetes\bc4\pbxlib\signal.cpp>*/


#define PA        0x3A4
#define PB        0x3A5
#define PC        0x3A6
#define PCONTRL   0x3A7

#define LOWMEM     2 //Memoria Baja
#define HIGHMEM    3 //Memoria Alta
#define DATAMEM    1 //Memoria de Datos
#define LOWIMP     1 //Canal transparente
#define HIGHIMP    0 //Alta impedancia

//POSICIONES DE LOS TERMINALES

#define MINTONE    104    //limites de tonos
#define MAXTONE    111
#define MINDTMF    96     //limites de DTMF
#define MAXDTMF    103
#define MINCE	    80     //limites de CE
#define MAXCE	    95
#define ABONADOS   79     //limite de abonado
//terminal del abonado operadora
#define OPERATOR    0

//Definicion de Constantes
#define MINTERM 	 0     //Ctes. para la generacion de los vectores
#define MAXTERM 	 MAXTONE
#define MINDIR  	 100
#define MAXDIR  	 200

#define PASSWD_DIG   11   //#	//codigos por recibir para los digitos especiales
#define SPECFUN_DIG  12   //*
#define OUTGOING_DIG  9   //acceso a troncal (llamada saliente)
#define LOCAL_DIG	    1   //llamada local

//Codigos aplicables para el tipo de llamada
#define TYPEMASK      0x0F  //mascara para obtener el tipo primario de llamada
#define LOCAL	       0x01  //llamada local
#define OUTGOING      0x02  //llamada saliente
#define SPECFUN       0x04  //servicios especiales
#define PASSWD        0x08  //servicio de password
#define O_LOCAL       0x12  //posibles digitos iniciales para llam local
#define O_CELL        0x22  //celular
#define O_LD          0x32  //larga distancia
#define O_NAT         0x42  //larga distancia nacional
#define O_INT         0x52  //larga distancia internacional
#define O_SPSERV      0x62  //serv. esp. con central

#define INITSTATE	 0     //Cte. de estados de terminal
#define BUSYTERM   1

#define NUMOFCALLS 5     //Cte. para el num de llamadas en el arreglo

#define MAXNUMBERDIGIT 3 // Numero maximo de digitos marcados

#define CA		 	 0     //Ctes. para tipo de terminal
#define CE      	 1
#define DTMF    	 2
#define TONE    	 3

#define INVITE	  	1    //Ctes. para tipos de tonos
#define BUSY		2
#define RING      3
#define LOCUTION1 4
#define LOCUTION2 5
#define LOCUTION3 6
#define LOCUTION4 7

#define OFFHOOK 	'1'   // Ctes. para tipos de mensaje de H->S (procesingHS)
#define DIGIT		'2'   // Digitos del 0 al 15
#define ONHOOK		'3'
#define TIMEOUT	'4'
#define IN_RING   '5'   // Ring entrante por troncal

#define REQUESTSIGNAL     '0'  // Ctes. para tipos de mensajes de S->H
#define BLOCKEDSIGNAL1    '1'
#define FIRSTDIGIT        '2'
#define RINGSIGNAL	     '3'
#define CONNECTED	        '4'
#define OHATREQorINDIAL   '5'
#define OHATWAITFS        '7'
#define OHATCONVERS	     '8'
#define OHATBUSY		     '9'
#define BLOCKEDSIGNAL2    'a'
#define BLOCKEDSIGNAL3    'b'
#define OUTGOINGSIGNAL    'c'
#define OHCEATREQorINDIAL 'd'
#define CE_CONVERS        'e'
#define DETACH_TONE       'f'
#define DETACH_RING       'g'
#define OHCEATCONVERS     'h'
#define SIM_OFFHOOK       'i'
#define RELEASE_TK        'j'
#define RELEASE_TK1       'k'
#define RELEASE_TK2       'l'
#define WELCOMESIGNAL     'm'
#define RINGSIGNAL2	     'n'



#define IDLE			0   //ctes. para enumeracion de estados de la llamada
#define REQUEST   	1
#define INDIAL			2
#define WAITFORSERV  3
#define CONVERSATION 4
#define RELEASE		5   //colgado incierto??
#define BLOCKEDCALL  6
#define BUSYCALL     7
#define BLOCKEDREQ   8

#define IDLE			0   //ctes. para enumeracion de estados del Party
#define OFFHOOKED		1
#define DIALING1		2
#define DIALING2		3
#define DIALING3		4
#define DIALING4		5
#define RINGING		6
#define CONVERSING	7
#define BLOCKED		8

#define DTMFPOS		0		//ctes. para asignacion de posiciones en call
#define TONEPOS		1
#define MAINPARTYPOS 2
#define SECPARTYPOS	3
#define THIRPARTYPOS 4

#define SIMETRIC	100 //256+16  	//distancia para simetrizar canal bajo y alto

#define FIRSTDIGTIMER 10  //ctes. para generacion de timers
#define INTERDIGTIMER  8
#define ANSWERTIMER   60
#define WELCOMETIMER  20  //Tiempo otorgado para escuchar bienvenida y marcar 
#define BLOCKEDTIMER  60


#define CA_RING 1   //tipos de timbrado
#define CE_RING 2
//#define NORMAL  1
//#define FAST    2

//ESTADOS POSIBLES DE LOS CANALES DE ENTRADA
#define FREE	     0     //libre
#define RESERVED    1     //reservado
#define SWITCHED    2     //conectado
#define HIGHZ		  3     //Alta impedancia

//CONSTANTES PARA EL MANEJO DE LLAMADAS SALIENTES
#define MINNUM_O_LOCAL 7  //numero minimo de digitos para marcar local 7=GDL
#define MINNUM_O_CELL  10 //  "      "              "            a celular
#define MINNUM_O_LD    10 //   "        "         "            " larga distancia
#define MINNUM_O_SPS   2  //        "       "             "      serv. especial
#define OUTGOINGLOCAL1 1  //posibles digitos iniciales para llam local
#define OUTGOINGLOCAL2 6
#define OUTGOINGLOCAL3 8
#define OUTGOINGLD     0  //digito inicial para larga distancia
#define OUTGOINGCELL   9  //digito inicial para llam a celular
#define OUTGOINGSPSERV 0  //digito inicial para serv. esp. con central
#define OUTGOINGINTCOD 0  //segundo digito para codigo internacional de LADA
#define OUTGOINGNATCOD 1  //segundo digito para codigo nacional de LADA
#define OUTGOINGSPS1   2  //segundos digitos posibles para servicios especiales
#define OUTGOINGSPS2   3
#define OUTGOINGSPS3   4
#define OUTGOINGSPS4   5
#define OUTGOINGSPS5   8

//Mascaras para el control de los derechos del abonado
#define LOCALMASK      0x01       //LOCAL PBX
#define OUTGOINGMASK   0x02       //OUTGOING
#define OUTLOCALMASK   0x04       //local OUTGOING
#define OUTCELLMASK    0x08       //celular
#define OUTLDMASK      0x10      //LD
#define OUTNATMASK     0x20      //LD nacional
#define OUTINTMASK     0x40      //LD internacional
#define SPS_C_MASK     0x80      //serv. especiales con central
#define SP_TK_MASK     0x100     //TK especial
#define SPS_P_MASK     0x200		//serv. especiales en conmutador
#define CONFMASK       0x400     //conferencia
//Mascaras para el control de los derechos de la troncal
#define LOCAL_DIAL_MASK  0x1000    //Troncal tipo DID (Marcacion directa)
//#define SP_TK_MASK     0x100     //TK especial

//Codigos de error
#define FAIL -1
#define OK    1
