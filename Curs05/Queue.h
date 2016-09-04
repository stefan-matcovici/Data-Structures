template<class Type>
class Queue
{
	class QueueNode
	{
		friend class Queue;
		QueueNode(Type i, QueueNode* next = 0)
		{
			m_inf = i;
			m_succ = next;
		}
		Type m_inf;
		QueueNode* m_succ;
	};

	QueueNode* m_begin;
	QueueNode* m_end;

public:
	Queue(): m_begin(0), m_end(0)
	{ }

	void clear()
	{
		while (!isEmpty())
		{
			QueueNode* temp;
			temp = m_begin;
			m_begin = temp->m_succ;
			delete temp;
		}
	}

	bool isEmpty()
	{
		return m_begin == 0;
	}

	void pop()
	{
		if (!isEmpty())
		{
			QueueNode* temp;
			temp = m_begin;
			m_begin = m_begin->m_succ;
			m_begin = temp
		}
	}

	void push(Type element)
	{
		QueueNode* temp;
		temp = new QueueNode(element);
		temp->m_succ = m_end;
		m_end = temp;
		if (isEmpty())
			m_begin = m_end;
	}

	Type top()
	{
		if (!isEmpty())
			return m_begin->m_inf;
		return Type();
	}
};
//typedef int elt;
//struct NodA
//{
//	elt inf;
//	NodA *drp, *stg;
//	bool tdrp;
//};
//struct Nodc
//{
//    NodA* inf;
//    Nodc *succ;
//};
//struct Coada
//{
//    Nodc *prim, *ultim;
//};
//
//Coada coadaVida()
//{
//	Coada C;
//    C.prim=NULL;
//    C.ultim=NULL;
//	return C;
//}
//
//bool esteVida(Coada C)
//{
//    return C.prim==NULL && C.ultim==NULL;
//}
//
//NodA* citesteC(Coada C)
//{
//    return C.prim->inf;
//}
//
//void insereazaC(Coada &C,NodA* e)
//{
//    Nodc *p;
//    p=new Nodc;
//    p->inf=e;
//    p->succ=NULL;
//    if (C.ultim!=NULL)
//        C.ultim->succ=p;
//    else
//    {
//        C.prim=p;
//    }
//    C.ultim=p;
//}
//
//void eliminaC(Coada &C)
//{
//    if (C.prim!=NULL)
//        C.prim=C.prim->succ;
//    if (C.prim==NULL)
//        C.ultim=NULL;
//}
//
