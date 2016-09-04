template<class Type>
class Stack
{
	class StackNode
	{
		friend class Stack;
		StackNode(Type i, StackNode* next = 0)
		{
			m_inf = i;
			m_succ = next;
		}
		Type m_inf;
		StackNode* m_succ;
	};

	StackNode* m_begin;

public:
	Stack()
	{
		m_begin = 0;
	}
	void clear()
	{
		while (!isEmpty())
		{
			StackNode* temp;
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
			StackNode* temp;
			temp = m_begin;
			m_begin = m_begin->m_succ;
			m_begin = temp
		}
	}

	void push(Type element)
	{
		StackNode* temp;
		temp = new StackNode(element);
		temp->m_succ = m_begin;
		m_begin = temp;
	}

	Type top()
	{
		if (!isEmpty())
			return m_begin->m_inf;
		return Type();
	}
};