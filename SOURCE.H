// Header fuente para trabajar en el Proyecto PBX

#include <c:\bc4\pbx\include\signal.h>
#include <c:\bc4\pbx\include\newarray.h>
#include <classlib\time.h>
#include <classlib\timer.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
//#include <c:\paquetes\bc4\pbxlib\signal.h>
//#include <c:\paquetes\bc4\pbxlib\newarray.h>
//#include <c:\paquetes\bc4\pbxlib\signal.cpp>
#include <c:\bc4\pbx\include\signal.cpp>

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

#define MINTONE    90     //limites de tonos
#define MAXTONE   100
#define MINDTMF    80     //limites de DTMF
#define MAXDTMF    89
#define MINCE	    70     //limites de CE
#define MAXCE	    79
#define ABONADOS   69     //limite de abonado

//Definicion de Constantes
#define MINTERM 	 0     //Ctes. para la generacion de los vectores
#define MAXTERM 	 100
#define MINDIR  	 100
#define MAXDIR  	 200

#define PASSWD   11   //#	//codigos por recibir para los digitos especiales
#define SPECFUN  12   //*
#define OUTGOING  9   //acceso a troncal (llamada saliente)
#define LOCAL	   1   //llamada local

#define INITSTATE	 0     //Cte. de estados de terminal
#define BUSYTERM   1

#define NUMOFCALLS 5     //cte. para el num de llamadas en el arreglo

#define MAXNUMBERDIGIT 3 // Numero maximo de digitos marcados

#define CA		 	 0     //Ctes. para tipo de terminal
#define CE      	 1
#define DTMF    	 2
#define TONE    	 3

#define INVITE	  	1    //ctes. para tipos de tonos
#define BUSY		2
#define RING      3
#define LOCUTION1 4
#define LOCUTION2 5
#define LOCUTION3 6
#define LOCUTION4 7

#define OFFHOOK 	'1'   //ctes. para tipos de mensaje de H->S (procesingHS)
#define DIGIT		'2'   // Digitos del 0 al 15
#define ANSWER		'3'
#define ONHOOK		'4'
#define TIMEOUT	'5'

#define REQUESTSIGNAL   '0'  //ctes. para tipos de mensajes de S->H
#define BLOCKEDSIGNAL1  '1'
#define BLOCKEDSIGNAL2  'a'
#define FIRSTDIGIT      '2'
#define RINGSIGNAL	   '3'
#define CONNECTED	      '4'
#define OHATREQorINDIAL '5'
#define OHATWAITFS      '7'
#define OHATCONVERS	   '8'
#define OHATBUSY		   '9'

#define IDLE			0   //ctes. para enumeracion de estados de la llamada
#define REQUEST   	1
#define INDIAL			2
#define WAITFORSERV  3
#define CONVERSATION 4
#define RELEASE		5   //colgado incierto??
#define BLOCKEDCALL  6
#define BUSYCALL     7

#define IDLE			0   //ctes. para enumeracion de estados del Party
#define OFFHOOKED		1
#define DIALING1		2
#define DIALING2		3
#define DIALING3		4
#define RINGING		5
#define CONVERSING	6
#define BLOCKED		7

#define DTMFPOS		0		//ctes. para asignacion de posiciones en call
#define TONEPOS		1
#define MAINPARTYPOS 2
#define SECPARTYPOS	3
#define THIRPARTYPOS 4

#define SIMETRIC	256    	//distancia para simetrizar canal bajo y alto

#define FIRSTDIGTIMER 10  //ctes. para generacion de timers
#define INTERDIGTIMER  8
#define ANSWERTIMER   60
#define BLOCKEDTIMER  60

#define CA_RING 1   //tipos de timbrado
#define CE_RING 2
//#define NORMAL  1
//#define FAST    2

//ESTADOS POSIBLES DE LOS CANALES DE ENTRADA
#define FREE	     0     //libre
#define RESERVED    1     //reservado
#define SWITCHED    2     //conectado
#define HIGHZ		3     //Alta impedancia


/* <<<<<<<<<<<<<<<<<<<<<Definicion de la clase party>>>>>>>>>>>>>>>>>>> */

