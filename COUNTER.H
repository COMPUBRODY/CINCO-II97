//>>>>>>>> Def de clase para crear contadores para temporizacion >>>>>>>>
class Counter
{
		unsigned int count;
		int term;
	public:
		Counter( int, unsigned int);      //constructor
		~Counter();                       //destructor
		int GetTerminal();
		void ReStart ( unsigned int );   //Fcn. para reiniciar contador
		int DetectFinalCount(int); //
		//int Update();           //Fcn. para actualizar el counter y verificar fin
		int  operator ==(const Counter&)const;
};