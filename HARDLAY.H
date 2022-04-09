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
		int Disconnect(Subscriber *,Tk *, Tone *, Dtmf *); //Fcn. desconecta abonado de todo
		int Disconnect(Subscriber *, Party *); //Fcn. desconectar abonado del tono de ring
};