class Party
{
 protected:
	int terminal;     //#SLIC
	int state;
	int highChannel;
	int lowChannel;
	int positionInCall;
 public:
	Party(int term);     //Constructor de la clase party
	virtual ~Party();
	void SetTerminal(int slic);       //Fija #SLIC
	int  GetTerminal();       //Leer #SLIC
	void SetState(int );          //Fijar estado
	int  GetState();          //Leer estado
	void SetHighChannel(int highC);    //Fijar canal alto
	int  GetHighChannel();    //Leer canal alto
	void SetLowChannel(int lowC);     //Fijar canal bajo
	int  GetLowChannel();     //Leer canal bajo
	void SetPositionInCall(int);    //Fijar posicion en el arreglo llamada
	int  GetPositionInCall();    //Leer posicion en llamada
	int  operator ==(const Party&)const;
};
//>>>>>>>> Def de clase para crear contadores para temporizacion >>>>>>>>
class Counter
{
		unsigned int count;
		int term;
	public:
		Counter( int, unsigned int);      //constructor
		int GetTerminal();
		void ReStart ( unsigned int );   //Fcn. para reiniciar contador
		int DetectFinalCount(int); //
		//int Update();           //Fcn. para actualizar el counter y verificar fin
		int  operator ==(const Counter&)const;
};

//>>>>>>>>> Def de clase para crear referencias a teminales timbrando >>>>>>>
class RingingTerm{
	int term;  //Numero de terminal
	int port;  //Puerto correspondiente a la terminal
	char mask; //mascara para determinar el bit correspondiente al puerto
	int ticksOn; //Duracion del encendido en Numero de ticks
	int ticksOff; //Duracion del encendido en Numero de ticks
	int count;
	int state;
	public:
	RingingTerm(int terminal, int typeRing); //constructor
	void On();
	void Off();
	int update();
	int  operator ==(const RingingTerm&)const;
	};

// >>>>>>>>>>>>>>>>>Definion de la clase de Circuito Abonado <<<<<<<<<<<<<<
class Subscriber: public Party
{
	private:
	  char dialDigit[20];
	  int numberDigit;
	  int dialedNumberDir;
	  Counter *counterPtr;
	  RingingTerm *ringPtr; //corresponde al abonado que se le marco
	public:
	  Subscriber(int);
	  int  GetNumberDigit();
	  void SetDialDigit(int);
	  char GetDialDigit(int);
	  int  GetDialedNumberDir();       //Numero de directorio marcado
	  Counter *GetCounterPtr();            //Posicion del temporizador
	  void SetCounterPtr(Counter *);
	  RingingTerm *GetRingPtr();               //Posicion del ring
	  void SetRingPtr(RingingTerm *);
};

// <<<<<<<<<<<< Definicion de la clase DTMF, herencia: Party >>>>>>>>>>>>
class Dtmf: public Party
{
	private:
	public:
		Dtmf(int);		//constructor
};

// <<<<<<<<<<<< Definicion de la clase TONE, herencia: Party >>>>>>>>>>>>
class Tone: public Party
{
	private:
		int typeOfTone;
	public:
		Tone(int,int);		//constructor
		int GetTypeOfTone();
};

// <<<<<<<<<<<< Definicion de la clase LLamada >>>>>>>>>>>>>>>>>>>>>>>>
// Call es definida como TIArrayAsVector que es un patron de clases que permite
// manejar los miembros de la clase.

class Call: public TIDTArrayAsVector<Party>
{
	private:
	 int typeOfCall;      //Tipo de llamada
	 int arrayPosition;   //Posicion que tiene el objeto llamada en el arreglo
								 //de punteros a objetos llamadas.
	 int numberOfSubs; 	 //numero de subscriptores en arreglo
	 int    state;        //Estado de la llamada
	 TTime  timeCreation; //Tiempo de inicio del objeto llamada
	 TTime *timeBegin;    //Tiempo de inicio de la conversacion
	 TTime *timeEnd;      //Tiempo de termino del objeto llamada

