// <<<<<<<<<<<< Definicion de la clase LLamada y su arreglo >>>>>>>>
// Call es definida como TIDTArrayAsVector que es un patron de clases que permite
// manejar los miembros de la clase.


class Call: public TIDTArrayAsVector<Party>
{
	private:
	 int typeOfCall;      //Tipo de llamada
	 char minNumberToDial;//minimo numero de digitos a marcar (segun typeOfCall) 
	 int arrayPosition;   //Posicion que tiene el objeto llamada en el arreglo
								 //de punteros a objetos llamadas.
	 int numberOfSubs; 	 //numero de subscriptores en arreglo
	 int    state;        //Estado de la llamada
	 TTime  timeCreation; //Tiempo de inicio del objeto llamada
	 TTime *timeBegin;    //Tiempo de inicio de la conversacion
	 TTime *timeEnd;      //Tiempo de termino del objeto llamada

	public:
	  Call();				//constructor
	  int DestroySubs(Party *);  //Fnc. para destruir un abonado de call
	  int DestroySubs(int);      //    "       "            "    por pos.
	  int  GetTypeOfCall();        //Fcn. que obtiene el tipo de llamada
	  void SetTypeOfCall(int );   //Fcn. que fija el tipo de llamada
	  char  GetMinNumberToDial(); //Fcn. que obtiene el minimo numero de digs a marcar
	  void SetMinNumberToDial(char );//Fcn. que fija el    "        "    "        "
	  int  GetArrayPosition();   //Fcn. que obtiene la posicion en el arreglo
										//de punteros a objetos llamadas
	  void SetArrayPosition(int  ); //Fcn. que fija la posicion
											 //en el arreglo de punteros
	  int  GetState();           //Fcn. que obtiene el estado de la llamada
	  void SetState(int );      //Fcn. que fija el estado de la llamada
	  int AddSubs(Party *); //Fcn para añadir un abonado al arreglo
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

/*<<<<<<<<<<<<<<< Definicion de la clase Arreglo que consiste en >>>>>>>>>>
<<<<<<<<<<<<<<<<< una lista de punteros a objetos llamadas       >>>>>>>>>>*/

class CallArray: public TIDTArrayAsVector<Call>
{
	public:
	Statistic statistic;
	CallArray(int);         // Funcion constructor opcion 1
	CallArray(int,int,int); // Funcion constructor opcion 2
	~CallArray();           // Funcion destructor
};