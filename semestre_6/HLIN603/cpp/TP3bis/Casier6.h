#ifndef Casier6_h
#define Casier6_h

template <typename T>
class Casier6
{
	private:
		T* cases[6];

	public:
		virtual Casier6();
		~Casier6();
		virtual void range(T* objet, int numeroCase);
};

#endif