	public:
	  Call();				//constructor
	  int  GetTypeOfCall();        //Fcn. que obtiene el tipo de llamada
	  void SetTypeOfCall(int );   //Fcn. que fija el tipo de llamada
	  int  GetArrayPosition();   //Fcn. que obtiene la posicion en el arreglo
										//de punteros a objetos llamadas
	  void SetArrayPosition(int  ); //Fcn. que fija la posicion
											 //en el arreglo de punteros
	  int  GetState();           //Fcn. que obtiene el estado de la llamada
	  void SetState(int );      //Fcn. que fija el estado de la llamada
	  int AddSubs(Subscriber *); //Fcn para añadir un abonado al arreglo
	  long GetTimeCreation();   //Fcn. que obtiene el tiempo de creacion del
										 // objeto llamada
	  long GetTimeBegin();      //Fcn. que obtiene el tiempo de inicio de la
										// conversacion
	  long GetTimeEnd();       //Fcn. que obtiene el tiempo de termino del
										// objeto llamada
	  long GetCallDuration();	//Fcn. para obtener la duracion de la llamada
	  int  SetTimeBegin();     //Fija el tiempo de inicio de la conversacion
	  int  SetTimeEnd();       //Fija el tiempo de termino del objeto llamada
	  int  GetTermPosition(int); //obtener la posicion en call con termNum
	  ~Call ();               //Fcn. Destructor de la clase llamada
	  int operator ==(const Call&)const; //Fcn.
};

//<<<<<<<<<<<<<<<<<< Definicion de la clase Estadistica  >>>>>>>>>>>>>>>>>>>

class Statistic
{
  private:
	unsigned long bhca;				//Intentos de llamada
	unsigned long fails;				//Intentos Fallidos de llamada
	unsigned long failsToFirstDigit;	//Intentos Fallidos antes del 1er. digito
	unsigned long timeout;			//Llamadas Caidas por Time Out
	unsigned long onHookInDial;	//Llamadas Terminadas durante la marcacion
	unsigned long noAnswer;			//Llamadas que no responden (timbran sin exito)
	unsigned long unSuccess;		//Llamadas no exitosas
	unsigned long success;			//Llamadas exitosas
	unsigned long incoming;			//Llamadas entrantes
	unsigned long outgoing;			//Llamadas salientes
	unsigned long transfered;		//Llamadas transferidas
	unsigned long local;				//Llamadas locales (internas)

  public:
	unsigned long GetBHCA();
	void IncBHCA();
	unsigned long GetFails();
	void IncFails();
	unsigned long GetFailsToFirstDigit();
	void IncFailsToFirstDigit();
	unsigned long GetTimeout();
	void IncTimeout();
	unsigned long GetOnHookInDial();
	void IncOnHookInDial();
	unsigned long GetNoAnswer();
	void IncNoAnswer();
	unsigned long GetUnSuccess();
	void IncUnSuccess();
	unsigned long GetSuccess();
	void IncSuccess();
	unsigned long GetIncoming();
	void IncIncoming();
	unsigned long GetOutgoing();
	void IncOutgoing();
	unsigned long GetTransfered();
	void IncTransfered();
	unsigned long GetLocal();
	void IncLocal();
	Statistic();		//Constructor de la clase
};

/*<<<<<<<<<<<<<<< Definicion de la clase Arreglo que consiste en >>>>>>>>>>
<<<<<<<<<<<<<<<<< una lista de punteros a objetos llamadas       >>>>>>>>>>*/

class CallArray: public TIDTArrayAsVector<Call>
{
	public:
	Statistic statistic;
	CallArray(int);         // Funcion constructor opcion 1
	CallArray(int,int,int); // Funcion constructor opcion 2
};

// <<<<<<<<<<<<<<<<<<<<< Definicion de la clase base Terminal >>>>>>>>>>>>>
class Terminal
{
	protected:
	int type;                          //Tipo de tabla(Abonados, tks, DTMF)
	int state;                         //Estado de la terminal

