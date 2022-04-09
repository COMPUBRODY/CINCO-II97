//Programa que maneja la clase Call que contiene una lista de punteros a
// objetos T llamados CA o CE .
// Call es definida como TMIListImp que es un patron de clases que permite
// manejar los miembros de la clase.
#include <classlib\listimp.h>
#include <c:\users\pbx\kori\include\newarray.h> //Prototipo de TIDT
#include <classlib\time.h>
#include <classlib\timer.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

/* <<<<<<<<<<<<<<<<<<<<<Definicion de la clase party>>>>>>>>>>>>>>>>>>> */

class Party
{
 private:
	int terminal;     //#SLIC
	int state;
	int highChannel;
	int lowChannel;
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
	int  operator ==(const Party&)const;
 };
/* <<<<<<<<<<<<<< Definicion de las funciones para la clase party >>>>>>>> */

Party::Party(int term) // Funcion constructor
{
terminal=term;
}
Party::~Party()      // Funcion destructor
{
}

void Party::SetTerminal(int slic) // Funcion que fija el numero de terminal
 {
	terminal=slic;
  }

int Party::GetTerminal()    // Funcion que obtiene el numero de terminal
 {
	return (terminal);
 }

void Party::SetState(int estado) // Funcion que fija el estado del abonado
 {
	state=estado;
 }

int Party::GetState() // Funcion que obtiene el estado del abonado
{
 return (state);
 }

void Party::SetHighChannel(int highC) // Funcion que fija el canal alto
{
 highChannel=highC;
}

int Party::GetHighChannel() // Funcion que obtiene el canal alto
{
 return (highChannel);
}

void Party::SetLowChannel(int lowC) // Funcion que fija el canal bajo
{
 lowChannel=lowC;
}

int Party::GetLowChannel() // Funcion obtiene
{
 return (lowChannel);
 }

int Party::operator ==(const Party& t) const // Operador de igual
{
  if(terminal==t.terminal)
	 return(1);
  else
	 return(0);
}

// <<<<<<<<<<<< Definicion de la clase LLamada >>>>>>>>>>>>>>>>>>>>>>>>

class Call: public TIListImp<Party>
{
	private:
	 int typeOfCall;      //Tipo de llamada
	 int arrayPosition;   //Posicion que tiene el objeto llamada en el arreglo
								 //de punteros a objetos llamadas.
	 int    state;        //Estado de la llamada
	 int    mainParty;    //Party principal
	 TTime  timeCreation; //Tiempo de inicio del objeto llamada
	 TTime *timeBegin;    //Tiempo de inicio de la conversacion
	 TTime *timeEnd;      //Tiempo de termino del objeto llamada


	public:
	  int  GetTypeOfCall();        //Fcn. que obtiene el tipo de llamada
	  void SetTypeOfCall(int );   //Fcn. que fija el tipo de llamada
	  int  GetArrayPosition();   //Fcn. que obtiene la posicion en el arreglo
										//de punteros a objetos llamadas
	  void SetArrayPosition(int  ); //Fcn. que fija la posicion
											 //en el arreglo de punteros
	  int  GetState();           //Fcn. que obtiene el estado de la llamada
	  void SetState(int );      //Fcn. que fija el estado de la llamada
	  int  GetMainParty();      //Fcn. que obtiene el # del Party principal
	  void SetMainParty(int);   //Fcn. que fija el # de Party principal
	  long GetTimeCreation();   //Fcn. que obtiene el tiempo de creacion del
										 // objeto llamada
	  long GetTimeBegin();      //Fcn. que obtiene el tiempo de inicio de la
										// conversacion
	  long GetTimeEnd();       //Fcn. que obtiene el tiempo de termino del
										// objeto llamada
	  int  SetTimeBegin();     //Fija el tiempo de inicio de la conversacion
	  int  SetTimeEnd();       //Fija el tiempo de termino del objeto llamada
	  ~Call ();               //Fcn. Destructor de la clase llamada
	  int operator ==(const Call&)const; //Fcn.
};

//Definicion de las funciones miembro de la clase llamada.

int Call::GetTypeOfCall()  //Fcn. que obtiene el tipo de llamada
{
	return(typeOfCall);
}

void Call::SetTypeOfCall(int x) //Fcn. que fija el tipo de llamada
{
	typeOfCall=x;
}

int Call::GetArrayPosition() //Fcn. que obtiene la posicion en el arreglo
										//de punteros a objetos llamadas
{
	return(arrayPosition);
}

void Call::SetArrayPosition(int x) //Fcn. que fija la posicion
															  //en el arreglo de punteros
{
	arrayPosition=x;
}

