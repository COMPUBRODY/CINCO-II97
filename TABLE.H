//<<<<<<<<<<<<<<<< Definicion de la clase apuntador a tablas >>>>>>>>>>>>>>>

class Table
{
	private:
	int CEOffset;              // Inicio de las respectivas terminales
	int DTMFOffset;
	int TONEOffset;
	TIDTArrayAsVector<Call> *subsTable; //Arreglo que liga subsTerm con su call
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
	int  GetDirRights(int);       // Funcion que obtiene los derechos del abonado
	void SetDirRights(int,int);   // Funcion que fija los derechos del abonado
	int  GetTermRights(int);       // Funcion que obtiene los derechos de la terminal
	void SetTermRights(int,int);   // Funcion que fija los derechos de la terminal
	void SetTypeOfTone(int,int);   //Funcion que fija el tipo de tono
	int  GetTypeOfTone(int);   //Funcion que obtiene el tipo de tono
	int  GetTermTone(int);		//Fcn. para obtener la terminal de algun tono
	int  FindFree(int termTyp,int subType = 0);// Funcion que encuentra un terminal libre
	int  Add(int); 			   //Fcn. para agregar un nuevo elemento terminal
	int  Detach(int);          //Fcn. para borrar un elemento terminal
	int  TermValid(int,int);   //Fcn. de validacion de terminal 1
	int  TermValid(int);			// "       "              "      2
	Call *GetCallPtr(int);		//Fcn. para obtener el ptr a call de un term.
	void SetCallPtr(int,Call *);//Fcn para fijar el CallPtr de subsTerm
	void DetachCallPtr(int);    //Fcn. para desligar la llamada del subs
};