	public:
	Terminal(int );                       //Constructor de la clase Terminal
	int GetState();                    // Funcion que obtiene el estado de la
												  // de la terminal
	void SetState(int);                   // Funcion que fija el estado de la
												  // terminal
	int GetType();                     // Funcion que obtiene el tipo de
												  // terminal
	int operator ==(const Terminal&)const; // Funcion operador doble igual
												  // Las funciones Virtuales se igualan
												  // a cero para hacer de la clase
												  // terminal una clase abstracta
												  // por lo que no se necesitan definir
	virtual int GetNumberDir();      //Funcion Virtual referida a CA o CE
	virtual void SetNumberDir(int);  //Funcion Virtual referida a CA o CE
	virtual int GetDirState();       //Funcion Virtual referida a CA o CE
	virtual void SetDirState(int) ;  //Funcion Virtual referida a CA o CE
	virtual int GetRights();         //Funcion Virtual referida a CA o CE
	virtual void SetRights(int);     //Funcion Virtual referida a CA o CE
	virtual void SetTypeOfTone(int); //Funcion Virtual referida a Tonos
	virtual int GetTypeOfTone() ;    //Funcion Virtual referida a Tonos
	virtual ~Terminal();             // Destructor de la clase Terminal
};

// <<<<<<<<<<<<<<<<<<<<<< Definicion de la clase derivada CARegister>>>>

class CARegister: public Terminal
{
	protected:
	int numberDir;
	int stateDir;
	int rights;

	public:
	CARegister(int);					  //constructor
	virtual void SetNumberDir(int); // Funcion que fija el numero de directorio
	virtual int GetNumberDir();	  // Fcn. obtencion del num de directorio
	virtual int GetDirState();		  // Fcn. para obtener el edo. del # d'directorio
	virtual void SetDirState(int);  // Fcn. para fijar el edo. del # d'directorio
	virtual int GetRights();        // Fcn. para obtener los derechos
	virtual void SetRights(int);    // Fcn. para fijar los derechos
};

// <<<<<<<<<<<<<<<< Definicion de la clase derivada CERegister>>>>>>>>>>>>

class CERegister: public CARegister   // Clase derivada de CARegister
{
	public:
	CERegister(int);					 //constructor
} ;

// <<<<<<<<<<<<<<<<<<<< Definicion de la clase derivada DTMFRegister>>>>

class DTMFRegister: public Terminal
{
	private:

	public:
	DTMFRegister(int);					 //constructor
} ;

// <<<<<<<<<<<<<<< Definicion de la clase derivada TONERegister >>>>>>>>>

class TONERegister: public Terminal
{
	private:
	int typeOfTone;                   //Tipo de tono

	public:
	TONERegister(int);					 //Constructor
	virtual void SetTypeOfTone(int);  //Funcion que fija el tipo de tono
	virtual int GetTypeOfTone();   //Funcion que obtiene el tipo de tono
} ;

//<<<<<<<<<<<<<<<< Definicion de la clase apuntador a tablas >>>>>>>>>>>>>>>

class Table
{
	private:
	int CEOffset;              // Inicio de las respectivas terminales
	int DTMFOffset;
	int TONEOffset;
	TIArrayAsVector<Call> *subsTable; //Arreglo que liga subsTerm con su call
	TArrayAsVector<double> *dirTable;  //Arreglo que contiene los # de directorio
	TIDTArrayAsVector<Terminal> *termTable; //Arreglo de punteros.#T=Posicion
														 // en el arreglo
	public:
	Table();							//constructor
	~Table();						//Destructor
	int  SearchDir(int);       // Funcion que busca el # de CA en el Directorio
	int  SearchTerminal(int);  // Funcion que busca el # de Terminal del CA
	void SetNumberDir(int,int);// Fnc. para fijar # de dir. en CAterminal
	int  GetTerminalState(int);// Funcion que obtiene el estado de la terminal
	void SetTerminalState(int,int); //Fnc. para fijar el edo de la terminal
	int  GetTerminalType(int); // Funcion que obtiene el tipo de terminal
	int  GetDirState(int);     // Funcion que obtiene el estado del # de Dir
	void SetDirState(int,int); // Fnc. para fijar el edo. del abonado
	int  GetRights(int);       // Funcion que obtiene los derechos del abonado
	void SetRights(int,int);   // Funcion que fija los derechos del abonado
	void SetTypeOfTone(int,int);   //Funcion que fija el tipo de tono
	int  GetTypeOfTone(int);   //Funcion que obtiene el tipo de tono
	int  GetTermTone(int);		//Fcn. para obtener la terminal de algun tono
	int  FindFree(int);   		// Funcion que encuentra un terminal libre
	int  Add(int); 			   //Fcn. para agregar un nuevo elemento terminal
	int  Detach(int);          //Fcn. para borrar un elemento terminal
	int  TermValid(int,int);   //Fcn. de validacion de terminal 1
	int  TermValid(int);			// "       "              "      2
	Call *GetCallPtr(int);		//Fcn. para obtener el ptr a call de un term.
	void SetCallPtr(int,Call *);//Fcn para fijar el CallPtr de subsTerm
};

