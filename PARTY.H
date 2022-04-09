/* <<<<<<<<<<<<<<<<<<<<<Definicion de la clase party>>>>>>>>>>>>>>>>>>> */

class Party
{
 protected:
	int terminal;     //#SLIC
	int type;
	int state;
	int highChannel;
	int lowChannel;
	int positionInCall;
 public:
	Party(int term,int type);     //Constructor de la clase party
	virtual ~Party();
	void SetTerminal(int slic);       //Fija #SLIC
	int  GetTerminal();       //Leer #SLIC
	void SetType(int );       //Fija tipo de terminal
	int  GetType();           //Leer     "     "
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

// >>>>>>>>>>>>>>>>>Definion de la clase de Circuito Abonado <<<<<<<<<<<<<<
class Subscriber: public Party
{
	private:
	  char dialDigit[20];
	  int numberOfDigits;
	  int dialedNumberDir;
	  Counter *counterPtr;
	  RingingTerm *ringPtr; //corresponde al abonado que se le marco
	public:
	  Subscriber(int,int type = CA);
	  int  GetNumberOfDigits();
	  int SetDialDigit(int,int);
	  char GetDialDigit(int);
	  int  GetDialedNumberDir();       //Numero de directorio marcado
	  Counter *GetCounterPtr();            //Posicion del temporizador
	  void SetCounterPtr(Counter *);
	  RingingTerm *GetRingPtr();               //Posicion del ring
	  void SetRingPtr(RingingTerm *);
};

// >>>>>>>>>>>>>>>>>Definion de la clase de Circuito de Enlace <<<<<<<<<<<<<<
class Tk: public Subscriber
{
	private:
	public:
	  Tk(int);
//	  void SetDialDigit(int);
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