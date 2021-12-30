#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
	char *m_name;
	int m_id;
	person(char *name = 0, int id = 0);
	~person();
};
inline person::person(char *name, int id) : m_id(id)
{
	if (name)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}
	else
	{
		m_name = new char[1];
		*m_name = '\0';
	}
}
inline person::~person(){ delete [] m_name;}



class teacher:public person
{
private:
	int m_degree;
	int m_dep;
public:
	teacher(int degree = 0,int dep =0,char *name = 0,int id = 0);
	~teacher(){}
	void show(){cout<<m_degree<<m_dep<<m_name<<m_id;}

};
inline teacher::teacher(int degree,int dep,char *name,int id):m_degree(degree),m_dep(dep),person(name,id)
{
	;
}





int main(void)
{
	teacher t1(1,2,"zhangsan",3);
	t1.show();
	return 0;
}