#pragma once
#ifndef __LIST_H__
#define __LIST_H__

template <class ValType>
class List
{
protected:
	Node<ValType> *head_node;
	int size;
public:
	class Iterator
	{
	private:
		Node<ValType> *current_node;
	public:
		Iterator()
		{
			current_node = NULL;

		}
		Iterator(Node<ValType> *obl)
		{
			current_node = obl;
		}
		Iterator(const Iterator &cop_iter)
		{
			current_node = cop_iter.current_node;
		}
		Iterator operator=(const Iterator &inp_iter)
		{
			current_node = inp_iter.current_node;
			return *this;
		}
		Iterator operator++(int)
		{
			if (current_node == NULL)
				throw 1;
			Iterator obl(*this);
			current_node = current_node->node;
			return obl;
		}
		Iterator operator++()
		{
			if ((current_node->node == NULL) || (current_node == NULL))
				throw 1;
			current_node = current_node->node;
			return *this;
		}
		ValType operator*()
		{
			return current_node->val;
		}
	};
	List()
	{
		head_node = NULL;
		size = 0;
	}
	List(const List<ValType> &cop)
	{
		Node<ValType> *cop_list = cop.head_node;
		push_front(cop_list->val);
		cop_list = cop_list->node;
		Node<ValType> *cop_head = head_node;
		while (cop_list != NULL)
		{
			Node<ValType> *obl_node = new Node<ValType>(cop_list->val);
			obl_node->node = cop_head->node;
			cop_head->node = obl_node;
			cop_head = cop_head->node;
			cop_list = cop_list->node;
		}
		size = cop.size;
	}
	~List()
	{
		while (size != 0)
		{
			Node<ValType> *obl = head_node->node;
			delete head_node;
			head_node = obl;
			size--;
		}
	}
	virtual void push_front(ValType val)
	{
		Node<ValType> *obl = new Node<ValType>(val);
		obl->node = head_node;
		head_node = obl;
		size++;
	}
	virtual void push_back(ValType val)
	{
		if (head_node == NULL)
		{
			push_front(val);
			return;
		}
		Node<ValType> *obl = head_node;
		while (obl->node != NULL)
			obl = obl->node;
		obl->node = new Node<ValType>();
		obl->node->val = val;
		obl->node->node = NULL;
		size++;
	}
	void insert(ValType val, int pos)
	{
		if ((pos > size) || (pos < 0))
			throw 1;
		if (pos == 0)
		{
			push_front(val);
			return;
		}
		int i = 0;
		pos--;
		Node<ValType> *step = head_node;
		while (i < pos)
		{
			if (step == NULL)
				throw 1;
			step = step->node;
			i++;
		}
		Node<ValType> *obl_node = new Node<ValType>(val);
		obl_node->node = step->node;
		step->node = obl_node;
		size++;
	}
	void insert(Node<ValType> *prev, ValType val)
	{
		Node<ValType> *obl = new Node<ValType>();
		obl->val = val;
		obl->node = prev->node;
		prev->node = obl;
		size++;
	}
	virtual void pop_back()
	{
		if (head_node == NULL)
			throw 1;
		if (head_node->node == NULL)
		{
			pop_front();
			return;
		}
		Node<ValType> *obl = head_node;
		while (head_node->node->node != NULL)
			head_node = head_node->node;
		delete head_node->node;
		head_node->node = NULL;
		head_node = obl;
		size--;
	}
	virtual void pop_front()
	{
		if (head_node == NULL)
			throw 1;
		Node<ValType> *step_head = head_node->node;
		delete head_node;
		head_node = step_head;
		size--;
	}
	void remove(int pos)
	{
		if ((pos < 0) || (pos > size))
			throw 1;
		if (pos == 0)
		{
			pop_front();
			return;
		}
		Node<ValType> *obl_head = head_node;
		int i = 0;
		pos--;
		while (i < pos)
		{
			if (head_node->node->node == NULL)
				throw 1;
			head_node = head_node->node;
			i++;
		}
		Node<ValType> *obl_step = head_node->node->node;
		delete head_node->node;
		head_node->node = obl_step;
		head_node = obl_head;
		size--;
	}
	void remove(Node<ValType> *prev)
	{
		if (prev->node == NULL)
			throw 1;
		Node<ValType> *obl = prev->node->node;
		delete prev->node;
		prev->node = obl;
		size--;
	}
	ValType find(int pos)
	{
		Node<ValType> *obl_step = head_node;
		int i = 0;
		while (i < pos)
		{
			if (obl_step->node == NULL)
				throw 1;
			obl_step = obl_step->node;
			i++;
		}
		return obl_step->val;

	}
	virtual void print()
	{
		Node<ValType> *step_head = head_node;
		while (step_head != NULL)
		{
			cout << step_head->val << ' ';
			step_head = step_head->node;
		}
	}
	Iterator begin()
	{
		Iterator obl(head_node);
		return obl;
	}
	int get_size()
	{
		return size;
	}
	bool empty()
	{
		return size;
	}
};
#endif