int Call::GetState()          //Fcn. que obtiene el estado de la llamada
{
	return(state);
}

void Call::SetState(int x) //Fcn. que fija el estado de la llamada
{
	state=x;
}

int Call::GetMainParty()  //Fcn. que obtiene el Party principal de la llamada
{
	return mainParty;
}

void Call::SetMainParty(int x) //Fcn. que asocia el Party principal con el
{                               //objeto llamada
	mainParty=x;
}
// <<<<<<<<<<<<<<Temporizacion de la clase llamada>>>>>>>>>>>>>>>>>>>>>>>

long Call::GetTimeCreation()   //Fcn. que obtiene el tiempo de creacion del
										 // objeto llamada
{
	return(timeCreation.Seconds());
}

long Call::GetTimeBegin()      //Fcn. que obtiene el tiempo de inicio de la
										// conversacion
{
	return timeBegin->Seconds();
}

long Call::GetTimeEnd()    //Fcn. que obtiene el tiempo de termino del
										// objeto llamada
{
	return timeEnd->Seconds();
}

int Call::SetTimeBegin()   //Fija el tiempo de inicio de la conversacion
{
  timeBegin=new TTime();   // Primera opcion para la temporizacion
//  TTime temp;            // Segunda opcion para la temporizacion
//  timeBegin=&temp;
  return 1;
}

int Call::SetTimeEnd()    //Fija el tiempo de termino del objeto llamada
{
	timeEnd=new TTime();   //Primera opcion para la temporizacion
/*  TTime temp;           // Segunda opcion para la temporizacion
  timeEnd=&temp; */
  return 1;
}

Call::~Call()          // Funcion Destructor
{
delete timeBegin;
delete timeEnd;
}

int Call::operator ==(const Call& T)const  //Fcn. operador doble igual
{
	return arrayPosition == T.arrayPosition;
}

//------------------------------------------------------//
//    OJO: LAS PRUEBAS SE HARAN EN EL PROYECTO PRUEBAS  //
//         COMO UNA MANERA DE MODULARIZACION            //
//			  LOS ARCHIVOS A MODIFICAR SERAN LOS NUEVOS Y  //
//         EL PROYECTO PRUEBAS.                         //
//------------------------------------------------------//

// <<<<<<<<<<<<<<<<<<<<< Funcion principal >>>>>>>>>>>>>>>>>>>>>>>>>

void main()
{

								 //Pruebas con la clase Call
 Call call;               // Objeto llamada
 Party *aParty;    //= new Party;  Puntero a objetos tipo party
 int x,y,z;

 Party uno(999);             // Un party asociado  a call
 call.Add(&uno);

 Party otro(666);           // Otro party asociado a call
 call.Add(&otro);
									 // Pruebas con la lista de partys en call
// *aParty=otro;
 aParty=call.PeekHead();
 Party aux(3);
 aux=*aParty;
 cout<<"\n Terminal ="<<aux.GetTerminal()<<endl;
 call.Detach(&otro);
  aParty=call.PeekHead();
  aux=*aParty;
  cout<<"\n Terminal ="<<aux.GetTerminal()<<endl;

						  // Cargar el objeto call con los siguientes datos

 x=1; //estado
 y=4; //tipo de llamada
 z=7; //posicion en el arreglo
 call.SetState(x);
 call.SetTypeOfCall(y);
 call.SetArrayPosition(z);
 cout<<"State= "<<call.GetState() <<endl;
 cout<<"type of Call= "<<call.GetTypeOfCall() <<endl;
 cout<<"Posicion=" <<call.GetArrayPosition() ;

									 // Pruebas de temporizacion
 long a,b,c;
 a= call.GetTimeCreation();
 cout<<"\n\n"<<"secA="<< a <<endl;
 getch();

 call.SetTimeBegin();
 b= call.GetTimeBegin();
 cout<<"\n\n"<<"secB="<< b ;
 getch();

 call.SetTimeEnd();
 c= call.GetTimeEnd();
 cout<<"\n\n"<<"secC="<< c <<endl;
 getch();

 cout<<endl<<"dur-llam="<< (c-b)<<endl<<endl;


 return;

}

//------------------------------------------------------//
//    OJO: LAS PRUEBAS SE HARAN EN EL PROYECTO PRUEBAS  //
//         COMO UNA MANERA DE MODULARIZACION            //
//			  LOS ARCHIVOS A MODIFICAR SERAN LOS NUEVOS Y  //
//         EL PROYECTO PRUEBAS.                         //
//------------------------------------------------------//

