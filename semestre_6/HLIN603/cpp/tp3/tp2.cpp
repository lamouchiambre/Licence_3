
#include <iostream>

using namespace std;
/*heritage doit etre toujours public 
sinon si B herite de A impossible d'ecrire A* a = new B();
principe meme de la prog Object 
*/
class C1
{
	protected: 
		virtual void f(){}
		friend class A;
		friend class B;
	public:
		virtual void mc1();
};

class C2 :public virtual C1
{
	public:
		virtual void mc2();
	};

void C1::mc1() {
	C1 *c1; 
	c1->f(); 
	C2 *c2; 
	c2->f(); // fonctionne car c2 utilisable parout dans la hierachie
}

void C2::mc2() {
	C1 *c1; 
	//c1->f(); car don est dans un methode c2 on ne peut pas acceder au element protected
	C2 *c2; 
	c2->f();}

class A
{
	public:
		virtual void ma() {
			C1 *c1; 
			c1->f(); 
			C2 *c2; 
			c2->f();}
};

class B : public virtual A
{	
	public:
		virtual void mb() {
			C1 *c1; 
			c1->f(); 
			C2 *c2; 
			c2->f();}
};

class D
{
public:
	virtual void md(){
		C1 *c1;
		//c1->f();
		C2 *c2; 
		//c2->f();
	}
};

int main(){
	C1 *c1; 
	//c1->f(); 
	C2 *c2; 
	//c2->f();
	cout << "je compile" << endl;
}