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
//	~Statistic();     //Destructor de la clase
};
