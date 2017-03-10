#include <iostream>
using std::cout;
using std::endl;


class Eye
{
public:
	void look()
	{	cout << "Eye::look()" << endl;	}
};

class Nose
{
public:
	void smell()
	{	cout << "Nose::smell()" << endl;	}
};

class Mouth
{
public:
	void eat()
	{	cout << "Mouth::eat()" << endl;	}
};

class Ear
{
public:
	void listen()
	{	cout << "Ear::listen()" << endl;	}
};


//继承：is A
class Head
: public Eye
, public Nose
, public Mouth
, public Ear
{};

//组合：has A
class HeadEx
{
public:
	void look()
	{	_eye.look();	}

	void smell()
	{	_nose.smell();	}	

	void eat()
	{	_mouth.eat();	}

	void listen()
	{	_ear.listen();	}	
private:
	Eye   _eye;
	Nose  _nose;
	Mouth _mouth;
	Ear   _ear;
};

int main(void)
{
	Head head;
	head.look();
	head.smell();
	head.eat();
	head.listen();
	cout << endl;

	HeadEx headex;
	headex.look();
	headex.smell();
	headex.eat();
	headex.listen();
	return 0;
}
