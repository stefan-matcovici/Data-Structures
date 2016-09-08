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
		m_end = m_begin;
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
		if (isEmpty())
		{
			m_end = temp;
			m_begin = m_end;
		}
		else
		{
			m_end->m_succ = temp;
			m_end = temp;
		}
	}

	Type top()
	{
		if (!isEmpty())
			return m_begin->m_inf;
		return Type();
	}
};