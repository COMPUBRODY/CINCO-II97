
// <<<<<<<<<<<<<<<<<<<<< Definicion de la clase base Terminal >>>>>>>>>>>>>
////////////////////  Y SUS DERIVADAS //////////////////
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
	CARegister();
	CARegister(int type);		  //constructor
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
	CERegister();					 //constructor
} ;

// <<<<<<<<<<<<<<<<<<<< Definicion de la clase derivada DTMFRegister>>>>

class DTMFRegister: public Terminal
{
	private:

	public:
	DTMFRegister();					 //constructor
} ;

// <<<<<<<<<<<<<<< Definicion de la clase derivada TONERegister >>>>>>>>>

class TONERegister: public Terminal
{
	private:
	int typeOfTone;                   //Tipo de tono

	public:
	TONERegister();					 //Constructor
	virtual void SetTypeOfTone(int);  //Funcion que fija el tipo de tono
	virtual int GetTypeOfTone();   //Funcion que obtiene el tipo de tono
} ;