//objeto matrix Temporal>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*class Matrix
{
	private:
		int matrixMirror[16][32];
	public:
		Matrix();
		int Test();
		int ConnectionUnidir(int ch,int ch1);
		int ConnectionBidir(int ch,int ch1);
		int DisconnectionUnidir(int ch,int ch1);  //Pendiente su uso
		int DisconnectionBidir(int ch,int ch1);
		int Disconnect(int ch);
		int FindFreeChannel(int term);
		int SetModeOutputChannel(int ch,int mode);
		int GetChannelState(int ch);
};*/



/////////////////////// CLASE MATRIX //////////////////////////////
class Matrix {
private:

unsigned char lowMemory[255];     //Memoria Baja
unsigned char dataMemory[255];    //Memoria de Datos
unsigned char highMemory[255];    //Memoria Alta
char  channelState[511];          //Estado del Canal
int arrayOfTerminals[511];        //Terminal del que llama y llamado

public:

//conexiones:
int ConnectionUnidir(int inChannel, int outChannel); // conexi¢n unidireccional
int ConnectionBidir(int inChannel1,int inChannel2); // conexi¢n bidireccional
int DisconnectionUnidir(int inChannel, int outChannel); // desconexi¢n unidireccional
int DisconnectionBidir(int inChannel1, int inChannel2);// desconexi¢n bidireccional
int Disconnect(int ch_in);   // desconexi¢n  de un canal

//busqueda:
int FindFreeChannel(int terminal);  // Busqueda de canal
int FreeChannel(int terminal);      // Liberar Canal
//int FreeChannel();     // Liberar Canal
int HowManyFreeChannel(); // Cuantos canales libres
int HowManyBusyChannel(); // Cuantos canales ocupados
int GetChannelState(int ch);
int SetChannelState(int channel, int state);

// funciones:
void Inicialize();
int WriteRegister(unsigned int PCMo,unsigned int Mem);
int WriteLowMemory(unsigned int CHo, unsigned int PCMi, unsigned int CHi);
int SetModeOutputChannel(int outChannel,int HighImp);
int ReadRegister(unsigned int PCMi,unsigned int Mem);
char ReadDataMemory(unsigned int CHi);

//variables:
unsigned int PCMo,PCMi,CHo,CHi;
int terminal;
};




//objeto AC Temporal>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class ActCods
{
	private:
		int ACMirror[256];
	public:
		ActCods();
		int Test();
		int SetOn(int te,int ch);
		int SetOff(int ch);
};

//<<<<<<<<<<<<<<<<<  definicion temporal de la clase para HARDLAY >>>>>>>>
class HardLay
{
	private:
		Matrix matrix;
		ActCods AC;
	public:
		//vector publico para el control del ring en abonados
		TIArrayAsVector<RingingTerm> *ringVector;
		HardLay();      //constructor
		~HardLay();     //destructor
		RingingTerm *SendRing(int, int);    //Fnc. de mandar ring a abonado
		void Kill(RingingTerm *);  // "    " eliminar "     "
		int Kill(Subscriber *, Tone *);  //Fnc. que pone el tono en 3er edo.(no habla)
		int FindFreeChannel(int);
		int Connect(Subscriber *,Tone *,Dtmf *);//Fnc. para conectar dos canales
		int Connect(Subscriber *,Tone *); // Fcn. para conectar el tono al abonado
		int Connect(Subscriber *,Subscriber *); // Fcn. para conectar dos abonados
		int Disconnect(Party *);  //Fnc. que desconecta un party
		int Disconnect(Subscriber *, Tone *, Dtmf *); //Fcn. desconecta abonado de todo
		int Disconnect(Subscriber *, Tone *); //Fcn. desconectar abonado del tono de ring
};

